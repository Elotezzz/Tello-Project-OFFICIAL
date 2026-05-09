#pragma once
#include <iostream>
#include "Tablero.h"

template <typename T>
class NodeTablero
{
public:
    T* data;
    NodeTablero<T>* next;
    NodeTablero<T>* prev;

    NodeTablero(T* data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedListTablero
{
private:
    NodeTablero<T>* head;
    int length;

    NodeTablero<T>* NodeAt(int pos) {
        if (pos >= length) {
            std::cout << "No existe posicion, debe ser menor al tamanio de la lista...\n";
            return nullptr;
        }
        int index = 0;
        NodeTablero<T>* aux = head;
        while (index < pos) {
            aux = aux->next;
            index++;
        }
        return aux;
    }

public:
    LinkedListTablero() : head(nullptr), length(0) {}

    ~LinkedListTablero() {
        NodeTablero<T>* aux = head;
        NodeTablero<T>* aux2;
        while (aux != nullptr) {
            aux2 = aux->next;
            delete aux;
            aux = aux2;
        }
    }

    void agregar(T* data) {
        NodeTablero<T>* nuevo = new NodeTablero<T>(data);
        if (head == nullptr) {
            head = nuevo;
        }
        else {
            NodeTablero<T>* aux = head;
            while (aux->next != nullptr)
                aux = aux->next;
            aux->next = nuevo;
            nuevo->prev = aux;
        }
        length++;
    }

    void imprimir(bool reverse = false) {
        if (isEmpty()) {
            std::cout << "Esta Vacio...\n";
            return;
        }
        NodeTablero<T>* aux = reverse ? NodeAt(length - 1) : head;
        while (aux != nullptr) {
            std::cout << aux->data->getNombre() << " ";
            aux = reverse ? aux->prev : aux->next;
        }
        std::cout << std::endl;
    }

    int getLength() const { return length; }
    bool isEmpty() const { return length == 0; }

    void AgregarInicio(T data) {
        NodeTablero<T>* node = new NodeTablero<T>(data);
        if (!isEmpty()) {
            node->next = head;
            head->prev = node;
        }
        head = node;
        length++;
    }

    void RemoverPrimero() {
        if (isEmpty()) {
            std::cout << "No se puede eliminar un nodo en una lista enlazada vacia\n";
            return;
        }
        NodeTablero<T>* aux = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete aux;
        length--;
    }

    void RemoverPosicion(int pos) {
        if (isEmpty()) {
            std::cout << "No se puede eliminar un nodo en una lista enlazada vacia\n";
            return;
        }
        if (pos == 0)
            RemoverPrimero();
        else {
            NodeTablero<T>* nodoAnterior = NodeAt(pos - 1);
            NodeTablero<T>* nodoEliminar = NodeAt(pos);
            if (nodoAnterior != nullptr && nodoEliminar != nullptr) {
                nodoAnterior->next = nodoEliminar->next;
                if (nodoEliminar->next != nullptr)
                    nodoEliminar->next->prev = nodoAnterior;
                delete nodoEliminar;
                length--;
            }
        }
    }

    void RemoverUltimo() {
        if (isEmpty()) {
            std::cout << "No se puede eliminar un nodo en una lista enlazada vacia\n";
            return;
        }
        if (length == 1) {
            delete head;
            head = nullptr;
            length--;
        }
        else {
            NodeTablero<T>* nodoPrevio = NodeAt(length - 2);
            if (nodoPrevio != nullptr) {
                delete nodoPrevio->next;
                nodoPrevio->next = nullptr;
                length--;
            }
        }
    }

    T* GetPrimero() {
        NodeTablero<T>* primero = NodeAt(0);
        if (primero == nullptr) return nullptr;
        return primero->data;
    }

    T* GetPos(int pos) {
        NodeTablero<T>* node = NodeAt(pos);
        if (node == nullptr) return nullptr;
        return node->data;
    }

    T* GetUltimo() {
        NodeTablero<T>* ultimo = NodeAt(length - 1);
        if (ultimo == nullptr) return nullptr;
        return ultimo->data;
    }

    void eliminarPorNombre(std::string nombre) {
        if (isEmpty()) {
            std::cout << "La lista esta vacia\n";
            return;
        }
        if (head->data->getNombre() == nombre) {
            RemoverPrimero();
            return;
        }
        NodeTablero<T>* anterior = head;
        while (anterior->next != nullptr && anterior->next->data->getNombre() != nombre)
            anterior = anterior->next;
        if (anterior->next == nullptr) {
            std::cout << "No se encontro el tablero con nombre: " << nombre << std::endl;
            return;
        }
        NodeTablero<T>* aEliminar = anterior->next;
        anterior->next = aEliminar->next;
        if (aEliminar->next != nullptr)
            aEliminar->next->prev = anterior;
        delete aEliminar;
        length--;
    }
};
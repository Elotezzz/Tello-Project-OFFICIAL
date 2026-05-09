#pragma once
#include <iostream>
#include "Tablero.h"

template <typename T>
class NodeTablero
{
public:
    T data;
    NodeTablero<T>* siguiente;
    NodeTablero<T>* anterior;

    NodeTablero(T& data) : data(data), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class LinkedListTablero
{
private:
    NodeTablero<T>* cabeza;
    int length;

    NodeTablero<T>* NodeAt(int pos) {
        if (pos >= length) {
            std::cout << "No existe posicion, debe ser menor al tamanio de la lista...\n";
            return nullptr;
        }
        int index = 0;
        NodeTablero<T>* aux = cabeza;
        while (index < pos) {
            aux = aux->siguiente;
            index++;
        }
        return aux;
    }

public:
    LinkedListTablero() : cabeza(nullptr), length(0) {}

    ~LinkedListTablero() {
        NodeTablero<T>* aux = cabeza;
        NodeTablero<T>* aux2;
        while (aux != nullptr) {
            aux2 = aux->siguiente;
            delete aux;
            aux = aux2;
        }
    }

    void agregar(T data) {
        NodeTablero<T>* nuevo = new NodeTablero<T>(data);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            NodeTablero<T>* aux = cabeza;
            while (aux->siguiente != nullptr)
                aux = aux->siguiente;
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
        length++;
    }

    void imprimir(bool reverse = false) {
        if (isEmpty()) {
            std::cout << "Esta Vacio...\n";
            return;
        }
        NodeTablero<T>* aux = reverse ? NodeAt(length - 1) : cabeza;
        while (aux != nullptr) {
            std::cout << aux->data << " ";
            aux = reverse ? aux->anterior : aux->siguiente;
        }
        std::cout << std::endl;
    }

    int getLength() const { return length; }
    bool isEmpty() const { return length == 0; }

    void AgregarInicio(T data) {
        NodeTablero<T>* node = new NodeTablero<T>(data);
        if (!isEmpty()) {
            node->siguiente = cabeza;
            cabeza->anterior = node;
        }
        cabeza = node;
        length++;
    }

    void RemoverPrimero() {
        if (isEmpty()) {
            std::cout << "No se puede eliminar un nodo en una lista enlazada vacia\n";
            return;
        }
        NodeTablero<T>* aux = cabeza;
        cabeza = cabeza->siguiente;
        if (cabeza != nullptr)
            cabeza->anterior = nullptr;
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
                nodoAnterior->siguiente = nodoEliminar->siguiente;
                if (nodoEliminar->siguiente != nullptr)
                    nodoEliminar->siguiente->anterior = nodoAnterior;
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
            delete cabeza;
            cabeza = nullptr;
            length--;
        }
        else {
            NodeTablero<T>* nodoPrevio = NodeAt(length - 2);
            if (nodoPrevio != nullptr) {
                delete nodoPrevio->siguiente;
                nodoPrevio->siguiente = nullptr;
                length--;
            }
        }
    }

    T* GetPrimero() {
        NodeTablero<T>* primero = NodeAt(0);
        if (primero == nullptr) return nullptr;
        return &primero->data;
    }

    T* GetPos(int pos) {
        NodeTablero<T>* node = NodeAt(pos);
        if (node == nullptr) return nullptr;
        return &node->data;
    }

    T* GetUltimo() {
        NodeTablero<T>* ultimo = NodeAt(length - 1);
        if (ultimo == nullptr) return nullptr;
        return &ultimo->data;
    }

    void eliminarPorNombre(std::string nombre) {
        if (isEmpty()) {
            std::cout << "La lista esta vacia\n";
            return;
        }
        if (cabeza->data.getNombre() == nombre) {
            RemoverPrimero();
            return;
        }
        NodeTablero<T>* anterior = cabeza;
        while (anterior->siguiente != nullptr && anterior->siguiente->data.getNombre() != nombre)
            anterior = anterior->siguiente;
        if (anterior->siguiente == nullptr) {
            std::cout << "No se encontro el tablero con nombre: " << nombre << std::endl;
            return;
        }
        NodeTablero<T>* aEliminar = anterior->siguiente;
        anterior->siguiente = aEliminar->siguiente;
        if (aEliminar->siguiente != nullptr)
            aEliminar->siguiente->anterior = anterior;
        delete aEliminar;
        length--;
    }
};
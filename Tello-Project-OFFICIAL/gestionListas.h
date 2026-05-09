#pragma once
#include <iostream>
#include "Listado.h"

template <typename T>
class NodeListados
{
public:
    T* data;                    // <-- puntero
    NodeListados<T>* siguiente;
    NodeListados<T>* anterior;

    NodeListados(T* data) : data(data), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class LinkedListListados
{
private:
    NodeListados<T>* cabeza;
    int length;

    NodeListados<T>* NodeAt(int pos) {
        if (pos >= length) {
            std::cout << "No existe posicion, debe ser menor al tamanio de la lista...\n";
            return nullptr;
        }
        int index = 0;
        NodeListados<T>* aux = cabeza;
        while (index < pos) {
            aux = aux->siguiente;
            index++;
        }
        return aux;
    }

public:
    LinkedListListados() : cabeza(nullptr), length(0) {}

    ~LinkedListListados() {
        NodeListados<T>* aux = cabeza;
        NodeListados<T>* aux2;
        while (aux != nullptr) {
            aux2 = aux->siguiente;
            delete aux->data;   // <-- libera el Listado
            delete aux;
            aux = aux2;
        }
    }

    void agregar(T* data) {     // <-- puntero
        NodeListados<T>* nuevo = new NodeListados<T>(data);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            NodeListados<T>* aux = cabeza;
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
        NodeListados<T>* aux = reverse ? NodeAt(length - 1) : cabeza;
        while (aux != nullptr) {
            std::cout << *aux->data << " ";   // <-- desreferencia
            aux = reverse ? aux->anterior : aux->siguiente;
        }
        std::cout << std::endl;
    }

    int getLength() const { return length; }
    bool isEmpty() const { return length == 0; }

    void RemoverPrimero() {
        if (isEmpty()) {
            std::cout << "No se puede eliminar un nodo en una lista enlazada vacia\n";
            return;
        }
        NodeListados<T>* aux = cabeza;
        cabeza = cabeza->siguiente;
        if (cabeza != nullptr)
            cabeza->anterior = nullptr;
        delete aux->data;   // <-- libera el Listado
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
            NodeListados<T>* nodoAnterior = NodeAt(pos - 1);
            NodeListados<T>* nodoEliminar = NodeAt(pos);
            if (nodoAnterior != nullptr && nodoEliminar != nullptr) {
                nodoAnterior->siguiente = nodoEliminar->siguiente;
                if (nodoEliminar->siguiente != nullptr)
                    nodoEliminar->siguiente->anterior = nodoAnterior;
                delete nodoEliminar->data;  // <-- libera el Listado
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
            delete cabeza->data;    // <-- libera el Listado
            delete cabeza;
            cabeza = nullptr;
            length--;
        }
        else {
            NodeListados<T>* nodoPrevio = NodeAt(length - 2);
            if (nodoPrevio != nullptr) {
                NodeListados<T>* ultimoNodo = nodoPrevio->siguiente;
                nodoPrevio->siguiente = nullptr;
                delete ultimoNodo->data;    // <-- libera el Listado
                delete ultimoNodo;
                length--;
            }
        }
    }

    T* GetPrimero() {
        NodeListados<T>* primero = NodeAt(0);
        if (primero == nullptr) return nullptr;
        return primero->data;   // <-- ya es puntero, sin &
    }

    T* GetPos(int pos) {
        NodeListados<T>* node = NodeAt(pos);
        if (node == nullptr) return nullptr;
        return node->data;      // <-- ya es puntero, sin &
    }

    T* GetUltimo() {
        NodeListados<T>* ultimo = NodeAt(length - 1);
        if (ultimo == nullptr) return nullptr;
        return ultimo->data;    // <-- ya es puntero, sin &
    }

    void eliminarPorNombre(std::string nombre) {
        if (isEmpty()) {
            std::cout << "La lista esta vacia\n";
            return;
        }
        if (cabeza->data->getNombre() == nombre) {  // <-- flecha en vez de punto
            RemoverPrimero();
            return;
        }
        NodeListados<T>* anterior = cabeza;
        while (anterior->siguiente != nullptr && anterior->siguiente->data->getNombre() != nombre)
            anterior = anterior->siguiente;
        if (anterior->siguiente == nullptr) {
            std::cout << "No se encontro el listado con nombre: " << nombre << std::endl;
            return;
        }
        NodeListados<T>* aEliminar = anterior->siguiente;
        anterior->siguiente = aEliminar->siguiente;
        if (aEliminar->siguiente != nullptr)
            aEliminar->siguiente->anterior = anterior;
        delete aEliminar->data;     // <-- libera el Listado
        delete aEliminar;
        length--;
    }

    void setDataPos(T* data, int pos) {
        NodeListados<T>* node = NodeAt(pos);
        if (node != nullptr)
            node->data = data;
    }
};
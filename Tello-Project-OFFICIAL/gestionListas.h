#pragma once
#include <iostream>
#include "Listado.h"

template <typename T>

class NodeListados
{
public:
	T data;
	NodeListados<T>* siguiente;
	NodeListados<T>* anterior;
    
	NodeListados(T& data) : data(data), siguiente(nullptr), anterior(nullptr) {}
	NodeListados(T& data, NodeListados<T>* next) : data(data), siguiente(siguiente), anterior(nullptr) {}
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
		// Buscar el nodo, usando la posición
		int index = 0;
		NodeListados<T>* aux = head;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta ubicar el nodo
		// en la posición que está mandada como parámetro
		while (index < pos) {
			aux = aux->next;
			index++;
		}
		return aux;
	}

public:
	LinkedListListados() {
		cabeza = nullptr;
	};
	~LinkedListListados() {
		NodeListados<T>* aux = cabeza;
		NodeListados<T>* aux2;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta eliminar el último
		while (aux != nullptr) {
			aux2 = aux->next;
			delete aux;
			aux = aux2;
		}
	};

    void agregar(T data)
    {
        NodeListados<T>* nuevo = new NodeListados<T>(data);
        if (cabeza == nullptr)
        {
            cabeza = nuevo;
        }
        else
        {
            NodeListados<T>* aux = cabeza;

            while (aux->siguiente != nullptr)
            {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
	void imprimir(bool reverse = false) {
		if (isEmpty()) {
			std::cout << "Esta Vacio...\n";
			return;
		}
		NodeListados<T>* aux;
		
		if (reverse)
			aux = NodeAt(length - 1);
		else
			aux = cabeza;
		while (aux != nullptr) {
			std::cout << aux->data << " ";
			
			if (reverse)
				aux = aux->anterior;
			else
				aux = aux->siguiente;
		}
		std::cout << std::endl;
	}
	int getLength() const { return length; }
	bool isEmpty() const { return length == 0; }
	
	void AgregarInicio(T data) {
		NodeListados<T>* node = new NodeListados<T>(data);
		if (isEmpty()) { // Cuando está vacío next y prev apuntan a nulo
			node->siguiente = nullptr;
			node->anterior = nullptr;
		}
		else {
			node->siguiente = cabeza;
			cabeza->anterior = node;
		}
		cabeza = node;
		length++;
	}

	void AgregarEnPos(T data, int pos) {
		// Ubicamos la posición anterior
		if (pos == 0) // Agrego al inicio
			AgregarInicio(data);
		else
		{
			NodeListados<T>* nodoAnterior = NodeAt(pos - 1);
			if (nodoAnterior == nullptr) {
				std::cout << "Error: No se puede ejecutar, posicion fuera de rango\n";
				return;
			}
			NodeListados<T>* nodoSiguiente = nodoAnterior->siguiente;
			// El nodo nuevo apunta a la siguiente posición
			NodeListados<T>* nodo = new NodeListados<T>(data, nodoSiguiente, nodoAnterior);
			// El nodo anterior apunta al nuevo nodo.
			nodoAnterior->siguiente = nodo;
			if (nodoSiguiente != nullptr)
				nodoSiguiente->anterior = nodo;
			length++;
		}
	}
	void ModificarPrimero(T data) {
		NodeListados<T>* NodoActual = NodeAt(0);
		if (NodoActual != nullptr) {
			NodoActual->data = data;
		}
	}

	void ModificarPosicion(T data, int pos) {
		NodeListados<T>* NodoActual = NodeAt(pos);
		if (NodoActual != nullptr) {
			NodoActual->data = data;
		}
	}

	void ModificarUltimo(T data) {
		NodeListados<T>* NodoActual = NodeAt(length - 1);
		if (NodoActual != nullptr) {
			NodoActual->data = data;
		}
	}

	void RemoverPrimero() {
		if (isEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		NodeListados<T>* aux = cabeza;
		cabeza = cabeza->siguiente;
		delete aux;
		length--;
	}

	void RemoverPosicion(int pos) {
		if (isEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		if (pos == 0) // Remuevo el inicio
			RemoveFirst();
		else {
			Node<T>* nodeBefore = NodeAt(pos - 1);
			Node<T>* nodeErase = NodeAt(pos);
			if (nodeBefore != nullptr && nodeErase != nullptr) {
				nodeBefore->next = nodeErase->next;
				// Podemos eliminar con tranquilidad el nodo elegido
				delete nodeErase;
				length--;
			}
		}
	}

	void RemoverUltimo() {
		if (IsEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		if (length == 1) {
			NodeListados<T>* aux = cabeza;
			cabeza = nullptr;
			delete aux;
			length--;
		}
		else {
			// Busca el penúltimo nodo, lo guardamos
			NodeListados<T>* nodePrevioAlUltimo = NodeAt(length - 2);
			if (nodePrevioAlUltimo != nullptr) {
				// Penúltimo nodo apunte a nulo y hacemos que el último nodo
				// sea eliminado.
				NodeListados<T>* ultimoNodo = nodePrevioAlUltimo->siguiente;
				nodePrevioAlUltimo->siguiente = nullptr;
				delete ultimoNodo;
				length--;
			}
		}
	}

	T GetPrimero() {
		NodeListados<T>* primero = NodeAt(0);
		return primero != nullptr ? primero->data : -1;
	}

	T GetPos(int pos) {
		NodeListados<T>* node = NodeAt(pos);
		return node != nullptr ? node->data : -1;
	}

	T GetUltimo() {
		NodeListados<T>* ultimo = NodeAt(length - 1);
		return ultimo != nullptr ? ultimo->data : -1;
	}
};


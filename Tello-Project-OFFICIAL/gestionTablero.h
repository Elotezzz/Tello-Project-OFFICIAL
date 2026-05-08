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
	NodeTablero(T& data, NodeTablero<T>* next) : data(data), siguiente(siguiente), anterior(nullptr) {}
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
		// Buscar el nodo, usando la posición
		int index = 0;
		NodeTablero<T>* aux = head;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta ubicar el nodo
		// en la posición que está mandada como parámetro
		while (index < pos) {
			aux = aux->next;
			index++;
		}
		return aux;
	}

public:
	LinkedListTablero() {
		cabeza = nullptr;
	};
	~LinkedListTablero() {
		NodeTablero<T>* aux = cabeza;
		NodeTablero<T>* aux2;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta eliminar el último
		while (aux != nullptr) {
			aux2 = aux->next;
			delete aux;
			aux = aux2;
		}
	};

	void agregar(T data)
	{
		NodeTablero<T>* nuevo = new NodeTablero<T>(data);
		if (cabeza == nullptr)
		{
			cabeza = nuevo;
		}
		else
		{
			NodeTablero<T>* aux = cabeza;

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
		NodeTablero<T>* aux;

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
		NodeTablero<T>* node = new NodeTablero<T>(data);
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
			NodeTablero<T>* nodoAnterior = NodeAt(pos - 1);
			if (nodoAnterior == nullptr) {
				std::cout << "Error: No se puede ejecutar, posicion fuera de rango\n";
				return;
			}
			NodeTablero<T>* nodoSiguiente = nodoAnterior->siguiente;
			// El nodo nuevo apunta a la siguiente posición
			NodeTablero<T>* nodo = new NodeTablero<T>(data, nodoSiguiente, nodoAnterior);
			// El nodo anterior apunta al nuevo nodo.
			nodoAnterior->siguiente = nodo;
			if (nodoSiguiente != nullptr)
				nodoSiguiente->anterior = nodo;
			length++;
		}
	}
	void ModificarPrimero(T data) {
		NodeTablero<T>* NodoActual = NodeAt(0);
		if (NodoActual != nullptr) {
			NodoActual->data = data;
		}
	}

	void ModificarPosicion(T data, int pos) {
		NodeTablero<T>* NodoActual = NodeAt(pos);
		if (NodoActual != nullptr) {
			NodoActual->data = data;
		}
	}

	void ModificarUltimo(T data) {
		NodeTablero<T>* NodoActual = NodeAt(length - 1);
		if (NodoActual != nullptr) {
			NodoActual->data = data;
		}
	}

	void RemoverPrimero() {
		if (isEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		NodeTablero<T>* aux = cabeza;
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
			NodeTablero<T>* aux = cabeza;
			cabeza = nullptr;
			delete aux;
			length--;
		}
		else {
			// Busca el penúltimo nodo, lo guardamos
			NodeTablero<T>* nodePrevioAlUltimo = NodeAt(length - 2);
			if (nodePrevioAlUltimo != nullptr) {
				// Penúltimo nodo apunte a nulo y hacemos que el último nodo
				// sea eliminado.
				NodeTablero<T>* ultimoNodo = nodePrevioAlUltimo->siguiente;
				nodePrevioAlUltimo->siguiente = nullptr;
				delete ultimoNodo;
				length--;
			}
		}
	}

	T GetPrimero() {
		NodeTablero<T>* primero = NodeAt(0);
		return primero != nullptr ? primero->data : -1;
	}

	T GetPos(int pos) {
		NodeTablero<T>* node = NodeAt(pos);
		return node != nullptr ? node->data : -1;
	}

	T GetUltimo() {
		NodeTablero<T>* ultimo = NodeAt(length - 1);
		return ultimo != nullptr ? ultimo->data : -1;
	}
};


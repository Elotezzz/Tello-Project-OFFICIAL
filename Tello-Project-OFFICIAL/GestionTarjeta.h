#pragma once
#include <iostream>
#include <string>
template <typename T>
class Nodo {
public:
	T data;
	Nodo<T>* next;
	// Constructor
	Nodo(T& data) : data(data), next(nullptr) {}
	Nodo(T& data, Nodo<T>* next) : data(data), next(next) {}
};

// Lista Enlazada
template <typename T>
class ListaEnlazadaTarjeta {
private:
	Nodo<T>* head;
	int length;

	// Método privado que va a buscar un nodo en una posición en particular
	// posición comienza de 0, como los arreglos
	Nodo<T>* NodeAt(int pos) {
		if (pos >= length) {
			std::cout << "No existe posicion, debe ser menor al tamanio de la lista...\n";
			return nullptr;
		}
		// Buscar el nodo, usando la posición
		int index = 0;
		Nodo<T>* aux = head;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta ubicar el nodo
		// en la posición que está mandada como parámetro
		while (index < pos) {
			aux = aux->next;
			index++;
		}
		return aux;
	}

public:
	// Constructor
	ListaEnlazadaTarjeta() : head(nullptr), length(0) {}
	// Destructor
	~ListaEnlazadaTarjeta() {
		Nodo<T>* aux = head;
		Nodo<T>* aux2;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta eliminar el último
		while (aux != nullptr) {
			aux2 = aux->next;
			delete aux;
			aux = aux2;
		}
	}

	void Print(bool space = true) {
		if (IsEmpty()) {
			std::cout << "La lista enlazada esta Vacia...\n";
			return;
		}
		Nodo<T>* aux = head;
		while (aux != nullptr) {
			std::string sep = space ? " " : "\n";
			std::cout << aux->data << sep;
			aux = aux->next;
		}
		std::cout << std::endl;
	}

	// La longitud
	int Length() {
		return length;
	}

	// Es vacío
	bool IsEmpty() {
		return length == 0;
	}

	void AddFirst(T data) {
		Nodo<T>* node = new Nodo<T>(data, IsEmpty() ? nullptr : head);
		head = node;
		length++;
	}

	void AddPos(T data, int pos) {
		// Ubicamos la posición anterior
		if (pos == 0) // Agrego al inicio
			AddFirst(data);
		else
		{
			Nodo<T>* nodeBefore = NodeAt(pos - 1);
			Nodo<T>* nodeAfter = nodeBefore->next;
			// El nodo nuevo apunta a la siguiente posición
			Nodo<T>* node = new Nodo<T>(data, nodeAfter);
			// El nodo anterior apunta al nuevo nodo.
			nodeBefore->next = node;
		}
		length++;
	}

	void AddLast(T data) {
		Nodo<T>* node = new Nodo<T>(data);
		if (IsEmpty()) {
			head = node;
		}
		else {
			// Buscamos el último nodo y lo agregamos
			Nodo<T>* nodeLast = NodeAt(length - 1);
			nodeLast->next = node;
		}
		length++;
	}

	void ModifyFirst(T data) {
		Nodo<T>* currentNode = NodeAt(0);
		if (currentNode != nullptr) {
			currentNode->data = data;
		}
	}

	void ModifyPos(T data, int pos) {
		Nodo<T>* currentNode = NodeAt(pos);
		if (currentNode != nullptr) {
			currentNode->data = data;
		}
	}

	void ModifyLast(T data) {
		Nodo<T>* currentNode = NodeAt(length - 1);
		if (currentNode != nullptr) {
			currentNode->data = data;
		}
	}

	void RemoveFirst() {
		if (IsEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		Nodo<T>* aux = head;
		head = head->next;
		delete aux;
		length--;
	}

	void RemovePos(int pos) {
		if (IsEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		if (pos == 0) // Remuevo el inicio
			RemoveFirst();
		else {
			Nodo<T>* nodeBefore = NodeAt(pos - 1);
			Nodo<T>* nodeErase = NodeAt(pos);
			if (nodeBefore != nullptr && nodeErase != nullptr) {
				nodeBefore->next = nodeErase->next;
				// Podemos eliminar con tranquilidad el nodo elegido
				delete nodeErase;
				length--;
			}
		}
	}

	void RemoveLast() {
		if (IsEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		if (length == 1) {
			Nodo<T>* aux = head;
			head = nullptr;
			delete aux;
			length--;
		}
		else {
			// Busca el penúltimo nodo, lo guardamos
			Nodo<T>* nodePreviousLast = NodeAt(length - 2);
			if (nodePreviousLast != nullptr) {
				// Penúltimo nodo apunte a nulo y hacemos que el último nodo
				// sea eliminado.
				Nodo<T>* nodeLast = nodePreviousLast->next;
				nodePreviousLast->next = nullptr;
				delete nodeLast;
				length--;
			}
		}
	}

	T* GetFirst() {
		Nodo<T>* first = NodeAt(0);
		if (first == nullptr) return nullptr;
		return &first->data;
	}

	T* GetPos(int pos) {
		Nodo<T>* node = NodeAt(pos);
		if (node == nullptr) return nullptr;
		return &node->data;
	}

	T* GetLast() {
		Nodo<T>* last = NodeAt(length - 1);
		if (last == nullptr) return nullptr;
		return &last->data;
	}
};
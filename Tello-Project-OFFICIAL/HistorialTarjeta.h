#pragma once
#include <iostream>

class Accion
{
private:
	std::string descripcion;
public:
	Accion() {};
	Accion(std::string descripcion) : descripcion(descripcion) {};

	std::string getDescripcion() const { return descripcion; }
};

template <typename T>
class NodoPila {
public:
	int dato;
	NodoPila<T>* siguiente;
	NodoPila(T valor) {
		dato = valor;
		siguiente = nullptr;
	}
};

template <typename T>
class Pila {
private:
	NodoPila<T>* cima;
public:
	Pila() {
		cima = nullptr;
	}

	void push(int valor) {
		NodoPila<T>* nuevo = new NodoPila<T>(valor);
		nuevo->siguiente = cima;
		cima = nuevo;
	}

	void pop() {
		if (cima == nullptr) return;
		NodoPila<T>* temp = cima;
		cima = cima->siguiente;
		delete temp;
	}

	int top() {
		return cima ? cima->dato : -1;
	}

	bool isEmpty() {
		return cima == nullptr;
	}
};
//🔥 ya esta tu codigo hecho tio maucho clauderon
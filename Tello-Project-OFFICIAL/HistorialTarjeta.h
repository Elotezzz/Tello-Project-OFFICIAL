#pragma once
#include <iostream>
#include "Tarjetas.h"

enum TipoAccion
{
	CREAR,
	ELIMINAR
};
class Accion
{
private:
	TipoAccion tipo;
	Tarjeta* tarjeta;
public:
	Accion() {
		this->tipo = CREAR;
		this->tarjeta = nullptr;	
	}
	Accion(TipoAccion tipo, Tarjeta* tarjeta){
		this->tipo = tipo;
		this->tarjeta = tarjeta;
	};
	TipoAccion getTipo() { return tipo; }
	Tarjeta* getTarjeta() { return tarjeta; }
};

template <typename T>
class NodoPila {
public:
	T dato;
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

	~Pila() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(T valor) {
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

	T top() {
		if (cima == nullptr)
			return T();
		return cima->dato;
	}

	bool isEmpty() {
		return cima == nullptr;
	}
};

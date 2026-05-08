#include "Tablero.h"

Tablero::Tablero() : nombre(""), cabeza(nullptr), cantidad(0), siguiente(nullptr) {}

Tablero::Tablero(std::string nombre) : nombre(nombre), cabeza(nullptr), cantidad(0), siguiente(nullptr) {}

Tablero::~Tablero() {}

std::string Tablero::getNombre() const { return nombre; }
int Tablero::getCantidad() const { return cantidad; }

void Tablero::setNombre(std::string nombre) { this->nombre = nombre; }

void Tablero::agregarListado(Listado* listado) {
    listado->setSiguiente(cabeza);
    cabeza = listado;
    cantidad++;
}

void Tablero::eliminarListado(std::string nombre) {
    Listado* actual = cabeza;
    Listado* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getNombre() == nombre) {
            if (anterior == nullptr)
                cabeza = actual->getSiguiente();
            else
                anterior->setSiguiente(actual->getSiguiente());
            delete actual;
            cantidad--;
            return;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }
}

Listado* Tablero::buscarListado(std::string nombre) {
    Listado* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getNombre() == nombre)
            return actual;
        actual = actual->getSiguiente();
    }
    return nullptr;
}

void Tablero::mostrarListados() {
    std::cout << "=== Tablero: " << nombre << " (" << cantidad << " listados) ===" << std::endl;
    Listado* actual = cabeza;
    while (actual != nullptr) {
        actual->mostrarTarjetas();
        std::cout << "===" << std::endl;
        actual = actual->getSiguiente();
    }
}

void Tablero::mostrarNombre() {
	std::cout << "Tablero: " << nombre << std::endl;
}

Tablero* Tablero::getSiguiente() { return siguiente; }
void Tablero::setSiguiente(Tablero* siguiente) { this->siguiente = siguiente; }
#include "Listado.h"

Listado::Listado() : nombre(""), cabeza(nullptr), cantidad(0), siguiente(nullptr) {}

Listado::Listado(std::string nombre) : nombre(nombre), cabeza(nullptr), cantidad(0), siguiente(nullptr) {}

Listado::~Listado() {}

std::string Listado::getNombre() const { return nombre; }
int Listado::getCantidad() const { return cantidad; }
Listado* Listado::getSiguiente() { return siguiente; }

void Listado::setNombre(std::string nombre) { this->nombre = nombre; }
void Listado::setSiguiente(Listado* siguiente) { this->siguiente = siguiente; }

void Listado::agregarTarjeta(Tarjeta* tarjeta) {
    tarjeta->setSiguiente(cabeza);
    cabeza = tarjeta;
    cantidad++;
}

void Listado::eliminarTarjeta(std::string id) {
    Tarjeta* actual = cabeza;
    Tarjeta* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getId() == id) {
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

Tarjeta* Listado::buscarTarjeta(std::string id) {
    Tarjeta* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getId() == id)
            return actual;
        actual = actual->getSiguiente();
    }
    return nullptr;
}

void Listado::mostrarTarjetas() {
    std::cout << "=== " << nombre << " (" << cantidad << " tarjetas) ===" << std::endl;
    Tarjeta* actual = cabeza;
    while (actual != nullptr) {
        actual->mostrarDatos();
        std::cout << "---" << std::endl;
        actual = actual->getSiguiente();
    }
}
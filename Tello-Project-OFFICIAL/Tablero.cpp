#include "Tablero.h"

Tablero::Tablero() : nombre(""), listados(new LinkedListListados<Listado>()) {}
Tablero::Tablero(std::string nombre) : nombre(nombre), listados(new LinkedListListados<Listado>()) {}
Tablero::~Tablero() { delete listados; }

std::string Tablero::getNombre() const { return nombre; }
int Tablero::getCantidad() const { return listados->getLength(); }

void Tablero::setNombre(std::string nombre) { this->nombre = nombre; }

void Tablero::agregarListado(Listado listado) {
    listados->agregar(listado);
}

void Tablero::eliminarListado(std::string nombre) {
    listados->eliminarPorNombre(nombre);
}

Listado* Tablero::buscarListado(std::string nombre) {
    for (int i = 0; i < listados->getLength(); i++) {
        Listado* l = listados->GetPos(i);
        if (l != nullptr && l->getNombre() == nombre)
            return l;
    }
    return nullptr;
}

void Tablero::mostrarListados() {
    std::cout << "=== Tablero: " << nombre << " (" << getCantidad() << " listados) ===" << std::endl;
    listados->imprimir();
}
#include "Listado.h"

Listado::Listado() : nombre(""), tarjetas(new ListaEnlazadaTarjeta<Tarjeta>()), siguiente(nullptr) {}

Listado::Listado(std::string nombre) : nombre(nombre), tarjetas(new ListaEnlazadaTarjeta<Tarjeta>()), siguiente(nullptr) {}

Listado::~Listado() {
    delete tarjetas;
}

std::string Listado::getNombre() const { return nombre; }
int Listado::getCantidad() const { return tarjetas->Length(); }
Listado* Listado::getSiguiente() { return siguiente; }

void Listado::setNombre(std::string nombre) { this->nombre = nombre; }


void Listado::agregarTarjeta(Tarjeta tarjeta) {
    tarjetas->AddLast(tarjeta);
}

void Listado::eliminarTarjeta(int pos) {
    tarjetas->RemovePos(pos);
}

Tarjeta* Listado::buscarTarjeta(int pos) {
    return tarjetas->GetPos(pos);
}

void Listado::mostrarTarjetas() {
    std::cout << "=== " << nombre << " (" << getCantidad() << " tarjetas) ===" << std::endl;
    tarjetas->Print(false);
}
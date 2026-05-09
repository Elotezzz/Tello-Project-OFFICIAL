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

void Listado::eliminarTarjetaPorPos(int pos) {
    tarjetas->RemovePos(pos);
}

Tarjeta* Listado::buscarTarjeta(int pos) {
    return tarjetas->GetPos(pos);
}

void Listado::mostrarTarjetas() {
    std::cout << "=== " << nombre << " (" << getCantidad() << " tarjetas) ===" << std::endl;
    tarjetas->Print(false);
}

Tarjeta* Listado::buscarPorNombreTarjeta(std::string nombre) {
    for (int i = 0; i < tarjetas->Length(); i++) {
        Tarjeta* t = tarjetas->GetPos(i);
        if (t != nullptr && t->getNombre() == nombre)
            return t;
    }
    return nullptr;
}
void Listado::eliminarTarjeta(std::string nombre) {
    tarjetas->eliminarPorNombre(nombre);
}

void Listado::crearTarjeta() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la tarjeta: ";
    std::getline(std::cin, nombre);
    if (buscarPorNombreTarjeta(nombre) != nullptr)
    {
        std::cout << "Ya existe una tarjeta con ese nombre\n";
        return;
    }
    Tarjeta nuevo(nombre);
    agregarTarjeta(nuevo);
}

void Listado::eliminarTarjetaPorNombre() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la tarjeta a eliminar: ";
    std::getline(std::cin, nombre);

    eliminarTarjeta(nombre);
    std::cout << "Tarjeta eliminada correctamente\n";
}
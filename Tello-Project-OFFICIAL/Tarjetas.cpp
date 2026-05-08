#include "Tarjetas.h"

Tarjeta::Tarjeta() : nombre(""), id(""), descripcion(""), prioridad(Baja), siguiente(nullptr) {}

Tarjeta::Tarjeta(std::string nombre, std::string id, std::string descripcion, Prioridad prioridad, Fecha fecha)
    : nombre(nombre), id(id), descripcion(descripcion), prioridad(prioridad), fecha(fecha), siguiente(nullptr) {
}

Tarjeta::~Tarjeta() {}

std::string Tarjeta::getNombre() const { return nombre; }
std::string Tarjeta::getId() const { return id; }
std::string Tarjeta::getDescripcion() const { return descripcion; }
Prioridad Tarjeta::getPrioridad() const { return prioridad; }
Fecha Tarjeta::getFecha() const { return fecha; }
Tarjeta* Tarjeta::getSiguiente() { return siguiente; }

void Tarjeta::setNombre(std::string nombre) { this->nombre = nombre; }
void Tarjeta::setId(std::string id) { this->id = id; }
void Tarjeta::setDescripcion(std::string descripcion) { this->descripcion = descripcion; }
void Tarjeta::setPrioridad(Prioridad prioridad) { this->prioridad = prioridad; }
void Tarjeta::setFecha(Fecha fecha) { this->fecha = fecha; }
void Tarjeta::setSiguiente(Tarjeta* siguiente) { this->siguiente = siguiente; }
void Tarjeta::mostrarDatos() {
    std::cout << "[" << id << "]" << "Nombre: "<< nombre << std::endl;
    std::cout << "Prioridad: " << prioridad << std::endl;
    std::cout << "Fecha: " << fecha.toString() << std::endl;
    std::cout << "Descripcion: " << descripcion << std::endl;
}
#include "Tarjetas.h"

Tarjeta::Tarjeta() : nombre(""), id(""), descripcion(""), prioridad(Baja) {}

Tarjeta::Tarjeta(std::string nombre, std::string id, std::string descripcion, Prioridad prioridad, Fecha fecha)
    : nombre(nombre), id(id), descripcion(descripcion), prioridad(prioridad), fecha(fecha) {
}

Tarjeta::~Tarjeta() {}

std::string Tarjeta::getNombre() const { return nombre; }
std::string Tarjeta::getId() const { return id; }
std::string Tarjeta::getDescripcion() const { return descripcion; }
Prioridad Tarjeta::getPrioridad() const { return prioridad; }
Fecha Tarjeta::getFecha() const { return fecha; }
Comentarios& Tarjeta::getComentarios() { return comentarios; }
Checklist& Tarjeta::getChecklist() { return checklist; }

void Tarjeta::setNombre(std::string nombre) { this->nombre = nombre; }
void Tarjeta::setId(std::string id) { this->id = id; }
void Tarjeta::setDescripcion(std::string descripcion) { this->descripcion = descripcion; }
void Tarjeta::setPrioridad(Prioridad prioridad) { this->prioridad = prioridad; }
void Tarjeta::setFecha(Fecha fecha) { this->fecha = fecha; }
void Tarjeta::mostrarDatos() {
    std::cout << *this << std::endl;
    std::cout << "Checklist:\n";
    checklist.mostrar();
    std::cout << "Comentarios:\n";
    comentarios.mostrar();
}
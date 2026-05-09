#include "Tarjetas.h"

Tarjeta::Tarjeta() : nombre(""), id(""), descripcion(""), prioridad(Baja) {}
Tarjeta::Tarjeta(std::string nombre)
    : nombre(nombre), id(""), descripcion(""), prioridad(Baja), fecha() {
}
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
void Tarjeta::editarNombre() {
    std::cout << "Nuevo nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
}

void Tarjeta::editarDescripcion() {
    std::cout << "Nueva descripcion: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);
}

void Tarjeta::editarPrioridad() {
    auto esValida = [](int p) { return p >= 0 && p <= 2; };

    std::cout << "Prioridad (0 = Baja, 1 = Media, 2 = Alta): ";
    int p;
    std::cin >> p;
    if (esValida(p))
        prioridad = (Prioridad)p;
    else
        std::cout << "Prioridad invalida\n";
}

void Tarjeta::editarFecha() {
    int dia, mes, ano;
    std::cout << "Dia: "; std::cin >> dia;
    std::cout << "Mes: "; std::cin >> mes;
    std::cout << "Ano: "; std::cin >> ano;
    Fecha nueva;
    if (!nueva.setDia(dia) || !nueva.setMes(mes) || !nueva.setAno(ano))
        std::cout << "Fecha invalida\n";
    else
        fecha = nueva;
}

void Tarjeta::agregarComentario() {
    std::string comentario;
    std::cout << "Comentario: ";
    std::getline(std::cin, comentario);
    comentarios.agregar(comentario);
}

void Tarjeta::agregarItemChecklist() {
    std::string item;
    std::cout << "Item: ";
    std::getline(std::cin, item);
    checklist.agregar(item);
}

void Tarjeta::mostrarDatos() {
    std::cout << *this << std::endl;
    std::cout << "Checklist:\n";
    checklist.mostrar();
    std::cout << "Comentarios:\n";
    comentarios.mostrar();
}
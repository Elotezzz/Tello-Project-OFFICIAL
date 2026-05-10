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
    if (esValida(p)) prioridad = (Prioridad)p;
    else std::cout << "Prioridad invalida\n";
}

void Tarjeta::editarFecha() {
    int dia, mes, ano;
    std::cout << "Dia: "; std::cin >> dia;
    std::cout << "Mes: "; std::cin >> mes;
    std::cout << "Ano: "; std::cin >> ano;
    Fecha nueva;
    if (!nueva.setDia(dia) || !nueva.setMes(mes) || !nueva.setAno(ano))
        std::cout << "Fecha invalida\n";
    else fecha = nueva;
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

void Tarjeta::guardar(std::ofstream& arch) const {
    arch << "================================\n";
    arch << "Tarjeta: " << nombre << "\n";
    arch << "ID: " << id << "\n";
    arch << "Descripcion: " << descripcion << "\n";
    arch << "Prioridad: " << prioridad << "\n";
    arch << "Fecha: " << fecha.getDia() << " " << fecha.getMes() << " " << fecha.getAno() << "\n";
    arch << "Comentarios: " << comentarios.getCantidad() << "\n";
    for (int i = 0; i < comentarios.getCantidad(); i++)
        arch << "  - " << comentarios.getComentario(i) << "\n";
    arch << "Checklist: " << checklist.getCantidad() << "\n";
    for (int i = 0; i < checklist.getCantidad(); i++)
        arch << "  - " << checklist.getItem(i) << " | " << checklist.estaCompletado(i) << "\n";
}

void Tarjeta::cargar(std::ifstream& arch) {
    std::string linea;
    std::getline(arch, linea); // ================================
    std::getline(arch, linea); nombre = linea.substr(9);
    std::getline(arch, linea); id = linea.substr(4);
    std::getline(arch, linea); descripcion = linea.substr(13);
    std::getline(arch, linea); prioridad = (Prioridad)std::stoi(linea.substr(10));
    std::getline(arch, linea);
    // parsear fecha
    std::string fechaStr = linea.substr(7);
    int d, m, a;
    sscanf_s(fechaStr.c_str(), "%d %d %d", &d, &m, &a);
    fecha.setDia(d); fecha.setMes(m); fecha.setAno(a);
    // comentarios
    std::getline(arch, linea);
    int numComentarios = std::stoi(linea.substr(13));
    for (int i = 0; i < numComentarios; i++) {
        std::getline(arch, linea);
        comentarios.agregar(linea.substr(4));
    }
    // checklist
    std::getline(arch, linea);
    int numItems = std::stoi(linea.substr(11));
    for (int i = 0; i < numItems; i++) {
        std::getline(arch, linea);
        std::string itemStr = linea.substr(4);
        int sep = itemStr.find(" | ");
        std::string item = itemStr.substr(0, sep);
        int comp = std::stoi(itemStr.substr(sep + 3));
        checklist.agregar(item);
        if (comp) checklist.marcarCompletado(i);
    }
}
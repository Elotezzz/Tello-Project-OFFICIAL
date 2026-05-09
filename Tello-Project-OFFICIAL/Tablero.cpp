#include "Tablero.h"

Tablero::Tablero() : nombre(""), listados(new LinkedListListados<Listado>()), miembro(new std::string[10]), cantidadMiembros(0) {}
Tablero::Tablero(std::string nombre) : nombre(nombre), listados(new LinkedListListados<Listado>()), miembro(new std::string[10]), cantidadMiembros(0) {
    listados->agregar(new Listado("Lista de tareas"));
    listados->agregar(new Listado("En proceso"));
    listados->agregar(new Listado("Hecho"));
}
Tablero::~Tablero() { delete listados; delete[] miembro; }

std::string Tablero::getNombre() const { return nombre; }
int Tablero::getCantidad() const { return listados->getLength(); }

void Tablero::setNombre(std::string nombre) { this->nombre = nombre; }

void Tablero::agregarListado(Listado* listado) {
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
    std::cout << "=== Tablero: " << nombre << " (" << getCantidad() << " listados) ===\n";
    listados->imprimir();
}

void Tablero::agregarMiembro(std::string nombre) {


}

void Tablero::mostrarMiembros() const{

}


void Tablero::crearLista() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la lista: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    if (buscarListado(nombre) != nullptr) {
        std::cout << "Ya existe una lista con ese nombre\n";
        return;
    }
    agregarListado(new Listado(nombre));
    std::cout << "Lista creada correctamente\n";
}

void Tablero::eliminarLista()
{
    std::string nombre;
    std::cout<< "Ingrese el nombre de la lista a eliminar: ";
    std::getline(std::cin, nombre);

    eliminarListado(nombre);
    std::cout<< "Lista eliminada correctamente\n";
}
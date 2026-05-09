#include "Controladora.h"

Controladora::Controladora() : tableros(new LinkedListTablero<Tablero>()) {}

Controladora::~Controladora() { delete tableros; }

int Controladora::getCantidad() const { return tableros->getLength(); }

void Controladora::agregarTablero(Tablero* tablero) {
    tableros->agregar(tablero);
}

void Controladora::eliminarTablero(std::string nombre) {
    tableros->eliminarPorNombre(nombre);
}

Tablero* Controladora::buscarTablero(std::string nombre) {
    for (int i = 0; i < tableros->getLength(); i++) {
        Tablero* t = tableros->GetPos(i);
        if (t != nullptr && t->getNombre() == nombre)
            return t;
    }
    return nullptr;
}

void Controladora::mostrarTableros() {
    std::cout << "=== Sistema (" << getCantidad() << " tableros) ===" << std::endl;
    tableros->imprimir();
}
void Controladora::crearTablero() {
	std::string nombre;
	std::cout << "Ingrese el nombre del nuevo tablero: ";
	std::cin >> nombre;
	if (buscarTablero(nombre) != nullptr) {
		std::cout << "Ya existe un tablero con ese nombre.\n";
		return;
	}
	Tablero* nuevoTablero = new Tablero(nombre);
	agregarTablero(nuevoTablero);
	std::cout << "Tablero '" << nombre << "' creado exitosamente.\n";
}

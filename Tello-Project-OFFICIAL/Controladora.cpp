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
    auto coincide = [&nombre](Tablero* t) { return t != nullptr && t->getNombre() == nombre; };

    for (int i = 0; i < tableros->getLength(); i++) {
        Tablero* t = tableros->GetPos(i);
        if (coincide(t)) return t;
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
void Controladora::ordenarTableros() {
    int n = tableros->getLength();
    if (n <= 1) {
        std::cout << "No hay suficientes tableros para ordenar\n"; return;
    }

    Tablero** arr = new Tablero * [n];
    for (int i = 0; i < n; i++)
        arr[i] = tableros->GetPos(i);

    auto comparar = [](Tablero* a, Tablero* b) { return a->getNombre() > b->getNombre(); };

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        Tablero* key = arr[i];
        int j = i - 1;
        while (j >= 0 && comparar(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Reenlazar sin destruir
    for (int i = 0; i < n; i++) tableros->setDataPos(arr[i], i);
    delete[] arr;
    std::cout << "Tableros ordenados alfabeticamente\n";
}
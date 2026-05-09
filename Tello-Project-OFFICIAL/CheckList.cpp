#include "Checklist.h"

Checklist::Checklist() : cantidad(0), capacidad(10) {
    items = new std::string[capacidad];
    completado = new bool[capacidad];
}

Checklist::~Checklist() {
    delete[] items;
    delete[] completado;
}

int Checklist::getCantidad() const { return cantidad; }

void Checklist::agregar(std::string item) {
    if (cantidad == capacidad) {
        capacidad *= 2;
        std::string* nuevosItems = new std::string[capacidad];
        bool* nuevosCompletado = new bool[capacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevosItems[i] = items[i];
            nuevosCompletado[i] = completado[i];
        }
        delete[] items;
        delete[] completado;
        items = nuevosItems;
        completado = nuevosCompletado;
    }
    items[cantidad] = item;
    completado[cantidad] = false;
    cantidad++;
}

void Checklist::eliminar(int pos) {
    if (pos < 0 || pos >= cantidad) {
        std::cout << "Posicion invalida\n";
        return;
    }
    for (int i = pos; i < cantidad - 1; i++) {
        items[i] = items[i + 1];
        completado[i] = completado[i + 1];
    }
    cantidad--;
}

void Checklist::marcarCompletado(int pos) {
    if (pos < 0 || pos >= cantidad) {
        std::cout << "Posicion invalida\n";
        return;
    }
    completado[pos] = true;
}

void Checklist::desmarcar(int pos) {
    if (pos < 0 || pos >= cantidad) {
        std::cout << "Posicion invalida\n";
        return;
    }
    completado[pos] = false;
}

std::string Checklist::getItem(int pos) const {
    if (pos < 0 || pos >= cantidad) return "";
    return items[pos];
}

bool Checklist::estaCompletado(int pos) const {
    if (pos < 0 || pos >= cantidad) return false;
    return completado[pos];
}

void Checklist::mostrar() const {
    if (cantidad == 0) {
        std::cout << "Checklist vacia\n";
        return;
    }
    for (int i = 0; i < cantidad; i++)
        std::cout << "  [" << (completado[i] ? "X" : " ") << "] " << items[i] << std::endl;
}
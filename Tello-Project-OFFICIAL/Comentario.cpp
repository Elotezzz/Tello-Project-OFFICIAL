#include "Comentarior.h"

Comentarios::Comentarios() : cantidad(0), capacidad(10) {
    comentarios = new std::string[capacidad];
}

Comentarios::~Comentarios() {
    delete[] comentarios;
}

int Comentarios::getCantidad() const { return cantidad; }

void Comentarios::agregar(std::string comentario) {
    if (cantidad == capacidad) {
        capacidad *= 2;
        std::string* nuevo = new std::string[capacidad];
        for (int i = 0; i < cantidad; i++)
            nuevo[i] = comentarios[i];
        delete[] comentarios;
        comentarios = nuevo;
    }
    comentarios[cantidad++] = comentario;
}

void Comentarios::eliminar(int pos) {
    if (pos < 0 || pos >= cantidad) {
        std::cout << "Posicion invalida\n";
        return;
    }
    for (int i = pos; i < cantidad - 1; i++)
        comentarios[i] = comentarios[i + 1];
    cantidad--;
}

std::string Comentarios::getComentario(int pos) const {
    if (pos < 0 || pos >= cantidad) return "";
    return comentarios[pos];
}

void Comentarios::mostrar() const {
    if (cantidad == 0) {
        std::cout << "Sin comentarios\n";
        return;
    }
    for (int i = 0; i < cantidad; i++)
        std::cout << "  [" << i + 1 << "] " << comentarios[i] << std::endl;
}
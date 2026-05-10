#pragma once
#include <string>
#include <iostream>
#include "Listado.h"
#include "gestionListas.h"
#include <fstream>

class Tablero
{
private:
    std::string nombre;
    LinkedListListados<Listado>* listados;
    std::string* miembro;
    int cantidadMiembros;

public:
    Tablero();
    Tablero(std::string nombre);
    Tablero(bool vacio);
    ~Tablero();

    std::string getNombre() const;
    int getCantidad() const;

    void setNombre(std::string nombre);

    void agregarListado(Listado* listado);
    void eliminarListado(std::string nombre);
    Listado* buscarListado(std::string nombre);
    void mostrarListados();
    friend std::ostream& operator<<(std::ostream& os, const Tablero& t) {
        os << "Tablero: " << t.nombre << " (" << t.listados->getLength() << " listados)";
        return os;
    }

	void agregarMiembro(std::string miembro);
	void mostrarMiembros() const;

    void crearLista();
    void eliminarLista();
    void ordenarListados();
};
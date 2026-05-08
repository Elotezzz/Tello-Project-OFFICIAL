#pragma once
#include <string>
#include <iostream>
#include "Listado.h"

class Tablero
{
private:
    std::string nombre;
    Listado* cabeza;
    int cantidad;
    Tablero* siguiente;

public:
    Tablero();
    Tablero(std::string nombre);
    ~Tablero();

    std::string getNombre() const;
    int getCantidad() const;

    void setNombre(std::string nombre);

    void agregarListado(Listado* listado);
    void eliminarListado(std::string nombre);
    Listado* buscarListado(std::string nombre);
    void mostrarListados();
    Tablero* getSiguiente();
    void setSiguiente(Tablero* siguiente);
	void mostrarNombre();
};
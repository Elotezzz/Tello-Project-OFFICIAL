#pragma once
#include <string>
#include <iostream>
#include "Tarjetas.h"
#include "ListaEnlazada.h"

class Listado
{
private:
    std::string nombre;
    ListaEnlazada<Tarjeta>* tarjetas;
    Listado* siguiente;

public:
    Listado();
    Listado(std::string nombre);
    ~Listado();

    std::string getNombre() const;
    int getCantidad() const;
    Listado* getSiguiente();

    void setNombre(std::string nombre);
    void setSiguiente(Listado* siguiente);

    void agregarTarjeta(Tarjeta tarjeta);
    void eliminarTarjeta(int pos);
    Tarjeta* buscarTarjeta(int pos);
    void mostrarTarjetas();
};
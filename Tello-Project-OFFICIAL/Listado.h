#pragma once
#include <string>
#include "Tarjetas.h"
#include <iostream>

class Listado
{
private:
    std::string nombre;
    Tarjeta* cabeza;
    int cantidad;
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

    void agregarTarjeta(Tarjeta* tarjeta);
    void eliminarTarjeta(std::string id);
    Tarjeta* buscarTarjeta(std::string id);
    void mostrarTarjetas();
};
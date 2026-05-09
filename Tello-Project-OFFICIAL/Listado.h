#pragma once
#include <string>
#include <iostream>
#include "Tarjetas.h"
#include "GestionTarjeta.h"

class Listado
{
private:
    std::string nombre;
    ListaEnlazadaTarjeta<Tarjeta>* tarjetas;
    Listado* siguiente;

public:
    Listado();
    Listado(std::string nombre);
    ~Listado();

    std::string getNombre() const;
    int getCantidad() const;
    Listado* getSiguiente();

    void setNombre(std::string nombre);

    void agregarTarjeta(Tarjeta tarjeta);
    void eliminarTarjeta(int pos);
    Tarjeta* buscarTarjeta(int pos);
    void mostrarTarjetas();
    friend std::ostream& operator<<(std::ostream& os, const Listado& l) {
        os << "Listado: " << l.nombre << " (" << l.tarjetas->Length() << " tarjetas)";
        return os;
    }
};
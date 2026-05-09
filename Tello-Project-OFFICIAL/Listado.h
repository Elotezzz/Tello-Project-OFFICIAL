#pragma once
#include <string>
#include <iostream>
#include "Tarjetas.h"
#include "GestionTarjeta.h"
#include "HistorialTarjeta.h"
class Listado
{
private:
    std::string nombre;
    ListaEnlazadaTarjeta<Tarjeta>* tarjetas;
    Listado* siguiente;
    Pila<Accion> historial;

public:
    Listado();
    Listado(std::string nombre);
    ~Listado();

    std::string getNombre() const;
    int getCantidad() const;
    Listado* getSiguiente();

    void setNombre(std::string nombre);

    void agregarTarjeta(Tarjeta* tarjeta);
    void eliminarTarjetaPorPos(int pos);
    void eliminarTarjeta(std::string nombre);
    Tarjeta* buscarTarjeta(int pos);
    void mostrarTarjetas();
    friend std::ostream& operator<<(std::ostream& os, const Listado& l) {
        os << "Listado: " << l.nombre << " (" << l.tarjetas->Length() << " tarjetas)";
        return os;
    }
    Tarjeta* buscarPorNombreTarjeta(std::string nombre);
	void crearTarjeta();
    void eliminarTarjetaPorNombre();
    void deshacer();
    void filtrarTarjetasPrio();
};
#pragma once
#include <string>
#include <iostream>
#include "Tablero.h"
#include "gestionTablero.h"
#include "Listado.h"
#include "gestionListas.h"
class Controladora
{
private:
    LinkedListTablero<Tablero>* tableros;

public:
    Controladora();
    ~Controladora();

    int getCantidad() const;

    void agregarTablero(Tablero tablero);
    void eliminarTablero(std::string nombre);
    Tablero* buscarTablero(std::string nombre);
    void mostrarTableros();
    void crearTablero();
};
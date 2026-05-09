#pragma once
#include <string>
#include <iostream>

class Checklist
{
private:
    std::string* items;
    bool* completado;
    int cantidad;
    int capacidad;

public:
    Checklist();
    ~Checklist();

    int getCantidad() const;

    void agregar(std::string item);
    void eliminar(int pos);
    void marcarCompletado(int pos);
    void desmarcar(int pos);
    std::string getItem(int pos) const;
    bool estaCompletado(int pos) const;
    void mostrar() const;
};
#pragma once
#include <string>
#include <iostream>

class Comentarios
{
private:
    std::string* comentarios;
    int cantidad;
    int capacidad;

public:
    Comentarios();
    ~Comentarios();

    int getCantidad() const;

    void agregar(std::string comentario);
    void eliminar(int pos);
    std::string getComentario(int pos) const;
    void mostrar() const;
};
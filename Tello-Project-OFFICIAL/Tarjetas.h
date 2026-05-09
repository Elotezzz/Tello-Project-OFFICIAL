#pragma once
#include <string>
#include "Fecha.h"
#include <iostream>
#include "Comentarior.h"
#include "CheckList.h"

enum Prioridad
{
    Baja = 0,
    Media = 1,
    Alta = 2
};

class Tarjeta
{
private:
    std::string nombre;
    std::string id;
    std::string descripcion;
    Prioridad prioridad;
    Fecha fecha;
    Comentarios comentarios;
    Checklist checklist;

public:
    Tarjeta();
    Tarjeta(std::string nombre, std::string id, std::string descripcion, Prioridad prioridad, Fecha fecha);
    Tarjeta(std::string nombre);
    ~Tarjeta();

    std::string getNombre() const;
    std::string getId() const;
    std::string getDescripcion() const;
    Prioridad getPrioridad() const;
    Fecha getFecha() const;
    Comentarios& getComentarios();
    Checklist& getChecklist();

    void setNombre(std::string nombre);
    void setId(std::string id);
    void setDescripcion(std::string descripcion);
    void setPrioridad(Prioridad prioridad);
    void setFecha(Fecha fecha);
    void mostrarDatos();
    friend std::ostream& operator<<(std::ostream& os, const Tarjeta& t) {
        os << "[" << t.id << "] Nombre: " << t.nombre
            << " | Prioridad: " << t.prioridad
            << " | Fecha: " << t.fecha.toString()
            << " | " << t.descripcion;
        return os;
    }
};
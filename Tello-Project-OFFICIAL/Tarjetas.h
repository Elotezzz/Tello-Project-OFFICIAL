#pragma once
#include <string>
#include "Fecha.h"

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

public:
    Tarjeta();
    Tarjeta(std::string nombre, std::string id, std::string descripcion,Prioridad prioridad, Fecha fecha);
    ~Tarjeta();

    std::string getNombre() const;
    std::string getId() const;
    std::string getDescripcion() const;
    Prioridad getPrioridad() const;
    Fecha getFecha() const;

    void setNombre(std::string nombre);
    void setId(std::string id);
    void setDescripcion(std::string descripcion);
    void setPrioridad(Prioridad prioridad);
    void setFecha(Fecha fecha);
};
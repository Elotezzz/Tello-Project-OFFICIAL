#include "Controladora.h"
Controladora::Controladora() { cabeza = nullptr; }
Controladora::~Controladora() {}

void Controladora::agregarTablero(std::string nombre) {
    Tablero* nuevo = new Tablero(nombre);
    if (cabeza == nullptr)
    {
        cabeza = nuevo;
    }
    else
    {
        Tablero* aux = cabeza;
        while (aux != nullptr)
        {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}
void Controladora::eliminarTablero(std::string nombre) {
    if (cabeza == nullptr) return;

    if (cabeza->getNombre() == nombre) //Esto es si el nombre del tablero que queremos eliminar coincide con la cabeza
    {
        Tablero* aux = cabeza;
        cabeza = cabeza->getSiguiente();
        delete aux;
        return;
    }

    Tablero* actual = cabeza;
    while (actual->getSiguiente() != nullptr && actual->getSiguiente()->getNombre() != nombre)
    {
        actual = actual->getSiguiente();
    }

    if (actual->getSiguiente() == nullptr)
    {
        std::cout << "No se encontró el tablero a eliminar";
    }

    Tablero* eliminado = actual->getSiguiente();
    actual->setSiguiente(eliminado->getSiguiente());
    delete eliminado;
}

Tablero* Controladora::getTablero(std::string nombre) {
    Tablero* aux = cabeza;
    while (aux != nullptr)
    {
        if (aux->getNombre() == nombre)
        {
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

void Controladora::mostrarTableros() {
    Tablero* aux = cabeza;
    while (aux != nullptr)
    {
        aux->mostrarNombre();
        aux->mostrarListados();
        aux->getSiguiente();
    }
}
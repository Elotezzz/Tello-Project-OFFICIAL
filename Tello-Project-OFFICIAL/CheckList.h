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

	// Función recursiva para contar items completados
	int contarCompletadosRecursivo(int indice) const {
		// Caso base: ya revisamos todos los items
		if (indice >= cantidad) return 0;
		
		// Caso recursivo: sumar 1 si está completado + contar el resto
		int actual = completado[indice] ? 1 : 0;
		return actual + contarCompletadosRecursivo(indice + 1);
	}

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

	// Función pública que retorna total de items completados
	int contarCompletados() const {
		return contarCompletadosRecursivo(0);
	}
	
	// Función pública que retorna progreso en porcentaje
	int obtenerPorcentajeCompletado() const {
		if (cantidad == 0) return 0;
		return (contarCompletadosRecursivo(0) * 100) / cantidad;
	}
};
#include "Menu.h"

Menu::Menu(const char* titulo, const char* opciones[], int cantidad) : titulo(titulo), opciones(opciones),
cntOpciones(cantidad), seleccion(0) {
}

int Menu::mostrarMenu() {
	char tecla;
	while (true) {
		system("cls");
		std::cout << "====== " << titulo << " ======\n";
		//recorremos el arreglo de opciones[] y preguntamos si la seleccion es igual a i 
		//(ejemplos 1. ingresar) se colocara la >; sino se colocara un espacio
		for (int i = 0; i < cntOpciones; i++) {
			if (seleccion == i) {
				std::cout << "> " << i + 1 << ". " << opciones[i] << "\n";
			}
			else {
				std::cout << "  " << i + 1 << ". " << opciones[i] << "\n";
			}
		}

		tecla = _getch();
		if (tecla == -32) {
			tecla = _getch();
			if (tecla == KEY_DOWN) {
				seleccion = (seleccion + 1) % cntOpciones; 
				// si la seleccion es 0 al bajar seria 1, asi hasta llegar a la ultima opcion 
				// por ejemplo 5; si llega hasta ahi se le saca el modulo con la cntOpciones que 
				// en este caso al ser 5, se volveria cero empezando de nuevo
			}
			else if (tecla == KEY_UP) {
				seleccion = (seleccion - 1 + cntOpciones) % cntOpciones;
			}
		}
		else if (tecla == KEY_ENTER) {
			return seleccion;
		}
	}
};

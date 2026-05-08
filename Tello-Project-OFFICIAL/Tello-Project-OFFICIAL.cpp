#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Menu.h"

using namespace std;

inline int menuLista() {
	const char* opcionesCrear[] = { "Crear Tarjeta", "Ver Tarjetas", "Mover Tarjeta", "Eliminar Tarjeta",
				"Seleccionar Tarjeta", "Filtrar Tarjetas", "Volver" };
	Menu menuCrear("LISTA", opcionesCrear, 7);
	int opcL = menuCrear.mostrarMenu();
	switch (opcL) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4: {

		//CREAR TARJETA

		break;
	}
	case 5:
		break;
	case 6:
		break;
	}
	return opcL;
}


inline int menuTablero() {
	const char* opcionesCrear[] = { "Agregar Miembros", "Ver Listas", "Crear lista", "Eliminar Lista",
				"Seleccionar Lista", "Ordenar Lista", "Volver" };
	Menu menuCrear("TABLERO", opcionesCrear, 7);
	int opcT = menuCrear.mostrarMenu();
	switch (opcT) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4: {

		//SELECCIONAR LISTA

		menuLista();
		break;
	}
	case 5:
		break;
	case 6:
		break;
	}
	return opcT; 
}

int main()
{
	int opc;

	//CREAR MENU =======
	const char* opciones[] = { "Crear Tablero", "Ver Tablero", "Eliminar Tablero", "Seleccionar Tablero", "Salir" };
	Menu menuPrincipal("TELLO", opciones, 5);
	//==================

	do {
		opc = menuPrincipal.mostrarMenu();
		switch (opc) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3: {

			//SELECCIONAR TABLERO
			menuTablero();
			break;
			}
		case 4:
			break;
		}
	} while (opc != 4);
	return 0;
}

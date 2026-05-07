#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Menu.h"

using namespace std;

//void menuInsertar() {
//	const char* opciones[] = { "Al inicio", "Al final", "En posición" };
//	int op = mostrarMenu("INSERTAR", opciones, 3);
//
//	switch (op) {
//	case 0: 
//
//		break;
//	case 1: 
//
//		break;
//	case 2: 
//
//		break;
//	}
//}

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
		case 3:
			break;
		case 4:
			break;
		}
	} while (opc != 4);
	return 0;
}

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Menu.h"
#include "Usuario.h"

using namespace std;

inline int menuLista() {
	const char* opcionesL[] = { "Crear Tarjeta", "Ver Tarjetas", "Mover Tarjeta", "Eliminar Tarjeta",
				"Seleccionar Tarjeta", "Filtrar Tarjetas", "Volver" };
	Menu menuCrear("LISTA", opcionesL, 7);
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
	const char* opcionesT[] = { "Agregar Miembros", "Ver Listas", "Crear lista", "Eliminar Lista",
				"Seleccionar Lista", "Ordenar Lista", "Volver" };
	Menu menuCrear("TABLERO", opcionesT, 7);
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
	Usuario u;

	const char* opcionesU[] = { "Iniciar sesion", "Registrarse"};
	Menu menuUsuario("BIENVENIDO A TELLO", opcionesU, 2);
	do
	{
		opc = menuUsuario.mostrarMenu();
		switch (opc) {
		case 0:

			//FALTA AGREGAR ESTA FUNCIONALIDAD QUE ES DE QUE EL USUARIO SOLO 
			// PUEDE VER LOS TABLEROS Q HA CREADO O LOS QUE LE HAN COMPARTIDO
			break;
		case 1:
			system("cls");
			cout << "Ingrese su nombre: ";
			cin >> u.nombre;
			cout << "Ingrese su password: ";
			cin >> u.password;
			cout << "Ingrese su correo: ";
			cin >> u.correo;
			ofstream archivoOut("Usuarios.txt", ios::app);
			u.guardar(archivoOut);
			archivoOut.close();
			break;
		}
	} while (opc!=1);
	

	const char* opciones[] = { "Crear Tablero", "Ver Tablero", "Eliminar Tablero", "Seleccionar Tablero", "Salir" };
	Menu menuPrincipal("TELLO", opciones, 5);
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

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Menu.h"
#include "Usuario.h"
#include "Tablero.h"

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
		case 0: {
			system("cls");
			string nombreI, passwordI;
			cout << "Ingrese su nombre: ";
			cin >> nombreI;
			cout << "Ingrese su password: ";
			cin >> passwordI;

			ifstream archivoIn("Usuarios.txt");
			if (!archivoIn.is_open()) {
				cout << "No hay usuarios registrados\n";
				Sleep(1000);
				break;
			}

			bool encontrado = false;
			Usuario aux;
			while (aux.leer(archivoIn)) {
				if (aux.nombre == nombreI && aux.password == passwordI) {
					encontrado = true;
					u = aux;
					break;
				}
			}
			archivoIn.close();

			if (encontrado) {
				cout << "Bienvenido " << u.nombre << "\n";
				Sleep(1000);
				opc = 1;
			}
			else {
				cout << "Usuario o contrasena incorrectos.\n";
				Sleep(1000);
			}
			break;
			}
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

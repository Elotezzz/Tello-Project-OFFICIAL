#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Menu.h"
#include "Usuario.h"
#include "Tablero.h"
#include "Controladora.h"
#include "Listado.h"
using namespace std;

inline int menuLista(Listado* listado) {
	const char* opcionesL[] = { "Crear Tarjeta", "Ver Tarjetas", "Mover Tarjeta", "Eliminar Tarjeta",
				"Seleccionar Tarjeta", "Filtrar Tarjetas", "Volver" };
	Menu menuCrear("LISTA", opcionesL, 7);
	int opcL;
	do {
		opcL = menuCrear.mostrarMenu();
		switch (opcL) {
		case 0:
			listado->crearTarjeta();
			break;
		case 1:
			listado->mostrarTarjetas();
			system("pause");
			break;
		case 2:

			//MOVER TARJETAS A OTRAS LISTAS

			break;
		case 3:
			listado->eliminarTarjetaPorNombre();
			break;
		case 4:
			//SELECCIONAR TARJETA
			break;
		case 5:
			//FILTRAR POR PRIORIDAD 
			break;
		case 6:
			break;
		}
	} while (opcL != 6);  
	return opcL;
}
inline int menuTablero(Tablero* tablero) {
	const char* opcionesT[] = { "Agregar Miembros", "Ver Listas", "Crear lista", "Eliminar Lista",
				"Seleccionar Lista", "Ordenar Lista", "Volver" };
	Menu menuCrear("TABLERO", opcionesT, 7);
	int opcT;
	do {
		opcT = menuCrear.mostrarMenu();
		switch (opcT) {
		case 0:
			//LEER TXT Y QUE AÑADI UN USUARIO AL TABLERO
			break;
		case 1:
			tablero->mostrarListados();
			system("pause");
			break;
		case 2:
			tablero->crearLista();
			break;
		case 3:
			tablero->eliminarLista();
			break;
		case 4: {
			std::string nombre;
			std::cout << "Ingrese el nombre de la lista: ";
			std::cin >> nombre;
			Listado* lista = tablero->buscarListado(nombre);
			if (lista != nullptr)
				menuLista(lista);
			else
				std::cout << "Lista no encontrada\n";
			break;
		}
		case 5:

			//ALGORITMO DE ORDENAMIENTO POR ABECEDARIO 

			break;
		case 6:
			break;
		}
	} while (opcT != 6);  
	return opcT;
}

int main()
{
	int opc;
	Usuario u;
	Controladora controladora;
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

	const char* opciones[] = { "Crear Tablero", "Ver Tableros", "Eliminar Tablero", "Seleccionar Tablero", "Salir" };
	Menu menuPrincipal("TELLO", opciones, 5);
	do {
		opc = menuPrincipal.mostrarMenu();
		switch (opc) {
		case 0:
			controladora.crearTablero();
			break;
		case 1:
			controladora.mostrarTableros();
			break;
		case 2:
		{
			string nombre;

			cout << "Ingrese el nombre del tablero a eliminar: ";
			cin >> nombre;
			controladora.eliminarTablero(nombre);
			break;
		}
		
		case 3: {
			//SELECCIONAR TABLERO  
			std::string nombre;
			std::cout << "Ingrese el nombre del tablero: ";
			std::cin >> nombre;

			Tablero* tablero = controladora.buscarTablero(nombre);

			if (tablero != nullptr)
			{
				menuTablero(tablero);
			}
			else
			{
				std::cout << "Tablero no encontrado\n";
			}
		}
			break;
		case 4:
			break;
		}
	} while (opc != 5);
	return 0;
}

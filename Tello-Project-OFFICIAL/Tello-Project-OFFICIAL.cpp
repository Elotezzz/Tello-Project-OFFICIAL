#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Menu.h"
#include "Usuario.h"
#include "Tablero.h"
#include "Controladora.h"
#include "Listado.h"
using namespace std;

inline int menuTarjeta(Tarjeta* tarjeta) {
	const char* opcionesT[] = { "Ver datos", "Editar nombre", "Editar descripcion",
		"Editar prioridad", "Editar fecha", "Agregar comentario",
		"Agregar item checklist", "Marcar item checklist", "Volver" };
	Menu menuCrear("TARJETA", opcionesT, 9);
	int opcT;
	do {
		opcT = menuCrear.mostrarMenu();
		switch (opcT) {
		case 0:
			tarjeta->mostrarDatos();
			_getch();
			break;
		case 1:
			tarjeta->editarNombre();
			break;
		case 2:
			tarjeta->editarDescripcion();
			break;
		case 3:
			tarjeta->editarPrioridad();
			break;
		case 4:
			tarjeta->editarFecha();
			break;
		case 5:
			std::cin.ignore();
			tarjeta->agregarComentario();
			break;
		case 6:
			std::cin.ignore();
			tarjeta->agregarItemChecklist();
			break;
		case 7: {
			tarjeta->getChecklist().mostrar();
			std::cout << "Ingrese posicion a marcar: ";
			int pos;
			std::cin >> pos;
			tarjeta->getChecklist().marcarCompletado(pos);
			_getch();
			break;
		}
		case 8:
			break;
		}
	} while (opcT != 8);
	return opcT;
}

inline int menuLista(Listado* listado) {
	const char* opcionesL[] = { "Crear Tarjeta", "Ver Tarjetas", "Mover Tarjeta", "Eliminar Tarjeta",
				"Seleccionar Tarjeta", "Filtrar Tarjetas", "Deshacer", "Volver" };
	Menu menuCrear("LISTA", opcionesL, 8);
	int opcL;
	do {
		opcL = menuCrear.mostrarMenu();
		switch (opcL) {
		case 0:
			cin.ignore();
			listado->crearTarjeta();
			break;
		case 1:
			listado->mostrarTarjetas();
			_getch();
			break;
		case 2:

			//MOVER TARJETAS A OTRAS LISTAS

			break;
		case 3:
			listado->eliminarTarjetaPorNombre();
			_getch();
			break;
		case 4: {
			std::string nombre;
			std::cout << "Ingrese el nombre de la tarjeta: ";
			std::cin >> nombre;
			Tarjeta* tarjeta = listado->buscarPorNombreTarjeta(nombre);
			if (tarjeta != nullptr)
				menuTarjeta(tarjeta);
			else
				std::cout << "Tarjeta no encontrada\n";
			break;
		}
		case 5:
			//FILTRAR POR PRIORIDAD
			listado->filtrarTarjetasPrio();
			Sleep(1000);
			break;
		case 6:
			listado->deshacer();
			_getch();
			break;
		case 7:
			break;
		}
	} while (opcL != 7);  
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
		case 0: {
			int totalUsuarios = 0;
			std::ifstream arch("Usuarios.txt");
			Usuario temp;
			while (temp.leer(arch)) totalUsuarios++;
			arch.close();

			Usuario* usuariosTemp = new Usuario[totalUsuarios];
			std::ifstream arch2("Usuarios.txt");
			for (int i = 0; i < totalUsuarios; i++) { usuariosTemp[i].leer(arch2); }
			arch2.close();

			const char** opcionesUsuarios = new const char* [totalUsuarios + 1];
			for (int i = 0; i < totalUsuarios; i++) { opcionesUsuarios[i] = usuariosTemp[i].nombre.c_str(); }
			opcionesUsuarios[totalUsuarios] = "Volver";

			Menu menuUsuarios("SELECCIONAR USUARIO", opcionesUsuarios, totalUsuarios + 1);
			int seleccion = menuUsuarios.mostrarMenu();

			if (seleccion < totalUsuarios)
				tablero->agregarMiembro(usuariosTemp[seleccion].nombre);
			delete[] usuariosTemp;
			break;
		}
		case 1:
			tablero->mostrarListados();
			_getch();
			break;
		case 2:
			tablero->crearLista();
			_getch();
			break;
		case 3:
			tablero->eliminarLista();
			_getch();
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
			tablero->ordenarListados();
			_getch();
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
				cout << "\nBienvenido " << u.nombre << "\n";
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
			system("cls");
			controladora.crearTablero();
			_getch();
			break;
		case 1:
			system("cls");
			controladora.mostrarTableros();
			_getch();
			break;
		case 2:
		{
			string nombre;
			system("cls");
			cout << "Ingrese el nombre del tablero a eliminar: ";
			cin >> nombre;
			controladora.eliminarTablero(nombre);
			_getch();
			break;
		}
		
		case 3: {
			//SELECCIONAR TABLERO  
			std::string nombre;
			system("cls");
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
			_getch();
		}
			break;
		case 4:
			break;
		}
	} while (opc != 5);
	return 0;
}

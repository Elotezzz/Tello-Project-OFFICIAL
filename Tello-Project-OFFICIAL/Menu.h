#pragma once
#include <conio.h>
#include <iostream>

#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_ENTER 13

class Menu
{
private:
	const char* titulo;
	const char** opciones;
	int cntOpciones;
	int seleccion;

public:
	Menu(const char* titulo, const char* opciones[], int cntOpciones);
	int mostrarMenu();
};
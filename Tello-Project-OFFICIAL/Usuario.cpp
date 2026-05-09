#include "Usuario.h"

Usuario::Usuario() {};

Usuario::Usuario(std::string nombre, std::string password, std::string correo)
    : nombre(nombre), password(password), correo(correo) {}

void Usuario::guardar(std::ofstream& archivo) {
    archivo << "================================" << "\n";
    archivo << "Nombre: " << nombre << "\n";
    archivo << "Correo: " << correo << "\n";
    archivo << "Password: " << password << "\n";
}

bool Usuario::leer(std::ifstream& archivo) {
    std::string linea;

    getline(archivo, linea);

    if (!getline(archivo, linea)) return false;
    nombre = linea.substr(8);

    if (!getline(archivo, linea)) return false;
    correo = linea.substr(8);

    if (!getline(archivo, linea)) return false;
    password = linea.substr(10);

    return true;
}
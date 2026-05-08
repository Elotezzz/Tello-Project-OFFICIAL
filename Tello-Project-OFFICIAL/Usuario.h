#include <fstream>
#include <string>

class Usuario {
public:
    std::string nombre;
    std::string password;
    std::string correo;

    Usuario(std::string nombre, std::string password, std::string correo);

    void guardar(std::ofstream& archivo);
    bool leer(std::ifstream& archivo);
};
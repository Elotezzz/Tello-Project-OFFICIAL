#pragma once
#include <string>

class Fecha
{
private:
    int dia;
    int mes;
    int ano;

public:
    Fecha();
    Fecha(int dia, int mes, int ano);
    ~Fecha();

    int getDia() const;
    int getMes() const;
    int getAno() const;

    bool setDia(int dia);
    bool setMes(int mes);
    bool setAno(int ano);

    std::string toString() const;
};
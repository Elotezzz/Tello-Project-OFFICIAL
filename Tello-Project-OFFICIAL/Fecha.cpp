#include "Fecha.h"

Fecha::Fecha() : dia(1), mes(1), ano(2011) {}

Fecha::Fecha(int dia, int mes, int ano) {
    if (!setDia(dia)) this->dia = 1;
    if (!setMes(mes)) this->mes = 1;
    if (!setAno(ano)) this->ano = 2011;
}

Fecha::~Fecha() {}

int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAno() const { return ano; }

bool Fecha::setDia(int dia) {
    if (dia < 1 || dia > 30) return false;
    this->dia = dia;
    return true;
}

bool Fecha::setMes(int mes) {
    if (mes < 1 || mes > 12) return false;
    this->mes = mes;
    return true;
}

bool Fecha::setAno(int ano) {
    if (ano < 2011 || ano > 2026) return false;
    this->ano = ano;
    return true;
}

std::string Fecha::toString() const {
    auto pad = [](int n) -> std::string {
        return (n < 10 ? "0" : "") + std::to_string(n);
        };
    return pad(dia) + "/" + pad(mes) + "/" + std::to_string(ano);
}
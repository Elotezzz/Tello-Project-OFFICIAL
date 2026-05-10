#include "Listado.h"

Listado::Listado() : nombre(""), tarjetas(new ListaEnlazadaTarjeta<Tarjeta>()), siguiente(nullptr) {}

Listado::Listado(std::string nombre) : nombre(nombre), tarjetas(new ListaEnlazadaTarjeta<Tarjeta>()), siguiente(nullptr) {}

Listado::~Listado() {
    delete tarjetas;
}

std::string Listado::getNombre() const { return nombre; }
int Listado::getCantidad() const { return tarjetas->Length(); }
Listado* Listado::getSiguiente() { return siguiente; }

void Listado::setNombre(std::string nombre) { this->nombre = nombre; }


void Listado::agregarTarjeta(Tarjeta* tarjeta) {
    tarjetas->AddLast(tarjeta);
}

void Listado::eliminarTarjetaPorPos(int pos) {
    tarjetas->RemovePos(pos);
}

Tarjeta* Listado::buscarTarjeta(int pos) {
    return tarjetas->GetPos(pos);
}

void Listado::mostrarTarjetas() {
    std::cout << "=== " << nombre << " (" << getCantidad() << " tarjetas) ===" << std::endl;
    tarjetas->Print(false);
}

Tarjeta* Listado::buscarPorNombreTarjeta(std::string nombre) {
    auto coincide = [&nombre](Tarjeta* t) { return t != nullptr && t->getNombre() == nombre; };
    for (int i = 0; i < tarjetas->Length(); i++) {
        Tarjeta* t = tarjetas->GetPos(i);
        if (coincide(t))
            return t;
    }
    return nullptr;
}
void Listado::eliminarTarjeta(std::string nombre) {
    tarjetas->eliminarPorNombre(nombre);
}

void Listado::crearTarjeta() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la tarjeta: ";
    std::getline(std::cin, nombre);
    if (buscarPorNombreTarjeta(nombre) != nullptr) {
        std::cout << "Ya existe una tarjeta con ese nombre\n";
        return;
    }
    Tarjeta* nueva = new Tarjeta(nombre);
    agregarTarjeta(nueva);

    historial.push(Accion(CREAR, nueva));
    std::cout << "Tarjeta creada correctamente\n";
}

void Listado::eliminarTarjetaPorNombre() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la tarjeta a eliminar: ";
    std::getline(std::cin, nombre);
    Tarjeta* t = buscarPorNombreTarjeta(nombre);
    historial.push(Accion(ELIMINAR, t));
    eliminarTarjeta(nombre);

    std::cout << "Tarjeta eliminada correctamente\n";
}

void Listado::deshacer() {

    if (historial.isEmpty()) {
        std::cout << "No hay acciones para deshacer\n";
        return;
    }
    Accion ultima = historial.top();
    historial.pop();
    if (ultima.getTipo() == CREAR)
    {
        eliminarTarjeta(ultima.getTarjeta()->getNombre());
        std::cout << "Se deshizo la creacion\n";
    }
    else if (ultima.getTipo() == ELIMINAR)
    {
        agregarTarjeta(ultima.getTarjeta());
        std::cout << "Se deshizo la eliminacion\n";
    }
}
void Listado::filtrarTarjetasPrio() {
    auto contarPrio = [&](Prioridad p) {
        int cnt = 0;
        for (int i = 0; i < tarjetas->Length(); i++) {
            Tarjeta* t = tarjetas->GetPos(i);
            if (t != nullptr && t->getPrioridad() == p) cnt++;
        }
        return cnt;
    };

    tarjetas->ordenarPorPrioridad();
	std::cout << "Tarjetas ordenadas por prioridad\n";
}

void Listado::guardar(std::ofstream& arch) const {
    arch << nombre << "\n";
    arch << getCantidad() << "\n";
    for (int i = 0; i < getCantidad(); i++)
        tarjetas->GetPos(i)->guardar(arch);
}

void Listado::cargar(std::ifstream& arch) {
    std::getline(arch, nombre);
    int n; arch >> n; arch.ignore();
    for (int i = 0; i < n; i++) {
        Tarjeta* t = new Tarjeta();
        t->cargar(arch);
        agregarTarjeta(t);
    }
}
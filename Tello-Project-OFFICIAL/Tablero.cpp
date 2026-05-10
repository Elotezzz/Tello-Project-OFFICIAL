#include "Tablero.h"

Tablero::Tablero() : nombre(""), listados(new LinkedListListados<Listado>()), miembro(new std::string[10]), cantidadMiembros(0) {}
Tablero::Tablero(std::string nombre) : nombre(nombre), listados(new LinkedListListados<Listado>()), miembro(new std::string[10]), cantidadMiembros(0) {
    listados->agregar(new Listado("Lista de tareas"));
    listados->agregar(new Listado("En proceso"));
    listados->agregar(new Listado("Hecho"));
}
Tablero::~Tablero() { delete listados; delete[] miembro; }

std::string Tablero::getNombre() const { return nombre; }
int Tablero::getCantidad() const { return listados->getLength(); }

void Tablero::setNombre(std::string nombre) { this->nombre = nombre; }

void Tablero::agregarListado(Listado* listado) {
    listados->agregar(listado);
}

void Tablero::eliminarListado(std::string nombre) {
    listados->eliminarPorNombre(nombre);
}

Listado* Tablero::buscarListado(std::string nombre) {
    auto coincide = [&nombre](Listado* l) { return l != nullptr && l->getNombre() == nombre; };

    for (int i = 0; i < listados->getLength(); i++) {
        Listado* l = listados->GetPos(i);
        if (coincide(l))
            return l;
    }
    return nullptr;
}

void Tablero::mostrarListados() {
    std::cout << "=== Tablero: " << nombre << " (" << getCantidad() << " listados) ===\n";
    listados->imprimir();
}

void Tablero::agregarMiembro(std::string nombre) {
    for (int i = 0; i < cantidadMiembros; i++) {
        if (miembro[i] == nombre) {
            std::cout << nombre << " ya es miembro de este tablero\n";
            return;
        }
    }
    miembro[cantidadMiembros++] = nombre;
}

void Tablero::mostrarMiembros() const{
    for (int i = 0; i < cantidadMiembros; i++)
        std::cout << "  " << i + 1 << " " << miembro[i] << "\n";
}


void Tablero::crearLista() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la lista: ";
    std::getline(std::cin, nombre);
    if (buscarListado(nombre) != nullptr) {
        std::cout << "Ya existe una lista con ese nombre\n";
        return;
    }
    agregarListado(new Listado(nombre));
    std::cout << "Lista creada correctamente\n";
}

void Tablero::eliminarLista()
{
    std::string nombre;
    std::cout<< "Ingrese el nombre de la lista a eliminar: ";
    std::getline(std::cin, nombre);

    eliminarListado(nombre);
    std::cout<< "Lista eliminada correctamente\n";
}

void merge(Listado** arr, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    Listado** izq = new Listado * [n1];
    Listado** der = new Listado * [n2];

    for (int i = 0; i < n1; i++) izq[i] = arr[inicio + i];
    for (int i = 0; i < n2; i++) der[i] = arr[medio + 1 + i];

    auto menor = [](Listado* a, Listado* b) { return a->getNombre() <= b->getNombre(); };

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (menor(izq[i], der[i]))
            arr[k++] = izq[i++];
        else
            arr[k++] = der[j++];
    }
    while (i < n1) arr[k++] = izq[i++];
    while (j < n2) arr[k++] = der[j++];

    delete[] izq;
    delete[] der;
}

void mergeSort(Listado** arr, int inicio, int fin) {
    if (inicio >= fin) return;
    int medio = (inicio + fin) / 2;
    mergeSort(arr, inicio, medio);
    mergeSort(arr, medio + 1, fin);
    merge(arr, inicio, medio, fin);
}

void Tablero::ordenarListados() {
    int n = listados->getLength();
    if (n <= 1) {
        std::cout << "No hay suficientes listas para ordenar\n";
        return;
    }

    Listado** arr = new Listado * [n];
    for (int i = 0; i < n; i++)
        arr[i] = listados->GetPos(i);

    mergeSort(arr, 0, n - 1);

    // En lugar de destruir y recrear, solo intercambia los punteros data en los nodos
    for (int i = 0; i < n; i++)
        listados->setDataPos(arr[i], i);

    delete[] arr;
    std::cout << "Listas ordenadas alfabeticamente\n";
}
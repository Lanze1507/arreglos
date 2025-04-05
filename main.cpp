#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;

struct Producto {
    string codigo;
    string nombre;
    float precio;
    int cantidad;
};

Producto inventario[MAX];
int totalProductos = 0;

void guardarEnArchivo() {
    ofstream archivo("inventario.txt");
    for (int i = 0; i < totalProductos; i++) {
        archivo << inventario[i].codigo << ","
                << inventario[i].nombre << ","
                << inventario[i].precio << ","
                << inventario[i].cantidad << endl;
    }
    archivo.close();
}

void cargarDesdeArchivo() {
    ifstream archivo("inventario.txt");
    string linea;
    totalProductos = 0;

    while (getline(archivo, linea)) {
        size_t pos = 0;
        string token;
        int campo = 0;
        Producto p;
        while ((pos = linea.find(',')) != string::npos) {
            token = linea.substr(0, pos);
            if (campo == 0) p.codigo = token;
            else if (campo == 1) p.nombre = token;
            else if (campo == 2) p.precio = stof(token);
            linea.erase(0, pos + 1);
            campo++;
        }
        p.cantidad = stoi(linea);
        inventario[totalProductos++] = p;
    }
    archivo.close();
}

void agregarProducto() {
    if (totalProductos >= MAX) {
        cout << "Inventario lleno." << endl;
        return;
    }
    Producto p;
    cout << "Ingrese el codigo: ";
    cin >> p.codigo;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, p.nombre);
    cout << "Ingrese el precio: ";
    cin >> p.precio;
    cout << "Ingrese la cantidad: ";
    cin >> p.cantidad;

    inventario[totalProductos++] = p;
    guardarEnArchivo();
}

void mostrarInventario() {
    for (int i = 0; i < totalProductos; i++) {
        cout << i + 1 << ". Codigo: " << inventario[i].codigo
             << ", Nombre: " << inventario[i].nombre
             << ", Precio: Q" << inventario[i].precio
             << ", Cantidad: " << inventario[i].cantidad << endl;
    }
}

void buscarProducto() {
    string codigoBuscado;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigoBuscado;

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigoBuscado) {
            cout << "Producto encontrado:" << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Precio: Q" << inventario[i].precio << endl;
            cout << "Cantidad: " << inventario[i].cantidad << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void menu() {
    int opcion;
    do {
        cout << "--- Menu de Inventario ---" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: mostrarInventario(); break;
            case 3: buscarProducto(); break;
            case 4: cout << "Saliendo del programa..."; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);
}

int main() {
    system("chcp 65001");
    cargarDesdeArchivo();
    menu();
    return 0;
}
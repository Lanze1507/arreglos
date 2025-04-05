//
// Created by crist on 5/04/2025.
//

#include "funcion6.h"
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
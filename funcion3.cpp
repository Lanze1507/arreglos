//
// Created by crist on 5/04/2025.
//

#include "funcion3.h"
void agregarProducto() {
    if (totalProductos >= MAX) {
        cout << "Inventario lleno." << endl;
        return;
    }
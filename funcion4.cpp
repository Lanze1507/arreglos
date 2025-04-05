//
// Created by crist on 5/04/2025.
//

#include "funcion4.h"
void mostrarInventario() {
    for (int i = 0; i < totalProductos; i++) {
        cout << i + 1 << ". Codigo: " << inventario[i].codigo
             << ", Nombre: " << inventario[i].nombre
             << ", Precio: Q" << inventario[i].precio
             << ", Cantidad: " << inventario[i].cantidad << endl;
    }
}
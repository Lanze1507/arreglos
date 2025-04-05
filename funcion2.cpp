//
// Created by crist on 5/04/2025.
//

#include "funcion2.h"
void cargarDesdeArchivo() {
    ifstream archivo("inventario.txt");
    string linea;
    totalProductos = 0;
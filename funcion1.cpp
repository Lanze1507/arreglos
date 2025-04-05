//
// Created by crist on 5/04/2025.
//

#include "funcion1.h"
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

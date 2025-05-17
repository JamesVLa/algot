/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: james
 *
 * Created on 17 de mayo de 2025, 01:07 AM
 */

#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

int main(int argc, char** argv) {
    struct Lista lista;
    construir(lista);

    // Insertar cuadrigas en orden desordenado (como en el ejemplo)
    insertarAlInicio(lista, 7, "Drusus", "Negro");
    insertarAlInicio(lista, 12, "Artax", "Verde");
    insertarAlInicio(lista, 4, "Ben-Hur", "Azul");
    insertarAlInicio(lista, 17, "Messala", "Rojo");

    cout << "Lista inicial:" << endl;
    imprime(lista);

    // Reordenar la lista
    reordenarListaParesImpares(lista);

    cout << "\nLista reordenada (pares al inicio, impares al final):" << endl;
    imprime(lista);

    // Liberar memoria
    destruir(lista);
    return 0;
}


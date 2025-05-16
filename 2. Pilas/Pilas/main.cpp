/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include "Pila.h"
#include "Elemento.h"
#include "funcionesPila.h"
using namespace std;


/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-1
 */
int main(int argc, char** argv) {

     /*Funciones de Pila*/
    struct Pila pila;
    struct Elemento elemento1, elemento2, elemento3, elemento4;
    construir(pila);

    elemento1.numero = 1;
    elemento1.tipo = 1;
    elemento2.numero = 3;
    elemento2.tipo = 2;
    elemento3.numero = 4;
    elemento3.tipo = 1;
    elemento4.numero = 5;
    elemento4.tipo = 2;
    /*Apilamos elementos en la pila*/
    apilar(pila, elemento1);
    apilar(pila, elemento2);
    apilar(pila, elemento3);
    apilar(pila, elemento4);

    imprimir(pila);

    /*Desapilamos elementos en la pila*/
    while (not esPilaVacia(pila)) {
        elemento1 = desapilar(pila);
        cout << "Desapilando: " << elemento1.numero << endl;
    }
    imprimir(pila);
    return 0;
}


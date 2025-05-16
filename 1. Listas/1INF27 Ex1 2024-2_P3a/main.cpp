/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: james
 *
 * Created on 16 de mayo de 2025, 03:45 PM
 */

#include <iostream>
#include "Lista.h"
#include "Elemento.h"
#include "funcionesLista.h"
using namespace std;

#define NUM_COMPUTADORAS 7 // 6 computadoras + 1 para índice 0 no usado

// Agrega una conexión entre computadora origen y destino

void agregarConexion(struct Lista * red, int origen, int destino) {
    insertarAlFinal(red[origen], destino);
    cout << "Se conectó la computadora " << origen << " con la computadora " << destino << endl;
}

// Elimina una conexión entre computadora origen y destino

void eliminarConexion(struct Lista * red, int origen, int destino) {
    eliminaNodo(red[origen], destino);
    cout << "Se desconectó la computadora " << origen << " con la computadora " << destino << endl;
}

// Verifica si hay un camino de origen a destino usando BFS con Lista

bool hayEscaladaPrivilegios(struct Lista * red, int origen, int destino, int n) {
    bool * visitado = new bool[n]();
    struct Lista cola;
    construir(cola);

    visitado[origen] = true;
    insertarAlFinal(cola, origen);

    while (!esListaVacia(cola)) {
        int actual = retornaCabeza(cola);
        eliminaCabeza(cola);
        if (actual == destino) {
            destruir(cola);
            delete[] visitado;
            return true;
        }
        struct Nodo * recorrido = red[actual].cabeza;
        while (recorrido != nullptr) {
            int vecino = recorrido->elemento.numero;
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                insertarAlFinal(cola, vecino);
            }
            recorrido = recorrido->siguiente;
        }
    }
    destruir(cola);
    delete[] visitado;
    return false;
}

// Imprime la red de computadoras y verifica escalada de privilegios

void imprimirRed(struct Lista * red, int n) {
    for (int i = 1; i < n; i++) {
        cout << "Computadora " << i << ": ";
        if (esListaVacia(red[i])) {
            cout << endl;
        } else {
            cout << "-> ";
            struct Nodo * recorrido = red[i].cabeza;
            while (recorrido != nullptr) {
                cout << recorrido->elemento.numero;
                if (recorrido->siguiente != nullptr) {
                    cout << " -> ";
                }
                recorrido = recorrido->siguiente;
            }
            cout << endl;
        }
    }
    cout << "VERIFICACIÓN: de computadora 1 a 6" << endl;
    cout << "Resultado: " << (hayEscaladaPrivilegios(red, 1, 6, n) ?
            "Si hay escalada de privilegios" : "No hay escalada de privilegios") << endl;
}

int main(int argc, char** argv) {
    // Construir el arreglo de listas
    struct Lista red[NUM_COMPUTADORAS];
    for (int i = 0; i < NUM_COMPUTADORAS; i++) {
        construir(red[i]);
    }

    // Escenario 1: Conexiones iniciales
    cout << "X" << endl;
    agregarConexion(red, 1, 2);
    agregarConexion(red, 1, 3);
    agregarConexion(red, 2, 4);
    agregarConexion(red, 5, 6);
    imprimirRed(red, NUM_COMPUTADORAS);

    // Escenario 2: Agregar 3->5, Eliminar 5->6
    cout << endl;
    agregarConexion(red, 3, 5);
    eliminarConexion(red, 5, 6);
    imprimirRed(red, NUM_COMPUTADORAS);

    // Escenario 3: Agregar 4->6
    cout << endl;
    agregarConexion(red, 4, 6);
    imprimirRed(red, NUM_COMPUTADORAS);

    // Destruir las listas
    for (int i = 0; i < NUM_COMPUTADORAS; i++) {
        destruir(red[i]);
    }

    return 0;
}


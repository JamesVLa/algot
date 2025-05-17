/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: james
 *
 * Created on 17 de mayo de 2025, 03:08 AM
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

// Función para encontrar un camino desde inicio hasta fin usando una pila (DFS)
void encontrarCamino(int inicio, int fin, int matriz[6][6], int numNodos) {
    struct Pila pila;
    construir(pila);

    // Arreglo para marcar nodos visitados
    bool visitado[6] = {false};
    
    // Arreglo para almacenar el padre de cada nodo (para reconstruir el camino)
    int padre[6] = {-1, -1, -1, -1, -1, -1};

    // Apilar el nodo inicial
    struct Elemento elemInicio;
    elemInicio.numero = inicio - 1; // Ajustar para indexación basada en 0
    elemInicio.tipo = 0;
    apilar(pila, elemInicio);
    visitado[inicio - 1] = true;

    bool encontrado = false;
    while (!esPilaVacia(pila) && !encontrado) {
        // Desapilar el nodo superior de la pila
        struct Elemento actual = desapilar(pila);
        int nodoActual = actual.numero;

        // Verificar si llegamos al nodo objetivo
        if (nodoActual + 1 == fin) {
            encontrado = true;
            break;
        }

        // Explorar los vecinos (nodos conectados directamente)
        for (int i = 0; i < numNodos; i++) {
            if (matriz[nodoActual][i] == 1 && !visitado[i]) {
                struct Elemento vecino;
                vecino.numero = i;
                vecino.tipo = 0;
                apilar(pila, vecino);
                visitado[i] = true;
                padre[i] = nodoActual; // Registrar el padre para reconstruir el camino
            }
        }
    }

    // Si encontramos el objetivo, reconstruir e imprimir el camino
    if (encontrado) {
        cout << "Camino encontrado: ";
        int camino[6];
        int longitudCamino = 0;
        int nodo = fin - 1; // Ajustar para indexación basada en 0
        while (nodo != -1) {
            camino[longitudCamino++] = nodo + 1; // Ajustar a base 1 para la salida
            nodo = padre[nodo];
        }
        // Imprimir el camino en el orden correcto (de inicio a fin)
        for (int i = longitudCamino - 1; i >= 0; i--) {
            cout << camino[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "No se encontró un camino desde " << inicio << " hasta " << fin << endl;
    }

    // Limpiar la pila
    destruirPila(pila);
}

int main(int argc, char** argv) {
    // Matriz de adyacencia (indexación basada en 0, pero los nodos están etiquetados de 1 a 6)
    int matriz[6][6] = {
        {0, 1, 0, 1, 0, 0}, // Nodo 1
        {0, 0, 1, 0, 0, 0}, // Nodo 2
        {0, 0, 0, 0, 1, 0}, // Nodo 3
        {0, 0, 0, 0, 0, 1}, // Nodo 4
        {0, 0, 0, 0, 0, 0}, // Nodo 5
        {0, 0, 0, 0, 0, 0} // Nodo 6
    };

    int inicio = 1; // Nodo inicial
    int fin = 6; // Nodo final
    int numNodos = 6;

    encontrarCamino(inicio, fin, matriz, numNodos);
    return 0;
}


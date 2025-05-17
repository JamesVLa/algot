/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Lista.h"
#include "Elemento.h"
#include "funcionesLista.h"
using namespace std;

/*Valores iniciales de la lista*/
void construir(struct Lista & tad) {/////////////////////////////////////7
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia(const struct Lista & tad) {/////////////////////////////////77
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista & tad) {/////////////////////////77
    return tad.longitud;
}

/*inserta un  struct Nodo * nuevoNodo = new struct Nodo; nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista& tad, int id, const char* nombre, const char* equipo) {
    struct Elemento elemento;
    elemento.id = id;
    strcpy(elemento.nombre, nombre);
    strcpy(elemento.equipo, equipo);

    struct Nodo* nuevoNodo = crearNodo(elemento, tad.cabeza);
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(const struct Elemento & elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & tad, int id, const char* nombre, const char* equipo) {

    struct Elemento elemento;
    elemento.id = id;
    strcpy(elemento.nombre, nombre);
    strcpy(elemento.equipo, equipo);

    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    tad.longitud++;
}

//Notar que esta función retorna nulo cuando la lista es vacía

/*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

///*inserta un nodo en orden*/
//void insertarEnOrden(struct Lista & tad, int numero) {
//
//    struct Elemento elemento;
//    elemento.numero = numero;
//
//    struct Nodo * nodoAnterior = obtenerNodoAnterior(tad, numero);
//    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
//    /*Si nodoAnterior es igual a nulo, la lista está vacia, se debe
//     insertar al inicio, no hay nodos menores que elemento*/
//    if (nodoAnterior == nullptr) { /*la lista está vacia*/
//        nuevoNodo->siguiente = tad.cabeza;
//        tad.cabeza = nuevoNodo;
//    } else {
//        nuevoNodo->siguiente = nodoAnterior->siguiente;
//        nodoAnterior->siguiente = nuevoNodo;
//    }
//    tad.longitud++;
//}
//
///*retorna el anterior al que tiene el elemento*/
//struct Nodo * obtenerNodoAnterior(const struct Lista & tad, int elemento) {
//    struct Nodo * anterior = nullptr;
//    struct Nodo * recorrido = tad.cabeza;
//    while ((recorrido != nullptr) and (recorrido->elemento.numero < elemento)) {
//        anterior = recorrido;
//        recorrido = recorrido->siguiente;
//    }
//    return anterior;
//}
//
//struct Nodo * seEncuentra(const struct Lista & tad, int elemento) {
//    struct Nodo * recorrido = tad.cabeza;
//
//    /*retorna el nodo correspondiente al elemento buscado*/
//    while ((recorrido != nullptr) and (recorrido->elemento.numero != elemento)) {
//        recorrido = recorrido->siguiente;
//    }
//    return recorrido;
//}
//
//int retornaCabeza(const struct Lista & lista) {
//    return lista.cabeza->elemento.numero;
//}
//
//void eliminaNodo(struct Lista & tad, int elemento) {
//    struct Nodo * ultimo = nullptr;
//    struct Nodo * recorrido = tad.cabeza;
//    /*Avanzo hasta encontrar el elemento*/
//    /*Si no lo encuentra no elimina nada*/
//    while ((recorrido != nullptr) and (recorrido->elemento.numero != elemento)) {
//        ultimo = recorrido;
//        recorrido = recorrido->siguiente;
//    }
//
//    if (recorrido != nullptr) {
//        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
//            tad.cabeza = recorrido->siguiente;
//        else
//            ultimo->siguiente = recorrido->siguiente;
//        delete recorrido; /*libera la memoria*/
//        tad.longitud--;
//    }
//}
//
//void eliminaCabeza(struct Lista & tad) {
//    struct Nodo * nodoAEliminar = tad.cabeza;
//    if (nodoAEliminar != nullptr) {
//        tad.cabeza = tad.cabeza->siguiente;
//        delete nodoAEliminar;
//        tad.longitud--;
//    }
//}
//
///*Elimina el último elemento de la lista, es llamado cola*/
//void eliminaCola(struct Lista tad) {
//    struct Nodo * ultimo = nullptr;
//    struct Nodo * penultimo = nullptr;
//    struct Nodo * recorrido = tad.cabeza;
//
//    while (recorrido != nullptr) {
//        if (ultimo != nullptr)
//            penultimo = ultimo;
//        ultimo = recorrido;
//        recorrido = recorrido->siguiente;
//    }
//
//    if (ultimo != nullptr) {
//        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
//        if (penultimo == nullptr)
//            tad.cabeza = nullptr;
//        else
//            penultimo->siguiente = nullptr;
//        delete ultimo;
//        tad.longitud--;
//    }
//}

void reordenarListaParesImpares(struct Lista& tad) {
    if (esListaVacia(tad) || tad.longitud == 1) return;

    // Sublistas para pares e impares
    struct Nodo* listaPares = nullptr;
    struct Nodo* listaImpares = nullptr;
    struct Nodo* ultimoPar = nullptr;
    struct Nodo* ultimoImpar = nullptr;
    struct Nodo* actual = tad.cabeza;
    struct Nodo* siguiente = nullptr;

    // Separar nodos en listas de pares e impares
    while (actual != nullptr) {
        siguiente = actual->siguiente; // Guardar el siguiente nodo
        actual->siguiente = nullptr;   // Desconectar el nodo actual

        if (actual->elemento.id % 2 == 0) { // Si es par
            if (listaPares == nullptr) {
                listaPares = actual;
                ultimoPar = actual;
            } else {
                ultimoPar->siguiente = actual;
                ultimoPar = actual;
            }
        } else { // Si es impar
            if (listaImpares == nullptr) {
                listaImpares = actual;
                ultimoImpar = actual;
            } else {
                ultimoImpar->siguiente = actual;
                ultimoImpar = actual;
            }
        }
        actual = siguiente; // Avanzar al siguiente nodo
    }

    // Reconectar las listas
    if (listaPares == nullptr) { // Solo hay impares
        tad.cabeza = listaImpares;
    } else if (listaImpares == nullptr) { // Solo hay pares
        tad.cabeza = listaPares;
    } else { // Hay ambos
        tad.cabeza = listaPares;
        ultimoPar->siguiente = listaImpares;
    }
}

void destruir(struct Lista & tad) {
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista& tad) {
    if (esListaVacia(tad)) {
        cout << "La lista está vacía" << std::endl;
        return;
    }

    struct Nodo* recorrido = tad.cabeza;
    while (recorrido != nullptr) {
        cout << "[ID: " << recorrido->elemento.id
                << ", Nombre: " << recorrido->elemento.nombre
                << ", Equipo: " << recorrido->elemento.equipo << "]" << endl;
        recorrido = recorrido->siguiente;
    }
}
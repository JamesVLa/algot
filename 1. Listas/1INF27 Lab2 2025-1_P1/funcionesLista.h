/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);/////////7777

void insertarAlInicio(struct Lista& tad, int id, const char* nombre, const char* equipo);///////////
void insertarAlFinal(struct Lista & tad, int id, const char* nombre, const char* equipo);/////////////
//void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(const struct Elemento & elemento, struct Nodo *);//////////////
struct Nodo * obtenerUltimoNodo(const struct Lista &);////////////////////////
//struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
//struct Nodo * seEncuentra(const struct Lista &, int);
//int retornaCabeza(const struct Lista & lista);

bool esListaVacia(const struct Lista &);////////////
int longitud(const struct Lista &);////////////////

void reordenarListaParesImpares(struct Lista&);


//void eliminaNodo(struct Lista &, int);
//void eliminaCabeza(struct Lista &);
//void eliminaCola(struct Lista);

void destruir(struct Lista &);////////////
void imprime(const struct Lista &);////////////////7

#endif /* FUNCIONESLISTA_H */


/* 
 * File:   Elemento.h
 * Author: ANA RONCAL
 *
 * Created on 11 de abril de 2025, 2:45 PM
 */

#ifndef ELEMENTO_H
#define ELEMENTO_H

#define MAX_NOMBRE 50
#define MAX_EQUIPO 20

/*información de la lista, acá se pueden añadir más datos*/
struct Elemento{
    int id;                    // Número de inscripción (ID)
    char nombre[MAX_NOMBRE];   // Nombre del conductor
    char equipo[MAX_EQUIPO];   // Color del equipo
};

#endif /* ELEMENTO_H */
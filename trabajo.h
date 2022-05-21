/*
 * trabajo.h
 *
 *  Created on: 18 may. 2022
 *      Author: USUARIO
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "mascota.h"
#include "tipo.h"
#include "servicio.h"
#include  "fecha.h"

typedef struct{
    int id;
    int idMascota;
    int idServicio;
    int isEmpty;
    eFecha fIngreso;
}trabajo;

int altaTrabajo(trabajo vec[], int tam,mascota vecm[], int tamm,tipo vect[], int tamt, servicio vecs[], int tams, int* pNextId);
void informarTrabajo(trabajo vec[], int tam,mascota vecM[], int tamm, servicio vecS[], int tamS);
int inicializarTrabajo(trabajo vec[], int tam);
int buscarTrabajoLibre(trabajo vec[], int tam, int* pIndex);
int bajaMascota(mascota lista[], int tam);


#endif /* TRABAJO_H_ */



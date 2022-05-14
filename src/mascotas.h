/*
 * mascotas.h
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "tipo.h"

#ifndef MASCOTAS_H_
#define MASCOTAS_H_

typedef struct
{
    int id;
    char nombre[20];
    tipo idTipo;
    color idColor;
    int edad;
    char vacunado[2];
    int isEmpty;
}mascota;



#endif /* MASCOTAS_H_ */

int inicializarMascotas(mascota vec[], int tam);
int altaMascotas(mascota vec[], int tam, int* pNextId);
int menuMascotas();
int buscarLibre(mascota vec[], int tam, int* pIndex);
void informarMascotas(mascota lista[], int tam);
int modificacionDemascota(mascota lista[], int tam, int* pNextId);
int menuModificarmascota();
//int hardcodearmascotas(mascota vec[], int tam, int cant, int* pNextId);

/*
 * mascota.h
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "tipo.h"
#include "cliente.h"

#include "servicio.h"


#ifndef MASCOTA_H_
#define MASCOTA_H_

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char vacunado[2];
    int isEmpty;
    int idColor;
    int idTipo;
    int idCliente;


}mascota;



#endif /* MASCOTAS_H_ */

int inicializarMascotas(mascota vec[], int tam);
int altaMascotas(mascota vec[], int tam,color vecc[], int tamc,tipo vect[],int tamt, servicio vecs[], int tams,cliente vecCL[],int TAMCL, int* pNextId);
int menuMascotas();
int buscarLibre(mascota vec[], int tam, int* pIndex);
void informarMascotas(mascota vec[], int tam,color vecC[], int tamc,tipo vecT[], int tamt, cliente vecCL[], int TAMCL);
int modificacionDemascota(mascota lista[], int tam, color colores[], int tamCol,tipo tipos[], int tamTipo,cliente vecCL[], int tamCL);
int menuModificarmascota();
void mostrarMascota(mascota vec[], int tam,tipo vecT[],int  tamt,color vecC[],int tamc);
int hardcodearmascotas(mascota vec[], int tam, int cant, int* pNextId);
int listarMascota(mascota mascotas[], int tam);
int ordenarMascotaPorTipoYNombre(mascota vec[], int tam, tipo vect[], int tamt);
int mascotaXColor(mascota vec[], int tam, color colores[], int tamC);
int promedioMascotaVacunadas(mascota vec[], int tam);
int informeMascotaMenor(mascota vec[], int tam);
int mascotaXtipo(mascota vec[], int tam, tipo tipos[], int tamT);
int cantidadTipoColor(mascota vec[], int tam, color vecC[], int tamC, tipo vecT[], int tamT );

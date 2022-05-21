/*
 * tipo.h
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{

 int id;
 char descripcionr[20];

}tipo;


int listarTipos(tipo tipos[], int tam);
int cargarNombreTipo(tipo tipos[], int tam, int id, char desc[]);
#endif /* TIPO_H_ */

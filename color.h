/*
 * color.h
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef COLOR_H_
#define COLOR_H_
typedef struct{

 int id;
 char nombreColor[20];

}color;


int listarColor(color colores[], int tam);
int cargarNombreColor(color colores[],int tamc,int idColor,char descColor[]);
#endif /* COLOR_H_ */

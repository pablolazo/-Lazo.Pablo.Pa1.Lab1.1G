/*
 * servicio.h
 *
 *  Created on: 18 may. 2022
 *      Author: USUARIO
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
    int id;
    char descripcion[20];
    int precio;
}servicio;

int listarServicio(servicio Servicios[], int tam);

#endif /* SERVICIO_H_ */

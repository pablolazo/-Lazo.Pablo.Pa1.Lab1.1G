/*
 * cliente.h
 *
 *  Created on: 20 may. 2022
 *      Author: USUARIO
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
typedef struct{
    int id;
    char nombre[20];
    char sexo[2];


}cliente;

int listarClientes(cliente clientes[], int tam);

#endif /* CLIENTE_H_ */

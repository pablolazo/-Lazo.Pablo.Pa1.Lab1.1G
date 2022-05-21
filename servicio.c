/*
 * servicio.c
 *
 *  Created on: 18 may. 2022
 *      Author: USUARIO
 */
#include "servicio.h"

int listarServicio(servicio Servicios[], int tam){

 int todoOk = 0;
    if(tam > 0 ){

        printf("   *** Listado de Servicios ***\n");
        printf("  id      descripcion    precio\n");
        printf("-----------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s\n", Servicios[i].id, Servicios[i].descripcion, Servicios[i].precio);

         }
    }
    return todoOk;
}



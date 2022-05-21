/*
 * color.c
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include "color.h"

 int cargarNombreColor(color colores[],int tamc,int idColor,char descColor[]){

    int todoOk = 0;


         for(int i= 0; i < tamc; i++){

            if( colores[i].id == idColor){
                strcpy(descColor,colores[i].nombreColor);
                todoOk = 1;
                break;
            }

         }

    return todoOk;
}

int listarColor(color colores[], int tam){

 int todoOk = 0;
    if(colores != NULL && tam > 0 ){

        printf("   *** Listado de colores ***\n");
        printf("  id      descripcion\n");
        printf("-----------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s\n", colores[i].id, colores[i].nombreColor);

         }
    }
    return todoOk;
}

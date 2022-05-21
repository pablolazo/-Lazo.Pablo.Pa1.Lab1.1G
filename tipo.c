/*
 * tipo.c
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include "tipo.h"


int listarTipos(tipo tipos[], int tam){

 int todoOk = 0;
    if(tipos != NULL && tam > 0 ){

        printf("   *** Listado de tipos ***\n");
        printf("  id      descripcion\n");
        printf("-----------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s\n", tipos[i].id, tipos[i].descripcionr);

         }
    }
    return todoOk;
}
int cargarNombreTipo(tipo tipos[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( tipos[i].id == id){
                strcpy( desc, tipos[i].descripcionr);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;

}

/*
 * trabajo.c
 *
 *  Created on: 18 may. 2022
 *      Author: USUARIO
 */
#include "trabajo.h"
#include "fecha.h"
#include "servicio.h"
#include "mascota.h"


int altaTrabajo(trabajo vec[], int tam,mascota vecm[], int tamm,tipo vect[], int tamt, servicio vecs[], int tams, int* pNextId)
{
    int todoOk = 0;
    int indice;
    trabajo nuevoTrabajos;


    int idServicio;
    int idMascota;
    eFecha fecha;





    if( tam > 0)
    {
        system("cls");
        printf("    *** Alta Trabajos ***\n\n");
        buscarTrabajoLibre(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoTrabajos.id = *pNextId;

            listarMascota(vecm, tamm);
            printf("ingrese mascota: ");
            scanf("%i",&idMascota);
            nuevoTrabajos.idMascota = idMascota;


            listarServicio(vecs, tams);
            printf("ingrese servicio: ");
            scanf("%i",&idServicio);
            nuevoTrabajos.idServicio = idServicio;


            printf("Ingrese fecha ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d",
             &fecha.dia,
             &fecha.mes,
             &fecha.anio);

            nuevoTrabajos.fIngreso.dia = fecha.dia;
            nuevoTrabajos.fIngreso.mes = fecha.mes;
            nuevoTrabajos.fIngreso.anio = fecha.anio;



            nuevoTrabajos.isEmpty = 0;


           vec[indice] = nuevoTrabajos;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}

void informarTrabajo(trabajo vec[], int tam,mascota vecM[], int tamm, servicio vecS[], int tamS)
{
	 printf("             id trabajo || mascota || servicio || precio || fecha \n\n");
	    for (int i = 0; i < tam; i++) {

	    	if(!vec[i].isEmpty){

	        printf("%15d %10s %10s  %10d %d/%d/%d \n",
	        		vec[i].id,vecM[i].nombre, vecS[i].descripcion,
					vecS[i].precio, vec[i].fIngreso.dia,vec[i].fIngreso.mes,vec[i].fIngreso.anio);

	    }}

	    printf("================================================================================================================\n");

	    system("PAUSE");
	    system("cls");
	}
int inicializarTrabajo(trabajo vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}
int buscarTrabajoLibre(trabajo vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


/*
 * mascotas.c
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"

int inicializarMascotas(mascota vec[], int tam)
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

int buscarLibre(mascota vec[], int tam, int* pIndex)
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

int altaMascotas(mascota vec[], int tam, int* pNextId)
{
    int todoOk = 0;
    int indice;
    mascota nuevoMascotas;
 //   color colores;




    if( vec != NULL && pNextId != NULL && tam > 0)
    {
        system("cls");
        printf("    *** Alta Mascotas ***\n\n");
        buscarLibre(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoMascotas.id = *pNextId;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoMascotas.nombre);

            printf("Ingrese tipo: ");
            fflush(stdin);
            gets(nuevoMascotas.idTipo.descripcionr);

            printf("Ingrese color: ");
            fflush(stdin);
            gets(nuevoMascotas.idColor.nombreColor);

            printf("Ingrese si esta vacunado: ");
            fflush(stdin);
            gets(nuevoMascotas.vacunado);

            printf("ingrese edad: ");
            scanf("%i", &nuevoMascotas.edad);


            nuevoMascotas.isEmpty = 0;

            vec[indice] = nuevoMascotas;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}

int menuMascotas()
{

    int opcion;

    system("cls");
    printf("     *** ABM Mascotass ***\n\n");
    printf("1. Alta Mascotas\n");
    printf("2. Modificar Mascotas\n");
    printf("4. listar Mascotass\n");
    printf("20. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

void informarMascotas(mascota lista[], int tam){
    printf("                  id||    nombre||  tipo  ||  color||  vacunado ||      edad   || \n\n");
    for (int i = 0; i < tam; i++) {
    	if(!lista[i].isEmpty){


        printf("%20d %8s %8s %8s %8s %20i  \n",  lista[i].id, lista[i].nombre, lista[i].idTipo.descripcionr, lista[i].idColor.nombreColor, lista[i].vacunado, lista[i].edad );

    }}

    system("PAUSE");
    system("cls");
}

int buscarmascota(mascota vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificacionDemascota(mascota lista[], int tam, int* pNextId){
	int todoOk =0 ;
	int id;
	int indice;
    char auxiliarNombre[100];
    char auxiliarColor[100];
    char auxiliarTipo[100];
    int edad;
    char vacunado[2];





           informarMascotas(lista, tam);
	        printf("Ingrese id: ");
	        scanf("%d", &id);

	indice = buscarmascota(lista, tam, id, &indice);

	informarMascotas(lista, tam);

	 switch(menuModificarmascota())
	                 {

	                 case 1:
	                     printf("Ingrese nuevo nombre: ");
	                     fflush(stdin);
	                     gets(auxiliarNombre);

	                     strcpy(lista[indice].nombre, auxiliarNombre);
	                     printf("Nombre modificado!");
	                     break;
	                 case 2:
	                	 printf("Ingrese nuevo tipo: ");
	                     fflush(stdin);
	                	 gets(auxiliarTipo);

	                     strcpy(lista[indice].idTipo.descripcionr, auxiliarTipo);
	                     printf("tipo modificado!");
	                     break;
	                 case 3:
	                	 printf("Ingrese nuevo color: ");
	                     fflush(stdin);
	                     gets(auxiliarColor);

	                     strcpy(lista[indice].idColor.nombreColor, auxiliarColor);
	                	 printf("color modificado!");
	                     break;
	                 case 4:
	                     printf("Ingrese nueva vacunacion: ");
	                     fflush(stdin);
	                     gets(vacunado);

	                     strcpy(lista[indice].vacunado, vacunado);
	                     printf("vacunado modificado!");

	                     break;
	                 case 5:
	                     printf("Ingrese edad");
	                     scanf("%i", &edad);

	                     lista[indice].edad = edad;
	                     printf("edad modificada!");
	                     break;
	                 case 6:
	                	 printf("gracias:\n ");

	                	 break;
	                 default:
	                 					printf("opcion invalida. ingrese un numero de la lista: \n");
	                 }



return todoOk;
}

int menuModificarmascota()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Nombre\n");
    printf("2. tipo\n");
    printf("3. color\n");
    printf("4. vacunacion\n");
    printf("5. edad\n");
    printf("6. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

/*int hardcodearmascotas(mascota vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;
    mascota mascotas[5] =
    {
        {0, "Juan", "ave", "negro", "s",10},  //(Ave, Perro, Roedor, Gato, Pez)
        {0, "Miguel", "perro", "blanco", "s",11},//(Negro, Blanco, Rojo, Gris, Azul)
        {0, "Juana","Roedor", "rojo", "s",12},
        {0, "Andrea", "Gato", "gris", "n",13},
        {0, "Juliana", "Pez", "azul", "n",14}

    };

    if( vec != NULL && pNextId != NULL && tam > 0 && tam <= 10 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            vec[i] = mascotas[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;

}*/


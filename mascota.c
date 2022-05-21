/*
 * mascota.c
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascota.h"
#include "imputs.h"

void mostrarMascota(mascota vec[], int tam,tipo vecT[],int  tamt,color vecC[],int tamc)
{


int idColor = 0 ;
int idTipo = 0;
    char descripcionColor[20];
    char descripcionTipo[20];
   cargarNombreColor(vecC,idColor, tamc, descripcionColor);
   cargarNombreTipo(vecT,idTipo,tamt,  descripcionTipo);
    printf("    %4d    %10s      %d    %s    %s   %d   %s  %d\n",
            vec->id,
            vec->nombre,
            vec->edad ,
            vec->vacunado,
            descripcionColor,
			idColor,
            descripcionTipo,
			idTipo
           );
}


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

int altaMascotas(mascota vec[], int tam,color vecc[], int tamc,tipo vect[],int tamt, servicio vecs[], int tams,cliente vecCL[],int TAMCL, int* pNextId)
{
    int todoOk = 0;
    int indice;
    mascota nuevoMascotas;
    cliente dueneo;
    int idColor;
    int idTipo;


    int validacionNombre = 0;
    int validarSoNo = 0;
    int validarNumero = 0;
    char numero[20];

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
            do{
            printf("Ingrese nombre de la mascota: ");
            fflush(stdin);
            gets(nuevoMascotas.nombre);
            validacionNombre=validarCaracter(nuevoMascotas.nombre);
            }while(validacionNombre==1);


            do{
            printf("Ingrese nombre del dueño: ");
            fflush(stdin);
            gets(dueneo.nombre);
            validacionNombre=validarCaracter(dueneo.nombre);
            }while(validacionNombre==1);


             printf("Ingrese sexo del dueño m o f: ");
             fflush(stdin);
             gets(dueneo.sexo);

            do{
            printf("Ingrese si la mascota  esta vacunada s o n: ");
            fflush(stdin);
            gets(nuevoMascotas.vacunado);
            validarSoNo = validarSoN(nuevoMascotas.vacunado);
             }while(validarSoNo==1);

             do{
                 printf("Ingrese edad: ");
                 fflush(stdin);
                 gets(numero);
                 validarNumero=esEnteroValido(numero);
                 }while(validarNumero==1);
            nuevoMascotas.edad = atoi(numero);


            nuevoMascotas.isEmpty = 0;

            listarColor(vecc, tamc);
            printf("ingresar id color: ");
            scanf("%i",&idColor);



            listarTipos(vect, tamt);
            printf("ingresar id tipo: ");
            scanf("%i",&idTipo);

            nuevoMascotas.isEmpty = 0;
            nuevoMascotas.idColor = idColor;
            nuevoMascotas.idTipo = idTipo;
            vec[indice] = nuevoMascotas;
            vecCL[indice] = dueneo;

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
    printf("3. Baja Mascotas\n");
    printf("4. listar Mascotass\n");
    printf("5. listar colores\n");
    printf("6. alta trabajo\n");
    printf("7. listar trabajo\n");
    printf("8. listar servicios\n");
    printf("9. listar mascota x color\n");
    printf("10. listar promedio de vacunados\n");
    printf("11. listar mascota menor\n");
    printf("12. listar mascota por tipo \n");
    printf("13. listar mascota por tipo y color\n");
    printf("20. salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

void informarMascotas(mascota vec[], int tam,color vecC[], int tamc,tipo vecT[], int tamt, cliente vecCL[], int TAMCL)
{
	 printf("                  id||   nombre || dueño || vacunado|| edad   || color   || tipo   || \n\n");
	    for (int i = 0; i < tam; i++) {
	    	if(!vec[i].isEmpty){


	        printf("%20d %8s %8s %8s %10d %10s %10s \n",
	        		vec[i].id, vec[i].nombre,vecCL[i].nombre, vec[i].vacunado,
					vec[i].edad, vecC[i].nombreColor, vecT[i].descripcionr);

	    }}
	    printf("================================================================================================================\n");

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
int modificacionDemascota(mascota lista[], int tam, color colores[], int tamCol,tipo tipos[], int tamTipo,cliente vecCL[], int tamCL)
{
	    int todoOk = 0;
	    int indice=0;
	    int id =0;
	    int edad;
	    char vacunado;


	    //char nuevoTipos;
	    //char nuevoColor;
	    int idColor;
	//   color descColor;
	    int idTipo;
	 //  color descTipo;
	   char auxiliarNombre;




	   informarMascotas(lista, tam, colores, tamCol, tipos, tamTipo,vecCL,tamCL);
	        printf("Ingrese id: ");
	        scanf("%d", &id);

	indice = buscarmascota(lista, tam, id, &indice);
            listarMascota(lista, tam);



	 switch(menuModificarmascota())
	                 {

	                 case 1:
	                     printf("Ingrese nuevo nombre: ");
	                     fflush(stdin);
	                     gets(&auxiliarNombre);

	                     strcpy(lista[indice].nombre, &auxiliarNombre);
	                     printf("Nombre modificado!");
	                     printf("%s ",lista[indice].nombre);
	                     break;
	                 case 2:
	                	 listarTipos(tipos, tamTipo);
	                	 printf("ingresar id tipo: ");
	                	 scanf("%i",&idTipo);
	                	 lista[indice].idTipo = idTipo;
                         break;
	                 case 3:
	                	 listarColor(colores, tamCol);
	                	 printf("ingresar id color: ");
	                	 scanf("%i",&idColor);
	                	 lista[indice].idColor = idColor;

	                	 printf("color modificado!");
	                     break;
	                 case 4:
	                     printf("Ingrese nueva vacunacion: ");
	                     fflush(stdin);
	                     gets(&vacunado);

	                     strcpy(lista[indice].vacunado, &vacunado);
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

int hardcodearmascotas(mascota vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;
    mascota mascotas[5] =
    {
        {0, "Juan", 11, "s",0,1000,2000},  //(Ave, Perro, Roedor, Gato, Pez)
        {0, "Miguel", 12, "s",0,1001,2001},//(Negro, Blanco, Rojo, Gris, Azul)
        {0, "Juana",13, "s",0,1002,2002},
        {0, "Andrea", 14, "n",0,1003,2003},
        {0, "Juliana", 15, "n",0,1004,2004}

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

}
int listarMascota(mascota mascotas[], int tam){

 int todoOk = 0;
    if(tam > 0 ){

        printf("   *** Listado de mascotas ***\n");
        printf("  id      nombre   \n");
        printf("------------------------------------- \n");

         for(int i= 0; i < tam; i++){
          if(!mascotas[i].isEmpty)
           printf("    %4d      %10s\n", mascotas[i].id, mascotas[i].nombre);

         }
    }
    return todoOk;
}
int bajaMascota(mascota lista[], int tam, color colores[], int tamCol,tipo tipos[], int tamTipo,cliente clientes[],int tamCL)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if( lista != NULL && tam > 0 )
    {
    	informarMascotas(lista, tam, colores, tamCol, tipos, tamTipo,clientes, tamCL);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarmascota(lista, tam, id, &indice);


            if(indice == -1)
            {
                printf("No existe un Mascota con id: %d en el sistema\n", id);
            }
            else
            {

            	listarMascota(lista, tam);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {

                	lista[indice].isEmpty = 1;

                    printf("Baja exitosa!!!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }



            todoOk = 1;
        }
    }
    return todoOk;
}


int ordenarMascotaPorTipoYNombre(mascota vec[], int tam, tipo vect[], int tamt)
{
    int todoOk = 0;
  mascota auxMascota;


    if( vec != NULL && tam >= 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if((vec[i].idTipo == vec[j].idTipo && strcmp(vec[i].nombre,vec[j].nombre) > 0)
                        ||(vec[i].idTipo != vec[j].idTipo && (vec[i].idTipo > vec[j].idTipo)))
                {
                    auxMascota = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxMascota;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}



int mascotaXColor(mascota vec[], int tam, color colores[], int tamC)
{
    int todoOk = 0;
    int flag;

    if( vec != NULL && tam > 0 && colores != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Informe mascotas x Color ***\n");
        printf("---------------------------------------------------------------\n\n");

        for(int i=0; i < tamC; i++)
        {

            printf("Color %s:\n\n", colores[i].nombreColor);
            flag = 1;

            for(int j = 0; j < tam; j++)
            {
                if( !vec[j].isEmpty && vec[j].idColor == colores[i].id)
                {
                	 printf("%20d %8s   %10s  \n",
                	vec[i].id, vec[i].nombre,
                     colores[i].nombreColor);


                }
            }
            if(flag){
                printf("No hay mascotas con ese color\n");
            }
            printf("\n---------------------------------------------------\n");

        }
        todoOk = 1;
    }
    return todoOk;

}

int promedioMascotaVacunadas(mascota vec[], int tam)
{
    int todoOk = 0;
    float acumVacunados = 0;
    int contMascotas = 0;

    float promedio = 0;


    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {if(vec[i].vacunado == 's' ||vec[i].vacunado == 'S' ){
            	acumVacunados += 1;

            }
            contMascotas++;
            }
        }
        if(contMascotas != 0)
        {
            promedio = acumVacunados / contMascotas;
        }



        system("cls");
        printf("     *** Promedio de Precios ***\n\n");

        printf("Cantidad de Mascotas: %i \n\n", contMascotas);
        printf("Promedio de vacunados: $ %.2f\n\n", promedio);

        todoOk = 1;
    }
    return todoOk;
}

int informeMascotaMenor(mascota vec[], int tam)
{
    int todoOk = 0;
    int Menor = 0;
    int flag = 1;

    if( vec != NULL && tam > 0)
    {
        system("cls");
        printf("     *** Mascota/s Menor/es ***\n\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].edad == Menor)
        {
                  printf(" %8s   %10d  \n",  vec[i].nombre,  vec[i].edad);

        }}
        if(flag)
        {
            printf("No hay mascotas en el sistema\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int mascotaXtipo(mascota vec[], int tam, tipo tipos[], int tamT)
{
    int todoOk = 0;
    int flag;

    if( vec != NULL && tam > 0 && tipos != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Informe mascotas x tipos ***\n");
        printf("---------------------------------------------------------------\n\n");

        for(int i=0; i < tamT; i++)
        {

            printf("Tipo %s:\n\n", tipos[i].descripcionr);
            flag = 1;

            for(int j = 0; j < tam; j++)
            {
                if( !vec[j].isEmpty && vec[j].idTipo == tipos[i].id)
                {
                	 printf("%20d %8s   %10s  \n",
                	vec[i].id, vec[i].nombre,
                     tipos[i].descripcionr);


                }
            }
            if(flag){
                printf("No hay mascotas con ese color\n");
            }
            printf("\n---------------------------------------------------\n");

        }
        todoOk = 1;
    }
    return todoOk;

}

int cantidadTipoColor(mascota vec[], int tam, color vecC[], int tamC, tipo vecT[], int tamT )
{
    int todoOk = 0;
    int idColor;
    int idTipo;
    int   flag = 0;

    printf("elegir color \n");

    listarColor(vecT, tamT);
    printf("ingresar id color: ");
    scanf("%i",&idColor);


    printf("elegir tipo \n");
    listarTipos(vecC, tamC);
    printf("ingresar id tipo: ");
    scanf("%i",&idTipo);


    if( vec != NULL && tam > 0  && tam > 0)
    {
        system("cls");
        printf("   *** Informe Empleados x color y tipo ***\n");
        printf("---------------------------------------------------------------\n\n");
        for(int i=0; i < tam; i++)
                {

                    printf("Color %s:\n\n", vecC[i].nombreColor);
                    printf("Tipo %s:\n\n", vecT[i].descripcionr);
                    flag = 1;
                    for(int j = 0; j < tam; j++)
                    {
                        if( !vec[j].isEmpty && vec[j].idColor == vec[i].id)
                        {
                        	 printf("%20d %8s   %10s  %10s  \n",
                        	vec[i].id, vec[i].nombre,
                             vecC[i].nombreColor,
							 vecT[i].descripcionr);


                        }
                    }
                    if(flag){
                        printf("No hay mascotas con ese color\n");
                    }
                    printf("\n---------------------------------------------------\n");

                }
                todoOk = 1;
            }
            return todoOk;

        }


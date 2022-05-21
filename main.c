#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "mascota.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "cliente.h"




#define TAM 5
#define TAMC 5
#define TAMT 5
#define TAMS 3
#define TAMTR 5
#define TAMCL 5

int main()
{setbuf(stdout, NULL);
    char salir = 'n';
    int proximoId = 1;
    int proximoIdTrabajo = 3000;
    int flagMascota = 0;
    int flagTrabajo = 0;
    cliente clientes[TAMCL];
    mascota lista[TAM];
    trabajo listaTRabajo[TAMTR];

    color colores[TAMC]=
     {
        {1000, "Negro" },
        {1001, "Blanco" },
        {1002, "Rojo" },
        {1003, "Azul" },
        {1004, "Gris" }
    };
    tipo tipos[TAMT]=
        {
            {2000, "Ave" },
            {2001, "Perro" },
            {2002, "Roedor" },
            {2003, "Gato" },
            {2004, "Pez" }
        };
    servicio servicios[TAMS]=
           {
               {20000, "Corte", 450 },
               {20001, "Deasparasitado", 800 },
               {20002, "Castrado", 600 }
            };

    inicializarMascotas(lista, TAM);
    inicializarTrabajo(listaTRabajo, TAMTR);

  //  hardcodearMascotas(lista, TAM, 10, &proximoId);

    do
    {
        switch(menuMascotas())
        {
        case 1:
            if(altaMascotas(lista, TAM, colores, TAMC, tipos, TAMT, servicios, TAMS,clientes,TAMCL, &proximoId))
            {
                printf("Mascotas cargado con exito!!!\n");
                flagMascota = 1;
            }
            else
            {
                printf("No se pudo cargar el Mascotas\n");
            }
            break;
        case 2:
             if(flagMascota == 1){
              modificacionDemascota(lista,TAM, colores, TAMC, tipos, TAMT, clientes, TAMCL);
             }
             else{
            	 printf("No hay mascotas a modificar ingrese una mascota \n");

             }
            break;

        case 3:
        	  if(flagMascota == 1){
              bajaMascota(lista, TAM);
        	  }
        	  else{
        	  printf("No hay mascotas para dar de baja ingrese una mascota \n");
        	       }
            break;

        case 4:
        	 if(flagMascota == 1){
            ordenarMascotaPorTipoYNombre(lista, TAM, tipos, TAMT);
        	informarMascotas(lista, TAM, colores, TAMC, tipos, TAMT, clientes, TAMCL);
        	 }
        	else{
            printf("No hay mascotas para informar ingrese una mascota \n");
        	}
            break;

        case 5:
            listarColor(colores, TAMC);

            break;

        case 6:
        	if(flagMascota == 1){
            altaTrabajo(listaTRabajo,TAMTR, lista, TAM,tipos, TAMT, servicios, TAMS, &proximoIdTrabajo);
            flagTrabajo = 1;
        	}else{
                printf("No hay mascotas para igresar trabajo, ingrese una mascota \n");
            	}
            break;

        case 7:
        	if(flagTrabajo == 1){
        		 informarTrabajo(listaTRabajo,TAMTR, lista, TAM, servicios, TAMS);
        	}else
        	{
        		printf("No hay  trabajo, ingrese uno \n");
        	}
            break;

        case 8:
           listarServicio(servicios, TAMS);
            break;
        case 9:
             mascotaXColor(lista,TAM, colores, TAMC);
            break;
        case 10:
             promedioMascotaVacunadas(lista, TAM);
             break;
        case 11:
             informeMascotaMenor(lista, TAM);
             break;
        case 12:
        	mascotaXtipo(lista,TAM, tipos, TAMT);
        	break;
        case 13:
            cantidadTipoColor(lista, TAM, colores, TAMC, tipos, TAMT);


            break;


        case 20:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');

    return 0;
}

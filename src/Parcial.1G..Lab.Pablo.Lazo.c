#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "color.h"
#include "tipo.h"
//#include "servicio.h"
//#include "trabajado.h"
//#include "fecha.h"

#define TAM 5
#define TAMS 5

int main()
{setbuf(stdout, NULL);
    char salir = 'n';
    int proximoId = 0001;
    mascota lista[TAM];
   /* color colores[TAMS]=
    {
        {1000, "Rojo" },
        {1001, "Amarillo" },
        {1002, "Verde" },
        {1003, "Azul" },
        {1004, "Gris" }
    };*/

    inicializarMascotas(lista, TAM);

  //  hardcodearMascotas(lista, TAM, 10, &proximoId);

    do
    {
        switch(menuMascotas())
        {
        case 1:
            if(altaMascotas(lista, TAM, &proximoId))
            {
                printf("Mascotas cargado con exito!!!\n");
            }
            else
            {
                printf("No se pudo cargar el Mascotas\n");
            }
            break;
        case 2:
         modificacionDemascota(lista,TAM, &proximoId);
            break;

        case 3:
            //modificarMascotas(lista, TAM);
            break;

        case 4:
        	 informarMascotas(lista, TAM);
            break;

        case 5:
        	//hardcodearmascotas(lista, TAM,10, &proximoId);
        	//informarMascotas(lista, TAM);
          //  listarMascotas(lista, TAM, sectores, TAMS);
            break;

        case 6:
           // listarEmpleadas(lista, TAM);
            break;

        case 7:
           // promedioSueldos(lista, TAM);
            break;

        case 8:
           // informeMascotasMayor(lista, TAM);
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

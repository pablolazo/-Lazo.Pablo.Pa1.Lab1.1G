/*
 * imputs.c
 *
 *  Created on: 20 may. 2022
 *      Author: USUARIO
 */
#include "imputs.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int primerLetraMayuscula(char palabra[], int tam)
{
  int todoOk = 0;

   if( palabra != NULL  && tam > 0)
     {

		palabra[0] = toupper(palabra[0]);


	  for (int i = 1; palabra[i] != '\0'; ++i)
	  	     {
	  		palabra[i] = tolower(palabra[i]);
	  	     }todoOk = 1;


	  todoOk = 1;

      }
   return todoOk;
   }
int validarCaracter(char palabra[]){
	int todoOk =0 ;
		int i;

		for(i=0 ; i<strlen(palabra); i++){
			if(!((palabra[i]>=65 && palabra[i]<=90) || (palabra[i]>=97 && palabra[i]<=122)))
			{
				printf("ingrese letras validas nuevamente\n");

				todoOk = 1;
			}
		}
	  return todoOk;

	}

int validarSoN(char palabra[]){
	int todoOk =0 ;
		int i;

		for(i=0 ; i<strlen(palabra); i++){
			if(!((palabra[i]==83 || palabra[i]==115 || (palabra[i]==78 || palabra[i]==110))))
			{
				printf("ingrese letras validas nuevamente\n");

				todoOk = 1;
			}
		}
	  return todoOk;

	}

int esEnteroValido(char palabra[]) {

	int todoOk =0 ;
		int i;

		for(i=0 ; i<strlen(palabra); i++){
			if(!((palabra[i]>=48 && palabra[i]<=57)))
			{
				printf("ingrese letras validas nuevamente\n");

				todoOk = 1;
			}
		}
	  return todoOk;

	}

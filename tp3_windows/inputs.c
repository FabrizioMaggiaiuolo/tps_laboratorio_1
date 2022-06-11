#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "inputs.h"

// INGRESAR DATOS

int input_GetInt(char mensaje[])
{
	int numeroIngresado;
	printf("%s \n",mensaje);
	scanf("%d",&numeroIngresado);

	return numeroIngresado;
}

float input_GetFloat(char mensaje[])
{
	float numeroIngresado;
	printf("%s \n",mensaje);
	scanf("%f",&numeroIngresado);

	return numeroIngresado;
}

char input_GetChar(char mensaje[])
{
	char charIngresado;
	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%c",&charIngresado);

	return charIngresado;
}

void input_GetString(char mensaje[],char* copiar)
{
	if(copiar != NULL)
	{
		char stringIngresado[100];
		printf("%s \n",mensaje);
		scanf("%s",stringIngresado);

		strcpy(copiar,stringIngresado);
	}
}

// VECTORES

/*
void ImprimirVectorInt(int numeros[],int tamano)
{
	int i;
	for(i= 0;i<tamano;i++)
	{
		printf("%d",numeros[i]);
	}
}

void OrdenarVectorMenorAMayor(int numeros[],int tamano)
{
	int i;
	int j;
	int aux;

	for(i = 0;i<tamano-1;i++)
	{
		for(j = i+1;j<tamano;j++)
		{
			if(numeros[i]>numeros[j])
			{
				aux = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = aux;
			}
		}
	}
}
*/

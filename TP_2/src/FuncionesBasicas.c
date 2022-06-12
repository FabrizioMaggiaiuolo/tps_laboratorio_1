#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesBasicas.h"

// INGRESAR DATOS

int GetInt(char mensaje[])
{
	int numeroIngresado;
	printf("%s \n",mensaje);
	scanf("%d",&numeroIngresado);

	return numeroIngresado;
}

float GetFloat(char mensaje[])
{
	float numeroIngresado;
	printf("%s \n",mensaje);
	scanf("%f",&numeroIngresado);

	return numeroIngresado;
}

char GetChar(char mensaje[])
{
	char charIngresado;
	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%c",&charIngresado);

	return charIngresado;
}

// CALCULAR RANGOS

int ValidarDistinto0(float numeroIngresado)
{
	int respuesta;
	respuesta = 0;
		if(numeroIngresado != 0)
		{
			respuesta = 1;
		}

	return respuesta;
}

int ValidarEntreRangos(float numeroIngresado, float menor, float mayor)
{
	int respuesta;
	respuesta = 0;

		if(numeroIngresado >= menor && numeroIngresado <= mayor)
		{
			respuesta = 1;
		}

	return respuesta;
}

int ValidarAfueraRangos(float numeroIngresado, float menor, float mayor)
{
	int respuesta;
	respuesta = 0;

		if(numeroIngresado < menor || numeroIngresado > mayor)
		{
			respuesta = 1;
		}

	return respuesta;
}

// CALCUALR LAS CARACTERISTICAS DE LOS DATOS

int CalcularSignoNumero(float numeroIngresado)
{
	int respuesta;
	respuesta = 0;

	if(numeroIngresado > 0)
	{
		respuesta = 1;
	}
	else
	{
		if(numeroIngresado < 0)
		{
			respuesta = -1;
		}
	}

	return respuesta;
}


int CalcularParidadNumero(int numeroIngresado)
{
	int respuesta;
	respuesta = 0;

	int resto;
	resto = numeroIngresado %2;

	if(resto == 0)
	{
		respuesta = 1;
	}
	else
	{
		if(resto == 1)
		{
			respuesta = -1;
		}
	}

	return respuesta;
}

// VECTORES

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

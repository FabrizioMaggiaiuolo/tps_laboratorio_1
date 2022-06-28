#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Passenger.h"
#include "inputs.h"

void IngresoPrecio(char precio[])
{
	input_GetString("Ingrese el precio",precio);
	while(esFlotante(precio) == 0)
	{
		input_GetString("El numero ingresado no es valido",precio);
	}
}

int IngresoTipoPasajero(char tipoPasajero[])
{
	int retorno;
	do
	{
		printf("Ingrese alguna de las siguientes opciones para el tipo de pasajero\n");
		printf("1. EconomyClass\n");
		printf("2. ExecutiveClass\n");
		printf("3. FirstClass\n");
		retorno = input_GetInt("");
	}
	while(retorno < 1 || retorno > 3);

	retorno--;

	if(retorno == 0)
	{
	strcpy(tipoPasajero, "EconomyClass");
	}
	else
	{
		if(retorno == 1)
		{
			strcpy(tipoPasajero, "ExecutiveClass");
		}
		else
		{
			 if(retorno == 2)
			 {
				 strcpy(tipoPasajero, "FirstClass");
			 }
		}
	}
	return retorno;
}

void IngresoCodigoVuelo(char codigoVuelo[])
{
	do
	{
		input_GetString("Ingrese el codigo de vuelo", codigoVuelo);
	} while (strlen(codigoVuelo) != 7);
	stringtoupper(codigoVuelo);
}

void IngresoEstadoVuelo(char estadoVuelo[])
{
	int retorno;
	do
	{
		printf("Ingrese alguna de las siguientes opciones para el tipo de pasajero\n");
		printf("1. En Horario\n");
		printf("2. Aterrizando\n");
		printf("3. En Vuelo\n");
		printf("4. Demorado\n");
		retorno = input_GetInt("");
	}
	while(retorno < 1 || retorno > 4);


	if(retorno == 1)
	{
	strcpy(estadoVuelo, "En Horario");
	}
	else
	{
		if(retorno == 2)
		{
			strcpy(estadoVuelo, "En Vuelo");
		}
		else
		{
			 if(retorno == 3)
			 {
				 strcpy(estadoVuelo, "FirstClass");
			 }
			 else
			 {
				 if(retorno == 4)
				 {
					 strcpy(estadoVuelo,"Demorado");
				 }
			 }
		}
	}
}

/*
Maggiaiuolo Fabrizio Julián
Div C
TP_2
Legajo 112952
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "funcionesExtras.h"

#define TAM 20
#define TAMF 3

int main(void) {

	setbuf(stdout,NULL);

	sFlights listFlights[TAMF];

	sPassenger pasajeros[TAM];

	initPassengers(pasajeros,TAM);

	initFlights(listFlights,TAMF);

	int IdIncremental;
	IdIncremental = 0;
	int* pIdIncremental;

	pIdIncremental = &IdIncremental;

	int opcion;
	opcion = 0;

	int banderaPrimeraOpcion;
	banderaPrimeraOpcion = 0;

	int* flagPrimeraOpcion;
	flagPrimeraOpcion = &banderaPrimeraOpcion;

	while(opcion != 6)
	{
		printf("Ingrese alguna de las siguientes opciones: \n");
		printf("1. Ingresar un pasajero \n");
		printf("2. Modificar un pasajero \n");
		printf("3. Eliminar pasajero \n");
		printf("4. Informes\n");
		printf("5. Carga Forzada\n");
		printf("6. Salir\n");
		scanf("%d",&opcion);

		if(*flagPrimeraOpcion == 0)
		{
			if(opcion != 2 && opcion != 3 && opcion != 4)
			{
				*flagPrimeraOpcion = 1;
			}
		}

		opcion = ValidarOpcionIngresada(opcion,flagPrimeraOpcion);

		EjecutarOpcion(opcion,pasajeros,TAM,pIdIncremental,listFlights,TAMF);

	}

	printf("Gracias por usar nuestro programa, vuelva pronto!!!");

}

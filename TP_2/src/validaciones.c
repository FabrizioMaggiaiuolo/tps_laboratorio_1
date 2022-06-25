#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "funcionesExtras.h"

int ValidarOpcionIngresada(int opcion,int* flagPrimeraOpcion)
{
	while (opcion<1 || opcion>6 || *flagPrimeraOpcion == 0 )
	{
		printf("ERROR \n");
		printf("Ingrese alguna de las siguientes opciones: \n");
		printf("1. Ingresar un pasajero \n");
		printf("2. Modificar un pasajero \n");
		printf("3. Eliminar pasajero \n");
		printf("4. Informes\n");
		printf("5. Carga Forzada\n");
		printf("6. Salir\n");
		opcion = input_GetInt("");

		if(*flagPrimeraOpcion == 0)
		{
			if(opcion != 2 && opcion != 3 && opcion != 4)
			{
				*flagPrimeraOpcion = 1;
			}
		}
	}
	return opcion;
}

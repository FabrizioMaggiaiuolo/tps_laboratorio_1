/*
Maggiaiuolo Fabrizio Julián
Div C
TP_1
*/

#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	float x; //Kilometros
	x = 0;
	float y; //Aerolineas
	y = 0;
	float z; //Latam
	z = 0;
	float precios[9];

	int respuesta;
	respuesta = 0;

	int calculado;
	calculado = 0;

	while(respuesta != 6)
	{
		respuesta = ImprimirMenu(respuesta,x,z,y);


		switch(respuesta)
		{

		case 1:
			system("cls");
			x = IngresoFloat("Ingrese la cantidad de kilometros del viaje");
			system("cls");
			break;

		case 2:
			system("cls");
			y = IngresoFloat("Ingrese el precio de Aerolineas: ");
			z = IngresoFloat("Ingrese el precio de Latam: ");
			system("cls");
			break;

		case 3:
			calculado = CalcularCostos(x,z,y,precios,calculado);
			break;

		case 4:
			InfomarResultados(precios,calculado,x,z,y);
			break;

		case 5:
			x = 7090;
			z = 162965;
			y = 159339;
			calculado = CalcularCostos(x,z,y,precios,calculado);
			InfomarResultados(precios,calculado,x,z,y);
			break;
		case 6:
			respuesta = 6;
			printf("Gracias por usar nuestro programa!!!");
			break;

		}

	}

}

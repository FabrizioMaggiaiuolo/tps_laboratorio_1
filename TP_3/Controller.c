#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "controlId.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"
#include "ingresoDeDatos.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int respuesta;
	respuesta = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			FILE* pFile =  fopen(path,"r");

			parser_PassengerFromText(pFile, pArrayListPassenger);

			fclose(pFile);

			respuesta = 1;
		}
	}

	return respuesta;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int respuesta;
	respuesta = 0;
	if(path != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			FILE* pFile;
			pFile = fopen(path,"rb");

			parser_PassengerFromBinary(pFile, pArrayListPassenger);

			fclose(pFile);

			respuesta = 1;
		}
	}

	return respuesta;
}

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int index;
	index = 0;

	if(pArrayListPassenger != NULL)
	{
		Passenger* pasajeroNuevo;
		char id[10];
		char nombre[50];
		char apellido[50];
		char precio[50];
		char tipoPasajero[15];
		char codigoVuelo[8];
		char estadoVuelo[20];

		LeerIdStr(id);
		SumarId();
		input_GetSinNumeros("Ingrese el nombre",nombre);
		input_GetSinNumeros("Ingrese el apellido",apellido);
		IngresoPrecio(precio);
		IngresoTipoPasajero(tipoPasajero);
		IngresoCodigoVuelo(codigoVuelo);
		IngresoEstadoVuelo(estadoVuelo);


		pasajeroNuevo = Passenger_newParametros(id, nombre, tipoPasajero, apellido, codigoVuelo, precio, estadoVuelo);

		ll_add(pArrayListPassenger, pasajeroNuevo);

		index = 1;
	}


    return index;
}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int index;
	index = 0;

	int id;
	if(pArrayListPassenger != NULL)
	{
		do
		{
			id = input_GetInt("Ingrese el id del pasajero que quiere modificar");
		} while (id < 1 || id > ll_len(pArrayListPassenger));

		Passenger* pasajeroAux;

		int i;
		i = 0;
		do
		{
			pasajeroAux = (Passenger*)ll_get(pArrayListPassenger, i);
			i++;
		} while (pasajeroAux->id != id);


		char precio[50];
		char tipoPasajero[15];

		int opcion;

		do
		{
			printf("1- Modificar el nombre\n");
			printf("2- Modificar el apellido\n");
			printf("3- Modificar el precio\n");
			printf("4- Modificar la clase del pasajero\n");
			printf("5- Modificar el codigo de vuelo\n");
			printf("6- Modificar el estado del vuelo\n");
			opcion = input_GetInt("Elija una de las opciones anteriores");
		} while (opcion < 1 && opcion > 6);

		switch(opcion)
		{
		case 1:
			//nombre
			input_GetSinNumeros("Ingrese el nuevo nombre", pasajeroAux->nombre);
			break;
		case 2:
			//apellido
			input_GetSinNumeros("Ingrese el nuevo apellido", pasajeroAux->apellido);
			break;
		case 3:
			//precio
			IngresoPrecio(precio);
			Passenger_setPrecio(pasajeroAux, atof(precio));
			break;
		case 4:
			//clase del pasajero
			pasajeroAux->tipoPasajero = IngresoTipoPasajero(tipoPasajero);
			break;
		case 5:
			//codigo del vuelo
			IngresoCodigoVuelo(pasajeroAux->codigoVuelo);
			break;
		case 6:
			//estado del vuelo
			IngresoEstadoVuelo(pasajeroAux->estadoVuelo);
			break;
		}

		index = 1;

	}

    return index;
}


int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int index;
	index = 0;

	if(pArrayListPassenger != NULL)
	{
		int id;
		do
		{
			id = input_GetInt("Ingrese el id del pasajero que quiere eliminar");
		} while (id < 1 || id > ll_len(pArrayListPassenger));

		Passenger* pasajeroAux;

		int i;
		i = 0;
		do
		{
			pasajeroAux = (Passenger*)ll_get(pArrayListPassenger, i);
			i++;
		} while (pasajeroAux->id != id);

		char confirmacion;
		do
		{
			printf("Esta seguro que quiere eliminar a: \n");
			Passenger_printUno(pasajeroAux);
			confirmacion = input_GetChar("Ingrese S (si) o N (no)");

		} while (confirmacion != 's' && confirmacion != 'S' && confirmacion != 'n' && confirmacion != 'N');

		if(confirmacion == 's' || confirmacion == 'S')
		{
			ll_pop(pArrayListPassenger, i-1);
			Passenger_delete(pasajeroAux);
			index = 1;

		}
	}

	return index;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{

	int index;
	index = 0;

	int cantidad;
	cantidad = ll_len(pArrayListPassenger);
	Passenger* aux;

	if(pArrayListPassenger != NULL)
	{
		for(int i = 0;i<cantidad; i++)
		{
			aux = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_printUno(aux);
		}
	}
    return index;
}


int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int index;
	index = 0;

	int opcion;

	if(pArrayListPassenger != NULL)
	{
		printf("Ingrese alguna de las siguientes opciones para el ordenamiento\n");
		printf("1. Ordenar por id\n");
		printf("2. Ordenar por nombre\n");
		opcion = input_GetInt("");

		while(opcion < 1 || opcion > 2)
		{
			opcion = input_GetInt("Ingrese una opcion valida");
		}

		printf("Ordenando...\n");
		switch(opcion)
		{
		case 1:
			ll_sort(pArrayListPassenger, Passenger_compareById, 1);
			break;
		case 2:
			ll_sort(pArrayListPassenger, Passenger_compareByName, 1);
			break;
		}

		index = 1;
	}

    return index;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int index;
	index = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pFile =  fopen(path,"w");

		int cantidad;
		cantidad = ll_len(pArrayListPassenger);

		Passenger* pasajeroAux;

		int id;
		char nombre[50];
		char apellido[50];
		float precio;
		int tipoPasajero;
		char codigoVuelo[10];
		char estadoVuelo[20];

		fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");

		for(int i = 0;i<cantidad;i++)
		{
			pasajeroAux = ll_get(pArrayListPassenger, i);

			Passenger_getId(pasajeroAux, &id);
			Passenger_getNombre(pasajeroAux, nombre);
			Passenger_getApellido(pasajeroAux, apellido);
			Passenger_getPrecio(pasajeroAux, &precio);
			Passenger_getTipoPasajero(pasajeroAux, &tipoPasajero);
			Passenger_getCodigoVuelo(pasajeroAux, codigoVuelo);
			Passenger_getEstadoVuelo(pasajeroAux, estadoVuelo);

			fprintf(pFile,"%d,%s,%s,%f,%s,",id,nombre,apellido,precio,codigoVuelo);

			if(tipoPasajero == 0)
			{
				fprintf(pFile,"EconomyClass");
			}
			else
			{
				if(tipoPasajero == 1)
				{
					fprintf(pFile,"ExecutiveClass");
				}
				else
				{
					fprintf(pFile,"FirstClass");
				}
			}

			fprintf(pFile,",%s\n",estadoVuelo);
		}

		fclose(pFile);

		index = 1;
	}

	return index;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int index;
	index = 0;

	Passenger* pasajeroAux;

	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");

		int largo;
		largo = ll_len(pArrayListPassenger);

		for(int i = 0; i< largo;i++)
		{

			pasajeroAux = ll_get(pArrayListPassenger, i);

			fwrite(pasajeroAux,sizeof(Passenger),1,pFile);

		}

		fclose(pFile);

		index = 1;
	}

    return index;
}


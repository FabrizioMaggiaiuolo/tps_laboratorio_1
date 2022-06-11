#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "controlId.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"

void menuModificaciones(void)
{
	printf("1- Modificar el nombre\n");
	printf("2- Modificar el apellido\n");
	printf("3- Modificar el precio\n");
	printf("4- Modificar la clase del pasajero\n");
	printf("5- Modificar el codigo de vuelo\n");
	printf("6- Modificar el estado del vuelo\n");
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int respuesta;
	respuesta = 0;
	if(path != NULL)
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

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
		input_GetString("Ingrese el nombre",nombre);
		input_GetString("Ingrese el apellido",apellido);
		input_GetString("Ingrese el precio",precio);
		input_GetString("Ingrese el tipoPasajero",tipoPasajero);
		input_GetString("Ingrese el codigoVuelo",codigoVuelo);
		input_GetString("Ingrese el estadoVuelo",estadoVuelo);


		pasajeroNuevo = Passenger_newParametros(id, nombre, tipoPasajero, apellido, codigoVuelo, precio, estadoVuelo);

		ll_add(pArrayListPassenger, pasajeroNuevo);
	}


    return index;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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

		} while (ll_get(pArrayListPassenger, id-1) == NULL);


		Passenger* pasajeroAux;

		pasajeroAux = ll_get(pArrayListPassenger, id-1);

		int opcion;

		do
		{
			menuModificaciones();
			opcion = input_GetInt("Elija una de las opciones anteriores");
		} while (opcion < 1 && opcion > 6);

		switch(opcion)
		{
		case 1:
			//nombre
			input_GetString("Ingrese el nuevo nombre", pasajeroAux->nombre);
			ll_set(pArrayListPassenger, id-1, pasajeroAux);
			break;
		case 2:
			//apellido
			input_GetString("Ingrese el nuevo apellido", pasajeroAux->apellido);
			ll_set(pArrayListPassenger, id-1, pasajeroAux);
			break;
		case 3:
			//precio
			Passenger_setPrecio(pasajeroAux, input_GetFloat("Ingrese el nuevo precio"));
			ll_set(pArrayListPassenger, id-1, pasajeroAux);
			break;
		case 4:
			//clase del pasajero
			Passenger_setPrecio(pasajeroAux, input_GetFloat("Ingrese el nuevo precio"));
			ll_set(pArrayListPassenger, id-1, pasajeroAux);
			break;
		case 5:
			//codigo del vuelo
			input_GetString("Ingrese el nuevo codigo de vuelo", pasajeroAux->apellido);
			ll_set(pArrayListPassenger, id-1, pasajeroAux);
			break;
		case 6:
			//estado del vuelo
			input_GetString("Ingrese el nuevo apellido", pasajeroAux->apellido);
			ll_set(pArrayListPassenger, id-1, pasajeroAux);
			break;
		}

	}

    return index;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 * 1 si se elemino correctamente y 0 si no se elimino
 */
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

		} while (ll_get(pArrayListPassenger, id-1) == NULL);

		Passenger* pasajeroAux;
		pasajeroAux = ll_get(pArrayListPassenger, id-1);


		char confirmacion;
		do
		{
			printf("Esta seguro que quiere eliminar a: \n");
			Passenger_printUno(pasajeroAux);
			confirmacion = input_GetChar("Ingrese S (si) o N (no)");

		} while (confirmacion != 's' && confirmacion != 'S' && confirmacion != 'n' && confirmacion != 'N');

		if(confirmacion == 's' || confirmacion == 'S')
		{
			Passenger_delete(pasajeroAux);
			ll_pop(pArrayListPassenger, id-1);
			index = 1;

		}
	}

	return index;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{

	int cantidad;
	cantidad = ll_len(pArrayListPassenger);
	Passenger* aux;

	for(int i = 0;i<cantidad; i++)
	{
		aux = (Passenger*) ll_get(pArrayListPassenger, i);
		Passenger_printUno(aux);
	}
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{

	ll_sort(pArrayListPassenger, Passenger_compareByName, 1);

    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int respuesta;
	respuesta = 0;
	if(path != NULL)
	{
		if(pArrayListPassenger != NULL)
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

			fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight");

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

			respuesta = 1;
		}
	}

	return respuesta;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	Passenger* pasajeroAux;

	FILE* pFile;
	pFile = fopen(path,"wb");

	int largo;
	largo = ll_len(pArrayListPassenger);

	for(int i = 0; i< largo;i++)
	{

		pasajeroAux = ll_get(pArrayListPassenger, i);

		fwrite(pasajeroAux,sizeof(Passenger),1,pFile);

	}

	fclose(pFile);
    return 1;
}


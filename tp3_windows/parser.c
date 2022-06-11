#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		char id[20];
		char nombre[100];
		char apellido[100];
		char precio[100];
		char estado[100];
		char codigo[100];
		char tipoPasajero[100];
		char falsaLectura[1000];
		Passenger* unPasajero;

		fscanf(pFile,"%s",falsaLectura);

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,tipoPasajero,estado);
			unPasajero = Passenger_newParametros(id, nombre, tipoPasajero, apellido, codigo, precio, estado);
			ll_add(pArrayListPassenger,unPasajero);
		}
	}
    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		int leyo;
		Passenger pasajero;
		Passenger* unPasajero;
		do
		{
			leyo = fread(&pasajero,sizeof(Passenger),1,pFile);

			if(leyo == 1)
			{
				unPasajero = &pasajero;
				ll_add(pArrayListPassenger,unPasajero);
			}
		}
		while(!feof(pFile));
	}
    return 1;
}

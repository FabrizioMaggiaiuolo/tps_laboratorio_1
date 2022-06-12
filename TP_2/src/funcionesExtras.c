#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesBasicas.h"
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "funcionesExtras.h"

void initFlights(sFlights listFlights[],int lenFlights)
{
	strcpy(listFlights[0].flycode ,"f200");
	listFlights[0].statusFlight = 1;

	strcpy(listFlights[1].flycode ,"f201");
	listFlights[1].statusFlight = 1;

	strcpy(listFlights[2].flycode ,"f202");
	listFlights[2].statusFlight = 0;
}

void EjecutarOpcion(int opcion,sPassenger list[],int len,int* pIdIncremental,sFlights listFlights[],int lenFlights)
{
	switch(opcion)
	{
	case 1:
		PedidaDeDatos(list,len,pIdIncremental,listFlights,lenFlights);
		break;
	case 2:
		ModificarDatos(list,len);
		break;
	case 3:
		EliminarPasajero(list,len);
		break;
	case 4:
		Listados(list,len,listFlights,lenFlights);
		break;
	case 5:
		cargaForzada(list,len,pIdIncremental);
		break;
	}
}

int buscarLibre(sPassenger list[],int len)
{
	int index;
	index = -1;

	for(int i = 0;i<len; i++)
	{
		if(list[i].isEmpty == 1)
		{
			index = i;
			break;
		}
	}
	return index;
}

void PedidaDeDatos(sPassenger list[],int len,int* pIdIncremental,sFlights listFlights[],int lenFlights)
{
	int r;
	char nombre[51];
	printf("Ingrese su nombre \n");
	scanf("%s",nombre);

	char apellido[51];
	printf("Ingrese su apellido \n");
	scanf("%s",apellido);

	float precio;
	precio = GetFloat("Ingrese el precio del vuelo");

	char codigoVuelo[10];
	printf("Ingrese una de las siguientes opciones para el codigo de vuelo \n");
	int i;
	for(i = 1;i<lenFlights+1;i++)
	{
		printf("%d. %s",i,listFlights[i].flycode);
	}
	scanf("%d",&i);
	strcpy(codigoVuelo,listFlights[i-1].flycode);

	int tipoPasajero;
	tipoPasajero = GetInt("Ingrese el tipo de pasajero (1.Turista 2.Ejecutivo 3.First class)");


	r = addPassengers(list,len,*pIdIncremental,nombre,apellido, precio, tipoPasajero,codigoVuelo);
	if(r == 0)
	{
		*pIdIncremental = *pIdIncremental+1;
	}
	else
	{
		printf("No se pudo cargar el pasajero correctamente, se llego al maximo de pasajero o hubo un error en la carga\n");
	}


}


void ModificarDatos(sPassenger list[],int len)
{
	int idIngresado;
	idIngresado = GetInt("Porfavor ingrese el id del pasajero que quiere modificar");

	int index;
	index = findPassengerById(list,len,idIngresado);

	if(index != -1)
	{
		int opcion;
		sPassenger auxiliar;
		auxiliar = list[index];
		printf("Ingrese una de las siguientes opciones para modificar:\n");
		printf("1. Nombre\n");
		printf("2. Apellido\n");
		printf("3. Precio\n");
		printf("4. Tipo de pasajero\n");
		printf("5. Codigo de vuelo\n");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			printf("El nombre actual es: %s\n",list[index].name);
			printf("Ingrese el nuevo nombre \n");
			scanf("%s",auxiliar.name);
			break;
		case 2:
			printf("El apellido actual es: %s\n",list[index].lastName);
			printf("Ingrese el nuevo apellido \n");
			scanf("%s",auxiliar.lastName);
			break;
		case 3:
			printf("El precio actual es: %f\n",list[index].price);
			auxiliar.price = GetFloat("Ingrese el nuevo precio");
			break;
		case 4:
			printf("El tipo de pasajero actual es: %d\n",list[index].typePassenger);
			auxiliar.typePassenger = GetInt("Ingrese el nuevo tipo de pasajero");
			break;
		case 5:
			printf("El codigo de vuelo actual es: %s\n",list[index].flycode);
			printf("Ingrese el nuevo codigo de vuelo \n");
			scanf("%s",auxiliar.flycode);
			break;
		}
		list[index] = auxiliar;

	}
	else
	{
		printf("No se encontro ningun pasajero con ese id\n");
	}

}

void EliminarPasajero(sPassenger list[],int len)
{
	int idIngresado;
	idIngresado = GetInt("Porfavor ingrese el id del pasajero que quiere eliminar");

	int index;
	index = removePassenger(list,len,idIngresado);
	if(index != -1)
	{
		printf("Se elmino correctamente");
	}
	else
	{
		printf("Hubo un error al eliminar al pasajer");
	}
}

void Listados(sPassenger list[],int len,sFlights listFlights[],int lenFlights)
{
	int opcion;
	printf("Ingrese una de las siguientes opciones para los listados: \n");
	printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero\n");
	printf("2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n");
	printf("3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
	scanf("%d",&opcion);

	switch(opcion)
	{
	case 1:
		ListadoApellidoTipo(list,len,listFlights,lenFlights);
		break;
	case 2:
		TotalPromedioPrecios(list,len);
		break;
	case 3:
		ListadoCodigoVueloActivo(list,len,listFlights,lenFlights);
		break;
	}
}

void ListadoApellidoTipo(sPassenger list[],int len,sFlights listFlights[],int lenFlights)
{
	sortPassengers(list,len,1);
	sortPassengersByType(list,len,1);
	printPassengers(list,len,listFlights,lenFlights);
}

void TotalPromedioPrecios(sPassenger list[],int len)
{
	int contadorPasajero;
	contadorPasajero = 0;
	float acumuladorPrecios;
	acumuladorPrecios = 0;
	float promedio;
	int contadorPasajerosSuperanPromedio;
	contadorPasajerosSuperanPromedio = 0;

	for(int i = 0;i<len;i++)
	{
		if(list[i].isEmpty == 0)
		{
			contadorPasajero++;
			acumuladorPrecios += list[i].price;
		}
	}

	promedio = acumuladorPrecios/(float)contadorPasajero;

	for(int i = 0;i<len;i++)
	{
		if(list[i].isEmpty == 0)
		{
			if(list[i].price > promedio)
			{
				contadorPasajerosSuperanPromedio++;
			}
		}
	}

	printf("El total de los precios es: %.4f \nEl promedio de los precios es: %.4f \nLa cantidad de pasajeros que superan este promedio es: %d \n",acumuladorPrecios,promedio,contadorPasajerosSuperanPromedio);

}

void ListadoCodigoVueloActivo(sPassenger list[],int len,sFlights listFlights[],int lenFlights)
{
	sPassenger listAux[len];
	int aux;
	aux = 0;
	sortPassengersByCode(list,len,1);

	for(int i = 0;i<len;i++)
	{
		if(list[i].isEmpty == 0)
		{
			for(int j = 0;j<lenFlights;j++)
			{
				if(strcmp(list[i].flycode,listFlights[j].flycode) == 0)
				{
					if(listFlights[j].statusFlight == 1)
					{
						listAux[aux] =list[i];
						aux++;
						break;
					}
				}

			}
		}
	}
	printPassengers(listAux,aux,listFlights,lenFlights);
}

void cargaForzada(sPassenger list[],int len,int* pIdIncremental)
{
	int index;
	index = buscarLibre(list,len);

	list[index].id = *pIdIncremental;
	strcpy(list[index].name,"Julian");
	strcpy(list[index].lastName,"Gonzalez");
	list[index].price = 10000;
	strcpy(list[index].flycode,"f200");
	list[index].typePassenger = 0;
	list[index].isEmpty = 0;

	*pIdIncremental = *pIdIncremental +1;

	list[index+1].id = *pIdIncremental;
	strcpy(list[index+1].name,"Kyara");
	strcpy(list[index+1].lastName,"Gonzalez");
	list[index+1].price = 10000;
	strcpy(list[index+1].flycode,"f200");
	list[index+1].typePassenger = 0;
	list[index+1].isEmpty = 0;

	*pIdIncremental = *pIdIncremental +1;

	list[index+2].id = *pIdIncremental;
	strcpy(list[index+2].name,"Marcelo");
	strcpy(list[index+2].lastName,"Bianchi");
	list[index+2].price = 15000;
	strcpy(list[2].flycode,"f201");
	list[index+2].typePassenger = 1;
	list[index+2].isEmpty = 0;

	*pIdIncremental = *pIdIncremental +1;

	list[index+3].id = *pIdIncremental;
	strcpy(list[index+3].name,"Francisco");
	strcpy(list[index+3].lastName,"Gomez");
	list[index+3].price = 22000;
	strcpy(list[index+3].flycode,"f200");
	list[index+3].typePassenger = 2;
	list[index+3].isEmpty = 0;

	*pIdIncremental = *pIdIncremental +1;

	list[index+4].id = *pIdIncremental;
	strcpy(list[index+4].name,"Martin");
	strcpy(list[index+4].lastName,"Gonzalez");
	list[index+4].price = 21000;
	strcpy(list[index+4].flycode,"f201");
	list[index+4].typePassenger = 2;
	list[index+4].isEmpty = 0;

	*pIdIncremental = *pIdIncremental +1;

	list[index+5].id = *pIdIncremental;
	strcpy(list[index+5].name,"Pilar");
	strcpy(list[index+5].lastName,"Gimenez");
	list[index+5].price = 20000;
	strcpy(list[index+5].flycode,"f202");
	list[index+5].typePassenger = 2;
	list[index+5].isEmpty = 0;

	*pIdIncremental = *pIdIncremental +1;

	list[index+6].id = *pIdIncremental;
	strcpy(list[index+6].name,"Milagros");
	strcpy(list[index+6].lastName,"Gimenez");
	list[index+6].price = 15000;
	strcpy(list[index+6].flycode,"f202");
	list[index+6].typePassenger = 1;
	list[index+6].isEmpty = 0;

	*pIdIncremental = *pIdIncremental +1;
}



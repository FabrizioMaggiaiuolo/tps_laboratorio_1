#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesBasicas.h"
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "funcionesExtras.h"

int initPassengers(sPassenger list[],int len)
{
	int index;
	index = -1;
	if(len < 2001)
	{
		for(int i = 0; i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		index = 0;
	}

	return index;

}

int addPassengers(sPassenger list[],int len,int id,char name[],char lastName[],float price,int typePassenger,char flycode[])
{
	int index;
	index = 0;

	int posicionLibre;
	posicionLibre = buscarLibre(list,len);
		if(posicionLibre != -1)
		{
			list[posicionLibre].id = id;
			strcpy(list[posicionLibre].name,name);
			strcpy(list[posicionLibre].lastName,lastName);
			list[posicionLibre].price = price;
			list[posicionLibre].typePassenger = typePassenger;
			strcpy(list[posicionLibre].flycode,flycode);
			list[posicionLibre].isEmpty = 0;
		}
		else
		{
			index = -1;
		}

	return index;
}

int findPassengerById(sPassenger list[],int len,int id)
{
	int index;
	index = -1;

	for( int i = 0;i<len;i++)
	{
		if(list[i].isEmpty == 0)
		{
			if(list[i].id == id)
			{
				index = i;
			}
		}
	}

	return index;
}
int removePassenger(sPassenger list[],int len,int id)
{
	int index;

	index = findPassengerById(list,len,id);
	if(index != -1)
	{
		list[index].isEmpty = 1;
		index = 0;
	}


	return index;
}

void printPassengers(sPassenger list[],int len,sFlights listFlights[],int lenFlights)
{
	printf("\n");
	printf("Nombre    Apellido      Precio       Numero de Vuelo      Estado de Vuelo     Tipo de pasajero \n");
	for(int i = 0;i<len;i++)
	{
		if(list[i].isEmpty == 0)
		{
			printf("%s  %10s 	%6.2f 	%8s",list[i].name,list[i].lastName,list[i].price,list[i].flycode);
			for(int j = 0; j<lenFlights;j++)
			{
				if(strcmp(list[i].flycode,listFlights[j].flycode ) == 0)
				{
					if(listFlights[j].statusFlight == 1)
					{
						printf("		ACTIVO");
					}
					else
					{
						printf("		INACTIVO");
					}
				}
			}
			if(list[i].typePassenger == 0)
			{
				printf("		Turista \n");
			}
			else
			{
				if(list[i].typePassenger == 1)
				{
					printf("		Ejecutivo \n");
				}
				else
				{
					printf("		First class \n");
				}
			}
		}
	}
	printf("\n");
}

int sortPassengers (sPassenger list[],int len,int order)
{
	int index;
	index = 0;

	sPassenger auxliar;
	if(order == 1)
	{
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if(strcmp(list[i].lastName,list[j].lastName)>0)
				{
					auxliar = list[i];
					list[i] = list[j];
					list[j] = auxliar;
				}
			}
		}
	}
	else
	{
		if(order == 0)
		{
			for(int i=len;i>1;i--)
			{
				for(int j=i-1;j>0;j--)
				{
					if(strcmp(list[i].lastName,list[j].lastName)>0)
					{
						auxliar = list[i];
						list[i] = list[j];
						list[j] = auxliar;
					}
				}
			}
		}
		else
		{
			index = -1;
		}
	}

	return index;
}


int sortPassengersByCode(sPassenger list[],int len,int order)
{
	int index;
	index = 0;

	sPassenger auxliar;
	if(order == 1)
	{
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if(strcmp(list[i].flycode,list[j].flycode)>0)
				{
					auxliar = list[i];
					list[i] = list[j];
					list[j] = auxliar;
				}
			}
		}
	}
	else
	{
		if(order == 0)
		{
			for(int i=len;i>1;i--)
			{
				for(int j=i-1;j>0;j--)
				{
					if(strcmp(list[i].flycode,list[j].flycode)>0)
					{
						auxliar = list[i];
						list[i] = list[j];
						list[j] = auxliar;
					}
				}
			}
		}
		else
		{
			index = -1;
		}
	}

	return index;
}
int sortPassengersByType(sPassenger list[],int len,int order)
{
	int index;
		index = 0;

		sPassenger auxliar;
		if(order == 1)
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmp(list[i].lastName,list[j].lastName)==0)
					{
						if(list[i].typePassenger<list[j].typePassenger)
						{
							auxliar = list[i];
							list[i] = list[j];
							list[j] = auxliar;
						}
					}
				}
			}
		}
		else
		{
			if(order == 0)
			{
				for(int i=len;i>1;i--)
				{
					for(int j=i-1;j>0;j--)
					{
						if(list[i].typePassenger<list[j].typePassenger)
						{
							auxliar = list[i];
							list[i] = list[j];
							list[j] = auxliar;
						}
					}
				}
			}
			else
			{
				index = -1;
			}
		}

		return index;
}

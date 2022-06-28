#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

Passenger* Passenger_new()
{
	return (Passenger*) malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellido, char* codigo,char* precio,char* estado)
{
	Passenger* pasajero;
	pasajero = Passenger_new();
	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL && apellido != NULL && codigo != NULL && precio != NULL && estado != NULL)
	{
		Passenger_setId(pasajero,atoi(idStr));
		Passenger_setNombre(pasajero,nombreStr);
		Passenger_setApellido(pasajero, apellido);
		Passenger_setPrecio(pasajero, atof(precio));
		Passenger_setCodigoVuelo(pasajero, codigo);
		Passenger_setEstadoVuelo(pasajero, estado);


		if(strcmp(tipoPasajeroStr,"EconomyClass") == 0)
		{
			Passenger_setTipoPasajero(pasajero,0);
		}
		else
		{
			if(strcmp(tipoPasajeroStr,"ExecutiveClass") == 0)
			{
				Passenger_setTipoPasajero(pasajero,1);
			}
			else
			{
				 if(strcmp(tipoPasajeroStr,"FirstClass") == 0)
				 {
					 Passenger_setTipoPasajero(pasajero,2);
				 }
			}
		}

	}


	return pasajero;
}

void Passenger_printUno(Passenger* this)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoVuelo[20];

	Passenger_getId(this, &id);
	Passenger_getNombre(this, nombre);
	Passenger_getApellido(this, apellido);
	Passenger_getPrecio(this, &precio);
	Passenger_getTipoPasajero(this, &tipoPasajero);
	Passenger_getCodigoVuelo(this, codigoVuelo);
	Passenger_getEstadoVuelo(this, estadoVuelo);

	printf("%4d %15s %15s %10.2f",id,nombre,apellido,precio);
	if(tipoPasajero == 0)
	{
		printf("%18s","EconomyClass");
	}
	else
	{
		if(tipoPasajero == 1)
		{
			printf("%18s","ExecutiveClass");
		}
		else
		{
			printf("%18s","FirstClass");
		}
	}
	printf("%15s %15s\n",codigoVuelo,estadoVuelo);
}

void Passenger_delete(Passenger* this)
{
	free(this);
}

// Comparaciones

int Passenger_compareByName(void* p1,void *p2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	return strcmp(pasajero1->nombre,pasajero2->nombre);
}

int Passenger_compareById(void* p1,void *p2)
{
	int retorno;
	retorno = 0;
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(pasajero1->id > pasajero2->id)
	{
		retorno = 1;
	}
	else
	{
		if(pasajero1->id < pasajero2->id)
		{
			retorno = -1;
		}
	}

	return retorno;
}

//ID

int Passenger_setId(Passenger* this,int id)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(id > 0)
		{
			this->id = id;
			respuesta = 1;
		}
	}

	return respuesta;
}
int Passenger_getId(Passenger* this,int* id)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		*id = this->id;
		respuesta = 1;
	}

	return respuesta;
}

//NOMBRE

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(nombre != NULL)
		{
			strcpy(this->nombre,nombre);
			respuesta = 1;
		}
	}

	return respuesta;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		respuesta = 1;
	}

	return respuesta;
}

//APELLIDO

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(apellido != NULL)
		{
			strcpy(this->apellido,apellido);
			respuesta = 1;
		}
	}

	return respuesta;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		strcpy(apellido, this->apellido);
		respuesta = 1;
	}

	return respuesta;
}

//CODIGO DE VUELO

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(codigoVuelo != NULL)
		{
			strcpy(this->codigoVuelo,codigoVuelo);
			respuesta = 1;
		}
	}

	return respuesta;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		respuesta = 1;
	}

	return respuesta;
}

//TIPO DE PASAJERO

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(tipoPasajero < 4 && tipoPasajero > 0)
		{
			this->tipoPasajero = tipoPasajero;
			respuesta = 1;
		}
	}

	return respuesta;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		respuesta = 1;
	}

	return respuesta;
}

//PRECIO

int Passenger_setPrecio(Passenger* this,float precio)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(precio > 0)
		{
			this->precio = precio;
			respuesta = 1;
		}
	}

	return respuesta;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		*precio = this->precio;
		respuesta = 1;
	}

	return respuesta;
}

//ESTADO DEL VUELO

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		if(estadoVuelo != NULL)
		{
			strcpy(this->estadoVuelo,estadoVuelo);
			respuesta = 1;
		}
	}
	return respuesta;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int respuesta;
	respuesta = 0;
	if(this != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		respuesta = 1;
	}

	return respuesta;
}

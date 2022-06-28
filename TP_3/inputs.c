#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h>

#include "inputs.h"

// INGRESAR DATOS

int esNumerica(char numero[])
{

	int i;
	i = 0;
	int retorno;
	retorno = 1;

	if(numero != NULL && strlen(numero) > 0)
	{
		while(numero[i] != '\0')
		{
			if(numero[i] < '0' || numero[i] > '9')
			{
				retorno = 0;
				break;
			}

			i++;
		}
	}

	return retorno;
}

int esFlotante(char numero[])
{

	int i;
	i = 0;
	int retorno;
	retorno = 1;

	int coma;
	coma = 0;

	if(numero != NULL && strlen(numero) > 0)
	{
		while(numero[i] != '\0')
		{
			if((numero[i] < '0' || numero[i] > '9') && (numero[i] != '.' || coma == 1) )
			{
				retorno = 0;
				break;
			}

			if(numero[i] == '.')
			{
				coma = 1;
			}

			i++;
		}
	}

	return retorno;
}

int noContieneNumeros(char string[])
{
	int i;
	i = 0;
	int retorno;
	retorno = 1;


	if(string != NULL && strlen(string) > 0)
	{
		while(string[i] != '\0')
		{
			if(string[i] >= '0' && string[i] <= '9')
			{
				retorno = 0;
				break;
			}

			i++;
		}
	}

	return retorno;
}

int soloLetras(char string[])
{
	int i;
	i = 0;
	int retorno;
	retorno = 1;


	if(string != NULL && strlen(string) > 0)
	{
		while(string[i] != '\0')
		{
			if(string[i] != ' ' && string[i] > 31 && !(string[i] >= 127 && string[i] <= 153) && !(string[i] >= 160 && string[i] <= 165) && !(string[i] >= 'A' && string[i] <= 'Z') &&  !(string[i] >= 'a' && string[i] <= 'z'))
			{
				retorno = 0;
				break;
			}

			i++;
		}
	}

	return retorno;
}

int input_GetInt(char mensaje[])
{
	char cadenaIngresada[22];

	printf("%s \n",mensaje);
	scanf("%s",cadenaIngresada);
	while (esNumerica(cadenaIngresada) == 0 || cadenaIngresada == NULL)
	{
		printf("\\ERROR\\ %s \n",mensaje);
		scanf("%s",cadenaIngresada);
	}

	return atoi(cadenaIngresada);
}

float input_GetFloat(char mensaje[])
{
	char cadenaIngresada[22];

		printf("%s \n",mensaje);
		scanf("%s",cadenaIngresada);
		while (esFlotante(cadenaIngresada) == 0 || cadenaIngresada == NULL)
		{
			printf("\\ERROR\\ %s \n",mensaje);
			scanf("%s",cadenaIngresada);
		}

		return atof(cadenaIngresada);
}

char input_GetChar(char mensaje[])
{
	char charIngresado;
	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%c",&charIngresado);

	return charIngresado;
}


void input_GetString(char mensaje[],char string[])
{
	char stringIngresado[102];

	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);

	while (stringIngresado == NULL || stringIngresado[1] == '\0')
	{
		printf("\\ERROR\\ %s \n",mensaje);
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
	}

	strcpy(string,stringIngresado);
}

void input_GetSinNumeros(char mensaje[],char string[])
{
	char stringIngresado[102];

	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);
	while (noContieneNumeros(stringIngresado) != 1 || stringIngresado == NULL || stringIngresado[1] == '\0')
	{
		printf("\\ERROR\\ %s \n",mensaje);
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
	}

	strcpy(string,stringIngresado);
}

void input_GetSoloLetras(char mensaje[],char string[])
{
	char stringIngresado[102];

	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);

	while (noContieneNumeros(stringIngresado) != 1 || stringIngresado == NULL || stringIngresado[1] == '\0')
	{
		printf("\\ERROR\\ %s \n",mensaje);
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
	}
	strcpy(string,stringIngresado);
}

void input_GetNombre(char string[])
{
	char stringIngresado[102];
	int i;
	i = 0;

	printf("%s \n","Ingrese su nombre completo (\"Apellidos, nombres\")");
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);

	stringtolower(stringIngresado);

	stringIngresado[i] = toupper(stringIngresado[i]);
	while(stringIngresado[i] != '\0')
	{
		if(stringIngresado[i-1] == ' ' || stringIngresado[i-1] == ',')
		{
			stringIngresado[i] = toupper(stringIngresado[i]);
		}
		i++;
	}

	strcpy(string,stringIngresado);
}

void stringtoupper(char string[])
{
	int i;
	i = 0;
	while(string[i] != '\0')
	{
		string[i] = toupper(string[i]);
		i++;
	}
}
void stringtolower(char string[])
{
	int i;
	i = 0;
	while(string[i] != '\0')
	{
		string[i] = tolower(string[i]);
		i++;
	}
}

#include "validaciones.h"
#include <string.h>

int esNumerica(char* cadena)
{
	int i;
	i = 0;
	int retorno = 0;
	if(cadena && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 1;
				break;
			}
			i++;
		}
	}
	return retorno;
}


// CALCULAR RANGOS

int validaciones_NumeroDistinto0(float numeroIngresado)
{
	int respuesta;
	respuesta = 0;
		if(numeroIngresado != 0)
		{
			respuesta = 1;
		}

	return respuesta;
}

int validaciones_NumeroEntreRangos(float numeroIngresado, float menor, float mayor)
{
	int respuesta;
	respuesta = 0;

		if(numeroIngresado >= menor && numeroIngresado <= mayor)
		{
			respuesta = 1;
		}

	return respuesta;
}

int validaciones_NumeroAfueraRangos(float numeroIngresado, float menor, float mayor)
{
	int respuesta;
	respuesta = 0;

		if(numeroIngresado < menor || numeroIngresado > mayor)
		{
			respuesta = 1;
		}

	return respuesta;
}

// CALCUALR LAS CARACTERISTICAS DE LOS DATOS
int validaciones_CalcularSignoNumero(float numeroIngresado)
{
	int respuesta;
	respuesta = 0;

	if(numeroIngresado > 0)
	{
		respuesta = 1;
	}
	else
	{
		if(numeroIngresado < 0)
		{
			respuesta = -1;
		}
	}

	return respuesta;
}


int validaciones_CalcularParidadNumero(int numeroIngresado)
{
	int respuesta;
	respuesta = 0;

	int resto;
	resto = numeroIngresado %2;

	if(resto == 0)
	{
		respuesta = 1;
	}
	else
	{
		if(resto == 1)
		{
			respuesta = -1;
		}
	}

	return respuesta;
}

//VALIDACION FECHAS

int validaciones_Anio(int anio, int anioMinimo, int anioMaximo)
{

	int index;
	index = 0;

	if(anio<anioMinimo || anio>anioMaximo)
	{
		index = 1;
	}

	return index;
}

int validaciones_Mes(int anio, int mes, int anioactual,int mesactual)
{

	int index;
	index = 0;
	if(mes<1 || mes > 12)
	{
		index = 1;
	}
	else
	{
		if(anio == anioactual)
		{
			if(mes < mesactual)
			{
				index = 1;
			}
		}
	}

	return index;
}

int validaciones_Dia(int anio, int mes,int dia,int anioactual,int mesactual,int diaActual)
{

	int index;
		index = 0;

		switch(mes)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(dia<1 || dia > 31)
			{
				index = 1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(dia<1 || dia > 30)
			{
				index = 1;
			}
			break;
		case 2:
			if(dia<1 || dia > 28)
			{
				index = 1;
			}
			break;
		}

		if(index != 1)
		{
			if(anio == anioactual)
			{
				if(mes == mesactual)
				{
					if(dia > diaActual)
					{
						index = 1;
					}
				}
			}
		}

	return index;
}

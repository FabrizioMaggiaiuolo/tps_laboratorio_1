#include "funciones.h"

#include <stdio.h>
#include <stdlib.h>

/// @brief Imprime el menu de opciones mostrando los datos ingresados
///
/// @param x Kilometros guardados
/// @param y Precio de Aerolineas guardado
/// @param z Precio de Latam guardado
/// @return la opcion seleccionada
int ImprimirMenu(float x,float y,float z)
{
	int respuesta;

	printf("MENU DE OPCIONES: \n");
	printf("Kilometros ingresados: %0.2f \n", x);
	printf("Precio Aerolineas ingresado: $%0.2f \n", y);
	printf("Precio Latam ingresado: $%0.2f \n\n", z);

	printf("Ingrese una de las siguientes opciones: \n");
	printf("1. Para ingresar los kilometros \n");
	printf("2. Para ingresar los precios de los vuelos \n");
	printf("3. Para calcular los costos \n");
	printf("4. Para informar los resultados \n");
	printf("5. Para carga forzada de datos \n");
	printf("6. Salir \n");
	printf("Que quiere hacer? \n");
	scanf("%d",&respuesta);
	printf("\n");

	return respuesta;
}

/// @brief Imprime por pantalla el calculo de todos los precios
///
/// @param precios array con los precios calculados
/// @param calculado si los precios fueron calculados o no (1 si  y 0 no)
/// @param x Kilometros guardados
/// @param y Precio de Aerolineas guardado
/// @param z Precio de Latam guardado
void InfomarResultados(float precios[],int calculado,float x,float y,float z)
{
	if(calculado == 1)
	{

		system("cls");
		printf("KMs ingresados: %0.2f km \n\n",x);

		printf("Precio Aerolineas: $%0.2f \n",y);
		printf("a) Precio con tarjeta de debito: $ %0.2f \n",precios[1]);
		printf("b) Precio con tarjeta de credito: $ %0.2f \n",precios[3]);
		printf("c) Precio pagado con bitcoin: %0.5f BTC \n",precios[5]);
		printf("d) Precio unitario: $ %0.2f \n",precios[7]);
		printf("\n");
		printf("Precio Latam: $%0.2f \n",z);
		printf("a) Precio con tarjeta de debito: $ %0.2f \n",precios[0]);
		printf("b) Precio con tarjeta de credito: $ %0.2f \n",precios[2]);
		printf("c) Precio pagado con bitcoin: %0.5f BTC \n",precios[4]);
		printf("d) Precio unitario: $ %0.2f \n",precios[6]);
		printf("\n");
		printf("La diferencia de precio es: $ %0.2f \n\n",precios[8]);

		printf("---------------------------------------------- \n\n");
	}
	else
	{
		system("cls");
		printf("Por favor ingrese los datos con las opciones 1. y 2. \nLuego calcule los costos con la opcion 3.\n\n");
	}
}

/// @brief Calcula los distintos costos y los guarda en un array
///
/// @param x Kilometros guardados
/// @param y Precio de Aerolineas guardado
/// @param z Precio de Latam guardado
/// @param precios array donde se guardaran los costos calculados
/// @return 1 si los precios fueron calculados
/// 		0 si no se ingreso alguno de los datos pedidos
int CalcularCostos(float x,float z,float y,float precios[])
{
	float descuento;
	float interes;
	float bitcoin;

	descuento = 10;
	interes = 25;
	bitcoin = 4606954.55;

	int calculado;

	system("cls");

	if(x != 0 && y != 0 && z != 0)
	{

		precios[0] = PrecioTarjetaDebito(y,descuento);
		precios[1] = PrecioTarjetaDebito(z,descuento);
		precios[2] = PrecioTarjetaCredito(y,interes);
		precios[3] = PrecioTarjetaCredito(z,interes);
		precios[4] = PrecioBitcoin(y,bitcoin);
		precios[5] = PrecioBitcoin(z,bitcoin);
		precios[6] = PrecioUnitario(y,x);
		precios[7] = PrecioUnitario(z,x);
		precios[8] = DiferenciaDePrecio(z,y);

		calculado = 1;
	}
	else
	{
		system("cls");
		printf("Por favor ingrese los datos con las opciones 1. y 2. \nLuego calcule los costos con la opcion 3.\n\n");
		calculado = 0;
	}
	return calculado;
}

/// @brief Calcula el precio si se paga con tarjeta de debito
///
/// @param precio el precio inicial
/// @param descuento el descuento a aplicar
/// @return el precio final
float PrecioTarjetaDebito(float precio,float descuento)
{
	precio -= (precio*descuento/100);

	return precio;
}

/// @brief Calcula el precio si se paga con tarjeta de credito
///
/// @param precio el precio inicial
/// @param interes el interes a aplicar
/// @return el precio final
float PrecioTarjetaCredito(float precio, float interes)
{
	precio += (precio*interes/100);

	return precio;
}

/// @brief Calcula el precio si se paga con bitcoin
///
/// @param precio el precio inicial
/// @param bitcoin el valor del bitcoin
/// @return el precio final
float PrecioBitcoin(float precio, float bitcoin)
{
	float precioBitcoin;
	precioBitcoin = (float)precio*1/bitcoin;

	return precioBitcoin;
}

/// @brief Calcula el precio por kilometro recorrido
///
/// @param precio el precio inicial
/// @param x los kilometros recorridos
/// @return el precio por kilometro
float PrecioUnitario(float precio,float x)
{
	precio /= x;

	return precio;
}

/// @brief Devuelve la diferencia de precio entre Aerolineas y Latam
///
/// @param z Precio de Latam guardado
/// @param y Precio de Aerolineas guardado
/// @return retorna la diferencia de precio entre ambas aerolineas
float DiferenciaDePrecio(float z, float y)
{
	int diferencia;

	diferencia = z-y;

	return diferencia;
}

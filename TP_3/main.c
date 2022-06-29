#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"
#include "controlId.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);

	int cargasFlag;
	cargasFlag = 0;
	int guardadoFlag;
	guardadoFlag = 0;

	int cargaLista;
	cargaLista = 0;

	int retorno;

	ArchivoIds(1);

    int option = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{

    	printf("\nMenu de opciones \n");
		printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
		printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
		printf("3. Alta de pasajero\n");
		printf("4. Modificar datos de pasajero\n");
		printf("5. Baja de pasajero\n");
		printf("6. Listar pasajeros\n");
		printf("7. Ordenar pasajeros\n");
		printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
		printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n");
		printf("10. Salir\n");

		option = input_GetInt("");

		if(option < 1 || option >10)
		{
			printf("Ingrese una opcion valida");

		}
		else
		{

			if((option != 1 && option != 2 && option != 3 && option != 10) && cargasFlag != 1)
			{
				printf("\nCargue algun pasajero para acceder a la opcion\n");
			}
			else
			{

				if(option < 1 || option >10)
				{
					printf("Ingrese una opcion valida");
				}
				else
				{

					switch(option)
					{

						case 1:

							if(cargaLista == 0)
							{

								retorno = controller_loadFromText("data.csv",listaPasajeros);
								if(retorno == 1)
								{
									printf("Se cargaron los datos correctamente\n");
								}

								cargasFlag = 1;
								cargaLista = 1;

							}
							else
							{
								printf("La lista ya fue cargada\n");
							}
							break;

						case 2:

							if(cargaLista == 0)
							{

								retorno = controller_loadFromBinary("data.bin", listaPasajeros);
								if(retorno == 1)
								{
									printf("Se cargaron los datos correctamente\n");
								}

								cargasFlag = 1;
								cargaLista = 1;

							}
							else
							{
								printf("La lista ya fue cargada\n");
							}

							break;

						case 3:

							retorno = controller_addPassenger(listaPasajeros);
							if(retorno == 1)
							{
								printf("Se cargo el pasajero correctamente\n");
							}
							cargasFlag = 1;
							break;

						case 4:

							retorno = controller_editPassenger(listaPasajeros);
							if(retorno == 1)
							{
								printf("Se modifico el pasajero correctamente\n");
							}
							break;

						case 5:

							retorno = controller_removePassenger(listaPasajeros);
							if(retorno == 1)
							{
								printf("Se removio el pasajero correctamente\n");
							}
							break;

						case 6:

							controller_ListPassenger(listaPasajeros);
							break;

						case 7:

							retorno = controller_sortPassenger(listaPasajeros);
							if(retorno == 1)
							{
								printf("Se ordeno los pasajero correctamente\n");
							}
							break;

						case 8:

							retorno = controller_saveAsText("data.csv", listaPasajeros);
							if(retorno == 1)
							{
								printf("Se guardaron los pasajero correctametne\n");
							}
							guardadoFlag = 1;
							break;

						case 9:

							retorno = controller_saveAsBinary("data.bin", listaPasajeros);
							if(retorno == 1)
							{
								printf("Se guardaron los pasajero correctametne\n");
							}
							guardadoFlag = 1;
							break;

						case 10:

							if(guardadoFlag == 1 || cargasFlag == 0)
							{
								printf("Gracias por ultilizar nuestro programa, vuelva pronto!!");
							}
							else
							{
								printf("Tiene que guardar los datos antes de salir\n");
							}
							break;

					}
				}
			}
		}

    } while (option != 10 || guardadoFlag != 1);

    return 0;
}


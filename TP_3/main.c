#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"

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

    int option = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{

    	printf("\nMenu de opciones: \n");
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

		if((option != 1 && option != 2 && option != 3 && option != 10) && cargasFlag != 1)
		{
			printf("\nCargue algun pasajero para acceder a la opcion\n");
		}
		else
		{
			switch(option)
			{
				case 1:
					controller_loadFromText("data.csv",listaPasajeros);
					cargasFlag = 1;
					break;
				case 2:
					controller_loadFromBinary("data.bin", listaPasajeros);
					cargasFlag = 1;
					break;
				case 3:
					controller_addPassenger(listaPasajeros);
					cargasFlag = 1;
					break;
				case 4:
					controller_editPassenger(listaPasajeros);
					break;
				case 5:
					controller_removePassenger(listaPasajeros);
					break;
				case 6:
					controller_ListPassenger(listaPasajeros);
					break;
				case 7:
					controller_sortPassenger(listaPasajeros);
					break;
				case 8:
					controller_saveAsText("data.csv", listaPasajeros);
					break;
				case 9:
					controller_saveAsBinary("data.bin", listaPasajeros);
					break;
				case 10:
					system("cls");
					printf("Gracias por ultilizar nuestro programa, vuelva pronto!!");
					break;
			}
		}

		//VERIFICAR QUE NO SE PUEDA ENTRAR A NINGUNA OPCION SIN HABER USADO LA OPCION 1,2 O 3

    } while (option != 10);

    return 0;
}


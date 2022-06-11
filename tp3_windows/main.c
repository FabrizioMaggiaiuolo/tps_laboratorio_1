#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include <string.h>

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

//Orden para hacer las cosas:
//Passenger
//Parser


int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();

//	controller_loadFromText("data.csv", listaPasajeros);
	controller_loadFromBinary("data.bin", listaPasajeros);
//
	controller_ListPassenger(listaPasajeros);
//
//	controller_removePassenger(listaPasajeros);
//
//	controller_addPassenger(listaPasajeros);
//	controller_addPassenger(listaPasajeros);
//
//	controller_ListPassenger(listaPasajeros);
//
//	controller_saveAsText("data.csv", listaPasajeros);
//	controller_saveAsBinary("data.bin", listaPasajeros);
//
//	controller_editPassenger(listaPasajeros);
//
//	controller_ListPassenger(listaPasajeros);

    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
        }
    }while(option != 10);

    return 0;
}


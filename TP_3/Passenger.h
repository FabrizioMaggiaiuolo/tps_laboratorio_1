#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoVuelo[20];

}Passenger;

/// @brief Crea un nuevo pasajero en memoria dinamica
///
/// @return retorna el pasajero
Passenger* Passenger_new();

/// @brief Crea un nuevo pasajero en memoria dinamica y le asigna todos los datos
///
/// TODOS LOS PARAMETROS SE RECIBEN COMO CADENA DE CARACTERES
/// @param idStr el id que se le asigna
/// @param nombreStr el nombre que se le asigna
/// @param tipoPasajeroStr el tipo de pasajero que se le asigna
/// @param apellido el apallido que se le asigna
/// @param codigo el codigo de vuelo que se le asigna
/// @param precio el precio del vuelo que se le asiga
/// @param estado el estado del vuelo que se le asigno
/// @return retorna el pasajero
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellido, char* codigo,char* precio,char* estado);

/// @brief libera el espacio en memoria dinamica utilizado por el pasajero
///
/// @param this el pasajero a eliminar
void Passenger_delete(Passenger* this);

/// @brief imprime por cosola todos los datos de un pasajero
///
/// @param this puntero al pasajero
void Passenger_printUno(Passenger* this);

/// @brief comparacion de nombre entre 2 pasajeros
///
/// @param p1
/// @param p2
/// @return 1 si el nombre del pasajero 1 > nombre del pasajero 2
/// -1 si el nombre del pasajero 1 < nombre del pasajero 2
/// 0 si el nombre del pasajero 1 = nombre del pasajero 2
int Passenger_compareByName(void* p1,void *p2);

/// @brief comparacion de id entre 2 pasajeros
///
/// @param p1
/// @param p2
/// @return 1 si el id del pasajero 1 > id del pasajero 2
/// -1 si el id del pasajero 1 < id del pasajero 2
/// 0 si el id del pasajero 1 = id del pasajero 2
int Passenger_compareById(void* p1,void *p2);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);


#endif /* PASSENGER_H_ */

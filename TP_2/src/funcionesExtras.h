#ifndef FUNCIONESEXTRAS_H_
#define FUNCIONESEXTRAS_H_

/// @brief inicializa vuelos (hardcodeo)
/// @param listFlights la lista de los vuelos
/// @param lenFlights el lardo de la lista de los vuelos
void initFlights(sFlights listFlights[],int lenFlights);

/// @brief recibe la opcion sellecionada y ejecuta la funcion que corresponda
/// @param opcion la opcion seleccionada
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
/// @param pIdIncremental puntero de id incremental
/// @param listFlights lista de vuelos
/// @param lenFlights largo de lista de vuelos
void EjecutarOpcion(int opcion,sPassenger list[],int len,int* pIdIncremental,sFlights listFlights[],int lenFlights);

/// @brief Se realiza la pedida de datos para poder dar alta a un pasajer
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
/// @param pIdIncremental puntero de id incremental
/// @param listFlights lista de vuelos
/// @param lenFlights largo de lista de vuelos
void PedidaDeDatos(sPassenger list[],int len,int* pIdIncremental,sFlights listFlights[],int lenFlights);

/// @brief busca un lugar libre dentro de las lista de pasajeros (isEmpy == 1)
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
/// @return retorna la poscion disponible o -1 en caso de que no halla
int buscarLibre(sPassenger list[],int len);

/// @brief pide los datos y modifica el pasajero
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
/// @param listFlights lista de vuelos
/// @param lenFlights largo de lista de vuelos
void ModificarDatos(sPassenger list[],int len, sFlights listFlights[],int lenFlights);

/// @brief pide el id e elimina el pasajero (isEmpy = 1)
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
void EliminarPasajero(sPassenger list[],int len);


/// @brief menu de los listados disponibles
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
/// @param listFlights lista de vuelos
/// @param lenFlights largo de lista de vuelos
void Listados(sPassenger list[],int len,sFlights listFlights[],int lenFlights);

/// @brief Lista los pasajeros por apellido y en caso de ser iguales por tipo de pasajero
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
/// @param listFlights lista de vuelos
/// @param lenFlights largo de lista de vuelos
void ListadoApellidoTipo(sPassenger list[],int len,sFlights listFlights[],int lenFlights);

/// @brief Muestra el promedio de la suma de todos los precios y la cantidad de pasajeros que superan ese promedio
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
void TotalPromedioPrecios(sPassenger list[],int len);

/// @brief Lista los pasajeros por codigo de vuelo donde este se encuentre activo
/// @param list lista de pasajeros
/// @param len largo de lista de pasajero
/// @param listFlights lista de vuelos
/// @param lenFlights largo de lista de vuelos
void ListadoCodigoVueloActivo(sPassenger list[],int len,sFlights listFlights[],int lenFlights);

void cargaForzada(sPassenger list[],int len,int* pIdIncremental);
#endif /* FUNCIONESEXTRAS_H_ */


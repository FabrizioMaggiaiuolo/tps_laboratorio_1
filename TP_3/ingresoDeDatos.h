#ifndef INGRESODEDATOS_H_
#define INGRESODEDATOS_H_

/// @brief Pide un precio, lo verifica y lo devuelve
///
/// @param precio String donde se guardara el precio ingresado
void IngresoPrecio(char precio[]);

/// @brief Imprime un submenu pidendo un tipo de pasajero, lo verifica y lo devuelve como string y int
///
/// @param tipoPasajero donde se guarda el tipo de pasajero ingresado como string
/// @return devuelve el tipo de pasajero como int
int IngresoTipoPasajero(char tipoPasajero[]);

/// @brief Pide un codigo de vuelo, lo verifica y lo devueloce
///
/// @param codigoVuelo donde se guarda el codigo de vuelo ingresado
void IngresoCodigoVuelo(char codigoVuelo[]);

/// @brief Imprime un sibmenu pidiendo un estado de vuelo, lo verifica y lo devuelo
///
/// @param tipoPasajero donde se guarda el estado de vuelo ingresado
void IngresoEstadoVuelo(char estadoVuelo[]);

#endif /* INGRESODEDATOS_H_ */

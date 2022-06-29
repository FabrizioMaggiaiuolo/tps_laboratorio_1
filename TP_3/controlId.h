#ifndef CONTROLID_H_
#define CONTROLID_H_

/// @brief abre o crea un archivo binario donde se guarda el id que se le pasa por parametro
///
/// @param id el id que sera guardado en el archivo
void ArchivoIds(int id);

/// @brief Lee el id guardado en un archivo binario y lo devuelve (int)
///
/// @return devuelve el id (int)
int LeerIdInt();

/// @brief Lee el id guardado en un archivo binario y lo devuelve (char*)
///
/// @param strId Donde se guarda el id en forma de cadena de caracteres (char*)
void LeerIdStr(char* strId);

/// @brief Suma una unidad al id guardado en un archivo binario
///
void SumarId();

#endif /* CONTROLID_H_ */

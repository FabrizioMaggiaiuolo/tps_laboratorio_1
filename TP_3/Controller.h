/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si carga los datos correctamente
 * y 0 si no (path = NULL o Linked list = NULL)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si carga los datos correctamente
 * y 0 si no (path = NULL o Linked list = NULL)
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si se le dio de alta correctamente
 * y 0 si no(Linked list = NULL)
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si se modificarons los datos correctamente
 * y 0 si no (Linked list = NULL)
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 * 1 si se elemino correctamente
 * y 0 si no se elimino (Linked list = NULL)
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si se se listo correctamente
 * y 0 si no (Linked list = NULL)
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si ordeno correctamente
 * y 0 si no(Linked list = NULL)
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si se guardaron los datos correctamente
 * y 0 si no (path = NULL o Linked list = NULL)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si se guardaron los datos correctamente
 * y 0 si no (path = NULL o Linked list = NULL)
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);




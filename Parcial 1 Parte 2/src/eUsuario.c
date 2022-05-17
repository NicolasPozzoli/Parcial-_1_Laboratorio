#include "eUsuario.h"
static int Usuario_idIncremental = 100;
static int eUsuario_ObtenerID(void);
static int eUsuario_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eUsuario_ObtenerID();

	return Usuario_idIncremental++;
}

void eUsuario_Inicializar(eUsuario array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eUsuario_ObtenerIndexLibre(eUsuario array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eUsuario_BuscarPorID(eUsuario array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idUsuario == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eUsuario_MostrarUno(eUsuario Usuario) {
	//PRINTF DE UN SOLO Usuario
	printf("%5d", Usuario.idUsuario);
	if(Usuario.tipo==TIPO_ADMIN)
	{
		printf("%15s","ADMIN");
	}else
	{
		printf("%15s","USUARIO");
	}
	printf("%30s", Usuario.correo);
	printf("%20s", Usuario.password);
	printf("  %15s", Usuario.direccion);
	printf("    %15d", Usuario.codPostal);
	if(Usuario.isEmpty==OCUPADO)
	{
		printf("%20s","OCUPADO\n");
	}
	else
	{
		if(Usuario.isEmpty==BAJA)
		{
			printf("%20s","BAJA\n");
		}
	}
}

int eUsuario_MostrarTodos(eUsuario array[], int TAM) {
	int i;
	int rtn = 0;
//	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Usuario");
	printf("%5s\n\n", "ID\t\tTIPO\t\tCORREO     \t\tPASSWORD\t\tDIRECCION\t\tCODPOSTAL\t\tESTADO\n "); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Usuario
				eUsuario_MostrarUno(array[i]);
				//CONTADOR DE Usuario
				rtn = 1;
			//	cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Usuario PARA MOSTRAR (ARRAY SIN ALTAS)
	/*if (cantidad > 0) {

	}
*/

	return rtn;
}

int eUsuario_MostrarDadosDeBaja(eUsuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Usuario\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Usuario
				eUsuario_MostrarUno(array[i]);
				//CONTADOR DE Usuario
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Usuario PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eUsuario eUsuario_CargarDatos(void) {
	eUsuario auxiliar;
	int opcionTipo;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	auxiliar.idUsuario = eUsuario_ObtenerID();
	//auxiliar.cantidadDias = Get_Int("Cantidad de dias de publicacion: ", "Error. Reingrese. ");
	//auxiliar.cuit = Get_Int("CUIT: : ", "Error. Reingrese. ");
	utn_getTextoPrueba("Ingrese correo: ",  "Error. Reingrese. ", 3, MAX_CHARS_CADENAS, auxiliar.correo);
		utn_getTexto("Ingrese contraseña: ",  "Error. Reingrese. ", 3, MAX_CHARS_CADENAS, auxiliar.password);
		utn_getTexto("Direccion: ",  "Error. Reingrese. ", 3, MAX_CHARS_CADENAS, auxiliar.direccion);
		utn_getNumero("Codigo Postal: ", "Error. Reingrese. ", 1, 9999, 3, &auxiliar.codPostal);
		puts("INGRESE TIPO");
		puts("1) ADMIN");
		puts("2) USUARIO");
		utn_getNumero("Escoja tipo : ", "Error. Reingrese. ", 1, 2, 3, &opcionTipo);
		switch (opcionTipo) {
		case 1:
			auxiliar.tipo = TIPO_ADMIN;
			break;
		case 2:
			auxiliar.tipo = TIPO_USUARIO;
			break;
		}

	return auxiliar;
}

eUsuario eUsuario_ModificarUno(eUsuario Usuario) {
	eUsuario auxiliar = Usuario;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eUsuario_Alta(eUsuario array[], int TAM) {
	int rtn = 0;
	eUsuario auxUsuario;

	//BUSCO ESPACIO EN ARRAY
	int index = eUsuario_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Usuario AUXILIAR
		auxUsuario = eUsuario_CargarDatos();

		if(VerificarCorreo(array, TAM, auxUsuario.correo)==-1)
		{
			//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
			auxUsuario.idUsuario = eUsuario_ObtenerID();
			//CAMBIO SU ESTADO A "OCUPADO"
			auxUsuario.isEmpty = OCUPADO;
			//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
			array[index] = auxUsuario;
		/*	if(addUsuario(array, TAM, auxUsuario.correo, auxUsuario.password, auxUsuario.tipo, auxUsuario.codPostal, auxUsuario.direccion, auxUsuario.isEmpty)==1)
			{
				rtn = 1;
			}
			*/
			rtn = 1;
		}
		else
		{
			puts("ESE CORREO YA ESTA REGISTRADO.");
		}

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	}

	return rtn;
}

int eUsuario_Baja(eUsuario array[], int TAM) {
	int rtn = 0;
	int idUsuario;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Usuario
	if (eUsuario_MostrarTipoUsuario(array, TAM)) {
		//BANDERA EN 1 SI HAY Usuario DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Usuario PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idUsuario);

		//BUSCO INDEX POR ID EN ARRAY
		while (eUsuario_BuscarPorID(array, TAM, idUsuario) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
	utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idUsuario);
		}

		//OBTENGO INDEX DEL ARRAY DE Usuario A DAR DE BAJA
		index = eUsuario_BuscarPorID(array, TAM, idUsuario);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eUsuario_Modificacion(eUsuario array[], int TAM) {
	int rtn = 0;
	int idUsuario;
	int index;
	int flag = 0;
	eUsuario auxiliar;

	//LISTO TODOS LOS Usuario
	if (eUsuario_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Usuario DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Usuario PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idUsuario);

		//BUSCO INDEX POR ID EN ARRAY
		while (eUsuario_BuscarPorID(array, TAM, idUsuario) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idUsuario);
		}

		//OBTENGO INDEX DEL ARRAY DE Usuario A MODIFICAR
		index = eUsuario_BuscarPorID(array, TAM, idUsuario);

		//LLAMO A FUNCION QUE MODIFICA Usuario
		auxiliar = eUsuario_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eUsuario_Sort(eUsuario array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eUsuario aux;

	/** EJEMPLO DE SORT CON ID DE Usuario
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idUsuario > array[j].idUsuario) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idUsuario < array[j].idUsuario) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

int eUsuario_BuscarPorCorreo(eUsuario array[], int TAM, char correo[], char password[]) {
	int rtn = -1;
	int i;



	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0 && correo!=NULL && password!=NULL) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if(array[i].isEmpty == OCUPADO)
			{
			if (strcmp (array[i].correo, correo)==0) {
				if(strcmp (array[i].password, password)==0)
				{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;

				}
			}
			}
		}
	}


	return rtn;
}

int LoguearUsuario (eUsuario array[],int TAM)
{
	int rtn = -1;
	char correo[MAX_CHARS_CADENAS];
	char password[MAX_CHARS_CADENAS];
	int index;

	if (array != NULL && TAM > 0 )
	{
		if(utn_getTextoPrueba("Ingrese correo: ",  "Error. Reingrese. ", 3, MAX_CHARS_CADENAS, correo)==0)
		{
			utn_getTexto("Ingrese contraseña: ",  "Error. Reingrese. ", 3, MAX_CHARS_CADENAS, password);
		}
		else
		{
			rtn=-1;
		}
		index=eUsuario_BuscarPorCorreo(array, TAM, correo, password);
		while (index == -1) {

			puts("NO ESTAS REGISTRADO. REGISTRATE PARA CONTNUAR");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE CORREO Y CONTRASEÑA VALIDOS.\n");
			utn_getTextoPrueba("Ingrese correo: ",  "Error. Reingrese. ", 3, MAX_CHARS_CADENAS, correo);
			utn_getTexto("Ingrese contraseña: ",  "Error. Reingrese. ", 3, MAX_CHARS_CADENAS, password);
			rtn=-1;
			index=eUsuario_BuscarPorCorreo(array, TAM, correo, password);
		}
		if(array[index].tipo==TIPO_ADMIN)
		{
			rtn=1;   // SI ESTA FUNCION ME RETORNA 1 ES TIPO ADMIN
		}
		else
		{
			if(array[index].tipo==TIPO_USUARIO)
			{
				rtn=2;    // SI ESTA FUNCION ME RETORNA 2 ES TIPO USUARIO
			}
		}



	}
	return rtn;
}



int addUsuario(eUsuario array[], int TAM,char correo[],char password[],int tipo, int codPostal, char direccion[],int estado) {
	int rtn = 0;
	eUsuario auxUsuario;

	if(array!=NULL && TAM>0 && correo!=NULL && password!=NULL && tipo>-1 && direccion!=NULL)
	{
	//BUSCO ESPACIO EN ARRAY
	int index = eUsuario_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Usuario AUXILIAR

		switch (tipo) {
		case 1:
			auxUsuario.tipo = TIPO_ADMIN;
			break;
		case 2:
			auxUsuario.tipo = TIPO_USUARIO;
			break;
		}

		strcpy(auxUsuario.correo,correo);
		strcpy(auxUsuario.password,password);
		strcpy(auxUsuario.direccion,direccion);
		auxUsuario.codPostal=codPostal;
		auxUsuario.tipo=tipo;
		auxUsuario.isEmpty=estado;
		//auxUsuario = eUsuario_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL

		rtn = 1;
	}
	}
	return rtn;
}

int eUsuario_MostrarTipoUsuario(eUsuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Usuario");
	printf("%5s\n\n", "ID\t\tTIPO\t\tCORREO     \t\tPASSWORD\t\tDIRECCION\t\tCODPOSTAL\t\tESTADO\n "); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			if(array[i].isEmpty == OCUPADO)
			{
			//PREGUNTO POR SU TIPO "USUARIO"
			if (array[i].tipo == TIPO_USUARIO) {
				//MUESTRO UN SOLO Usuario

				eUsuario_MostrarUno(array[i]);
				//CONTADOR DE Usuario

				cantidad++;
			}
		}
	}
	}

	//SI CANTIDAD == 0 - NO HUBO Usuario PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}


int VerificarCorreo(eUsuario array[], int TAM, char correo[]) {
	int rtn = -1;
	int i;



	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0 && correo!=NULL) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if(array[i].isEmpty == OCUPADO)
			{
			if (strcmp (array[i].correo, correo)==0) {
				{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;

				}
			}
			}
		}
	}


	return rtn;
}


//---------------------------------------------------------------------------------------------------




int eUsuario_printByStatus(eUsuario* list, int length, int status)
{
	int ret = -1; //NULL LIST
	if(list != NULL)
	{
		if(length > 0)
		{
			encabezadoTablaeUsuario();
			int i;
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == status)
				{
					eUsuario_printOne(list[i]);
					ret = 0;
				}
			}
			pieTablaeUsuario();
		}
		else
		{
			ret = -2; //la longitud de la lista es menor a 1
		}
	}
	return ret;
}

/// @fn void eUsuario_printOne(eUsuario)
/// @brief imprime solo un dato del tipo eUsuario
/// el numero que va dsp del % es correlativo con la cantidad de - que tiene el encabezado
/// @param eUsuario
void eUsuario_printOne(eUsuario eUsuario)
{
    // 4               26                          25                  10                20	      4          15
	//ID           CORREO                         nombre            PASSWORD        DIRECCION       CP        TIPO
	printf( "|%d|%-30s|%-25s|%-10s|%-4d"
			,eUsuario.idUsuario,eUsuario.correo,eUsuario.password,eUsuario.direccion,eUsuario.codPostal);

	switch(eUsuario.tipo)
	{
		char permisos[20];
		case TIPO_ADMIN:
			strncpy(permisos,"Administrador",sizeof(permisos));
			printf("|%-15s|\n",permisos);
			break;
		case TIPO_USUARIO:
			strncpy(permisos,"Convencional",sizeof(permisos));
			printf("|%-15s|\n",permisos);
			break;
	}
}

void encabezadoTablaeUsuario(void)
{
	        // 4               26                           25                  10                20	      4          15
			//ID           CORREO                         nombre            PASSWORD        DIRECCION       CP        TIPO
	printf("+----+------------------------------+-------------------------+----------+--------------------+----+---------------+\n");
	printf("| ID |            CORREO            |          NOMBRE         | PASSWORD |      DIRECCION     | CP |      TIPO     |\n");
	printf("+----+------------------------------+-------------------------+----------+--------------------+----+---------------+\n");
}
void pieTablaeUsuario(void)
{
	printf("+----+------------------------------+-------------------------+----------+--------------------+----+---------------+\n");
}



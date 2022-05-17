#include "eProducto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

 static int Producto_idIncremental = 100;
 int eProducto_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eProducto_ObtenerID();
	Producto_idIncremental++;
	return Producto_idIncremental;
}

void eProducto_Inicializar(eProducto array[], int TAM) {
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

int eProducto_ObtenerIndexLibre(eProducto array[], int TAM) {
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
				printf("\nINDEX LIBRE AL MOMENTO DE DAR INDEX LIBRE: %d\n",rtn);
				break;
			}
		}
	}

	return rtn;
}

int eProducto_BuscarPorID(eProducto array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idProducto == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eProducto_MostrarUno(eProducto Producto) {
	//PRINTF DE UN SOLO Producto
	printf("%5d\t", Producto.idProducto);
	if (Producto.categoria == TIPO_INMUEBLE) {
		printf("%5s", "\tINMUEBLE");
	} else {
		if(Producto.categoria== TIPO_ELECTRODOMESTICO)
		{
			printf("%5s", "\tELECTRODOMESTICO");
		}else
		{
			if(Producto.categoria== TIPO_TECNOLOGIA)
			{
				printf("%5s", "\tTECNOLOGIA   ");
			}else
			{
				if(Producto.categoria== TIPO_VEHICULOS)
				{
					printf("%5s", "\tVEHICULOS     ");
				}else
				{
					if(Producto.categoria== TIPO_MODA)
					{
						printf("%5s", "\tMODA       ");
					}else
					{
						if(Producto.categoria== TIPO_HERRAMIENTAS)
						{
							printf("%5s", "\tHERRAMIENTAS  ");
						}
					}
				}
			}
		}
	}
	printf("%20s", Producto.nombreProducto);
	printf("%12.2f", Producto.precio);
	printf("%5d\n", Producto.stock);



}

int eProducto_MostrarTodos(eProducto array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO PRODUCTOS");
	printf("%5s%15s%11s%6s\n\n", "ID", "\tCATEGORIA", "\tNOMBRE PRODUCTO","\t\tPRECIO\tSTOCK"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Producto
				eProducto_MostrarUno(array[i]);
				//CONTADOR DE Producto
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Producto PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eProducto_MostrarDadosDeBaja(eProducto array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Producto\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Producto
				eProducto_MostrarUno(array[i]);
				//CONTADOR DE Producto
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Producto PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eProducto eProducto_CargarDatos(void) {
	eProducto auxiliar;
	int opcion;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */

	utn_getTexto("NOMBRE DE Producto: ", "Error.", 3, MAX_CHARS_CADENA, auxiliar.nombreProducto);
	utn_getFloat("Precio: ", "Error.", 1, 10000000, 3, &auxiliar.precio);
	puts("INGRESE CATEGORIA");
	puts("1) INMUEBLE");
	puts("2) ELECTRODOMESTICO");
	puts("3) TECNOLOGIA");
	puts("4) VEHICULOS");
	puts("5) MODA");
	puts("6) HERRAMIENTAS");
	utn_getNumero("SELECCIONE CATEGORIA: ", "Error. Reingrese. ", 1, 6, 3, &opcion);
	switch (opcion) {
	case 1:
		auxiliar.categoria = TIPO_INMUEBLE;
		break;
	case 2:
		auxiliar.categoria = TIPO_ELECTRODOMESTICO;
		break;
	case 3:
		auxiliar.categoria = TIPO_TECNOLOGIA;
		break;
	case 4:
		auxiliar.categoria = TIPO_VEHICULOS;
		break;
	case 5:
		auxiliar.categoria = TIPO_MODA;
		break;
	case 6:
		auxiliar.categoria = TIPO_HERRAMIENTAS;
		break;
	}
	return auxiliar;
}

eProducto eProducto_ModificarUno(eProducto Producto) {
	eProducto auxiliar = Producto;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eProducto_Alta(eProducto array[], int TAM) {
	int rtn = 0;
	eProducto auxProducto;
if(array!=NULL && TAM>0)
{
	//BUSCO ESPACIO EN ARRAY
	int index = eProducto_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Producto AUXILIAR
		auxProducto = eProducto_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxProducto.idProducto = eProducto_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxProducto.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxProducto;


		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}
}

	return rtn;
}

int eProducto_Baja(eProducto array[], int TAM) {
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Producto
	if (eProducto_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Producto PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idProducto);

		//BUSCO INDEX POR ID EN ARRAY
		while (eProducto_BuscarPorID(array, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idProducto);
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A DAR DE BAJA
		index = eProducto_BuscarPorID(array, TAM, idProducto);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eProducto_Modificacion(eProducto array[], int TAM) {
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;
	eProducto auxiliar;

	//LISTO TODOS LOS Producto
	if (eProducto_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Producto PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idProducto);
		//BUSCO INDEX POR ID EN ARRAY
		while (eProducto_BuscarPorID(array, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero("INGRESE ID A DAR DE BAJA: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idProducto);
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A MODIFICAR
		index = eProducto_BuscarPorID(array, TAM, idProducto);

		//LLAMO A FUNCION QUE MODIFICA Producto
		auxiliar = eProducto_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eProducto_Sort(eProducto array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eProducto aux;

	/** EJEMPLO DE SORT CON ID DE Producto
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
						if (array[i].categoria > array[j].categoria) {
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
						if (array[i].categoria < array[j].categoria) {
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



int eProducto_ComprarPorID(eProducto array[], int TAM) {
	int rtn = -1;
	int idProducto;
	int index;
//	int flag = 0;
	int cantidad;
	float valorCompraTotal;
	int opcionConfirm;


	//LISTO TODOS LOS Producto
	//SI HAY Producto PARA DAR DE BAJA
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
	if(utn_getNumero("INGRESE ID DEL PRODUCTO QUE QUIERE COMPRAR: ", "Error. ID no valido. Ingrese nuevamente. ", 0, 999999, 3, &idProducto)==0)
	{

	}else
	{
		puts("ERROR AL ENCONTRAR PRODUCTO.");
		rtn = -1;
	}

		//BUSCO INDEX POR ID EN ARRAY
		while (eProducto_BuscarPorID(array, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			if(utn_getNumero("INGRESE ID DEL PRODUCTO QUE QUIERE COMPRAR: ", "Error. ID no valido. Ingrese nuevamente. ", 0, 999999, 3, &idProducto)==0)
			{

			}else
			{
				puts("ERROR AL ENCONTRAR PRODUCTO.");
				rtn = -1;
			}
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A COMPRAR
		index = eProducto_BuscarPorID(array, TAM, idProducto);



		/**PREGUNTAR CANTIDAD*/
		if(utn_getNumero("INGRESE CANTIDAD: ", "Error. Ingrese nuevamente. ", 1, 999999, 3, &cantidad)==0)
		{
			if(cantidad<=array[index].stock)
			{
				valorCompraTotal=array[index].precio*cantidad;

				array[index].stock=array[index].stock-cantidad;

				printf("\nEL TOTAL DE SU COMPRA ES: %.2f\n",valorCompraTotal);
				if(utn_getNumero("1- CONFIRMAR\n"
								"0- CANCELAR\n", "Error. Ingrese nuevamente. ", 0, 1, 3, &opcionConfirm)==0)
				{
					switch(opcionConfirm)
					{
					case 0:

						break;
					case 1:
						puts("COMPRA REALIZADA.");
						rtn = index;
						break;
					}
				}else
				{
					puts("ERROR.");
					rtn = -1;
				}




			}

		}else
		{
			puts("ERROR.");
			rtn = -1;
		}



		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE



	return rtn;
}


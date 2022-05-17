/*
 * Producto_Usuario.c
 *
 *  Created on: 15 may. 2022
 *      Author: nicop
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "eProducto.h"
#include "eUsuario.h"

#define MAX_CHARS 50



int uProducto_uUsuario_Alta(eProducto arrayProducto[], int TAM, eUsuario arrayUsuario[], int TAMU)
{
	int rtn = -1;
	eProducto auxiliarProducto;
	char auxNombreProducto[MAX_CHARS];
	float auxPrecioProducto;
	int auxStockProducto;
	int auxCategoriaProductoOpcion;
//	int auxCategoriaProducto;
	int auxFKidUsuario;
	int index;
	//BUSCO ESPACIO EN ARRAY


	index=eProducto_ObtenerIndexLibre(arrayProducto, TAM);
//	printf("\nINDEX AL MOMENTO DE DAR ALTA UN PRODUCTO: %d\n",index);


	if (index != -1) {

		if(utn_getTexto( "INGRESE NOMBRE DE PRODUCTO:", "ERROR. Intente nuevamente.", 3, MAX_CHARS, auxNombreProducto)==0)
		{}
		else
		{
			rtn=-1;
		}
		if(utn_getFloat("PRECIO DE PRODUCTO: ", "ERROR. Intente nuevamente.", 1, 1000000, 3,&auxPrecioProducto)==0)
		{}
		else
		{
			rtn=-1;
		}
		if(utn_getNumero( "STOCK: ", "ERROR. Intente nuevamente.", 1, 10000, 3,&auxStockProducto)==0){
		}
		else
		{
			rtn=-1;
		}
		if(utn_getNumero("ESCOJA CATEGORIA: \n"
						"1) INMUEBLE \n"
						"2) ELECTRODOMESTICO\n"
						"3) TECNOLOGIA\n"
						"4) VEHICULOS\n"
						"5) MODA\n"
						"6) HERRAMIENTAS", "OPCION NO VALIDA. Intente nuevamente.", 1, 6, 3,&auxCategoriaProductoOpcion)==0)
			{

			}
			else
			{
				rtn=-1;
			}

		eUsuario_MostrarTipoUsuario(arrayUsuario, TAMU);
		//

		if(utn_getNumero("INGRESE SU ID:", "ERROR. Intente nuevamente.", 0, 10000, 3,&auxFKidUsuario)==0)
		{}
		else
		{
			rtn=-1;
		}
		if(eUsuario_BuscarPorID(arrayUsuario, TAMU, auxFKidUsuario)!=-1)
		{
			strncpy(auxiliarProducto.nombreProducto,auxNombreProducto,MAX_CHARS);
			auxiliarProducto.precio = auxPrecioProducto;
			auxiliarProducto.stock=auxStockProducto;
			auxiliarProducto.categoria=auxCategoriaProductoOpcion;
			auxiliarProducto.FK_idUsuario=auxFKidUsuario;
			printf("Cargar datos FK ID: %d\n",auxiliarProducto.FK_idUsuario);
			printf("Cargar datos Categoria: %d\n",auxiliarProducto.categoria);

			rtn = 1;
		}
		else
		{
			puts("ERROR AL ENCONTRAR ID.");
		}


		auxiliarProducto.idProducto = eProducto_ObtenerID();

		auxiliarProducto.isEmpty = OCUPADO;
	//	printf("\nINDEX: %d\n",index);
		arrayProducto[eProducto_ObtenerIndexLibre(arrayProducto, TAM)] = auxiliarProducto;
		eProducto_MostrarTodos(arrayProducto, TAM);

		rtn = 1;

	}
	printf("Cargar datos FK ID: %d\n",auxiliarProducto.FK_idUsuario);
	printf("Cargar datos Categoria: %d\n",auxiliarProducto.categoria);

	return rtn;
}

int uProducto_uUsuario_Baja(eProducto arrayProducto[], int TAM, eUsuario arrayUsuario[], int TAMU)
{
	int rtn=-1;

	if(eProducto_Baja(arrayProducto, TAM)==1)
	{
		rtn=1;
	}


	return rtn;
}

int uProducto_uUsuario_ReponerStock (eProducto arrayProducto[], int TAM)
{
	int rtn=-1;
	int flag=0;
	int idProducto;
	int index;
	int nuevoStock;
	//LISTO TODOS LOS Producto
	if (eProducto_MostrarTodos(arrayProducto, TAM)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}


	if (flag) {

		utn_getNumero("INGRESE ID A REPONER: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idProducto);

		//BUSCO INDEX POR ID EN ARRAY
		while (eProducto_BuscarPorID(arrayProducto, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");


			utn_getNumero("INGRESE ID A REPONER: ", "ERROR. Intente nuevamente.", 0, 9999999, 3, &idProducto);
		}


		index = eProducto_BuscarPorID(arrayProducto, TAM, idProducto);



		utn_getNumero("INGRESE NUEVO STOCK", "ERROR.", 1, 9000, 3, &nuevoStock);
		arrayProducto[index].stock = nuevoStock;


		rtn = 1;
	}

	return rtn;
}


int filtrarProductoPorNombre (eProducto array[], int TAM)
{
	int rtn=-1;
	char nombreProducto[MAX_CHARS_CADENAS];
	int indexProducto;

	if(utn_getString("INGRESE NOMBRE DE PRODUCTO: ", "ERROR. Intente nuevamente.", 3, TAM, nombreProducto)==0)
	{
		indexProducto=eProducto_BuscarPorNombre(array, TAM, nombreProducto);
		if(indexProducto!=-1)
		{
			eProducto_MostrarTodosPorNombre(array, TAM, nombreProducto);
		}
	}



	return rtn;
}



int eProducto_BuscarPorNombre(eProducto array[], int TAM, char nombreProducto[]) {
	int rtn = -1;
	int i;



	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0 && nombreProducto!=NULL) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if(array[i].isEmpty == OCUPADO)
			{
			if (strcmp (array[i].nombreProducto, nombreProducto)==0) {


				//SI ENCONTRE EL NOMBRE
				//DEVUELVO EL INDEX DE DONDE ESTA EL NOMBRE BUSCADO Y SALGO
				rtn = i;
				break;


			}
			}
		}
	}


	return rtn;
}


int eProducto_MostrarTodosPorNombre(eProducto array[], int TAM, char nombreProducto[]) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\n\t> LISTADO PRODUCTOS");
	printf("%5s%15s%11s%6s\n\n", "ID", "\tCATEGORIA", "\tNOMBRE PRODUCTO","\t\tPRECIO\tSTOCK"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				if (strcmp (array[i].nombreProducto, nombreProducto)==0)
				{
				//MUESTRO UN SOLO Producto
				eProducto_MostrarUno(array[i]);

				}
			}
		}
	}


	return rtn;
}




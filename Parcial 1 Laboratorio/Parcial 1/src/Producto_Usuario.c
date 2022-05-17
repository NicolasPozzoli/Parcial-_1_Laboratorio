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


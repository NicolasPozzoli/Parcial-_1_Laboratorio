/*
 * Producto_Usuario_Tracking.c
 *
 *  Created on: 16 may. 2022
 *      Author: nicop
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Input.h"
#include "eProducto.h"
#include "eUsuario.h"
#include "eTracking.h"
#define MAX_CHARS 50


long int time_Current(void)
{
	return time(NULL);
}

long int time_Add(double secondsAdd)
{
	return secondsAdd+time_Current();
}

long int CalcularHoraLlegada(long int horarioPedido,int km)
{
	long int retorno;
	if(km==20)
	{
		retorno=time_Add(40);
	}
	else
	{
		if(km==30)
		{
			retorno=time_Add(60);
		}
		else
		{
			if(km==50)
			{
				retorno=time_Add(100);
			}
			else
			{
				if(km==80)
				{
					retorno=time_Add(160);
				}
				else
				{
					if(km==150)
					{
						retorno=time_Add(300);
					}

				}
			}
		}
	}

	return retorno;
}

int calcularDistanciaDeEntrega(int codPostal)
{
	int rtn=-1;

	if(codPostal<=0)
	{
		puts("ERROR. Fuera del rango.");
	}
	else
	{
		if(codPostal>0 && codPostal<1001)
		{
			rtn=20;
		}
		else
		{
			if(codPostal>1000 && codPostal<3001)
			{
				rtn=30;
			}
			else
			{
				if(codPostal>3000 && codPostal<5001)
				{
					rtn=50;
				}
				else
				{
					if(codPostal>5000 && codPostal<8001)
					{
						rtn=80;
					}
					else
					{
						if(codPostal>8000 && codPostal<10000)
						{
							rtn=150;
						}

					}
				}
			}
		}

	}

	return rtn;
}



int uProducto_uUsuario_uTracking_Alta(eProducto arrayProducto[], int TAM, eUsuario arrayUsuario[], int TAMU,eTracking arrayTracking[],int TAMT)
{
	int rtn=-1;
	eTracking auxTracking;

	int idProducto;
	int indexTracking;
	int indexProducto;
	//int flag = 0;
	//int cantidad;
	float valorCompraTotal;
	int opcionConfirm;
	int codPostalComprador;
	int distanciaKM;
	int idComprador;
	int indexUsuario;


	//BUSCO ESPACIO EN ARRAY
	indexTracking = eTracking_ObtenerIndexLibre(arrayTracking, TAMT);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (indexTracking != -1) {
		//PIDO DATOS - CARGO Tracking AUXILIAR



		//LISTO TODOS LOS Producto
		eProducto_MostrarTodos(arrayProducto, TAM);
		//SI HAY Producto PARA DAR DE BAJA
			//PIDO ID A DAR DE BAJA
			//USAR FUNCION GET_INT DE LIBRERIA DE INPUTS
		if(utn_getNumero("INGRESE ID DEL PRODUCTO QUE QUIERE COMPRAR: ", "Error. ID no valido. Ingrese nuevamente. ", 0, 999999, 3, &idProducto)==0)
		{

		}else
		{
			puts("ERROR AL ENCONTRAR PRODUCTO.");
			rtn = -1;
		}

			//BUSCO INDEX POR ID EN ARRAY
			while (eProducto_BuscarPorID(arrayProducto, TAM, idProducto) == -1) {
				puts("NO EXISTE ID.");

				//USAR FUNCION GET_INT DE LIBRERIA DE INPUTS
				if(utn_getNumero("INGRESE ID DEL PRODUCTO QUE QUIERE COMPRAR: ", "Error. ID no valido. Ingrese nuevamente. ", 0, 999999, 3, &idProducto)==0)
				{

				}else
				{
					puts("ERROR AL ENCONTRAR PRODUCTO.");
					rtn = -1;
				}
			}

			//OBTENGO INDEX DEL ARRAY DE Producto A COMPRAR
			indexProducto = eProducto_BuscarPorID(arrayProducto, TAM, idProducto);

			if(indexProducto!=-1)
			{
				auxTracking.idProducto=idProducto;


			//PREGUNTAR CANTIDAD
			if(utn_getNumero("INGRESE CANTIDAD: ", "Error. Ingrese nuevamente. ", 1, 999999, 3, &auxTracking.cantidad)==0)
			{
				if(auxTracking.cantidad<=arrayProducto[indexProducto].stock)
				{
					valorCompraTotal=arrayProducto[indexProducto].precio*auxTracking.cantidad;

					arrayProducto[indexProducto].stock=arrayProducto[indexProducto].stock-auxTracking.cantidad;

					printf("\nEL TOTAL DE SU COMPRA ES: $%.2f\n",valorCompraTotal);
					if(utn_getNumero("1- CONFIRMAR\n"
									"0- CANCELAR\n", "Error. Ingrese nuevamente. ", 0, 1, 3, &opcionConfirm)==0)
					{
						switch(opcionConfirm)
						{
						case 0:

							break;
						case 1:
							puts("COMPRA REALIZADA.");

						//eUsuario_MostrarTodos(arrayUsuario, TAMU);


							utn_getNumero("\nCONFIRME COMPRA CON SU ID DE USUARIO: .\n", "Error. Ingrese nuevamente. ", 0, 10000, 3, &idComprador);

							indexUsuario=eUsuario_BuscarPorID(arrayUsuario, TAMU,idComprador);



							if(idComprador!=-1)
							{
								auxTracking.FK_idComprador=idComprador;

								rtn = 1;

								auxTracking.FK_idVendedor=arrayProducto[indexProducto].FK_idUsuario;
								codPostalComprador=arrayUsuario[indexUsuario].codPostal;
								distanciaKM=calcularDistanciaDeEntrega(codPostalComprador);
								if(distanciaKM!=-1)
								{
									auxTracking.distanciaKM=distanciaKM;
									auxTracking.horaPedido= time_Current();
									auxTracking.horaLlegada=CalcularHoraLlegada(auxTracking.horaPedido, auxTracking.distanciaKM);

									printf("\nDISTANCIA DE ENTREGA: %dKM\n",auxTracking.distanciaKM);
									printf("\nHORA DE LLEGADA: %ldKM\n",auxTracking.distanciaKM);
									printf("\nID DE COMPRADOR: %dKM\n",auxTracking.FK_idComprador);
									printf("\nID DE VENDEDOR: %dKM\n",auxTracking.FK_idVendedor);
									printf("\nCANTIDAD: %dKM\n",auxTracking.cantidad);
									printf("\nID PRODUCTO: %dKM\n",auxTracking.idProducto);
									printf("\nID TRACKING: %dKM\n",auxTracking.idTracking);







								}

							}


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

		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxTracking.idTracking = eTracking_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxTracking.isEmpty = OCUPADO;

		auxTracking.status = EN_PREPARACION;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		arrayTracking[indexTracking] = auxTracking;


	}
	else
		{

		}
	}
	return rtn;
}

/*
eTracking uProducto_uUsuario_uTracking_CargarDatos(void) {
	eTracking auxiliar;
	int opcion;
	// CARGAR DATOS NECESARIOS PARA EL ALTA
	// IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA


/*

	return auxiliar;
}
*/



int actualizarEstadoTracking(eTracking array[], int TAM)
{
	int retorno=-1;
	int i;
	long int horaActual;
	horaActual=time(NULL);
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			if(array[i].status != CANCELADO)
			{
				if(horaActual>array[i].horaPedido)
				{
					array[i].status = EN_VIAJE;
					retorno=1;
				}
				if(horaActual>array[i].horaLlegada)
				{
					array[i].status = ENTREGADO;
					retorno=1;
				}
			}
		}

	eTracking_MostrarTodos(array, TAM);
		return retorno;
}

int eTracking_MostrarCompradosPorUsuario(eTracking array[], int TAM,eUsuario arrayUsuario[], int TAMU) {
	int i;
	int rtn = 0;
	int cantidad = 0;
	int idComprador;
	int index;

	utn_getNumero("INGRESE SU ID:", "ERROR.", 99, 9000000, 3, &idComprador);

	index=eUsuario_BuscarPorID(arrayUsuario, TAMU, idComprador);

	//CABECERA
	puts("\n\t> LISTADO Tracking");
	printf("%5s%5s%11s%6s\n\n", "ID", "ESTADO", "ID COMPRADOR","ID VENDEDOR");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Tracking
				eTracking_MostrarUno(array[i]);
				//CONTADOR DE Tracking
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Tracking PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}


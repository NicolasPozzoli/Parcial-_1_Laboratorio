/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Producto_Usuario.h"
#include "Producto_Usuario_Tracking.h"


#define MAX_TAM 200



int main(void) {
	setbuf (stdout ,NULL);
	int opcion;
	int opcionUsuario;
	int opcionAdmin;
	int retornoDelogin;
	int flag=0;
	int opcionUsuario2;

	//eUsuario usuarioLogueado; // modificar
	eUsuario arrayUsuario[MAX_TAM];
	eProducto arrayProducto[MAX_TAM];
	eTracking arrayTracking[MAX_TAM];


	eUsuario_Inicializar(arrayUsuario, MAX_TAM);

	eProducto_Inicializar(arrayProducto, MAX_TAM);

	eTracking_Inicializar(arrayTracking, MAX_TAM);

	do
	{

	if(utn_getNumero("\n**************************\n"
					"**1er EXAMEN LAB I - 1H**\n"
					"**************************\n"
					"\n1) INGRESAR\n"
					"2) REGISTRARSE\n"
					"\n0) SALIR\n", "Opcion no valida. Reintente ", 0, 2, 3, &opcion)==0)
	{
		switch (opcion) {
			case 1:
				retornoDelogin=LoguearUsuario(arrayUsuario, MAX_TAM);

				if(retornoDelogin>-1)
				{
					puts("LOGUEADO CORRECTAMENTE.\n\n");
					if(retornoDelogin==2)
					{
						do
						{

					if(utn_getNumero("\n**************************\n"
									"**1er EXAMEN LAB I - 1H**\n"
									"********* USUARIO *********\n"
									"***************************\n"
									"\n1) COMPRAR\n"
									"2) VENDER\n"
									"3) ESTADO DE COMPRAS\n"
									"4) ESTADO DE VENTAS\n"
									"\n0) SALIR\n", "Opcion no valida. Reintente ", 0, 4, 3, &opcionUsuario)==0)
					{
						switch(opcionUsuario)
						{
							case 1:
								if(eProducto_Sort(arrayProducto, MAX_TAM, -1)==1)
								{
									if(uProducto_uUsuario_uTracking_Alta(arrayProducto, MAX_TAMPRODUC, arrayUsuario, MAX_TAMUSUARIO, arrayTracking, MAX_TAM)==1)
									{
										puts("PRODUCTO COMPRADO.");
									}
									else
									{
										puts("ERROR AL COMPRAR.\n");
									}


								}else
								{
									puts("ERROR NO HAY PRODUCTOS QUE MOSTRAR.\n");
								}
								break;
							case 2:
								if(utn_getNumero("1-> PUBLICAR PRODUCTO.\n"
												"2-> REPONER STOCK. \n\n"
												"0-> SALIR.\n"
												"ESCOJA OPCION: ", "ERROR.", 0, 2, 3, &opcionUsuario2)==0)
								{
									switch(opcionUsuario2)
									{
									case 1:
										if(uProducto_uUsuario_Alta(arrayProducto, MAX_TAMPRODUC, arrayUsuario, MAX_TAMUSUARIO)==1)
										{
											puts("PRODUCTO CREADO.\n");

										}else
										{
											puts("ERROR AL CREAR PRODUCTO.\n");
										}
										break;
									case 2:
										if(uProducto_uUsuario_ReponerStock(arrayProducto, MAX_TAMPRODUC)==1)
										{
											puts("NUEVO STOCK ASIGNADO.");
										}
										else
										{
											puts("NO SE PUDO REPONER.");
										}
										break;
									case 0:
										break;
									}


								}




								break;
							case 3:

								break;
							case 4:

								break;
							case 0:
								break;

						}
					}

					}while(opcionUsuario!=0);
					}

					else
					{
						if(retornoDelogin==1)
						{

							do
							{
							if(utn_getNumero("\n**************************\n"
											"**1er EXAMEN LAB I - 1H**\n"
											"********** ADMIN **********\n"
											"***************************\n"
											"\nA) LISTAR ESTADO DE TODOS LOS USUARIOS\n"
											"B) LISTAR TODOS LOS PRODUCTOS POR CATEGORIA\n"
											"C) BAJA DE UN PRODUCTO\n"
											"D) BAJA DE UN USUARIO\n"
											"E) VER TRACKING GLOBAL\n"
											"F) FILTRAR POR NOMBRE DE PROODUCTO.\n"
											"\n0) SALIR\n", "Opcion no valida. Reintente ", 0, 6, 3, &opcionAdmin)==0)
							{
								switch(opcionAdmin)
								{
									case 1:
										if(eUsuario_MostrarTipoUsuario(arrayUsuario, MAX_TAMUSUARIO)==1)
										{
											//MOSTRADO
										}
										else
										{
											puts("NO HAY USUARIOS PARA MOSTRAR.\n");
										}
										break;
									case 2:
										eProducto_MostrarTodos(arrayProducto, MAX_TAMPRODUC);
										break;
									case 3:
										if(uProducto_uUsuario_Baja(arrayProducto, MAX_TAMPRODUC, arrayUsuario, MAX_TAMUSUARIO)==1)
										{
											puts("EXITO AL DAR DE BAJA.\n");
										}
										else
										{
											puts("ERROR AL DAR DE BAJA.\n");
										}
										break;
									case 4:
										if(eUsuario_Baja(arrayUsuario, MAX_TAMUSUARIO)==1)
										{
											//USUARIO DADO DE BAJA
										}
										else
										{
											puts("ERROR AL DAR DE BAJA.\n");
										}
										break;
									case 5:
										eTracking_MostrarTodos(arrayTracking, MAX_TAM);

										break;
									case 6:
										filtrarProductoPorNombre(arrayProducto, MAX_TAMPRODUC);
										break;
									case 0:
										break;


								}

							}
							}while(opcionAdmin!=0);
						}

					}

				}
				else
				{
					puts("NO ESTAS REGISTRADO, PRESIONA 0 PARA VOLVER AL MENU PRINCIPAL\n");
				}
				break;
			case 2:
				if(eUsuario_Alta(arrayUsuario, MAX_TAM)==1)
				{
					puts("\nREGISTRADO CORRECTAMENTE.");
					flag=1;
				}
				else
				{
					puts("\nERROR AL REGISTRAR.");
				}

				break;
			case 0:
				eUsuario_MostrarTodos(arrayUsuario, MAX_TAM);
				break;
		}

	}
	}while(opcion!=0);

	return EXIT_SUCCESS;
}




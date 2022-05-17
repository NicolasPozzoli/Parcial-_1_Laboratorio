/*
 * Producto_Usuario_Tracking.h
 *
 *  Created on: 16 may. 2022
 *      Author: nicop
 */

#ifndef PRODUCTO_USUARIO_TRACKING_H_
#define PRODUCTO_USUARIO_TRACKING_H_

#include "eProducto.h"
#include "eUsuario.h"
#include "eTracking.h"

int calcularDistanciaDeEntrega(int codPostal);
long int time_Current(void);
long int time_Add(double secondsAdd);
long int CalcularHoraLlegada(long int horarioPedido,int km);
int actualizarEstadoTracking(eTracking array[], int TAM);
int uProducto_uUsuario_uTracking_Alta(eProducto arrayProducto[], int TAM, eUsuario arrayUsuario[], int TAMU,eTracking arrayTracking[],int TAMT);

#endif /* PRODUCTO_USUARIO_TRACKING_H_ */

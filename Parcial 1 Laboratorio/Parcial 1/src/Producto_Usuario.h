/*
 * Producto_Tracking_Usuario.h
 *
 *  Created on: 15 may. 2022
 *      Author: nicop
 */

#ifndef PRODUCTO_USUARIO_H_
#define PRODUCTO_USUARIO_H_

#include "eProducto.h"
#include "eUsuario.h"

#define MAX_CHARS 50

int uProducto_uUsuario_Baja(eProducto arrayProducto[], int TAM, eUsuario arrayUsuario[], int TAMU);
int uProducto_uUsuario_Alta(eProducto arrayProducto[], int TAM, eUsuario arrayUsuario[], int TAMU);

#endif /* PRODUCTO_USUARIO_H_ */

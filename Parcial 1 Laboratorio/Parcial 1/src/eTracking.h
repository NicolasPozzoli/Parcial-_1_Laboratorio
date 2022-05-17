#ifndef Tracking_H_
#define Tracking_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EN_PREPARACION 2
#define EN_VIAJE 0
#define ENTREGADO 1
#define CANCELADO -1


#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


//*** eTracking
typedef struct {
	int idTracking;
	int idProducto;
	int isEmpty;

	int FK_idComprador;   // usuario logueado
	int FK_idVendedor; // ID con el producto

	int status;
	int cantidad;
	int distanciaKM;
	int long horaLlegada;
	int long horaPedido;
} eTracking;
//***

/** INICIO CABECERAS DE FUNCION*/
void eTracking_Inicializar(eTracking array[], int TAM);
int eTracking_ObtenerID(void);
int eTracking_ObtenerIndexLibre(eTracking array[], int TAM);
int eTracking_BuscarPorID(eTracking array[], int TAM, int ID);
void eTracking_MostrarUno(eTracking Tracking);
int eTracking_MostrarTodos(eTracking array[], int TAM);
int eTracking_MostrarDadosDeBaja(eTracking array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eTracking_Sort(eTracking array[], int TAM, int criterio);

//ABM
eTracking eTracking_CargarDatos(void);
eTracking eTracking_ModificarUno(eTracking Tracking);
int eTracking_Alta(eTracking array[], int TAM);
int eTracking_Baja(eTracking array[], int TAM);
int eTracking_Modificacion(eTracking array[], int TAM);
/** FIN CABECERAS DE FUNCION*/

#endif

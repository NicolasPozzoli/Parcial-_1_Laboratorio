#ifndef Producto_H_
#define Producto_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMPRODUC 200
#define MAX_CHARS_CADENA 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define TIPO_INMUEBLE 1
#define TIPO_ELECTRODOMESTICO 2
#define TIPO_TECNOLOGIA 3
#define TIPO_VEHICULOS 4
#define TIPO_MODA 5
#define TIPO_HERRAMIENTAS 6

//*** eProducto
typedef struct {
	int idProducto;
	int isEmpty;

	int FK_idUsuario;   //VENDEDOR

	char nombreProducto[MAX_CHARS_CADENA];
	float precio;
	int categoria;
	int stock;
} eProducto;
//***

/** INICIO CABECERAS DE FUNCION*/
void eProducto_Inicializar(eProducto array[], int TAM);
int eProducto_ObtenerIndexLibre(eProducto array[], int TAM);
int eProducto_ObtenerID(void);
int eProducto_BuscarPorID(eProducto array[], int TAM, int ID);
void eProducto_MostrarUno(eProducto Producto);
int eProducto_MostrarTodos(eProducto array[], int TAM);
int eProducto_MostrarDadosDeBaja(eProducto array[], int TAM);

int eProducto_ComprarPorID(eProducto array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eProducto_Sort(eProducto array[], int TAM, int criterio);

//ABM
eProducto eProducto_CargarDatos(void);
eProducto eProducto_ModificarUno(eProducto Producto);
int eProducto_Alta(eProducto array[], int TAM);
int eProducto_Baja(eProducto array[], int TAM);
int eProducto_Modificacion(eProducto array[], int TAM);
/** FIN CABECERAS DE FUNCION*/

#endif

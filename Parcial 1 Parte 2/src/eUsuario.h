#ifndef Usuarioerica_H_
#define Usuarioerica_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#define MAX_CHARS_CADENAS 50
#define MAX_TAMUSUARIO 10000
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define TIPO_ADMIN 1
#define TIPO_USUARIO 0

//*** eUsuario
typedef struct {
	int idUsuario;
	int isEmpty;

	int FK_idProducto;

	int tipo;
	int codPostal;
	char correo[MAX_CHARS_CADENAS];
	char password[MAX_CHARS_CADENAS];
	char direccion[MAX_CHARS_CADENAS];
} eUsuario;
//***

/** INICIO CABECERAS DE FUNCION*/
void eUsuario_Inicializar(eUsuario array[], int TAM);
int eUsuario_ObtenerIndexLibre(eUsuario array[], int TAM);
int eUsuario_BuscarPorID(eUsuario array[], int TAM, int ID);
int eUsuario_BuscarPorCorreo(eUsuario array[], int TAM, char correo[], char password[]);
int LoguearUsuario (eUsuario array[],int TAM);
void eUsuario_MostrarUno(eUsuario Usuario);
int eUsuario_MostrarTodos(eUsuario array[], int TAM);
int eUsuario_MostrarDadosDeBaja(eUsuario array[], int TAM);
int addUsuario(eUsuario array[], int TAM,char correo[],char password[],int tipo, int codPostal, char direccion[],int estado);
int eUsuario_MostrarTipoUsuario(eUsuario array[], int TAM);
int VerificarCorreo(eUsuario array[], int TAM, char correo[]);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eUsuario_Sort(eUsuario array[], int TAM, int criterio);

//ABM
eUsuario eUsuario_CargarDatos(void);
eUsuario eUsuario_ModificarUno(eUsuario Usuario);
int eUsuario_Alta(eUsuario array[], int TAM);
int eUsuario_Baja(eUsuario array[], int TAM);
int eUsuario_Modificacion(eUsuario array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
//--------------------------------------------------------------------------



#endif

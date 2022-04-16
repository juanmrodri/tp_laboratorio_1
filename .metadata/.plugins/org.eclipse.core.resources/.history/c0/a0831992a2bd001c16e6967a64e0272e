/*
 * input.c
 *
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#include <stdlib.h>
#include "input.h"
#include "calculos.h"

// static func. firm

static int getInt(int* pResultado);

static int isNumeric(char* cadena);

static int myGets(char* cadena, int longitud);

//

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int i;
	int ret;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				//scanf("%d",&aux);
				if(getInt(&aux) == 0 && aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					ret=0; // salio bien
					break;
				}
				else
				{
					printf("%s",mensajeError);
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=1; // salio mal
		}

	return ret;
}


static int getInt(int* pResultado)
{
	int ret;
	char buffer[4096];

	ret=1;

	if(myGets(buffer,sizeof(buffer))==0 && isNumeric(buffer))
	{
		ret=0;
		*pResultado = atoi(buffer);
	}
	return ret;
}


int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float aux;
	int i;
	int ret;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{

				printf("%s",mensaje);
				fflush(stdin);
				scanf("%f",&aux);
				if(aux >= minimo && aux <= maximo)
				{
					ret=0; // salio ok!
					*pResultado = aux;
					break;
				}
				/*
				 if(getFloat(&aux) == 0 && aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					ret=0; // salio bien
					break;
				}
				 */
				else
				{
					printf("%s",mensajeError);
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=1; // salio mal
		}

	return ret;
}

/*
static int getFloat(float* pResultado)
{
	int ret;
	char buffer[4096];

	ret=1;
	if(myGets(buffer,sizeof(buffer))==0 && isNumeric(buffer))
	{
		ret=0;
		*pResultado = atof(buffer);
	}
	return ret;
}
*/
/*
static int getFloat(float* pResultado)
{
	int ret;
	char buffer[4096];
	char *bufferAux;
	float aux;


	ret=1;

	if(myGets(buffer,sizeof(buffer))==0 && isNumeric(buffer))
	{
		ret=0;
		aux = strtod(buffer,&bufferAux);
		*pResultado = aux;
	}
	return ret;
}
*/

static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);

	cadena[strlen(cadena)-1]='\0'; // arregla el enter que se agrega al final, para que fgets cargue correctamente la cadena

	return 0;
}

static int isNumeric(char* cadena)
{
	int ret=1;
	int i=0; // me tomo esta licencia aca

	if(cadena[0] == '-') // negativos
	{
		i = 1;
	}
	for( ; cadena[i] !='\0'; i++)
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			ret = 0;
			break;
		}
	}

	return ret;
}

int utn_cargaForzada(int* kilometros, float* precioAerolineas, float* precioLatam, int km, float aerolineas, float latam)
{
	int ret;

	ret=1;
	if(kilometros!=NULL && precioAerolineas!=NULL && precioLatam!=NULL && km >0 && aerolineas>0 && latam>0)
	{
		*kilometros = km;
		*precioAerolineas = aerolineas;
		*precioLatam = latam;
		ret=0;
		printf("\nCarga forzada realizada exitosamente\n\n");
	}

	return ret;
}


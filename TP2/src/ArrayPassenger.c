/*
 * ArrayPassenger.c
 *
 *  Created on: 27 abr 2022
 *      Author: juanm
 */

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "ArrayPassenger.h"
#include "utn.h"
#define EMPTY 1
#define OCCUP 0

// static functions

static int newIdGenerator(void);

//******************************************

static int newIdGenerator(void)
{
	static int cont=1;
	return cont++;
}

//******************************************

int initPassengers(Passenger* list, int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=EMPTY; // esta vacio
			ret=0;
		}
	}
	return ret;
}

int findEmptyPassengerPos(Passenger* list, int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==EMPTY)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}

int isPassengerAdded(Passenger* list, int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCCUP)
			{
				ret=0;
				break;
			}
		}
	}
	return ret;
}

int loadPassengers(Passenger* list, int len)
{
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	char auxFlycode[10];
	int auxTypePassenger;
	int auxStatusFlight;
	int indexFree;
	int ret=-1;

	if(list!=NULL && len>0)
	{
		indexFree=findEmptyPassengerPos(list, len);

		if(indexFree!=-1 && list[indexFree].isEmpty == EMPTY)
		{
			printf("\t----------------------------------------------\n\n");
			//printf("\nlugares disponibles: %d\n\n", len-(indexFree+1));

			if(utn_getText(auxName, 51,"\n\tIngrese el nombre del pasajero: ", "\n\tError al ingresar el nombre\n", 2)==0)
			{
				if(utn_getText(auxLastName, 51, "\n\tIngrese el apellido del pasajero: ", "\n\tError al ingresar el apellido\n", 2)==0)
				{
					if(utn_getFloat(&auxPrice, "\n\tIngrese el precio del vuelo: ", "\n\tError al ingresar el precio\n", 50000, 900000, 2)==0)
					{
						if(utn_getText(auxFlycode, 10, "\n\tIngrese el codigo de vuelo: ", "\n\tError al ingresar el codigo de vuelo\n", 2)==0)
						{
							if(utn_getNumber(&auxTypePassenger, "\n\tIngrese el tipo de pasajero\n\t1-turista\n\t2-primera clase\n\t3-ejecutivo\n\t4-premium economy: ", "\n\tError al tipo de pasajero\n", 1, 4, 2)==0)
							{
								if(utn_getNumber(&auxStatusFlight, "\n\tIngrese el status del vuelo\n\t1-ACTIVO\n\t2-CANCELADO: ", "\n\tError al ingresar el status del vuelo\n", 1, 2, 2)==0)
								{
									list[indexFree].statusFlight = auxStatusFlight; // cargamos el estado asi por ahora
									addPassenger(list, len, newIdGenerator(), auxName, auxLastName, auxPrice, auxTypePassenger, auxFlycode);
									ret=0;
								}
								else
								{
									ret=-1;
									printf("\n\tSe produjo un error al ingresar el status del vuelo!\n");
								}
							}
							else
							{
								ret=-1;
								printf("\n\tSe produjo un error al ingresar el tipo de pasajero!\n");
							}
						}
						else
						{
							ret=-1;
							printf("\n\tSe produjo un error al ingresar el codigo de vuelo!\n");
						}
					}
					else
					{
						ret=-1;
						printf("\n\tSe produjo un error al ingresar el precio!\n");
					}
				}
				else
				{
					ret=-1;
					printf("\n\tSe produjo un error al ingresar el apellido!\n");
				}
			}
			else
			{
				ret=-1;
				printf("\n\tSe produjo un error al ingresar el nombre!\n");
			}
		}

	}
	else
	{
		// directamente no se puede ingresar ningun dato
		ret=-1;
		printf("\n\tError al realizar la carga!\n");
	}

	return ret;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int ret=-1;
	int indexFree;

	if(list!=NULL && len>0 && id!=0 && name!=NULL && lastName!=NULL)
	{
		indexFree = findEmptyPassengerPos(list, len);
		list[indexFree].id = id;
		strcpy(list[indexFree].name,name);
		strcpy(list[indexFree].lastName,lastName);
		list[indexFree].price = price;
		list[indexFree].typePassenger = typePassenger;
		strcpy(list[indexFree].flycode,flycode);
		list[indexFree].isEmpty = OCCUP; // ya no esta disponible la posicion
	}

	return ret;
}

int modPassengers(Passenger* list, int len, int pos, int id)
{
	int ret=-1;
	int auxResponse;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	int auxTypePassenger;
	char auxFlycode[10];
	char auxType[16];


	if(list->typePassenger == 1)
		{
			strcpy(auxType,"Turista");
		}
		else
		{
			if(list->typePassenger == 2)
			{
				strcpy(auxType,"Primera Clase");
			}
			else
			{
				if(list->typePassenger == 3)
				{
					strcpy(auxType,"Ejecutivo");
				}
				else
				{
					if(list->typePassenger == 5)
					{
						strcpy(auxType,"Premium Economy");
					}
				}
			}
		}

	if(list!=NULL && len>0 && pos>=0 && id>0)
	{
		if(list[pos].id == id)
		{
			printf("\n\tUsted esta por modificar a pasajero id (%d):\n\tNombre: %s\n\tApellido: %s\n\tprecio: %2.f\n\tTipo de pasajero: %s\n\tCodigo de vuelo: %s\n\n",list[pos].id, list[pos].name, list[pos].lastName, list[pos].price, auxType, list[pos].flycode);

			 if(utn_getNumber(&auxResponse, "\tDesea continuar? (0 si- 1 no) ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
			 {
				 if(auxResponse==0)
				 {
					 if(utn_getNumber(&auxResponse, "\n\tDesea modificar el nombre? (0 si- 1 no) ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
					 {
						 if(auxResponse==0)
						 {
							 if(utn_getText(auxName, 51, "\n\tIngrese el nombre del pasajero: ", "\n\tError al ingresar el nombre\n", 2)==0)
							 {
								 strcpy(list[pos].name,auxName);
								 printf("\n\tModificacion realizada con exito\n\n");
							 }
							 else
							 {
								 // no se modifica
								 ret=-1;
							 }
						 }
					 }
					 if(utn_getNumber(&auxResponse, "\n\tDesea modificar el apellido? (0 si- 1 no) ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
					 {
						 if(auxResponse==0)
						 {
							 if(utn_getText(auxLastName, 51, "\n\tIngrese el apellido del pasajero: ", "\n\tError al ingresar el apellido\n", 2)==0)
							 {
								 strcpy(list[pos].lastName,auxLastName);
								 printf("\n\tModificacion realizada con exito\n\n");
							 }
							 else
							 {
								 // no se modifica
								 ret=-1;
							 }
						 }
					 }
					 if(utn_getNumber(&auxResponse, "\n\tDesea modificar el precio? (0 si- 1 no) ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
					 {
						 if(auxResponse==0)
						 {
							 if(utn_getFloat(&auxPrice, "\n\tIngrese el precio del vuelo: ", "\n\tError al ingresar el precio\n", 50000, 900000, 2)==0)
							 {
								 list[pos].price = auxPrice;
								 printf("\n\tModificacion realizada con exito\n\n");
							 }
						 }
						 else
						 {
							 // no se modifica
							 ret=-1;
						 }
					 }
					 if(utn_getNumber(&auxResponse, "\n\tDesea modificar el Tipo de pasajero? (0 si- 1 no) ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
					 {
						 if(auxResponse==0)
						 {
							 if(utn_getNumber(&auxTypePassenger, "\n\tIngrese el tipo de pasajero\n\t1-turista\n\t2-primera clase\n\t3-ejecutivo\n\t4-premium economy: ", "\n\tError al ingresar el tipo de pasajero\n", 1, 4, 2)==0)
							 {
								 list[pos].typePassenger = auxTypePassenger;
								 printf("\n\tModificacion realizada con exito\n\n");
							 }
						 }
						 else
						 {
							 // no se modifica
							 ret=-1;
						 }
					 }
					 if(utn_getNumber(&auxResponse, "\n\tDesea modificar el codigo de vuelo? (0 si- 1 no) ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
					 {
						 if(auxResponse==0)
						 {
							 if(utn_getText(auxFlycode, 10, "\n\tIngrese el codigo de vuelo: ", "\n\tError al ingresar el codigo de vuelo\n", 2)==0)
							 {
								strcpy(list[pos].flycode,auxFlycode);
								printf("\n\tModificacion realizada con exito\n\n");
								ret=0;
							 }
						 }
						 else
						 {
							 // no se modifica
							 ret=-1;
						 }
					 }
					 else
					 {
						 // se modifica hasta aca
						 ret=-1;
						 printf("\n\tModificacion terminada!\n");
					 }
				 }
				 ret=-1;
				 // se elije no modificar nada primerisima opcion
				 printf("\n\tVolviendo al menu anterior\n\n");
			 }
			 else
			 {
				 ret=-1;
				 printf("\n\tNo se modificara ningun dato\n");
			 }
		}
    }
    ret=-1;

	return ret;
}

int printPassenger(Passenger* list)
{
	char auxType[16];
	char auxStatus[10];

	if(list->typePassenger == 1)
	{
		strcpy(auxType,"Turista");
	}
	else
	{
		if(list->typePassenger == 2)
		{
			strcpy(auxType,"Primera Clase");
		}
		else
		{
			if(list->typePassenger == 3)
			{
				strcpy(auxType,"Ejecutivo");
			}
			else
			{
				if(list->typePassenger == 4)
				{
					strcpy(auxType,"Premium Economy");
				}
			}
		}
	}

	if(list->statusFlight == 1)
	{
		strcpy(auxStatus,"ACTIVO");
	}
	else
	{
		if(list->statusFlight == 2)
		{
			strcpy(auxStatus,"CANCELADO");
		}
	}


	int ret=-1;
	if(list->isEmpty == OCCUP)
	{
		printf("\n\tId: %d\n"
				"\n\tNombre: %s\n"
				"\n\tApellido: %s\n"
				"\n\tPrecio: %.2f\n"
				"\n\tCodigo de vuelo: %s\n"
				"\n\tTipo de pasajero: %s\n"
				"\n\tEstado del vuelo: %s\n\n",list->id, list->name, list->lastName,list->price,list->flycode,auxType,auxStatus);
	}
	return ret;
}

int printPassengers(Passenger* list, int length)
{
	int ret=-1;
	int i;
	if(list!=NULL && length>0)
	{
		for(i=0; i<length;i++)
		{
			if(list[i].isEmpty == OCCUP)
			{
				printPassenger(&list[i]);
			}
		}
		ret=0;
	}
	return ret;
}

int removePassenger(Passenger* list, int len, int id)
{
	int ret=-1;
	int i;
	int auxResponse;
	char auxType[16];
	char auxStatus[10];

		if(list->typePassenger == 1)
		{
			strcpy(auxType,"Turista");
		}
		else
		{
			if(list->typePassenger == 2)
			{
				strcpy(auxType,"Primera Clase");
			}
			else
			{
				if(list->typePassenger == 3)
				{
					strcpy(auxType,"Ejecutivo");
				}
				else
				{
					if(list->typePassenger == 4)
					{
						strcpy(auxType,"Premium Economy");
					}
				}
			}
		}

		if(list->statusFlight == 1)
		{
			strcpy(auxStatus,"ACTIVO");
		}
		else
		{
			if(list->statusFlight == 2)
			{
				strcpy(auxStatus,"CANCELADO");
			}
		}

	printf("\n\tTipo de pasajero: %s\n\tEstado del vuelo: %s\n\n",auxType, auxStatus);

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCCUP && list[i].id==id)
			{
				printf("\n\t!!! Usted esta por dar de baja el id (%d) !!!\n\tNombre: %s\n\tApellido: %s\n\tprecio: %2.f\n\tCodigo de vuelo: %s\n\tTipo de pasajero: %s\n\tEstado del vuelo: %s\n\n",list[i].id, list[i].name,list[i].lastName, list[i].price,list[i].flycode, auxType, auxStatus);

				if(utn_getNumber(&auxResponse, "\n\tDesea continuar? (0 si- 1 no) ", "\n\tPor favor elija una opcion correcta", 0, 1, 2)==0)
				{
					if(auxResponse==0)
					{
						ret=0;
						list[i].isEmpty=EMPTY;
						printf("\n\tBaja realizada con exito!\n\n");
					}
					else
					{
						ret=-1;
						printf("\n\tNo se realizara la baja\n\n");
					}
				}
				ret=-1;
			}
		}
	}
	return ret;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int ret=-1;
	int i;
	int flagSwap;
	int newLen;
	Passenger aux;

	if(list!=NULL && len>0 && order<2)
	{
		if(order==0)
		{
			newLen = len-1;
			do
			{
				flagSwap=0;
				for(i=0;i<newLen;i++)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName) > 0) // s1 es mayor que s2
					{
						flagSwap=1;
						aux = list[i];
						list[i] = list[i+1];
						list[i+1] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName,list[i+1].lastName) == 0) // si llegan a ser iguales, comparamos los tipos de pasajeros
						{
							if(list[i].typePassenger > list[i+1].typePassenger)
							{
								flagSwap=1;
								aux = list[i];
								list[i] = list[i+1];
								list[i+1] = aux;
							}
						}
					}
				}
				newLen--;
			}while(flagSwap);
		}
		else
		{
			if(order==1)
			{
				newLen = len-1;
				do
				{
					flagSwap=0;
					for(i=0;i<newLen;i++)
					{
						if(strcmp(list[i].lastName,list[i+1].lastName) < 0) // s1 es menor que s2
						{
							flagSwap=1;
							aux = list[i];
							list[i] = list[i+1];
							list[i+1] = aux;
						}
						else
						{
							if(strcmp(list[i].lastName,list[i+1].lastName) == 0) // si llegan a ser iguales, comparamos los tipos de pasajeros
							{
								if(list[i].typePassenger < list[i+1].typePassenger)
								{
									flagSwap=1;
									aux = list[i];
									list[i] = list[i+1];
									list[i+1] = aux;
								}
							}
						}
					}
					newLen--;
				}while(flagSwap);
			}
		}
	}
	return ret;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int ret=-1;
	int i;
	int flagSwap;
	int newLen;
	Passenger aux;

	if(list!=NULL && len>0 && order<2)
	{
		if(order==0)
		{
			newLen = len-1;
			do
			{
				flagSwap=0;
				for(i=0;i<newLen;i++)
				{
					if(list[i].statusFlight > list[i+1].statusFlight)
					{
						flagSwap=1;
						aux = list[i];
						list[i] = list[i+1];
						list[i+1] = aux;

						if(strcmp(list[i].flycode,list[i].flycode) < 0)
						{
							flagSwap=1;
							aux = list[i];
							list[i] = list[i+1];
							list[i+1] = aux;
						}
					}
				}
				newLen--;
			}while(flagSwap);
		}
		else
		{
			if(order==1)
			{
				newLen = len-1;
				do
				{
					flagSwap=0;
					for(i=0;i<newLen;i++)
					{
						if(list[i].statusFlight < list[i+1].statusFlight)
						{
							flagSwap=1;
							aux = list[i];
							list[i] = list[i+1];
							list[i+1] = aux;
							if(strcmp(list[i].flycode,list[i].flycode) > 0)
							{
								flagSwap=1;
								aux = list[i];
								list[i] = list[i+1];
								list[i+1] = aux;
							}
						}
					}
					newLen--;
				}while(flagSwap);
			}
		}
	}
	return ret;
}

// *** CARGA FORZADA *** //

void forcedLoadPassenger(Passenger* list, int len, char name[],char lastName[],float price,int typePassenger,int statusFlight , char flycode[])
{
	int indexFree;
		indexFree = findEmptyPassengerPos(list, len);
		list[indexFree].id = newIdGenerator();
		strcpy(list[indexFree].name,name);
		strcpy(list[indexFree].lastName,lastName);
		list[indexFree].price = price;
		list[indexFree].typePassenger = typePassenger;
		strcpy(list[indexFree].flycode,flycode);
		list[indexFree].statusFlight = statusFlight;
		list[indexFree].isEmpty = OCCUP;
}



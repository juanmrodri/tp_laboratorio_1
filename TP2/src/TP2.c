/*
 ============================================================================
 Name        : prototipo_TP2.c
 Author      : Rodriguez Juan Manuel
 Version     : 0.0.2
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "report.h"
#define LEN_PASSENGERS 2000

int main(void) {
	setbuf(stdout, NULL);

	int response;
	int auxId;
	int auxPos;
	int auxOrder;
	float auxAveragePrice;
	float auxTotalPrice;
	int averagePassenger;

	Passenger passengerList[LEN_PASSENGERS];

	initPassengers(passengerList, LEN_PASSENGERS);

	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Josesito", "Perez", 50000, 1, 1, "JPA");
	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Carlos", "Ramirez", 50000, 3, 2, "BNA");
	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Aldo", "Tomaso", 50000, 4, 1, "MDQ");
	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Carlos", "Roldan", 75000, 2, 1, "BSA");
	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Aristobulo", "Saez", 50000, 2, 2, "MDZ");
	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Anibal", "Baez", 95000, 3, 2, "XPR002");
	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Roberto", "Camanio", 50000, 1, 1, "XPR002");
	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Roberto", "Rodriguez", 120000, 2, 1, "XPR002");
	forcedLoadPassenger(passengerList, LEN_PASSENGERS, "Anibal", "Rodriguez", 50000, 1, 1, "XPR002");

	do
	{
		if(utn_getNumber(&response, "\n\tQue desea Realizar\n\n\n"
		"\t1) Alta de pasajero\n\n"
		"\t2) Modificar pasajero\n\n"
		"\t3) Baja de pasajero\n\n"
		"\t4) informar (...)\n\n\t--> ", "\n\tError al ingresar opcion\n", 1, 7, 2)==0)
		{
			switch(response)
			{
				case 1:
					// ALTA
					if(findEmptyPassengerPos(passengerList, LEN_PASSENGERS)>-1)
					{
						printf("\n\t------- Ingrese los datos del pasajero -------\n\n");
						// hay posiciones libres
						loadPassengers(passengerList, LEN_PASSENGERS);
					}
					else
					{
						printf("\n\tPor el momento, no se pueden cargar mas empleados\n\n");
					}

					break;
				case 2:
					// MODIFICAR
					if(isPassengerAdded(passengerList, LEN_PASSENGERS)==0)
					{
						printPassengers(passengerList, LEN_PASSENGERS);

						// si existen usuarios imprimimos y solicitamos al usuario la accion
						if(utn_getNumber(&auxId, "\n\tIngrese el Id del pasajero que quiere modificar ", "\n\tError al ingresar opcion\n", 1, 200, 2)==0)
						{
							// se busca el id y se encuentra su pos. en array
							auxPos = findPassengerById(passengerList, LEN_PASSENGERS, auxId);

							if(auxPos!=-1)
							{
								// se usa esa pos para modificar
								modPassengers(passengerList, LEN_PASSENGERS, auxPos, auxId);

							}
							else
							{
								printf("\n\tNo existe el Id seleccionado\n\n");
							}

						}
						else
						{
							printf("\n\tNo se realizara la modificacion\n\n");
						}

					}
					else
					{
						printf("\n\tNo existen pasajeros ingresados, no se puede realizar la modificacion\n\n");
					}
					break;
				case 3:
					// BAJA
					if(isPassengerAdded(passengerList, LEN_PASSENGERS)==0)
					{
						printPassengers(passengerList, LEN_PASSENGERS);

						// si existen usuarios imprimimos y solicitamos al usuario la accion
						if(utn_getNumber(&auxId, "\n\tIngrese el Id del pasajero que quiere dar de baja ", "\n\tError al ingresar opcion\n", 1, 200, 2)==0)
						{
							// se busca el id y se encuentra su pos. en array
							auxPos = findPassengerById(passengerList, LEN_PASSENGERS, auxId);

							if(auxPos!=-1)
							{
								// se usa esa pos para modificar
								removePassenger(passengerList, LEN_PASSENGERS, auxId);

							}
							else
							{
								printf("\n\tNo existe el Id seleccionado\n\n");
							}

						}
						else
						{
							printf("\n\tNo se realizara la baja\n\n");
						}

					}
					else
					{
						printf("\n\tNo existen pasajeros ingresados, no se puede realizar la baja\n\n");
					}
					break;
				case 4:
					// INFORMAR
					if(isPassengerAdded(passengerList, LEN_PASSENGERS)==0)
					{
						if(utn_getNumber(&response, "\n\tQue desea informar\n\n\n"
										"\t1) Listado de pasajeros Ord. alfabeticamente por Apellido y Tipo de pasajero\n\n"
										"\t2) Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio\n\n"
										"\t3) Listado de los pasajeros por Codigo de vuelo y Estods de vuelo 'ACTIVO'\n\n"
										"\t4) Volver al menu anterior\n\n\t--> ", "\n\tError al ingresar opcion\n\n", 0, 4, 2)==0)
						{
							switch(response)
							{
							case 1:
								// Ordenamiento por apellido y tipo
								if(utn_getNumber(&auxOrder, "\n\tComo quiere ordenar el listado de pasajeros? (0 - ascendente - 1 Descendente)\n\n\t--> ", "\n\tError al ingresar opcion\n", 0, 1, 2)==0)
								{
									sortPassengers(passengerList, LEN_PASSENGERS, auxOrder);
									printf("\n\tOrdenamiento realizado con exito!\n\n");
									printPassengers(passengerList, LEN_PASSENGERS);
								}
								break;
							case 2:

								auxTotalPrice = totalFlightPrice(passengerList, LEN_PASSENGERS);

								auxAveragePrice = averageFlightPrice(passengerList, LEN_PASSENGERS);

								averagePassenger = averagePassengerPrice(passengerList, LEN_PASSENGERS, auxAveragePrice);

								printf("\n\tprecio total: %.2f\n\n", auxTotalPrice);

								printf("\tprecio promedio: %.2f\n\n", auxAveragePrice);

								printf("\tCantidad de pasajeros que superan ese promedio: %d\n\n", averagePassenger);

								break;
							case 3:
								// Listado por Codigo de vuelo y estados activos
								if(utn_getNumber(&auxOrder, "\n\tComo quiere ordenar el listado de pasajeros (codigo de vuelo y estado activo)? (0 - ascendente - 1 Descendente)\n\n\t--> ", "\n\tError al ingresar opcion\n", 0, 1, 2)==0)
								{
									sortPassengersByCode(passengerList, LEN_PASSENGERS, auxOrder);
									printf("\n\tOrdenamiento realizado con exito!\n\n");
									printPassengers(passengerList, LEN_PASSENGERS);
								}
								break;
							}
						}
					}
					else
					{
						printf("\n\tNo existen pasajeros ingresados, no se puede informar nada\n\n");
					}

					break;
				case 6:
					// funcion secreta para printear
					if(isPassengerAdded(passengerList, LEN_PASSENGERS)==0)
					{
						printPassengers(passengerList, LEN_PASSENGERS);
					}
					else
					{
						printf("\n\tPor el momento no se pueden mostrar empleados\n\n");
					}
					break;
				case 7:
					// funcion secreta para limpiar
					system("cls");
					break;
			}
		}

	}while(response!=5);



	return EXIT_SUCCESS;
}

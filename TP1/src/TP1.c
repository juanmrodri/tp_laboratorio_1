/*
 ============================================================================
 Name        : tp_1_prototipo.c
 Author      : Rodriguez Juan Manuel
 Version     : 1.0.1
 Copyright   : Your copyright notice
 Description : calculador de viajes, Ansi-style
 ============================================================================

Enunciado

1. Ingresar kilometros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)
	Precio vuelo Aerolineas:
	Precio vuelo Latam:

3. Calcular todos los costos:
	a) Tarjeta de debito (descuento 10%)
	b) Tarjeta de credito (interes 25%)
	c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
	d) Mostrar precio por km (precio unitario)
	e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)

4. Informar Resultados
	Latam:
	a) Precio con tarjeta de debito: r
	b) Precio con tarjeta de credito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	Aerolíneas:
	a) Precio con tarjeta de debito: r
	b) Precio con tarjeta de credito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	La diferencia de precio es : r

5. Carga forzada de datos

6. Salir

--- tener en cuenta el vuelo mas largo realizado en el 2022 - 19483 km (Korea - Buenos Aires), puede ser el limite de kilometros

 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"


int main(void) {
	setbuf(stdout, NULL);

	int respuestaIngresada;
	int kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;
	float debitoAerolineas;
	float debitoLatam;
	float creditoAerolineas;
	float creditoLatam;
	double bitcoinAerolineas; // mayor precision en digitos despues de la coma con el double, igual respeto lo que indica la consigna con solo 2 digitos despues de la coma
	double bitcoinLatam; // mayor precision en digitos despues de la coma con el double, igual respeto lo que indica la consigna con solo 2 digitos despues de la coma
	float unitarioAerolineas;
	float unitarioLatam;
	float diferenciaPrecios;

	kilometrosIngresados=0;
	precioAerolineas=0;
	precioLatam=0;
	debitoAerolineas=0;
	debitoLatam=0;

	do
		{
			printf(""
			"1) Ingresar Kilometros: (%d km)\n"
			"2) Ingresar precio de vuelos(Aerolineas($%.2f), Latam($%.2f)\n"
			"3) Calcular todos los costos\n"
			"4) Informar resultados\n"
			"5) Carga forzada de datos\n"
			"6) Salir\n",kilometrosIngresados, precioAerolineas, precioLatam);
			if(utn_getNumber(&respuestaIngresada, "Por favor elija una opcion: ", "Error! no se pudo guardar la seleccion\n", 1, 6, 2)==0)
			{
				switch(respuestaIngresada)
				{
					case 1:
						system("cls");
						utn_getNumber(&kilometrosIngresados, "Por favor ingrese los kilometros: ", "Error! al ingresar los kilometros\n", 1, 19483, 2);
					break;

					case 2:
						system("cls");
						printf(""
						"1) Aerolineas\n"
						"2) Latam\n");
						utn_getNumber(&respuestaIngresada, "\nPor favor elija una opcion: ", "Error! en opcion ingresada\n", 1, 19483, 2);
						switch(respuestaIngresada)
						{
						case 1:
							system("cls");
							utn_getFloat(&precioAerolineas, "\n\nPor favor ingrese el precio de Aerolineas: ", "Error al ingresar el precio\n", 1, 250000, 2);
						break;

						case 2:
							system("cls");
							utn_getFloat(&precioLatam, "\n\nPor favor ingrese el precio de Latam: ", "Error al ingresar el precio\n", 1, 250000, 2);
						break;
						}
					break;
					case 3:
						if(precioAerolineas!=0 && precioLatam!=0)
						{
							// importes de Aerolineas
							calculaTarjetaDebito(&debitoAerolineas, precioAerolineas);
							calculaTarjetaCredito(&creditoAerolineas, precioAerolineas);
							calcularBitcoin(&bitcoinAerolineas, precioAerolineas);
							calcularUnitario(&unitarioAerolineas, precioAerolineas, kilometrosIngresados);

							// importes de Latam
							calculaTarjetaDebito(&debitoLatam, precioLatam);
							calculaTarjetaCredito(&creditoLatam, precioLatam);
							calcularBitcoin(&bitcoinLatam, precioLatam);
							calcularUnitario(&unitarioLatam, precioLatam, kilometrosIngresados);

							// diferencia
							calcularDiferencia(&diferenciaPrecios, precioAerolineas, precioLatam);
							printf("\nCalculos realizados\n\n");
						}
						else
						{
							if(precioAerolineas==0 && precioAerolineas==0)
							{
								printf("\nPor favor ingrese los importes para poder calcular!\n\n");
							}
							else
							{
								if(precioAerolineas==0)
								{
									printf("\nPor favor ingrese el importe de Aerolineas para poder calcular\n\n");
								}
								else
								{
									if(precioLatam==0)
									{
										printf("\nPor favor ingrese el importe de Latam para poder calcular\n\n");
									}
								}
							}
						}
					break;
					case 4:
						if(debitoAerolineas==0 || precioLatam==0)
						{
							printf("\nLos informes no estan disponibles en este momento, falta alguno de los datos para poder calcularlos\n");
						}
						else
						{
							if(kilometrosIngresados==0)
							{

								printf("\nAlguno de los calculos no se ha completado, quiere ver los informes de todos modos? 1) si 2) no\n\n");
								utn_getNumber(&respuestaIngresada, "Por favor elija una opcion ", "Error! no se pudo guardar la seleccion\n", 1, 2, 2);
								if(respuestaIngresada==1)
								{
									printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
									printf("a) Precio con tarjeta de debito: $%.2f\n",debitoAerolineas);
									printf("b) Precio con tarjeta de credito: $%.2f\n",creditoAerolineas);
									printf("c) Precio con pagando con bitcoin:  %.2f BTC\n",bitcoinAerolineas);
									printf("d) Precio unitario: %.2f\n\n",unitarioAerolineas);
									printf("Precio Latam: $%.2f\n",precioLatam);
									printf("a) Precio con tarjeta de debito: %.2f\n",debitoLatam);
									printf("b) Precio con tarjeta de credito: %.2f\n",creditoLatam);
									printf("c) Precio con pagando con bitcoin: %.2f BTC\n",bitcoinLatam);
									printf("d) Precio unitario: %.2f\n\n",unitarioLatam);
									printf("La diferencia de precio es: %.2f\n\n",diferenciaPrecios);
								}
							}
							else
							{
								printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
								printf("a) Precio con tarjeta de debito: $%.2f\n",debitoAerolineas);
								printf("b) Precio con tarjeta de credito: $%.2f\n",creditoAerolineas);
								printf("c) Precio con pagando con bitcoin:  %.2f BTC\n",bitcoinAerolineas);
								printf("d) Precio unitario: %.2f\n\n",unitarioAerolineas);
								printf("Precio Latam: $%.2f\n",precioLatam);
								printf("a) Precio con tarjeta de debito: %.2f\n",debitoLatam);
								printf("b) Precio con tarjeta de credito: %.2f\n",creditoLatam);
								printf("c) Precio con pagando con bitcoin: %.2f BTC\n",bitcoinLatam);
								printf("d) Precio unitario: %.2f\n\n",unitarioLatam);
								printf("La diferencia de precio es: %.2f\n\n",diferenciaPrecios);
							}
						}

					break;
					case 5:
						if(kilometrosIngresados!=0 || precioAerolineas!=0 || precioLatam!=0)
						{
							printf("\nAlguna de las opciones ya tiene datos ingresados, desea sobreescribir? 1) si 2) no\n\n");
							utn_getNumber(&respuestaIngresada, "Por favor elija una opcion ", "Error! no se pudo guardar la seleccion\n", 1, 2, 2);
							if(respuestaIngresada==1)
							{
								utn_cargaForzada(&kilometrosIngresados, &precioAerolineas, &precioLatam, 7090, 162965, 159339);
							}
							else
							{
								printf("\nNo se realizo la carga forzada!\n\n");
							}
						}
						else
						{
							utn_cargaForzada(&kilometrosIngresados, &precioAerolineas, &precioLatam, 7090, 162965, 159339);
						}
					break;
				}
			}
			else
			{
				printf("\nPor favor elija una de las 6 opciones!\n\n");
			}

		}while(respuestaIngresada!=6);

	return EXIT_SUCCESS;
}

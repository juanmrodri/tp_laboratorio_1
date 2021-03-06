/*
 * utn.h
 *
 *	tener en cuenta que en la note estas bibliotecas se llaman input.h/input.c
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* \brief Solicita un numero entero a un usuario y se llama a la funcion getInt para recibirlo
* \param pResultado Se carga el numero ingresado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
* \brief Solicita un numero flotante a un usuario
* \param pResultado Se carga el numero ingresado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
* \brief permite ingresar 3 parametros por valor, y los carga a 3 punteros
* \param kilometros puntero donde se alojara el dato seleccionado en valor km
* \param precioAerolineas puntero donde se alojara el dato seleccionado en valor aerolineas
* \param precioLatam puntero donde se alojara el dato seleccionado en valor latam
* \param km valor para alojar en puntero kilometros
* \param aerolineas valor para alojar en puntero precioAerolineas
* \param latam valor para alojar en puntero precioLatam
* \return exito = [0] - error = [1]
*/
int utn_cargaForzada(int* kilometros, float* precioAerolineas, float* precioLatam, int km, float aerolineas, float latam);

#endif /* INPUT_H_ */

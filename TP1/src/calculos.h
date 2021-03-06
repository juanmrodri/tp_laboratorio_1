/*
 * calculos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: jmrodri
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
* \brief permite realizar el calculo pertinente para el pago en debito
* \param pResultado puntero con el resultado de la operacion
* \param importe valor del importe para realizar el calculo
* \return exito = [0] - error = [1]
*/
int calculaTarjetaDebito(float *pResultado, float importe);

/**
* \brief permite realizar el calculo pertinente para el pago en credito
* \param pResultado puntero con el resultado de la operacion
* \param importe valor del importe para realizar el calculo
* \return exito = [0] - error = [1]
*/
int calculaTarjetaCredito(float *pResultado, float importe);

/**
* \brief permite realizar el calculo pertinente para el pago en Bitcoins
* \param pResultado puntero con el resultado de la operacion
* \param importe valor del importe para realizar el calculo
* \return exito = [0] - error = [1]
*/
int calcularBitcoin(double *pResultado, float importe);

/**
* \brief permite realizar el calculo del precio unitario en relacion a los kms
* \param pResultado puntero con el resultado de la operacion
* \param importe valor del importe para realizar el calculo
* \param distancia valor de la distancia para realizar el calculo
* \return exito = [0] - error = [1]
*/
int calcularUnitario(float *pResultado, float importe, int distancia);

/**
* \brief permite calcular la diferencia entre el importe de aerolineas y latam
* \param pResultado puntero con el resultado de la operacion
* \param importeAerolineas valor del importe de aerolineas
* \param importeLatam valor valor del importe de Latam
* \return exito = [0] - error = [1]
*/
int calcularDiferencia(float *pResultado, float importeAerolineas, int importeLatam);


#endif /* CALCULOS_H_ */

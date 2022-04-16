/*
 * calculos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: jmrodri
 */

#include <stdio.h>
#include <stdlib.h>

int calculaTarjetaDebito(float *pResultado, float importe)
{
	int ret;

	ret=1;
	if(pResultado!=NULL && importe>0)
	{
		*pResultado = importe*10/100;
		ret=0; // todo ok!
	}

	return ret;
}

int calculaTarjetaCredito(float *pResultado, float importe)
{
	int ret;
	float auxPorcentaje;

	ret=1;
	if(pResultado!=NULL && importe>0)
	{
		auxPorcentaje = importe*25/100;
		importe = importe + auxPorcentaje;
		*pResultado = importe;
		ret=0; // todo ok!
	}

	return ret;
}

int calcularBitcoin(double *pResultado, float importe)
{
	int ret;

	ret=1;
	if(pResultado!=NULL && importe>0)
	{
		// 1 BTC = 4606954.55
		*pResultado = importe/4606954.55;
		ret=0; // todo ok!
	}

	return ret;
}

int calcularUnitario(float *pResultado, float importe, int distancia)
{
	int ret;

	ret=1;
	if(pResultado!=NULL && importe>0 && distancia>0)
	{
		*pResultado = (float)importe/distancia;
		ret=0; // todo ok!
	}

	return ret;
}

int calcularDiferencia(float *pResultado, float importeAerolineas, int importeLatam)
{
	int ret;

	ret=1;
	if(pResultado!=NULL && importeAerolineas>0 && importeLatam>0)
	{

		if(importeAerolineas>importeLatam)
		{
			*pResultado=importeAerolineas-importeLatam; // aerolineas es mayor
		}
		else
		{
			if(importeLatam>importeAerolineas)
			{
				*pResultado=importeLatam-importeAerolineas; // Latam es mayor
			}
			else
			{
				*pResultado=0; // en el rarisimo caso de que los dos importes sean iguales
			}
		}
		ret=0; // todo ok!
	}

		return ret;
}



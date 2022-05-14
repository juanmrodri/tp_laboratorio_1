/*
 * report.c
 *
 *  Created on: 14 may 2022
 *      Author: juanm
 */

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "ArrayPassenger.h"
#include "utn.h"
#define EMPTY 1
#define OCCUP 0

float totalFlightPrice(Passenger* list, int len)
{
	int i;
	float totalPrice=0;

	if(list!= NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCCUP)
			{
				totalPrice = totalPrice+list[i].price;
			}
		}
	}

	return totalPrice;
}

float averageFlightPrice(Passenger* list, int len)
{
	int i;
	int countPassengers=0;
    float averagePrice;

	if(list!= NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCCUP)
			{
				countPassengers++;
			}
		}
		averagePrice = totalFlightPrice(list, len);

		averagePrice = averagePrice / (float) countPassengers;
	}

	return averagePrice;
}

int averagePassengerPrice(Passenger* list, int len, float averagePrice)
{
	int totalPassenger=0;
	int i;

	if(list!= NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCCUP)
			{
				if(list[i].price > averagePrice)
				{
					totalPassenger++;
				}
			}
		}
	}
	return totalPassenger;
}

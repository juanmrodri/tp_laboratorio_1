/*
 * report.h
 *
 *  Created on: 14 may 2022
 *      Author: juanm
 */

#ifndef REPORT_H_
#define REPORT_H_

/** \brief sum all the price field of every OCCUP array positions
* \param list Passenger*
* \param len int
* \return float total price
*/
float totalFlightPrice(Passenger* list, int len);

/** \brief calculate the average price, using totalFloghtPrice func.
* \param list Passenger*
* \param len int
* \return float average price
*/
float averageFlightPrice(Passenger* list, int len);

/** \brief count, if exist, all the > averageFlightPrice array[].price positions
* \param list Passenger*
* \param len int
* \param averagePrice float
* \return float average price
*/
int averagePassengerPrice(Passenger* list, int len, float averagePrice);


#endif /* REPORT_H_ */

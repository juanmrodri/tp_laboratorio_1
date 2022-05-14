/*
 * ArrayPassenger.h
 *
 *  Created on: 27 abr 2022
 *      Author: juanm
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
		{
			int id;
			char name[51];
			char lastName[51];
			float price;
			char flycode[10];
			int typePassenger; // 1-turista// 2-primera clase// 3-ejecutivo// 4-premium economy
			int statusFlight; // 1 - activo // 2 cancelado
			int isEmpty;
		} Passenger;


/** \brief To indicate that all position in the array are empty,* this function put the flag (isEmpty) in TRUE in all* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int initPassengers(Passenger* list, int len);

/** \brief ask the user for the passengers data fields, calls addPassenger() input data is ok!
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int loadPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);

/** \brief ask the user for the passengers data fields to modify, calls addPassenger() input data is ok!
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int modPassengers(Passenger* list, int len, int pos, int id);

/** \brief find a Passenger by Id en returns the index position in array.*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int sortPassengers(Passenger* list, int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list);

/** \brief loops the array and calls printPassenger
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengers(Passenger* list, int length);

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int sortPassengersByCode(Passenger* list, int len, int order);

/** \brief finds the first empty position, when success its asigned to pos int*
* \param list Passenger*
* \param len int
* \param pos int*
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) - i position of the array
*/
int findEmptyPassengerPos(Passenger* list, int len);

/** \brief finds the first occupied position
* \param list Passenger*
* \param len int
* \param pos int*
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int isPassengerAdded(Passenger* list, int len);

/** \brief forced load in a existing list of passengers the values received as parameters* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param statusFlight int
* \param flycode[] char
*/
void forcedLoadPassenger(Passenger* list, int len, char name[],char lastName[],float price,int typePassenger,int statusFlight , char flycode[]);


#endif /* ARRAYPASSENGER_H_ */

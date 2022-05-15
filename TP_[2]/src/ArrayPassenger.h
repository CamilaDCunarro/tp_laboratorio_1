/*
 * ArrayPassenger.h
 *
 *  Created on: 12 may. 2022
 *      Author: Asus
 */

#ifndef ARRAYPASSENGER_H_
#define  LEN_PASSENGER 20000
#define ARRAYPASSENGER_H_





struct {
	  int id;
	  char name[51];
	  char lastName[51];
	  float price;
	  char flycode[10];
	  int typePassenger;
	  // primera clase, ejecutivo y premium
	  int isEmpty;
	} typedef Passenger;


void initPassengers(Passenger pArray[], int len);
int addPassenger(Passenger pArry[], int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[]);
int buscarIndexPorIsEmpty(Passenger pArray[], int len);
int findPassengerById (Passenger pArray [],int len, int id);
int removePassenger(Passenger pArray[], int len, int idAsociado);
void printOnePassenger(Passenger onePassenger, int len);
int printPassenger(Passenger pArray[], int len);
void increaseidPassenger();

int modificPassager(Passenger pArray[], int len, int id);
int sortPassengersByCode();




#endif /* ARRAYPASSENGER_H_ */

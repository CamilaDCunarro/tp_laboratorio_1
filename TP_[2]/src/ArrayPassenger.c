/*
 * ArrayPassenger.c
 *
 *  Created on: 12 may. 2022
 *      Author: Asus
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "utn.h"

void initPassengers(Passenger pArray[], int len) {

	if (pArray != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			pArray[i].isEmpty = 1;
		}
	}
}


int buscarIndexPorIsEmpty(Passenger pArray[], int len)
{
	int retorno = -1;

		if(pArray != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(pArray[i].isEmpty == 1)
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

int addPassenger(Passenger pArry[], int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[])
{
	int retorno = -1;
	Passenger auxiliarPassenger;

	if(pArray != NULL && len > 0 && name != NULL && lastName !=NULL && flycode !=NULL  )
	{
		if(	(utn_getStringLeter(auxiliarPassenger.name, "Ingrese Nombre", "ERROR", 2) == 0 &&
				utn_getStringLeter(auxiliarPassenger.lastName, "Ingrese Apellido", "ERROR", 2)
			 == 0 &&
			utn_getNumeroFlotante(&auxiliarPassenger.price ,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getStringLeter(auxiliarPassenger.flycode,"Ingrese Codigo de vuelo ","ERROR",2)==0) &&
			utn_getNumero(&auxiliarPassenger.typePassenger, "Ingrese tipo de pasajero primera clase, ejecutivo y premium", "ERROR", 1, 100, 2)==0)

		{

			increaseidPassenger();
			myGets(auxiliarPassenger.id, len);
			retorno = 0;
			/*auxiliarPassenger.id = *id;
			auxiliarPassenger.isEmpty = 0;
			pArray[indice] = auxiliarPassenger;*/

		}
	}
	return retorno;
}


void increaseidPassenger(){

	static int id = 0;

    id++;


    printf("NumeroStatic: %d\n", id);
}


int findPassengerById (Passenger pArray [],int len, int id){
	int retorno =-1;

	int i ;
	if (pArray != NULL && len >0 && id>0){

		for (i=0;i<len; i++){

			if (pArray[i].id==id && pArray[i].isEmpty ==0 ){
				retorno =i; //me retorna la poscicion del array
				break;

			}

		 }

		}
return retorno;


}
int removePassenger(Passenger pArray[], int len, int idAsociado) {
	int retorno = -1;
	int index;
	if (pArray != NULL && len > 0 && idAsociado > 0) {
		index = findPassengerById(pArray, len, idAsociado);
		if (index != -1) {
			printOnePassenger(pArray[index]);
			pArray[index].isEmpty = 1;
			retorno = 0;
		}

	}
	return retorno;
}

void printOnePassenger(Passenger onePassenger, int len)
{
	if(onePassenger.isEmpty == 0)

	{
		printf("%d %s  %s  %d  %d", onePassenger.id, onePassenger.name, onePassenger.lastName, onePassenger.price, onePassenger.flycode, onePassenger.typePassenger);
	}
}


int printPassenger(Passenger pArray[], int len)
{
	int retorno = -1;

	if(pArray != NULL && len >0)
	{
		for(int i = 0; i < len; i++)
		{
			printOnePassenger(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int sortPassengersByCode(){

}

int modificPassager(Passenger pArray[] ,int len, int id)

{
	int respuesta = -1;
	Passenger auxModificacion;

	if(pArray != NULL && pArray > 0 && id < len && id >= 0 && pArray[id].isEmpty == 0)
	{
		if(	(utn_getStringLeter(auxModificacion.name, "Ingrese Nombre", "ERROR", 2) == 0 &&
						utn_getStringLeter(auxModificacion.lastName, "Ingrese Apellido", "ERROR", 2)
					 == 0 &&
					utn_getNumeroFlotante(&auxModificacion.price ,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0 &&
					utn_getStringLeter(auxModificacion.flycode,"Ingrese Codigo de vuelo ","ERROR",2)==0) &&
					utn_getNumero(&auxModificacion.typePassenger, "Ingrese tipo de pasajero primera clase, ejecutivo y premium", "ERROR", 1, 100, 2)==0)
		{
			respuesta = 0;
			auxModificacion.id = pArray[id].id;
			auxModificacion.isEmpty = 0;
			pArray[id] = auxModificacion;
		}
	}
	return respuesta;
}



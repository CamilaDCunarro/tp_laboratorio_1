/*
 * utn.h
 *
 *  Created on: 12 may. 2022
 *      Author: Asus
 */

#ifndef UTN_H_
#define UTN_H_



/* - getInt
  - getFloat
  - getString
  - getNumero
  - esNumerica
  - myGets*/


int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int getInt(int* pResultado);
int esNumerica(char pArrar[], int longitud);
int myGets(char pArray [], int longitud);
int utn_getStringLeter(char pArray[],char* mensaje,char* mensajeError, int reintentos);
int esLetra(char cadena[]);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int esFlotante(char* cadena);
int getFloat(float* pResultado);


#endif /* UTN_H_ */

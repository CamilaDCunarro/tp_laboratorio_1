/*
 * bibliotecaTp.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Asus
 */

#ifndef BIBLIOTECATP_H_
#define BIBLIOTECATP_H_
#endif /* BIBLIOTECATP_H_ */
#include <stdio.h>



int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,int minimo, int maximoDeReintentos);
/**
 * \brief Solicita un numero al usuario,lo valida, verifica y devuelve el resultado.
 * \param pNumeroIngresado es un puntero al resultado. Aqui se deja el numero ingresado por el usuario.
 * \param mensaje es el mensaje que voy a mostrar.
 * \param mensaje error a mostrar.
 * \param minimo es el minimo valor aceptado.
 * \param maximo es el maximo valor aceptado.
 * \param maximoDeReintentos es la maxima de veces que voy a poder operar en caso de error.
 * \return en caso de exito ( 0) y (-1) en caso que de error.
 */
int precioDescuento (float *pPrecioDescuento,float *preciofinalDescuento );
/**
 * \brief Solicita un numero al usuario,lo valida, verifica,realiza el descuento y lo guardia en el puntero precio final y devuelve el resultado.
 * \param pPrecioDescuento float  puntero al precio ingresado por el usuario. .
 * \param preciofinalDescuento float puntero al preciofinal ingresado por el usuario.
 * \return en caso de exito ( 0) y (-1) en caso que de error.
 */

int precioInteres (float *pPrecioInteres, float *preciofinalInteres);
/**
 * \brief Solicita un numero al usuario,lo valida, verifica,realiza el calculo del interes y lo guardia en el puntero precio final interes y devuelve el resultado.
 * \param pPrecioInteres float  puntero al precio ingresado por el usuario. .
 * \param preciofinalInteres float puntero al preciofinal ingresado por el usuario.
 * \return en caso de exito ( 0) y (-1) en caso que de error.
 */
int precioBitcon (float *pPrecioIngresado, float * pPrecioFinalBitcon);

/**
 * \brief Solicita un numero al usuario,lo valida, verifica,realiza el calculo y lo guardia en el pPrecioFinalBitcon y devuelve el resultado.
 * \param pPrecioIngresa float  puntero al precio ingresado por el usuario. .
 * \param preciofinalBitcon float puntero al preciofinal ingresado por el usuario.
 * \return en caso de exito ( 0) y (-1) en caso que de error.
 */
int precioUnitario ( float *pPrecioIngresado, int kilometros, float *pPrecioUnitarioFinal);
/**
 * \brief Solicita un numero al usuario,lo valida, verifica,realiza el calculo unitario entre el precio ingresado y los kilometros y lo guardia en el puntero precio Unitario final y devuelve el resultado.
 * \param pPrecioIngresado float  puntero al precio ingresado por el usuario. .
 * \param int kilometros ingresados por el usuario. Siempre es el mismo valor por lo cual no lleva puntero.
 * \return en caso de exito ( 0) y (-1) en caso que de error.
 */
int diferenciaDePrecio (float *diferenciaPrecio,float precioLatam, float precioAerolineas);
/**
 * \brief Solicita dos precios al usuario,calcula y guarda el resultado en el puntero diferenciaPrecio.
 * \param direnciaPrecio  float puntero que guarda el calculo entre los precios intresados por el usuario.
 * \return en caso de exito ( 0) y (-1) en caso que de error.
 */
void cargaForzada();
/**
 * \brief Datos ya cargados por el programador. Realiza Calculos y los retorna a travez de Printf.

 * \return.
 */




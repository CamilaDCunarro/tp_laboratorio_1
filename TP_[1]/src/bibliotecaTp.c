/*
 * bibliotecaTp.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Asus
 */
#include <stdio.h>

#include "bibliotecaTp.h"




	int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
			int maximo, int minimo, int maximoDeReintentos){

		int auxNumeroIngresado;
		int retorno;
		retorno = -1;

		if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
			do{
				printf("%s", mensaje);
				scanf("%d", &auxNumeroIngresado);
				maximoDeReintentos--;

				if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
							*pNumeroIngresado = auxNumeroIngresado;
							retorno = 0;
							break;
				}else{
					printf("%s", mensajeError);
				}

			}while(maximoDeReintentos > 0);
		}

		return retorno;
	}


	int precioDescuento (float *pPrecioDescuento, float *preciofinalDescuento){

		int retornoDescuento;
		float auxiliarDescuento;

		retornoDescuento=-1;

		if (pPrecioDescuento != NULL && preciofinalDescuento != NULL) {

			 auxiliarDescuento = *pPrecioDescuento;


			 *preciofinalDescuento = auxiliarDescuento -( auxiliarDescuento * 0.10);

				retornoDescuento=0;
			}

		return retornoDescuento;

	}
	int  precioInteres (float *pPrecioInteres, float *preciofinalInteres){

			int retornoInteres;
			float auxiliarInteres;
			retornoInteres=-1;

			if (pPrecioInteres != NULL && preciofinalInteres != NULL ) {

				 auxiliarInteres = *pPrecioInteres;
				 //aca guardo lo que entro y la asigno a otra variable auxiliar.

				 *preciofinalInteres = auxiliarInteres + (auxiliarInteres *0.25);

					retornoInteres=0;
				}

			return retornoInteres;

		}

int precioBitcon (float *pPrecioIngresado, float * pPrecioFinalBitcon)
{
	int retornoBitcon;
	retornoBitcon=-1;
	float precioBitcon;
	precioBitcon=  4606954.55;
	float auxiliarBitcon;

	if (pPrecioIngresado != NULL && pPrecioFinalBitcon != NULL ){

		auxiliarBitcon= *pPrecioIngresado;

		*pPrecioFinalBitcon= auxiliarBitcon * precioBitcon;


		retornoBitcon=0;
	}

	return retornoBitcon;

}

int precioUnitario ( float *pPrecioIngresado, int kilometros, float *pPrecioUnitarioFinal){

	int retornoUnitario;
	retornoUnitario=-1;
	float auxiliarPrecioUnitario;



	if (pPrecioIngresado != NULL && pPrecioUnitarioFinal){

		auxiliarPrecioUnitario=*pPrecioIngresado;


		*pPrecioUnitarioFinal= auxiliarPrecioUnitario * kilometros;


		retornoUnitario=0;
	}


return retornoUnitario;

}

int diferenciaDePrecio (float *diferenciaPrecio,float precioLatam, float precioAerolineas){

	int retornoDiferencia=-1;


	if (diferenciaPrecio!= NULL ){

		*diferenciaPrecio = precioLatam-precioAerolineas;


			retornoDiferencia=0;
		}


	return retornoDiferencia;
}

void cargaForzada(){

	int kilometrosIngresadosForzados;
	kilometrosIngresadosForzados=7090;
	int precioLatam=159339;
	int precioAerolineas=162965;
	float descuentoLatam;
	float descuentoAerolineas;
	float interesLatam;
	float interesAerolieas;
	float precioBitcon=4606954.55;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;

	float bitcoinLatam;
	float bitcoinAerolineas;
	int difrenciaPrecio;

	descuentoAerolineas=(float) precioAerolineas- (precioAerolineas *0.10);
	descuentoLatam= (float)precioLatam - (precioLatam*0.10);

	interesAerolieas=(float)precioAerolineas + (precioAerolineas*0.25);
	interesLatam= (float)precioLatam + (precioLatam*0.25);

	bitcoinLatam= (float) precioLatam*precioBitcon;
	bitcoinAerolineas=(float)precioAerolineas*precioBitcon;

	precioUnitarioAerolineas= precioAerolineas * kilometrosIngresadosForzados;
	precioUnitarioLatam=precioLatam*kilometrosIngresadosForzados;

	difrenciaPrecio= precioLatam - precioAerolineas;

	printf ("\n KMs Ingresados \n %d",kilometrosIngresadosForzados);
	printf ("\n LATAM:\n");

	printf("\n a) Precio con tarjeta de débito:%2.f\n",descuentoLatam);
	printf("\n b) Precio con tarjeta de crédito: %2.f \n",interesLatam);
	printf("\n c) Precio pagando con bitcoin: %2.f\n",bitcoinLatam);
	printf("\n d) Precio unitario:: %2.f \n",precioUnitarioLatam);

	printf ("\n AEROLINEAS:\n");
	printf("\n a) Precio con tarjeta de débito: $ %2.f\n",descuentoAerolineas);
	printf("\n b) Precio con tarjeta de crédito: $ %2.f \n",interesAerolieas);
	printf("\n c) Precio pagando con bitcoin: $  %2.f\n",bitcoinAerolineas);
	printf("\n d) Precio unitario:: $ %2.f \n",precioUnitarioAerolineas);


	printf ("\nLa diferencia de precio es:$ %d\n",difrenciaPrecio);

}

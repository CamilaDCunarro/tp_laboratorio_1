/*
 ============================================================================
Para ello el programa iniciará y contará con un menú de opciones:

el usuario ingresa el precio y el kilometro. ejemplo si el kilometro salen 100 pesos calcularlo

en el submenu debo tener una opcion de salir del sub menu al menu principal

1. Ingresar Kilómetros: ( km=x) x son los kilometros que ingresa el usuario. VALIDAR LOS DATOS ENTRE 0 Y 1000000


2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z) ACA PUEDE IR UN SUBMENU
Ejemplo:
ingrese 550 km
y


- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:

a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)  //precio*kilometro
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

4. Informar Resultados  (Se puede ingresar un submenu) ACA VAN LOS PRINTF.
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “

5. Carga forzada de datos ( en el 5 son datos que ya le pongo yo por defecto, no se los pido al usuario si apreto 5 y 4 me tiene que mostar
los datos que me da el 4 con los datos cargados en el 4 )
6. Salir


validar que sucede que pasa cuando el usuario no ingresa nada! PRESTARLE ATENCION A LAS CONSIGNAS.
USAR FUNCIONES Y BIBLIOTECA.
USAR PASAJE POR REFERENCIA.
 ============================
 */
//ORDENAR EL CODIGO CONTROL SHIF F

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTp.h"



int main(void) {
setbuf(stdout, NULL);

int  kilometrosIngresados;
float precioAerolineas;
float precioLatam;
int menuDeOpciones;
int subMenuDeOpciones;

int validacionRetornoMenu;
int validacionRetornoSubMenu;
int banderaKilometros;
int banderaSubmenu;
float precioDescuentoLatam;
float precioDescuentoAerolineas;
float precioInteresLatam;
float precioInteresAerolineas;
float precioAerolineasBitcon;
float precioLatamBitcoin;
float precioUnitarioFinalAerolineas;
float precioUnitarioFinalLatam;
float diferenciaDePrecios;
int validacionRetornoDescuentoAerolineas;
int validacionRetornoDescuentoLatam;
int validacionRetornoInteresAerolineas;
int validacionRetornoInteresLatam;
int validacionPrecioBitconAerolineas;
int validacionPrecioBitconLatam;
int validacionPrecioUnitarioLatam;
int validacionPrecioUnitarioAerolineas;
int validacionDifereciaDePrecio;
int banderaCalculos;
int banderaDeingresos;


banderaKilometros = 0;
banderaSubmenu=0;
banderaCalculos=0;
banderaDeingresos=0;
//AGREGARLE BANDERAS


	do {

		validacionRetornoMenu = getInt(&menuDeOpciones,
						"\n 1.Ingresar Kilómetros:\n 2. Ingresar Precio de Vuelos: LATAM , AEROLINEAS. \n 3. Calcular todos los costos:\n 4. Informar resultados:\n 5. Carga forzada de datos:\n 6. Salir:\n",
						"La opcion es incorrecta:\n", 6, 1, 1);

		if (validacionRetornoMenu == 0) {

			switch (menuDeOpciones) {
			case 1:

				printf("\n>>>Opcion 1: Ingrese KILOMETROS<<<\n");

				if (kilometrosIngresados <=0 && kilometrosIngresados >1000000) {

					printf("\nERROR: INGRESE KILOMETROS VALIDOS\n");

				} else {
					scanf("%d",&kilometrosIngresados);
					printf("\n KMs Ingresados :%d\n", kilometrosIngresados);

					banderaKilometros = 1;

				}
				break;

			case 2:
				if (banderaKilometros == 0 ) {
					printf("\n ERROR INGRESE KILOMENTROS ");

				} else {
					do {
						validacionRetornoSubMenu =
						getInt(&subMenuDeOpciones,
										"\n INGRESE PRECIO DE VUELVOS\n 1. PRECIO VUELO LATAM :\n 2.PRECIO VUELO AEROLINEAS:\n 3.VOLVER\n",
										"La opcion es incorrecta:\n", 3, 1, 1);
						if (validacionRetornoSubMenu == 0) {

							switch (subMenuDeOpciones) {
							case 1:

								printf ("\nIngrese Precio de LATAM\n");
								scanf ("%f.2",&precioLatam);
								printf ("\nEl precio Ingresado de LATAM es: %2.f\n",precioLatam);

								banderaSubmenu=1;
								break;

							case 2:
								if (banderaSubmenu==0){
									printf ("Error:Ingrese Precio de LATAM ");
								}else
									{
									printf ("\nIngrese Precio de AEROLINEAS\n");
									scanf("%f.2",&precioAerolineas);
									printf ("\nEl precio Ingresado de Aerolineas es: %2.f \n",precioAerolineas);


								}

								break;
								}
							}

					} while (subMenuDeOpciones != 3);

				}

				banderaDeingresos=1;
				break;


			case 3:
				//CALCULOS

				printf("\n>>>Opcion 3: REALIZAR CALCULOS<<<\n");

				if (banderaDeingresos==0){

					printf ("\n ERROR, INGRESE LOS PRECIOS PRIMERO");
				} else {
				validacionRetornoDescuentoLatam= precioDescuento(&precioLatam,&precioDescuentoLatam);
				validacionRetornoInteresLatam=precioInteres(&precioLatam, &precioInteresLatam);
				validacionPrecioBitconLatam=precioBitcon(&precioLatam, &precioLatamBitcoin);
				validacionPrecioUnitarioLatam=precioUnitario(&precioLatam, kilometrosIngresados, &precioUnitarioFinalLatam);

				validacionRetornoDescuentoAerolineas=precioDescuento(&precioAerolineas,&precioDescuentoAerolineas);
				validacionRetornoInteresAerolineas= precioInteres(&precioAerolineas, &precioInteresAerolineas);
				validacionPrecioBitconAerolineas=precioBitcon(&precioAerolineas, &precioAerolineasBitcon);
				validacionPrecioUnitarioAerolineas=precioUnitario(&precioAerolineas, kilometrosIngresados, &precioUnitarioFinalAerolineas);


				validacionDifereciaDePrecio =diferenciaDePrecio(&diferenciaDePrecios, precioLatam, precioAerolineas);
				}

				banderaCalculos=1;

				break;


			case 4:

				if (banderaCalculos==0){

					printf("\n ERROR,Debe realizar los calculos primero para mostrarlos");
				}else {
					//LATAM
									printf ("\n KILOMETROS INGRESADOS:\n %d",kilometrosIngresados);

									printf ("\n LATAM:\n");

									if (validacionRetornoDescuentoLatam==0){
										printf ("\n a) Precio con tarjeta de débito: $ %2.f\n",precioDescuentoLatam);

									} else {
										printf ("Error, no se calculo el descuento");
									}

									if (validacionRetornoInteresLatam==0){
										printf ("\n b) Precio con tarjeta de crédito $ %2.f \n",precioInteresLatam);
									}else {
										printf ("Error, no se calculo el interes");
									}
									if (validacionPrecioBitconLatam==0){
										printf ("\n c) Precio pagando con bitcoin : $ %2.f \n",precioLatamBitcoin);

									}else {
										printf ("Error, no se calculo el precio en Bitcon");
									}
									if (validacionPrecioUnitarioLatam==0){
										printf ("\n c) d) Precio unitario:$ %2.f \n",precioUnitarioFinalLatam);
									}else {
										printf ("Error, no se calculo el precio unitario");
									}


									printf ("\n AEROLINEAS:\n");

									if (validacionRetornoDescuentoAerolineas==0){
										printf ("\n a) Precio con tarjeta de débito: $ %2.f\n",precioDescuentoAerolineas);

									} else {
										printf ("\nError, no se calculo el descuento\n");
									}

									if (validacionRetornoInteresAerolineas==0){
										printf ("\n b) Precio con tarjeta de crédito: $ %2.f \n",precioInteresAerolineas);
									}else {
										printf ("\nError, no se calculo el interes\n");
									}
									if (validacionPrecioBitconAerolineas==0){
										printf ("\n c) Precio pagando con bitcoin :$ %2.f \n",precioAerolineasBitcon);

									}else {
										printf ("\nError, no se calculo el precio en Bitcon\n");
									}
									if (validacionPrecioUnitarioAerolineas==0){
										printf ("\n c) d) Precio unitario:: $ %2.f \n",precioUnitarioFinalAerolineas);
									}else {
										printf ("\nError, no se calculo el precio unitario\n");
									}

									if (validacionDifereciaDePrecio==0){
										printf ("\nLa diferencia de precio es: $ %2.f\n",diferenciaDePrecios);
									}


				}

				break;
			case 5:
				printf("\n>>>Opcion 5  : CARGA FORZADA <<<\n");
				cargaForzada();

				break;

			case 6:
				break;
			}
		} else {
			printf("Error: Selecione Opcion correcta");
		}

	} while (menuDeOpciones != 6);

	return EXIT_SUCCESS;
	}




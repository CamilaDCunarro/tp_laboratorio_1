/*

Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.

El sistema deberá tener el siguiente menú de opciones:

1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id.



El resto de los campos se le pedirá al usuario.

2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo



3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.



4. INFORMAR: (submenu)


1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero. (premium, midium, basic)

2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.


3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’

1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que NO se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero. ( flag si no ingreso antes error)

2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
Para la realización de este programa, se utilizará una biblioteca llamada “ArrayPassenger” que
facilitará el manejo de la lista de pasajeros y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "ArrayFlight.h"

#define  LEN_PASSENGER 2
#define LEN_VUELO 10




int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int opcionSubMenu;
	int auxPassenger;
	int auxId=0;

	Passenger Pasajero [LEN_PASSENGER];
	Flight Vuelo [LEN_VUELO];



	 initPassengers(Pasajero, LEN_PASSENGER);



	do{

		if ((utn_getNumero(&opcionMenu," ****MENU PRINCIPAL****\n"
				"\n 1.ALTA PASAJERO:"
				" \n 2.MODIFICAR PASJERO: "
				"\n 3.BAJA PASAJERO: "
				"\n 4.INFORMAR: "
				"\n 5.CARGA FORZADA :\n"
				" 7.SALIR: \n"
				,"ERROR: INGRESE OPCION CORRECTA ", 1, 7, 2)==0))


		{

		    switch(opcionMenu)
		    {
		       case 1:

		    	   auxPassenger= buscarIndexPorIsEmpty(Pasajero, LEN_PASSENGER);
		    	   if (auxPassenger>0){

		    		   if (addPassenger(auxPassenger, LEN_PASSENGER, auxId, Pasajero.name,Pasajero.lastName,Pasajero. price, Pasajero.typePassenger,Vuelo. flycode)==0)
		    		   {

		    		   printf ("Se cargo con Exito");
		    	   }
		    }



		            break;
		       case 2:

		    	   /*2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
                   o Precio o Tipo de pasajero o Código de vuelo*/

		            break;
		       case 3:

		    	   /*3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.*/
		            break;
		       case 4:

		    	    if (utn_getNumero(opcionSubMenu, "Elija la opcion a mostrar:\n 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
		    	    		"\n 2. Total y promedio de los precios de los pasajes y cuántos pasajeros superan el precio promedio.\n"
		    	    		" 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n 5 Salir ", "ERROR", 1, 5, 2)==0){
		    	    	switch (opcionSubMenu){

		    	    	            	case 1:
		    	    	            	break;

		    	    					case 2:
		    	    					break;
		    	    					case 3:
		    	    					break;
		    	    					case 4:
		    	    					break;
		    	    					case 5:
		    	    					break;

		    	    	            	}



		    	    }


		            break;
		       case 5:
		    	   	   	   //Carga forzada

		            break;
		       case 6:
		    	   //salir
		    	   break;

		    }

		}

	    }while(opcionMenu != 7);



	return EXIT_SUCCESS;
}




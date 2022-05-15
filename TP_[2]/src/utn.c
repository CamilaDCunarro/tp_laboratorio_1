


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


 int myGets(char pArray [], int longitud)

 //tomar dato array
 {
 	int retorno=-1;
 	char auxArray[5000];
 	if(pArray!=NULL && longitud>0)
 	{

 		//Fgets toma de datos para string, es mas seguro, en el tercer parametro le digo de donde viene la data de la consola.
 		//me va a tomar el tamaño de la palabra hasta un \0
 		//sizeof me muestra el tamañan del array palabra,espacio que ocupa en memoria ejemno nombre [11] va a mostrar 11
 		if(fgets(auxArray, sizeof(auxArray),stdin)!=NULL)
 			//fgets lee de un archivo una cadena de caracteres.
 		{     //strlen (palabra) me muestra el tamañao de la cadena Ejemplo,si dice juan va a mostrar 4
 			if(auxArray[strnlen(auxArray, sizeof(auxArray))-1] =='\n')
 			{
 				//si encuentra un \n lo resta si no sigue hasta encontrar un \0
 				auxArray[strnlen(auxArray,sizeof(auxArray))-1] = '\0';
 				//le agrego el -1 porque el fgets lee todo y me va a leer tambien el \n si mi array es de 3 y tiene el \n tambien lo lee
 			}
 			if(strnlen(auxArray, sizeof(auxArray))<=longitud)
 			{

 				strncpy(pArray, auxArray, longitud);
 				retorno=0;
 			}
 		}
 	}
 	return retorno;
 }
 int getInt(int* pResultado)
{
	int retorno = -1;
	char auxArray[50];
	if(pResultado!=NULL)
	{
		if(myGets(auxArray, sizeof(auxArray))==0 && esNumerica(auxArray, sizeof(auxArray))==1)
		{
			*pResultado=atoi(auxArray);
			//convertir la cadena de texto, en numerica si solo hubiese numeros, integer
			retorno=0;
		}
	}

	return retorno;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
 {
 	int retorno = -1;//si esta mal me retorna -1 si esta bien me retorna 0
 	int auxNumero;

 	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
 	{

 		do
 		{
 			printf("%s", mensaje);

 			//mi funcion getInt que dentro tiene mygets reemplaza a al scanf.
 			if(getInt(&auxNumero)==0 && auxNumero>=minimo && auxNumero<=maximo)
 			{
 				*pResultado=auxNumero;
 				retorno=0;
 				break;
 			}
 			else
 			{
 				printf("%s", mensajeError);
 				reintentos--;
 			}
 		}while(reintentos>=0);
 	}
 	return retorno;
 }


//nos asegura que si cuando llamo a la funcion pedir numero sea un numero entenro





 //es para saber si mi cadena esta formada solmente por unca cadena de numeros
  int esNumerica(char pArrar[], int longitud)
  {

 	 //retorna 1 si esta todo bien porque era static
  	int retorno= 1;
  	int i;
  	if(pArrar!=NULL)
  	{
  				//recorre mientras no haya un \0
  		for(i=0; i<longitud && pArrar[i]!='\0'; i++)
  		{

  			//porque en la primera posicicon del array es posible encontrar un + o -
  			if(i==0 && (pArrar[i]=='+' || pArrar[i]=='-'))
  			{
  				continue; //vuelve a evaluar el for
  			}
  			if(pArrar[i]<'0'||pArrar[i]>'9')
  			{

  				//retorna 0 si esta todo mal
  				retorno=0;
  				break;
  			}
  		}
  	}
  	return retorno;
  }
  int utn_getStringLeter(char pArray[],char* mensaje,char* mensajeError, int reintentos)
   {
   	int retorno = -1;
   	char auxString[40];

   	if(pArray != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
   	{
   		do
   		{
   			printf("%s", mensaje);
   			if(myGets(auxString,40)==0 && esLetra(auxString)==0)
   			{
   				strcpy(pArray, auxString);
   				retorno=0;
   				break;
   			}
   			else
   			{
   				printf("%s", mensajeError);
   				reintentos--;
   			}
   		}while(reintentos>=0);
   	}
   	return retorno;
   }

  int esLetra(char cadena[])
  {
  	int retorno = 1;
  	int i=0;

  	if (cadena != NULL){
  		//mientras cadena sea disinto de \0
  		while (cadena [i]!= '\0'){

  			if(cadena[i]<'A' || (cadena[i]>'Z' &&  cadena[i]< 'a')|| cadena[i]>'z'){

  				retorno =1;

  			}else {
  				retorno =0;
  				break;
  				//0 esta mal
  			}
  			i++;
  		}
  	}
  return retorno ;
  int getFloat(float* pResultado)
  {
      int retorno=-1;
      char buffer[64];

      if(pResultado != NULL)
      {
      	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
      	{
  			*pResultado = atof(buffer);
  			retorno = 0;
  		}
      }
      return retorno;
  }


  /**
   * \brief Verifica si la cadena ingresada es flotante
   * \param cadena Cadena de caracteres a ser analizada
   * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
   *
   */
  int esFlotante(char* cadena)
  {
  	int i=0;
  	int retorno = 1;
  	int contadorPuntos=0;

  	if(cadena != NULL && strlen(cadena) > 0)
  	{
  		for(i=0 ; cadena[i] != '\0'; i++)
  		{
  			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
  			{
  				continue;
  			}
  			if(cadena[i] < '0' || cadena[i] > '9' )
  			{
  				if(cadena[i] == '.' && contadorPuntos == 0)
  				{
  					contadorPuntos++;
  				}
  				else
  				{
  					retorno = 0;
  					break;
  				}
  			}
  		}
  	}
  	return retorno;
  }

  /**
   * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
   * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
   * \param mensaje Es el mensaje a ser mostrado
   * \param mensajeError Es el mensaje de Error a ser mostrado
   * \param minimo Es el numero maximo a ser aceptado
   * \param maximo Es el minimo minimo a ser aceptado
   * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
   *
   */
  int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
  {
  	float bufferFloat;
  	int retorno = -1;
  	while(reintentos>=0)
  	{
  		reintentos--;
  		printf("%s",mensaje);
  		if(getFloat(&bufferFloat) == 0)
  		{
  			if(bufferFloat >= minimo && bufferFloat <= maximo)
  			{
  				*pResultado = bufferFloat;
  				retorno = 0;
  				break;
  			}
  		}
  		printf("%s",mensajeError);
  	}
  	return retorno;
  }
  int getString(char* cadena, int longitud)
  {
  	int retorno=-1;
  	char bufferString[4096]; // *****************************

  	if(cadena != NULL && longitud > 0)
  	{

  		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
  		{
  			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
  			{
  				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
  			}
  			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
  			{
  				strncpy(cadena,bufferString,longitud);
  				retorno=0;
  			}
  		}
  	}
  	return retorno;
  }



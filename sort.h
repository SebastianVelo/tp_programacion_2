#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRE 0

/** \brief  Ordena un array de enteros
 *
 * \param array int* Puntero al array
 * \param cantidadElementos int cantidad de elementos del array
 * \param flagOrden int [1] Ordena de mayor a menor [0] Ordena de menor a mayor
 * \return int [-1] Error [0] Ok
 *
 */
int sort_ordenarArrayEnteros(int* array,int cantidadElementos, int flagOrden){
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<cantidadElementos-1;i++)            {
                if((array[i] < array[i+1] && flagOrden)||(array[i] > array[i+1] && !flagOrden))                {
                    swapInt(&array[i],&array[i+1]);
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}



/** \brief
 *
 * \param array int*
 * \param length int
 * \return int
 *
 */
int sort_mostrarArrayEnteros(int* array, int length){
    int retorno = -1;
    int i;
    if(length > 0)    {
        retorno = 0;
        for(i=0;i<length;i++)        {
            printf("\n%d",array[i]);
        }
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param length int
 * \return int
 *
 */
int sort_ordenarArrayCadenaCaracteres(char array[][50], int length, int flagOrden){
    int retorno = -1;
    int flagSwap;
    int i;
    if(length > 0)  {
        retorno = 0;
        do {
            flagSwap = 0;
            for(i=0;i<length-1;i++) {
                if((strcmp(array[i], array[i+1]) > 0 && flagOrden) || (strcmp(array[i], array[i+1]) < 0  && !flagOrden)){
                    swapString(&array[i],&array[i+1]);
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


/** \brief
 *
 * \param
 * \param length int
 * \return int
 *
 */
int sort_mostrarArrayCadenaCaracteres(char array[][50], int length){
    int retorno = -1;
    int i;
    if(length > 0)
    {
        retorno = 0;
        for(i=0;i<length;i++)
        {
            printf("\n%s",array[i]);
        }
    }
    return retorno;
}


/** \brief Intercambia dos string
 *
 * \param stString string*
 * \param ndString string*
 * \return int
 *
 */
int swapString(char * stString, char * ndString){
    char  auxiliar[50];
    strcpy(auxiliar, stString);
    strcpy(stString, ndString);
    strcpy(ndString, auxiliar);
    return 0;
}

/** \brief Intercambia dos enteros
 *
 * \param stInt int*
 * \param ndInt int*
 * \return int
 *
 */
int swapInt(int* stInt,int* ndInt){
    int auxiliar;
    auxiliar = *stInt;
    *stInt = *ndInt;
    *ndInt = auxiliar;
    return 0;
}



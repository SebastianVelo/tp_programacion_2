#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "styles.h"

#define MIN_DNI 100000
#define MAX_DNI 99999999
#define MIN_EDAD 0
#define MAX_EDAD 127

#define ADD 1
#define DEL 2
#define SHOWL 3
#define SHOWG 4
#define EXIT 5

#define NAME_LENGTH 50

#define ASC 1
#define DES 0
#define NO -1


typedef struct EPerson {
   char  name[NAME_LENGTH];
   int   dni;
   int   age;
   int   isEmpty;
   int   id;
} EPerson;

int firstIndexAvailable(EPerson persons[], int length){
    int i;
    for(i = 0; i < length; i++){
        if(persons[i].isEmpty)
            return i;
    }
    return -1;
}

int person_add(EPerson persons[], int length){
    int index = firstIndexAvailable(persons, length);
    int ret = FAIL;
    if(index >= 0 && index < length){
        showSeparator(4);
        if(getString(&persons[index].name, "Ingrese nombre: ", NAME_LENGTH) == FAIL)
            return ret;
        if(getInt(&persons[index].dni, "Ingrese DNI : ", "Ingrese un DNI correcto. \n", MIN_DNI, MAX_DNI, 3) == FAIL)
            return ret;
        if(getInt(&persons[index].age, "Ingrese EDAD : ", "Ingrese una EDAD correcta. \n", MIN_EDAD, MAX_EDAD, 3) == FAIL)
            return ret;
        showSeparator(4);

        ret = SUCCESS;
        persons[index].isEmpty = 0;
        persons[index].id = getMaxId(persons, length) + 1;
    }
    return ret;
}

int person_del(EPerson persons[], int length){
    int ret = FAIL;
    int id;
    if(getInt(&id, "Ingrese que usuario desea borrar: ", "Ingrese un indice correcto.\n", 0, length, 3) == FAIL)
        return ret;

    int index = getIndexOfID(persons, length, id);
    if(!persons[index].isEmpty){
        persons[index].isEmpty = 1;
        ret = SUCCESS;
    }
    return ret;
}

int person_showl(EPerson persons[], int length, int ord){
    int i;
    int ret = FAIL;
    sortPersonArray(persons, length, ord);
    showSeparator(4);
    for(i = 0; i < length; i++){
        if(!persons[i].isEmpty){
            printf("||| ID#%d|||", persons[i].id);
            printf("\n");
            printf("Nombre: %s", persons[i].name);
            printf("DNI: %d", persons[i].dni);
            printf("\n");
            printf("Edad: %d", persons[i].age);
            printf("\n");
            showSeparator(4);
            ret = SUCCESS;
        }
    }
    return ret;
}


void person_initializePersonArray(EPerson persons[], int length){
    int i;
    for(i = 0; i < length; i++){
        persons[i].isEmpty = 1;
        persons[i].id = -1;
        persons[i].dni = 0;
        persons[i].age = 0;
        strcpy(persons[i].name, "");
    }
}

int getIndexOfID(EPerson persons[], int length, int id){
    int i;
    for(i = 0; i < length; i++){
        if(!persons[i].isEmpty && persons[i].id == id){
            return i;
        }
    }
    return -1;
}

/** \brief
 *
 * \param
 * \param length int
 * \return int
 *
 */
int sortPersonArray(EPerson persons[], int length, int flagOrden){
    int retorno = FAIL;
    int flagSwap;
    int i;
    if(length > 0 && flagOrden != NO)  {
        retorno = SUCCESS;
        do {
            flagSwap = FALSE;
            for(i=0;i<length-1;i++) {
                if((strcmp(persons[i].name, persons[i+1].name) > 0 && flagOrden) || (strcmp(persons[i].name, persons[i+1].name) < 0  && !flagOrden)){
                    swapPerson(&persons[i],&persons[i+1]);
                    flagSwap = TRUE;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief Intercambia dos enteros
 *
 * \param stP EPerson*
 * \param ndP EPerson*
 * \return int
 *
 */
int swapPerson(EPerson * stP, EPerson * ndP){
    EPerson auxiliar;
    auxiliar = *stP;
    *stP = *ndP;
    *ndP = auxiliar;
    return 0;
}

int getMaxId(EPerson persons[], int length){
    int idMax = persons[0].id;
    int i;
    for(i = 1; i < length; i++){
        if(persons[i].id > idMax)
            idMax = persons[i].id;
    }
    return idMax;
}

#include <stdio.h>
#include <stdlib.h>
#include "person.h"

#define SIZE 6

void showOptions(void){
    /** Doy las opciones que otorga el enunciado */
    showHeader(4);
    printf("%d : AGREGAR PERSONA \n", ADD);
    printf("%d : BORRAR PERSONA \n", DEL);
    printf("%d : MOSTRAR LISTA ORDENADA (POR NOMBRE) \n", SHOWL);
    printf("%d : MOSTRAR GRAFICO DE EDADES \n", SHOWG);
    printf("%d : SALIR", EXIT);
    showHeader(4);
}


int main()
{
    EPerson persons[SIZE];
    int seguir = TRUE;
    int option;

    showOptions();
    person_initializePersonArray(persons, SIZE);

    while(seguir == TRUE){
        showHeader(4);
        /** Flusheo el buffer de entrada. */
        fflush(stdin);

        /** Pido la operacion al usuario. Si despues de dos reintentos ingresa una operacion invalida, la opcion por default sera EXIT */
		if(getInt(&option, "Ingrese la operacion a realizar: ", "Ingrese una opcion valida. \n", ADD, EXIT, 3) == FAIL)
            option = EXIT;
		/** VALIDACION DE OPCION: Si pidio salir, cambio el valor de control del bucle y también breakeo la iteración. */
		if(option == EXIT){
			seguir = FALSE;
			break;
		}

		switch(option){
            case ADD:
                     if(person_add(persons, SIZE) == SUCCESS)
                        printf("¡Persona agregada!");
                      else
                        printf("¡Ya esta el cupo de %d personas! Escriba opcion %d para borrar personas.", SIZE, DEL);
                     break;
            case SHOWL:
                      if(person_showl(persons, SIZE, ASC) == SUCCESS)
                        printf("¡Aca esta la lista de personas cargadas!");
                      else
                        printf("¡Aun no ingreso ninguna persona! Escriba opcion %d para agregar personas.", ADD);
                     break;
            case DEL:
                     if(person_showl(persons, SIZE, NO) == FAIL){
                        printf("¡Aun no ingreso ninguna persona! Escriba opcion %d para agregar personas.", ADD);
                        break;
                     }
                     if(person_del(persons, SIZE) == SUCCESS)
                        printf("¡Persona borrada satisfactoriamente!");
                     else
                        printf("¡Aun no ingreso a esta persona! Escriba opcion %d para agregar personas.", ADD);
                     break;
            case SHOWG:
              //     person_showd(persons);
                     break;
		}
    }
    return 0;
}

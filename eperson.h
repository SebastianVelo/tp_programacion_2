#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


typedef struct EPerson {
   char  name[50];
   int   dni;
   int   edad;
   int   estado;
} EPerson;

int getInt(int *resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    long resultadoAux = 0;
    int ret = 0;
    do{
        fflush(stdin);

		printf("%s", mensaje);
        scanf("%ld", &resultadoAux);
        if((resultadoAux >= minimo && resultadoAux <= maximo)){
            *resultado = (int) resultadoAux;
            ret = 1;
            break;
        }
        printf("%s", mensajeError);
        reintentos--;
    }while(reintentos > 0);

    return ret;
}

int lastIndexOf(EPerson persona[], int length){
    int i;
    for(i = 0; i < length; i++){
        if(persona[i].estado)
            return i;
    }
    return -1;
}

int add(EPerson persons[], int length){
    int index = lastIndexOf(persons, length);
    int ret = -1;
    if(index >= 0){
        if(getInt(&persons[index].dni, "Ingrese DNI : ", "Ingrese un DNI correcto. \n", 10000, 99999999, 3) == FALSE)
            return ret;
        if(getInt(&persons[index].edad, "Ingrese EDAD : ", "Ingrese una EDAD correcta. \n", 0, 127, 3) == FALSE)
            return ret;
   /*     if(getInt(&persons[index].dni, "Ingrese DNI : ", "Ingrese un DNI correcto. \n", 10000, 99999999, 3) == FALSE)
            return ret;*/
        ret = 0;
        persons[index].estado = 1;
    }
    return ret;
}

void showl(EPerson persons[], int length){
    int i;
    for(i = 0; i < length; i++){
        printf("\n");
        printf("INDEX: %d", i);
        printf("\n");
        printf("DNI: %d", persons[i].dni);
        printf("\n");
        printf("Edad: %d", persons[i].edad);
        printf("\n");
        printf("ESTADO: %d", persons[i].estado);
        printf("\n______________________\n");
        printf("----------------------");
    }
}

void initializePersonArray(EPerson persons[], int length){
    int i;
    for(i = 0; i < length; i++){
        persons[i].estado = 0;
        persons[i].dni = 0;
        persons[i].edad = 0;
        persons[i]. = 0;
    }
}

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define FAIL -1
#define SUCCESS 0

int getInt(int *resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    long resultadoAux = 0;
    int ret = FAIL;
    do{
        fflush(stdin);

		printf("%s", mensaje);
        scanf("%ld", &resultadoAux);
        if((resultadoAux >= minimo && resultadoAux <= maximo)){
            *resultado = (int) resultadoAux;
            ret = SUCCESS;
            break;
        }
        printf("%s", mensajeError);
        reintentos--;
    }while(reintentos > 0);

    return ret;
}

int getFloat(float *resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    float resultadoAux = 0;
    int ret = FAIL;
    do{
        fflush(stdin);

		printf("%s", mensaje);
        scanf("%f", &resultadoAux);
        int isValid = (resultadoAux > minimo && resultadoAux < maximo);
        if(isValid) {
            *resultado = resultadoAux;
            ret = SUCCESS;
            break;
        }
        printf("%s", mensajeError);
        reintentos--;
    }while(reintentos > 0);

    return ret;
}

int getString(char *resultado, char* mensaje, int length){
    int ret = SUCCESS;
    fflush(stdin);
    printf("%s", mensaje);
    fgets(resultado, length, stdin);
    return ret;
}



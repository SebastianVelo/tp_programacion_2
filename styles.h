#include <stdio.h>
#include <stdlib.h>

void showHeader(int size){
     int i;
     printf("\n");
     for(i = 0; i < size; i++)
        printf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
     printf("\n");
}
void showSeparator(int size){
     int i;
     for(i = 0; i < size; i++)
        printf("||||");
     printf("\n");
}


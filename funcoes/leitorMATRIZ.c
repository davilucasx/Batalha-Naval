#include <stdio.h>
#include "../biblioteca/leitorMATRIZ.h"
void leitor_matriz(){
    char i,j;
    printf("  ");
    for(i= 0; i < 8; i++){
        printf("%d ", i);
    }
    printf("\n");
    for(i = 0; i < 8; i++){
        printf("%d ", i);
        for(j = 0; j < 8; j++){
            printf("? ");
        }
        printf("\n");
    }
}
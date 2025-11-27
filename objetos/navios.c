#include <stdio.h>
#include "../biblioteca/leitorNAVIO.h"
void navio_pequeno(){
    char navio[2] = {
        'P','P'
    };
    printf("Navio pequeno: %c %c\n", navio[0], navio[1]);
}
void navio_medio(){
    char navio[3] = {
        'M','M','M'
    };
    printf("Navio medio: %c %c %c\n", navio[0], navio[1], navio[2]);
}
void navio_grande(){
    char navio[4] = {
        'G','G','G','G'
    };
    printf("Navio grande: %c %c %c %c\n", navio[0], navio[1], navio[2], navio[3]);
}
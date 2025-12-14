#include <stdio.h>
#include "../biblioteca/mostrarTABULEIRO.H"
// Funcao que mostra o tabuleiro do jogador //
void mostrar_tabuleiro (char tabuleiro[8][8]){
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++){
        printf("%d ", i+1);
        for (int j = 0; j < 8; j++){
            printf("%c ", tabuleiro[i][j]);

        }      
        printf("\n");    
    }
    printf("-----------------\n");
    printf("\n");
}
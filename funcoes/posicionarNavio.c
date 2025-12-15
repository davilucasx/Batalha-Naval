#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/posicionarNavio.h"

/*
 * posicionarNavio(): Verifica se é possível posicionar um navio de índice `i`
 * (0=P/2 células, 1=M/3 células, 2=G/4 células) na posição inicial
 * (`linha`,`coluna`) com a orientação `orientacao` ('H' ou 'V').
 *
 * Retorna:
 *  - 1 se a posição é válida
 *  - 0 se a posição é inválida (não cabe ou colide)
 *  - -1 se a orientação é inválida
 */
int posicionarNavio(char tabuleiro[8][8], int linha, int coluna, char orientacao, int i){
    if(orientacao == 'H' || orientacao == 'h'){
        /* Verifica limites e sobreposição horizontal */
        if(i == 0){
            if(coluna + 2 > 8){
                return 0; /* extrapola borda */
            }
            for (int j = 0; j < 2; j++){
                if (tabuleiro[linha][coluna+j] != '~'){
                    return 0; /* sobrepõe outro navio */
                }
            }
        }
        if(i == 1){
            if(coluna + 3 > 8){
                return 0;
            }
            for (int j = 0; j < 3; j++){
                if (tabuleiro[linha][coluna+j] != '~'){
                    return 0;
                }
            }
        }
        if(i == 2){
            if(coluna + 4 > 8){
                return 0;
            }
            for (int j = 0; j < 4; j++){
                if (tabuleiro[linha][coluna+j] != '~'){
                    return 0;
                }
            }
        }
        return 1;
    }

    if(orientacao == 'V' || orientacao == 'v'){
        /* Verifica limites e sobreposição vertical */
        if(i == 0){
            if(linha + 2 > 8){
                return 0;
            }
            for (int j = 0; j < 2; j++){
                if (tabuleiro[linha+j][coluna] != '~'){
                    return 0;
                }
            }
        }
        if(i == 1){
            if(linha + 3 > 8){
                return 0;
            }
            for (int j = 0; j < 3; j++){
                if (tabuleiro[linha+j][coluna] != '~'){
                    return 0;
                }
            }
        }
        if(i == 2){
            if(linha + 4 > 8){
                return 0;
            }
            for (int j = 0; j < 4; j++){
                if (tabuleiro[linha+j][coluna] != '~'){
                    return 0;
                }
            }
        }
        return 1;
    }
    return -1; /* orientação inválida */
}


#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/posicionarNavio.h"

int posicionarNavio(char tabuleiro[8][8], int linha, int coluna, char orientacao, int i){
    if(orientacao == 'H' || orientacao == 'h'){
        if(i == 0){
            if(coluna + 2 > 8){
                return 0;
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
            for (int j = 0; j < 3; j++){
                if (tabuleiro[linha][coluna+j] != '~'){
                    return 0;
                }
            }
        }
        return 1;
    }

    if(orientacao == 'V' || orientacao == 'v'){
        if(i == 0){
            if(linha + 2 > 8){
                return 0;
            }
        }
        if(i == 1){
            if(linha + 3 > 8){
                return 0;
            }
            for (int j = 0; j < 3; j++){
                if (tabuleiro[linha][coluna+j] != '~'){
                    return 0;
                }
            }
        }
        if(i == 2){
            if(linha + 4 > 8){
                return 0;
            }
            for (int j = 0; j < 3; j++){
                if (tabuleiro[linha][coluna+j] != '~'){
                    return 0;
                }
            }
        }
        return 1;
    }
}


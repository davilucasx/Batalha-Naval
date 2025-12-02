#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/navio.h"



void navio(char tabuleiro[8][8], int linha, int coluna, char orientacao, int i){
    if (orientacao == 'H' || orientacao == 'h')
            {
                // Horizontamente
                if (i == 0)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        tabuleiro[linha][coluna + k] = 'P';
                    }
                }
                if (i == 1)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        tabuleiro[linha][coluna + k] = 'M';
                    }
                }
                if (i == 2)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        tabuleiro[linha][coluna + k] = 'G';
                    }
                }
                // Verticalmente
            }
            else if (orientacao == 'V' || orientacao == 'v')
            {
                if (i == 0)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        tabuleiro[linha + k][coluna] = 'P';
                    }
                }
                if (i == 1)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        tabuleiro[linha + k][coluna] = 'M';
                    }
                }
                if (i == 2)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        tabuleiro[linha + k][coluna] = 'G';
                    }
                }
            }
}
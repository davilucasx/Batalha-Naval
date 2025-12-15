#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/navio.h"


// Funcao que adiciona o adiciona o navio ao "TABULEIRO"//
void navio(char tabuleiro[8][8], int linha, int coluna, char orientacao, int i){
    if (orientacao == 'H' || orientacao == 'h')
            {
                // Horizontamente
                if (i == 0)
                {// Navio Pequeno
                    for (int k = 0; k < 2; k++)
                    {// Tamanho do navio pequeno
                        tabuleiro[linha][coluna + k] = 'P';
                    }
                }
                if (i == 1)
                {// Navio Medio
                    for (int k = 0; k < 3; k++)
                    {// Tamanho do navio medio 
                        tabuleiro[linha][coluna + k] = 'M';
                    }
                }
                if (i == 2)
                {// Navio Grande
                    for (int k = 0; k < 4; k++)
                    {// Tamanho do navio grande
                        tabuleiro[linha][coluna + k] = 'G';
                    }
                }
                // Verticalmente
            }
            else if (orientacao == 'V' || orientacao == 'v')
            {// Adiciona o navio verticalmente
                if (i == 0)
                {// Navio Pequeno
                    for (int k = 0; k < 2; k++)
                    {// Tamanho do navio pequeno
                        tabuleiro[linha + k][coluna] = 'P';
                    }
                }
                if (i == 1)
                {// Navio Medio
                    for (int k = 0; k < 3; k++)
                    {// Tamanho do navio medio 
                        tabuleiro[linha + k][coluna] = 'M';
                    }
                }
                if (i == 2)
                {// Navio Grande
                    for (int k = 0; k < 4; k++)
                    {// Tamanho do navio grande
                        tabuleiro[linha + k][coluna] = 'G';
                    }
                }
            }
}
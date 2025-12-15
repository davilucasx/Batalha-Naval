#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/navio.h"



/*
 * navio(): marca no `tabuleiro` as células correspondentes a um navio
 * de tipo `i` (0=P,1=M,2=G) a partir da posição inicial
 * (`linha`,`coluna`) e seguindo a `orientacao` ('H' ou 'V').
 *
 * Observação: assume-se que `posicionarNavio` já validou que a
 * posição é segura (dentro do tabuleiro e sem sobreposição).
 */
void navio(char tabuleiro[8][8], int linha, int coluna, char orientacao, int i){
    if (orientacao == 'H' || orientacao == 'h')
            {
                /* Preenche horizontalmente o símbolo correspondente */
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
                /* Preenche verticalmente o símbolo correspondente */
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
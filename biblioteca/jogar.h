#ifndef _JOGAR_H
#define _JOGAR_H

int ataque(int linha, int coluna, char tabuleiro[8][8], char tabuleiro_oculto[8][8]);
void jogar(Jogador jogador[2], int rodadas, int turno);

#endif
#ifndef _MENU_H
#define _MENU_H

typedef struct
{
    char nome[50];
    char tabuleiro[8][8];
    char tabuleiro_oculto[8][8];
    int acertos;
    int acertos_navio[3];// Array de inteiros, com 3 elementos 
    int erros;
}Jogador;

void salvar(Jogador jogadores[2], int rodada, int turno);
void menu();//void indica que a funcao nao retorna nenhum valor//

#endif
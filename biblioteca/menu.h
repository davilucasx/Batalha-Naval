#ifndef _MENU_H
#define _MENU_H

typedef struct
{
    char nome[50];
    char tabuleiro[8][8];
    char tabuleiro_oculto[8][8];
    int acertos;
    int acertos_navio[3];
}Jogador;
void menu();

#endif
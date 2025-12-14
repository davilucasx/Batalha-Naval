#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/leitorTXT.h"
#include "biblioteca/criarTABULEIRO.h"
#include "biblioteca/menu.h"
/* Funcao que recebe jogador e guarda as informacoes dele(ex nome, tabuleiro, tabuleiro_oculto e acertos) */
struct Jogador
{
    char nome[50];
    char tabuleiro[8][8];
    char tabuleiro_oculto[8][8];
    int acertos;
};
/*Funcao principal do programa*/
int main()
{   
    char voltar;
    menu();

    // Comando para retornar ao menu inicial ou sair do programa
    printf("Retornar ao menu inicial, Sim (s) ou Nao (n) ?");
    scanf(" %c", &voltar);
    system("clear||cls");//biblioteca stdlib.h//clear e cls para compatibilidade entre sistemas operacionais//
    if (voltar == 's' || voltar == 'S')
    {
        main();
    }
    return 0;
}

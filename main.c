#include <stdio.h>//printf, scanf
#include <stdlib.h>//system, exit
#include "biblioteca/leitorTXT.h"//leitor_texto
#include "biblioteca/criarTABULEIRO.h"
#include "biblioteca/menu.h"//menu
/* Funcao que recebe jogador e guarda as informacoes dele(ex nome, tabuleiro, tabuleiro_oculto e acertos) */
struct Jogador
{
    char nome[50];
    char tabuleiro[8][8];//proprio tabuleiro do jogador//
    char tabuleiro_oculto[8][8];//tabuleiro que o jogador usa para atacar o adversário//
    int acertos;
};
/*Funcao principal do programa*/
int main()
{   
    char voltar;
    menu();

    // Comando para retornar ao menu inicial ou sair do programa
    printf("Retornar ao menu inicial, Sim (s) ou Nao (n): ");
    scanf(" %c", &voltar);
    system("clear||cls");//biblioteca stdlib.h//clear e cls para compatibilidade entre sistemas operacionais//
    if (voltar == 's' || voltar == 'S')
    {
        main();
    }
    return 0;
}

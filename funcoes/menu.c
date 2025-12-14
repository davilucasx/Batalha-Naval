#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/menu.h"
#include "../biblioteca/criarTABULEIRO.h"
#include "../biblioteca/leitorTXT.h"


// Funcao que exibe o menu principal do jogo e lida com as escolhas do usuario // 
void menu(){
    int escolha;          // Escolha a opção do menu
    int entrada_invalida; // Caso não escolha uma opção válida no menu

    // Exibe o menu
    do
    {
        entrada_invalida = 0;
        printf("-----------------------\n");
        printf("  BATALHA NAVAL\n");
        printf("-----------------------\n");
        printf("Menu:\n");
        printf("(0) Sair do Jogo\n");
        printf("(1) Novo Jogo\n");
        printf("(2) Continuar Jogando\n");
        printf("(3) Instrucoes\n");
        printf("-----------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        system("clear||cls"); // Limpa a tela para melhor visualizacao do menu

        // Escolha do usuário, menu destinado a escolha das opcoes do jogo//
        switch (escolha)
        {
        case 0:
            exit(1);
        case 1:
            system("clear||cls"); // Limpa a tela para melhor visualizacao do menu
            printf("-----------------------\n");
            printf("-------Novo Jogo-------\n");
            printf("-----------------------\n");
            criar_matriz_tabuleiro();// chama a funcao que cria o tabuleiro//
            break;
        case 2:
            printf("(2) Continuar Jogando\n");
            break;
        case 3:
            printf("--- Conteudo do Arquivo instrucoes.md ---\n");
            leitor_texto("../instrucoes/instrucoes.txt");// chama a funcao que le o arquivo de instrucoes//
            printf("--------------------------------------\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            entrada_invalida = 1;
            while (getchar() != '\n')
                ; // Limpa o buffer de entrada para evitar loop infinito com scanf em C
            break;
        }
    } while (entrada_invalida == 1);
//Enquanto a entrada for invalida, o menu sera exibido novamente//
}
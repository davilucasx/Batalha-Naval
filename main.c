#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/leitorTXT.h"
#include "biblioteca/criarTABULEIRO.h"
int main()
{
    int escolha;          // Escolha a opção do menu
    int entrada_invalida; // Caso não escolha uma opção válida no menu
    char voltar;          // Voltador de um menu para a tela ininical

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

        // Escolha do usuário
        switch (escolha)
        {
        case 0:
            break;
        case 1:
            system("clear||cls"); // Limpa a tela para melhor visualizacao do menu
            printf("-----------------------\n");
            printf("-------Novo Jogo-------\n");
            printf("-----------------------\n");
            criar_matriz_tabuleiro();
            break;
        case 2:
            printf("(2) Continuar Jogando\n");
            break;
        case 3:
            printf("--- Conteudo do Arquivo instrucoes.md ---\n");
            leitor_texto("../instrucoes/instrucoes.txt");
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

    // Comando para retornar ao menu inicial ou sair do programa
    printf("Retornar ao menu inicial, Sim (s) ou Nao (n) ?");
    scanf(" %c", &voltar);
    system("clear||cls");
    if (voltar == 's' || voltar == 'S')
    {
        main();
    }
    return 0;
}

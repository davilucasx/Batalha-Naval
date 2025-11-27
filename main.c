#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/leitorTXT.h"
#include "biblioteca/leitorMATRIZ.h"
#include "biblioteca/leitorNAVIO.h"
int main() {
     int escolha;
     int entrada_invalida;
     char voltar;

// Exibe o menu e lê a escolha do usuário
    do{
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

        switch(escolha) {
            case 0:
                printf("(0) Sair do Jogo\n");
                break;
            case 1:
                printf("(1) Novo Jogo\n");
                system("clear||cls"); // Limpa a tela para melhor visualizacao do menu
                printf("-----------------------\n");
                printf("MODELO DO TABLULEIRO\n");
                printf("---------------------\n");
                leitor_matriz();
                printf("\n");
                navio_pequeno();
                navio_medio();
                navio_grande();
                break;
            case 2:
                printf("(2) Continuar Jogando\n");
                break;
            case 3:
                printf("(3) Instrucoes\n");
                printf("--- Conteudo do Arquivo instrucoes.md ---\n");
                leitor_texto("../instrucoes/instrucoes.txt"); // Chama a função para ler e exibir o conteúdo do arquivo Markdown nas instruções
                printf("--------------------------------------\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                entrada_invalida = 1;
                while (getchar() != '\n'); // Limpa o buffer de entrada para evitar loop infinito com scanf em C
                break;
            }
    } while (entrada_invalida == 1);
    printf("Retornar ao menu inicial, Sim (s) ou Nao (n) ?");
    scanf(" %c", &voltar);
    system("clear||cls");
    if(voltar == 's' || voltar == 'S'){
        main();
    }
    else{
    system("pause||read -p 'Pressione Enter para continuar...' -n 1");
    }
    return 0;
}

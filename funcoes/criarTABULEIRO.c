#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca/criarTABULEIRO.h"
#include "../biblioteca/mostrarTABULEIRO.h"
#include "../biblioteca/navio.h"
#include "../biblioteca/posicionarNavio.h"

struct Jogador
{
    char nome[50];
    char tabuleiro[8][8];
    char tabuleiro_oculto[8][8];
};
void criar_matriz_tabuleiro()
{
    struct Jogador jogador[2]; // Dois jogadores
    int linha, coluna, i = 0;
    char orientacao;
    char tabuleiro[8][8];
    // Inicializa o tabuleiro com '~' representando água
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tabuleiro[i][j] = '~';
        }
    }
    printf("Bem-vindo ao jogo Batalha Naval!\n");
    printf("Jogador 1, digite seu nome: ");
    scanf("%s", jogador[0].nome);
    printf("Jogador 2, digite seu nome: ");
    scanf("%s", jogador[1].nome);
    system("clear||cls");

    // Loop para cada jogador posicionar seus navios
    for (int jogador_atual = 0; jogador_atual < 2; jogador_atual++)
    {
        // Exibe o tabuleiro
        printf("Tabuleiro Inicial:\n");
        mostrar_tabuleiro(tabuleiro);
        printf("%s, e hora de posicionar seus navios!\n", jogador[jogador_atual].nome);
        // Anexa os navios no tabuleiro
        printf("\n");

        while (i < 3)
        {
            printf("Posicione o navio %i no tabuleiro!\n", i + 1);
            if (i == 0)
            {
                printf("Navio 1: P P\n");
            }
            else if (i == 1)
            {
                printf("Navio 2: M M M\n");
            }
            else
            {
                printf("Navio 3: G G G G\n");
            }
            printf("Digite a posicao inicial no tabuleiro, linha e coluna nessa ordem\n");
            printf("LINHA: ");
            scanf("%d", &linha);
            linha--;
            if(linha < 0 || linha > 7){
                system("clear||cls");
                printf("Opcao de linha invalida! \n\n");
                mostrar_tabuleiro(tabuleiro);
                continue;
            }
            printf("COLUNA: ");
            scanf("%d", &coluna);
            coluna--;
            if(coluna < 0 || coluna > 7){
                system("clear||cls");
                printf("Opcao de coluna invalida! \n\n");
                mostrar_tabuleiro(tabuleiro);
                continue;
            }

            printf("Agora digite H para horizontal ou V para vertical: ");
            scanf(" %c", &orientacao);
            if(orientacao != 'H' && orientacao != 'h' && orientacao != 'V' && orientacao != 'v'){
                system("clear||cls");
                printf("Orientacao invalida! \n");
                continue;
            }

            int valido = posicionarNavio(tabuleiro, linha, coluna, orientacao, i);
            if (!valido)
            {
                system("clear||cls");
                printf("Posicao invalida para o navio %i! Tente novamente.\n", i + 1);
                continue;
            }
            navio(tabuleiro, linha, coluna, orientacao, i);

            system("clear||cls");
            if (i == 0)
            {
                printf("TABULEIRO ATUALIZADO (+)( )( )\n");
            }
            else if (i == 1)
            {
                printf("TABULEIRO ATUALIZADO (+)(+)( )\n");
            }
            else if (i == 2)
            {
                printf("TABULEIRO ATUALIZADO (+)(+)(+)\n");
            }

            mostrar_tabuleiro(tabuleiro);
            printf("\n");
            i++;
        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                jogador[jogador_atual].tabuleiro[i][j] = tabuleiro[i][j];
            }
        }
        printf("%s, voce posicionou todos os seus navios!\n", jogador[jogador_atual].nome);
        system("pause");
        system("clear||cls");
        while (getchar() != '\n')
            ;  // Limpa o buffer de entrada para evitar loop infinito com scanf em C
        i = 0; // Reseta o contador de navios para o próximo jogador
        // Limpa o tabuleiro para o próximo jogador
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                tabuleiro[i][j] = '~';
            }
        }
    }
    system("clear||cls");
    printf("Mostrar os tabuleiros dos jogadores:\n");
    for (int jogador_atual = 0; jogador_atual < 2; jogador_atual++)
    {
        printf("Tabuleiro de %s:\n", jogador[jogador_atual].nome);
        mostrar_tabuleiro(jogador[jogador_atual].tabuleiro);
        printf("\n");
    }
}
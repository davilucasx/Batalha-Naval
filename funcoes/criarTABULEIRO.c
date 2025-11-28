#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca/criarTABULEIRO.h"
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
        printf("  0 1 2 3 4 5 6 7\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d ", i);
            for (int j = 0; j < 8; j++)
            {
                printf("%c ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        printf("-----------------\n");
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
            printf("COLUNA: ");
            scanf("%d", &coluna);
            printf("Agora digite H para horizontal ou V para vertical: ");
            scanf(" %c", &orientacao);
            // Adiciona o navio ao tabuleiro escolhendo a posição inicial linha e coluna
            if (orientacao == 'H' || orientacao == 'h')
            {
                printf("O navio sera posicionado horizontalmente\n");
                // Horizontamente
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
                printf("O navio sera posicionado verticalmente\n");
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
            else
            {
                printf("Direcao invalida! Tente novamente.\n");
                continue;
            }
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

            printf("  0 1 2 3 4 5 6 7\n");
            for (int i = 0; i < 8; i++)
            {
                printf("%d ", i);
                for (int j = 0; j < 8; j++)
                {
                    printf("%c ", tabuleiro[i][j]);
                }
                printf("\n");
            }
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
        printf("  0 1 2 3 4 5 6 7\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d ", i);
            for (int j = 0; j < 8; j++)
            {
                printf("%c ", jogador[jogador_atual].tabuleiro[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
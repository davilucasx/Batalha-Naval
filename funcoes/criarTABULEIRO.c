#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca/criarTABULEIRO.h"
#include "../biblioteca/mostrarTABULEIRO.h"
#include "../biblioteca/navio.h"
#include "../biblioteca/posicionarNavio.h"
#include "../biblioteca/menu.h"
#include "../biblioteca/jogar.h"


void criar_matriz_tabuleiro()
{
    Jogador jogador[2]; // Dois jogadores
    int linha, coluna, i = 0;
    char orientacao;
    // Inicializa o tabuleiro com '~' representando água
    
    for (int jog = 0; jog < 2; jog++){
        jogador[jog].acertos_navio[0] = 2;
        jogador[jog].acertos_navio[1] = 3;
        jogador[jog].acertos_navio[2] = 4;
    }
    jogador[0].acertos = 0;
    jogador[1].acertos = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            jogador[0].tabuleiro[i][j] = '~';
            jogador[1].tabuleiro[i][j] = '~';
            jogador[0].tabuleiro_oculto[i][j] = '~';
            jogador[1].tabuleiro_oculto[i][j] = '~';
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
        

        while (i < 3)
        {
            mostrar_tabuleiro(jogador[jogador_atual].tabuleiro);
            printf("-----------------\n");
            printf("%s, e hora de posicionar seus navios!\n", jogador[jogador_atual].nome);
            // Anexa os navios no tabuleiro
            printf("\n");
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
                printf("Erro: Opcao de linha invalida! \n");
                continue;
            }
            printf("COLUNA: ");
            scanf("%d", &coluna);
            coluna--;
            if(coluna < 0 || coluna > 7){
                system("clear||cls");
                printf("Erro: Opcao de coluna invalida! \n");
                continue;
            }

            printf("Agora digite H para horizontal ou V para vertical: ");
            scanf(" %c", &orientacao);
            if(orientacao != 'H' && orientacao != 'h' && orientacao != 'V' && orientacao != 'v'){
                system("clear||cls");
                printf("Erro: Orientacao invalida! \n");
                continue;
            }

            int valido = posicionarNavio(jogador[jogador_atual].tabuleiro, linha, coluna, orientacao, i);
            if (!valido)
            {
                system("clear||cls");
                printf("Erro: Posicao invalida para o navio %i! Tente novamente.\n", i + 1);
                continue;
            }
            navio(jogador[jogador_atual].tabuleiro, linha, coluna, orientacao, i);

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

            i++;
        }

        
        mostrar_tabuleiro(jogador[jogador_atual].tabuleiro);
        printf("%s, voce posicionou todos os seus navios!\n", jogador[jogador_atual].nome);
        system("pause");
        system("clear||cls");
        while (getchar() != '\n')
            ;  // Limpa o buffer de entrada para evitar loop infinito com scanf em C
        i = 0; // Reseta o contador de navios para o próximo jogador
        // Limpa o tabuleiro para o próximo jogador
        
        
    }
    system("clear||cls");
    printf("Mostrar os tabuleiros dos jogadores:\n");
    
    for (int jogador_atual = 0; jogador_atual < 2; jogador_atual++)
    {
        printf("Tabuleiro de %s:\n", jogador[jogador_atual].nome);
        mostrar_tabuleiro(jogador[jogador_atual].tabuleiro);
        
        printf("\n");
    }
    int turno = 0;
    int rodadas = 1;

   jogar(jogador, rodadas, turno);
}

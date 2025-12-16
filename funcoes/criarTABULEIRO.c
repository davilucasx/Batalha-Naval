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
    // Inicializa os acertos dos navios//
    for (int jog = 0; jog < 2; jog++){
        jogador[jog].acertos_navio[0] = 2;
        jogador[jog].acertos_navio[1] = 3;
        jogador[jog].acertos_navio[2] = 4;
    }
    jogador[0].acertos = 0;
    jogador[1].acertos = 0;//Jogador 1 e 2 comecam com acertos 0//
    jogador[0].erros = 0;
    jogador[1].erros = 0;
    // Cria os tabuleiros (Matrizes) dos jogadores//
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            jogador[0].tabuleiro[i][j] = '~';//Tabuleiro do 1 jogador //
            jogador[1].tabuleiro[i][j] = '~';//Tabuleiro do 2 jogador //
            jogador[0].tabuleiro_oculto[i][j] = '~';//Tabuleiro oculto do 1 jogador //
            jogador[1].tabuleiro_oculto[i][j] = '~';// Tabuleiro oculto do 2 jogador //
        }
    }
    printf("\n");
    printf("=========================================\n");
    printf("=          BEM VINDO AO JOGO            =\n");
    printf("=========================================\n\n");
    printf("Vamos comecar! Insira os nomes dos jogadores:\n\n");

    printf("Jogador 1, digite seu nome: ");
    scanf("%s", jogador[0].nome);
    printf("Jogador 2, digite seu nome: ");
    scanf("%s", jogador[1].nome);
    system("clear||cls");

    // Loop para cada jogador posicionar seus navios
    for (int jogador_atual = 0; jogador_atual < 2; jogador_atual++)
    {
        // Exibe o tabuleiro
        printf("\n========================================\n");
        printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
        printf("========================================\n\n");
        printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
        printf("Tabuleiro Inicial:\n");
        

        while (i < 3)
        {
            mostrar_tabuleiro(jogador[jogador_atual].tabuleiro);// Mostra o tabuleiro atual do jogador sem barcos//
            printf("\nNAVIOS DISPONIVEIS:\n");
            printf("   [Navio 1 - Pequeno]   P P         (2 celulas)\n");
            printf("   [Navio 2 - Medio]     M M M       (3 celulas)\n");
            printf("   [Navio 3 - Grande]    G G G G     (4 celulas)\n");
            
            printf("PROGRESSO: ");
            if (i == 0)
            {
                printf("[X][][]\n");
            }
            else if (i == 1)
            {
                printf("[X][X][]\n");
            }
            else if (i == 2)
            {
                printf("[X][X][X]\n");
            }

            printf("\n");
            
            printf("--- POSICIONAMENTO DO NAVIO %i ---\n", i + 1);
            if (i == 0) printf("Pequeno (P):  2 celulas\n");
            else if (i == 1) printf("Medio (M):    3 celulas\n");
            else printf("Grande (G):   4 celulas\n");
            printf("\n");
            
            printf("LINHA (1-8): ");
            scanf("%d", &linha);
            linha--;// subtrai 1 para se ajustar ao indice da matriz original (0-7) 
            if(linha < 0 || linha > 7){
                system("clear||cls");
                printf("\nErro: Linha invalida! Digite um numero entre 1 e 8.\n\n");
                system("pause");
                system("clear||cls");
                printf("\n========================================\n");
                printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
                printf("========================================\n");
                printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
                continue;
            }
            printf("COLUNA (1-8): ");
            scanf("%d", &coluna);
            coluna--;// subtrai 1 para se ajustar ao indice da matriz original (0-7)
            if(coluna < 0 || coluna > 7){
                system("clear||cls");
                printf("\nErro: Coluna invalida! Digite um numero entre 1 e 8.\n\n");
                system("pause");
                system("clear||cls");
                printf("\n========================================\n");
                printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
                printf("========================================\n");
                printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
                continue;
            }

            printf("ORIENTACAO - [H]orizontal ou [V]ertical? ");
            scanf(" %c", &orientacao);
            if(orientacao != 'H' && orientacao != 'h' && orientacao != 'V' && orientacao != 'v'){
                system("clear||cls");
                printf("Erro: Orientacao invalida! Digite H ou V \n");
                system("pause");
                system("clear||cls");
                printf("\n========================================\n");
                printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
                printf("========================================\n");
                printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
                continue;
            }

            int valido = posicionarNavio(jogador[jogador_atual].tabuleiro, linha, coluna, orientacao, i);
            if (!valido)// Verifica se a posicao e valida atraves da funcao posicionarNavio//
            {
                system("clear||cls");
                printf("Erro: Posicao invalida para o navio %i! Tente novamente.\n", i + 1);
                system("pause");
                system("clear||cls");
                printf("\n========================================\n");
                printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
                printf("========================================\n");
                printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
                continue;
            }
            navio(jogador[jogador_atual].tabuleiro, linha, coluna, orientacao, i);// Adiciona o navio ao tabuleiro//

            system("clear||cls");
            printf("\n========================================\n");
            printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
            printf("========================================\n");
            printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
            i++; //Incrementa o contador de navios posicionados//
        }

        
        mostrar_tabuleiro(jogador[jogador_atual].tabuleiro);
        printf("%s, voce posicionou todos os seus navios!\n", jogador[jogador_atual].nome);
        system("pause");
        system("clear||cls");//biblioteca stdlib.h//
        while (getchar() != '\n')
            ;  // Limpa o buffer de entrada para evitar loop infinito com scanf em C
        i = 0; // Reseta o contador de navios para o próximo jogador
        // Limpa o tabuleiro para o próximo jogador
        
        
    }
    system("clear||cls");
    printf("\n========================================\n");
    printf("==  PREPARACAO CONCLUIDA!  ==\n");
    printf("========================================\n\n");
    
    printf("\nPressione ENTER para iniciar a batalha...\n");

    system("pause");
    system("clear||cls");
    int turno = 0;// Comeca com o jogador 1//
    int rodadas = 1;

   jogar(jogador, rodadas, turno);// Chama a funcao jogar//
}

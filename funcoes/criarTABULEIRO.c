#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca/criarTABULEIRO.h"
#include "../biblioteca/mostrarTABULEIRO.h"
#include "../biblioteca/navio.h"
#include "../biblioteca/posicionarNavio.h"
#include "../biblioteca/menu.h"
#include "../biblioteca/jogar.h"


/*
 * criar_matriz_tabuleiro(): inicializa os dois jogadores e seus
 * respectivos tabuleiros, solicita nomes e coordena o processo
 * de posicionamento dos navios antes de iniciar a partida.
 */
void criar_matriz_tabuleiro()
{
    Jogador jogador[2]; // Dois jogadores (índices 0 e 1)
    int linha, coluna, i = 0;
    char orientacao;

    /* acertos_navio: número de células restantes para cada navio
     * acertos_navio[0] = navio P (2 células)
     * acertos_navio[1] = navio M (3 células)
     * acertos_navio[2] = navio G (4 células)
     */
    for (int jog = 0; jog < 2; jog++){
        jogador[jog].acertos_navio[0] = 2;
        jogador[jog].acertos_navio[1] = 3;
        jogador[jog].acertos_navio[2] = 4;
    }

    /* Zera contadores de acertos (cada jogador ainda não acertou nada) */
    jogador[0].acertos = 0;
    jogador[1].acertos = 0;

    /* Inicializa os 8x8 tabuleiros com '~' representando água */
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
    
    printf("\n");
    printf("========================================\n");
    printf("==        BEM VINDO AO JOGO          ==\n");
    printf("========================================\n\n");
    printf("Vamos comecar! Insira os nomes dos jogadores:\n\n");
    
    printf("Jogador 1, digite seu nome: ");
    scanf("%s", jogador[0].nome);
    printf("Jogador 2, digite seu nome: ");
    scanf("%s", jogador[1].nome);
    system("clear||cls");

    // Loop para cada jogador posicionar seus navios
    for (int jogador_atual = 0; jogador_atual < 2; jogador_atual++)
    {
        system("clear||cls");
        printf("\n========================================\n");
        printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
        printf("========================================\n\n");
        printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
        // Exibe o tabuleiro
        printf("Seu Tabuleiro:\n");
        

        while (i < 3)
        {
            mostrar_tabuleiro(jogador[jogador_atual].tabuleiro);
            printf("\nNAVIOS DISPONIVEIS:\n");
            printf("   [Navio 1 - Pequeno]   P P         (2 celulas)\n");
            printf("   [Navio 2 - Medio]     M M M       (3 celulas)\n");
            printf("   [Navio 3 - Grande]    G G G G     (4 celulas)\n\n");
            
            printf("PROGRESSO: ");

            for(int p = 0; p < 3; p++) {
                if(p < i) printf("[X] ");
                else printf("[ ] ");
            }

            printf("\n\n");
            
            printf("--- POSICIONAMENTO DO NAVIO %i ---\n", i + 1);
            if (i == 0) printf("Pequeno (P):  2 celulas\n");
            else if (i == 1) printf("Medio (M):    3 celulas\n");
            else printf("Grande (G):   4 celulas\n");
            printf("\n");

            
            printf("LINHA (1-8): ");
            scanf("%d", &linha);
            linha--;
            if(linha < 0 || linha > 7){
                system("clear||cls");
                printf("\nErro: Linha invalida! Digite um numero entre 1 e 8.\n\n");
                system("pause");
                system("clear||cls");
                printf("\n========================================\n");
                printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
                printf("========================================\n\n");
                printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
                continue;
            }
            printf("COLUNA (1-8): ");
            scanf("%d", &coluna);
            coluna--;
            if(coluna < 0 || coluna > 7){
                system("clear||cls");
                printf("\nErro: Coluna invalida! Digite um numero entre 1 e 8.\n\n");
                system("pause");
                system("clear||cls");
                printf("\n========================================\n");
                printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
                printf("========================================\n\n");
                printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
                continue;
            }

            printf("ORIENTACAO - [H]orizontal ou [V]ertical? ");

            scanf(" %c", &orientacao);
            if(orientacao != 'H' && orientacao != 'h' && orientacao != 'V' && orientacao != 'v'){
                system("clear||cls");
                printf("\nErro: Orientacao invalida! Digite H ou V.\n\n");
                system("pause");
                system("clear||cls");
                printf("\n========================================\n");
                printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
                printf("========================================\n\n");
                printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
                continue;
            }

            int valido = posicionarNavio(jogador[jogador_atual].tabuleiro, linha, coluna, orientacao, i);
            if (!valido)
            {
                system("clear||cls");
                printf("\nErro: Posicao invalida para o navio! Verifique se:\n");
                printf("   - Cabe no tabuleiro\n");
                printf("   - Nao sobrepoe outro navio\n\n");
                system("pause");
                system("clear||cls");
                printf("\n========================================\n");
                printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
                printf("========================================\n\n");
                printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
                continue;
            }
            navio(jogador[jogador_atual].tabuleiro, linha, coluna, orientacao, i);

            system("clear||cls");
            printf("\nNavio %d posicionado com sucesso!\n", i + 1);
            printf("\nProgresso: ");
            for(int p = 0; p < 3; p++) {
                if(p <= i) printf("[X] ");
                else printf("[ ] ");
            }

            printf("\n\n");
            system("pause");
            system("clear||cls");
            printf("\n========================================\n");
            printf("POSICIONAMENTO DE NAVIOS - TURNO %d\n", jogador_atual + 1);
            printf("========================================\n\n");
            printf("Jogador: %s\n\n", jogador[jogador_atual].nome);
            
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
    printf("\n========================================\n");
    printf("==  PREPARACAO CONCLUIDA!  ==\n");
    printf("========================================\n\n");
    printf("Tabuleiros dos jogadores (verificacao final):\n\n");
    
    for (int jogador_atual = 0; jogador_atual < 2; jogador_atual++)
    {
        printf("Tabuleiro de %s:\n", jogador[jogador_atual].nome);

        mostrar_tabuleiro(jogador[jogador_atual].tabuleiro);
    }
    printf("\nPressione ENTER para iniciar a batalha...\n");

    system("pause");
    system("clear||cls");
    int turno = 0;

   jogar(jogador, turno);
}

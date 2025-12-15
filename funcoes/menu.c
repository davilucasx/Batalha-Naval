#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/menu.h"
#include "../biblioteca/criarTABULEIRO.h"
#include "../biblioteca/leitorTXT.h"
#include "../biblioteca/jogar.h"


void salvar(Jogador jogadores[2], int rodada, int turno){
    FILE *save = fopen("save.txt", "w");
    printf("Arquivo aberto com sucesso!\n");

    if (save == NULL){
        printf("Erro ao salvar o jogo.");
        return;
    }

    

    for (int j = 0; j < 2; j++){
        fprintf (save, "%s\n", jogadores[j].nome);
        for(int i = 0; i < 8; i++){
            for (int n = 0; n < 8; n++){
                fprintf(save, "%c", jogadores[j].tabuleiro[i][n]);
            }
            fprintf(save, "\n");
        }
        for(int i = 0; i < 8; i++){
            for (int n = 0; n < 8; n++){
                fprintf(save, "%c", jogadores[j].tabuleiro_oculto[i][n]);
            }
            fprintf(save, "\n");
        }
        fprintf(save, "%d\n", jogadores[j].acertos);
        for (int i = 0; i < 3; i++){
            fprintf(save, "%d\n", jogadores[j].acertos_navio[i]);
        }
    }
    fprintf(save, "%d\n", rodada);
    fprintf(save, "%d", turno);
    fclose(save);
}

void carregar(){

    FILE *save = fopen("save.txt", "r");
    printf("Arquivo aberto com sucesso!\n");
    Jogador jogadores[2];
    int turno, rodada;
    if (save == NULL){
        printf("Erro ao carregar o jogo.");
        return;
    }

    

    for (int j = 0; j < 2; j++){
        fscanf (save, "%s", jogadores[j].nome);
        for(int i = 0; i < 8; i++){
            for (int n = 0; n < 8; n++){
                fscanf(save, " %c", &jogadores[j].tabuleiro[i][n]);
            }
        }
        for(int i = 0; i < 8; i++){
            for (int n = 0; n < 8; n++){
                fscanf(save, " %c", &jogadores[j].tabuleiro_oculto[i][n]);
            }
        }
        fscanf(save, "%d", &jogadores[j].acertos);
        for (int i = 0; i < 3; i++){
            fscanf(save, "%d", &jogadores[j].acertos_navio[i]);
        }
    }
    fscanf(save, "%d", &rodada);
    fscanf(save, "%d", &turno);
    fclose(save);
    jogar (jogadores, rodada, turno);
}

// Funcao que exibe o menu principal do jogo e lida com as escolhas do usuario // 
void menu(){
    int escolha;          // Escolha a opção do menu
    int entrada_invalida; // Caso não escolha uma opção válida no menu

    // Exibe o menu
    do
    {
        entrada_invalida = 0;
        printf("=======================================\n");
        printf("=           BATALHA NAVAL             =\n");
        printf("=======================================\n");
        printf("\n");
        printf("--- MENU PRINCIPAL ---\n");
        printf("[0] Sair do Jogo\n");
        printf("[1] Novo Jogo\n");
        printf("[2] Continuar Jogando\n");
        printf("[3] Instrucoes\n");
        printf("\nEscolha uma opcao (0-3): ");
        scanf("%d", &escolha);
        system("clear||cls"); // Limpa a tela para melhor visualizacao do menu

        // Escolha do usuário, menu destinado a escolha das opcoes do jogo//
        switch (escolha)
        {
        case 0:
            exit(1);
        case 1:
            system("clear||cls"); // Limpa a tela para melhor visualizacao do menu
            printf("--- Novo Jogo ---\n");
            criar_matriz_tabuleiro();// chama a funcao que cria o tabuleiro//
            break;
        case 2:
            carregar();
            printf("(2) Continuar Jogando\n");
            break;
        case 3:
            printf("\n--- Instrucoes do jogo ---\n");
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
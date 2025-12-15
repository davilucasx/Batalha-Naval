#include <stdio.h>
#include <stdlib.h>
// Cabeçalhos de definição de tipos e funções usadas pelo menu
#include "../biblioteca/menu.h"
#include "../biblioteca/criarTABULEIRO.h"
#include "../biblioteca/leitorTXT.h"
#include "../biblioteca/save.h"
#include "../biblioteca/jogar.h"





/*
 * menu(): exibe o menu principal e chama as rotinas correspondentes.
 * - [1] Novo Jogo: inicia fluxo de criação/posicionamento de tabuleiros
 * - [2] Continuar Jogo: carrega arquivo de save e retoma a partida
 * - [3] Instruções: mostra o arquivo de instruções
 * - [0] Sair: encerra o programa
 */
void menu(){
    int escolha;          // Escolha a opção do menu
    int entrada_invalida; // Flag para repetir caso de opção inválida

    // Exibe o menu
    do
    {
        entrada_invalida = 0;
        printf("\n");
        printf("========================================\n");
        printf("=            BATALHA NAVAL             =\n");
        printf("========================================\n");
        printf("\n");
        printf("--- MENU PRINCIPAL ---\n");
        printf("[1] Novo Jogo\n");
        printf("[2] Continuar Jogo\n");
        printf("[3] Instrucoes\n");
        printf("[0] Sair do Jogo\n");
        printf("\nEscolha uma opcao (0-3): ");
        scanf("%d", &escolha);
        system("clear||cls"); // Limpa a tela para melhor visualizacao do menu

        // Escolha do usuário
        switch (escolha)
        {
        case 0:
            system("clear||cls");
            printf("\nObrigado por jogar! Ate a proxima.\n\n");
            exit(1);
        case 1: /* Iniciar novo jogo */
            system("clear||cls");
            printf("--- NOVO JOGO ---\n\n");
            criar_matriz_tabuleiro();
            break;
        case 2: /* Continuar a partir de um save */
            {
                /* Lista saves registrados e permite escolher um para carregar */
                system("clear||cls");
                char names[64][64];
                int count = listar_saves(names, 64);
                if (count == 0){
                    printf("Nenhum salvamento encontrado. Inicie um novo jogo.\n\n");
                    system("pause");
                    break;
                }

                printf("--- Saves Disponiveis ---\n");
                for (int i = 0; i < count; i++){
                    printf("[%d] %s\n", i+1, names[i]);
                }
                printf("[0] Cancelar\n");
                printf("\n");
                printf("Escolha o numero do save para carregar (0 para cancelar): ");
                int sel = 0;
                scanf("%d", &sel);
                if (sel <= 0 || sel > count){
                    printf("Operacao cancelada.\n\n");
                    system("pause");
                    break;
                }
                /* Tenta carregar o save escolhido */
                Jogador jogador[2];
                int turno = 0;
                if (carregar_jogo_named(jogador, &turno, names[sel-1])){
                    printf("Jogo '%s' carregado! Retornando ao jogo...\n\n", names[sel-1]);
                    system("pause");
                    jogar(jogador, turno);
                } else {
                    printf("Falha ao carregar o save '%s'.\n\n", names[sel-1]);
                    system("pause");
                }

            }
            break;
        case 3:
            system("clear||cls");
            printf("\n--- INSTRUCOES DO JOGO ---\n\n");
            leitor_texto("instrucoes/instrucoes.txt");
            printf("\nPressione ENTER para retornar ao menu...\n");
            system("pause");
            break;
        default:
            printf("\nOpcao invalida! Digite um numero entre 0 e 3.\n\n");
            entrada_invalida = 1;
            system("pause");
            while (getchar() != '\n')
                ; // Limpa o buffer de entrada para evitar loop infinito com scanf em C
            break;
        }
    } while (entrada_invalida == 1);

}
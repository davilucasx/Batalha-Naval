#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/menu.h"
#include "../biblioteca/mostrarTABULEIRO.H"
#include "../biblioteca/save.h"


/*
 * ataquex(): executa um ataque do `atacante` contra o `defensor` na
 * posição (linha,coluna). Atualiza o `tabuleiro_oculto` do atacante
 * com 'X' em caso de acerto e 'O' em caso de erro. Também decrementa
 * o contador `acertos_navio` do defensor para checar quando um navio
 * foi completamente destruído.
 *
 * Retorna 1 se acertou (qualquer parte de um navio), 0 caso contrário.
 */
int ataquex(int linha, int coluna, Jogador *defensor, Jogador *atacante) {

    char alvo = defensor->tabuleiro[linha][coluna];

    if (alvo == 'P' || alvo == 'M' || alvo == 'G') {
        int destruido = 0;
        switch (alvo) {
            case 'P':
                /* diminui contagem do navio pequeno */
                defensor->acertos_navio[0]--;
                if (defensor->acertos_navio[0] == 0) { printf("Navio P destruido!\n");
                destruido = 1;
                }
                break;
            case 'M':
                /* diminui contagem do navio médio */
                defensor->acertos_navio[1]--;
                if (defensor->acertos_navio[1] == 0){ printf("Navio M destruido!\n");
                destruido = 1;
                }
                break;
            case 'G':
                /* diminui contagem do navio grande */
                defensor->acertos_navio[2]--;
                if (defensor->acertos_navio[2] == 0){ printf("Navio G destruido!\n");
                destruido = 1;
                }
                break;
        }

        /* marca acerto no tabuleiro oculto do atacante */
        atacante->tabuleiro_oculto[linha][coluna] = 'X';

        if(!destruido){
            printf("Acertou o navio!\n");
        }

        return 1;

    } else {
        /* marca água no tabuleiro oculto */
        atacante->tabuleiro_oculto[linha][coluna] = 'O';
        printf("Errou o navio, agua!\n");
        return 0;
    }
}

void jogar(Jogador jogador[2], int turno){
    int linha;
    int coluna;
    int vencedor = 2; /* vencedor index: 0 ou 1; 2 = jogo em andamento */
    while(vencedor == 2){
        system("clear||cls");
        printf("\n========================================\n");
        printf("=            RODADA DE BATALHA         =\n");
        printf("========================================\n\n");

        printf("Turno de ataque: %s (Jogador %d)\n", jogador[turno].nome, turno + 1);
        printf("Adversario: %s (Jogador %d)\n\n", jogador[1-turno].nome, (1-turno) + 1);

        printf("Seu mapa de alvos:\n");

        mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);
        
        printf("~ = agua   X = acertou   O = errou   P/M/G = navios\n\n");

        printf("Seus acertos ate agora: %d/9\n\n", jogador[turno].acertos);

        
        printf("Digite as coordenadas do seu ataque:\n");
        printf("LINHA (1-8) (digite 0 para menu de pausa): ");
        scanf("%d", &linha);
        if (linha == 0){
                /* Menu de pausa */
                system("clear||cls");
                printf("\n========================================\n");
                printf("=            MENU DE PAUSA             =\n");
                printf("========================================\n\n");
                printf("[1] Salvar e continuar jogando\n");
                printf("[2] Salvar e sair\n");
                printf("[3] Voltar ao jogo sem salvar\n");
                printf("[4] Sair sem salvar\n\n");
                printf("Escolha uma opcao (1-4): ");
                int opcao_pausa = 0;
                scanf("%d", &opcao_pausa);
                if (opcao_pausa == 1){
                    /* Salvar e continuar jogando */
                    char savename_continue[64];
                    system("clear||cls");
                    printf("\nDigite um nome para o salvamento (sem espacos): ");
                    scanf(" %63s", savename_continue);
                    int _r = salvar_jogo_named(jogador, turno, savename_continue);
                    if (_r == 1){
                        printf("\nJogo salvo em save/%s.dat\n", savename_continue);
                    } else if (_r == -1){
                        printf("\nSalvamento cancelado pelo usuario.\n");
                    } else {
                        printf("\nFalha ao salvar o jogo.\n");
                    }
                    system("pause");
                    system("clear||cls");
                    continue; /* volta ao jogo */
                } else if (opcao_pausa == 2){
                    /* Salvar e sair */
                    char savename[64];
                    system("clear||cls");
                    printf("\nDigite um nome para o salvamento (sem espacos): ");
                    scanf(" %63s", savename);
                    int _r2 = salvar_jogo_named(jogador, turno, savename);
                    if (_r2 == 1){
                        printf("\nJogo salvo em save/%s.dat\n", savename);
                        system("pause");
                        return; /* volta ao menu */
                    } else if (_r2 == -1){
                        printf("\nSalvamento cancelado pelo usuario. Voltando ao jogo.\n");
                        system("pause");
                        system("clear||cls");
                        continue; /* volta ao jogo */
                    } else {
                        printf("\nFalha ao salvar o jogo.\n");
                        system("pause");
                        system("clear||cls");
                        continue; /* volta ao jogo */
                    }
                } else if (opcao_pausa == 3){
                    /* Voltar ao jogo sem salvar */
                    system("clear||cls");
                    continue; /* volta ao jogo */
                } else if (opcao_pausa == 4){
                    /* Sair sem salvar: volta ao menu principal */
                    system("clear||cls");
                    return; /* volta ao menu */
                } else {
                    /* Opcao invalida: retornar ao jogo */
                    system("clear||cls");
                    continue; /* volta ao jogo */
                }
        }
        linha--;
        if(linha < 0 || linha > 7){
                system("clear||cls");
                printf("\nErro: Linha invalida! Digite um numero entre 1 e 8.\n\n");
                system("pause");
                continue;
            }
        printf("COLUNA (1-8): ");
        scanf("%d", &coluna);
        coluna--;
        if(coluna < 0 || coluna > 7){
                system("clear||cls");
                printf("\nErro: Coluna invalida! Digite um numero entre 1 e 8.\n\n");
                system("pause");
                continue;
            }
        if(jogador[turno].tabuleiro_oculto[linha][coluna] != '~'){
                system("clear||cls");
                printf("\nAviso: Essa posicao ja foi atacada!\n");
                printf("Tente outra coordenada.\n\n");
                system("pause");
                continue;
        }
        
        printf("\n");
        /*
         * Executa o ataque e incrementa o contador de acertos do jogador
         * caso `ataquex` retorne sucesso. Note que `ataquex` também atualiza
         * o estado interno (`acertos_navio`) do defensor e o tabuleiro oculto
         * do atacante.
         */
        if (ataquex(linha,coluna, &jogador[1-turno], &jogador[turno])) jogador[turno].acertos++;
        printf("\nResultado do ataque:\n");
        mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);
        
        if (jogador[turno].acertos == 9) {
            vencedor = turno;
            break;
        }
        
        printf("\nTurno de %s concluido!\n", jogador[turno].nome);

        printf("Pressione ENTER para passar o controle...\n");
        system("pause");

        if (turno == 1){
            turno = 0;
        } else turno = 1;
        
    }
    
    system("clear||cls");
    printf("\n========================================\n");
    printf("==  PARABENS, %s!  ==\n", jogador[vencedor].nome);
    printf("========================================\n\n");
    printf("Voce afundou todos os navios do inimigo!\n");
    printf("Voce e o CAPITAO DO OCEANO!\n\n");

    system("pause");
}
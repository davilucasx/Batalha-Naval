#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/menu.h"
#include "../biblioteca/mostrarTABULEIRO.H"


int ataquex(int linha, int coluna, Jogador *defensor, Jogador *atacante) {

    char alvo = defensor->tabuleiro[linha][coluna];

    if (alvo == 'P' || alvo == 'M' || alvo == 'G') {
        int destruido = 0;
        switch (alvo) {
            case 'P':
                atacante->acertos_navio[0]--;
                if (atacante->acertos_navio[0] == 0) { printf("Navio P destruido!\n");
                destruido = 1;
                }
                break;
            case 'M':
                atacante->acertos_navio[1]--;
                if (atacante->acertos_navio[1] == 0){ printf("Navio M destruido!\n");
                destruido = 1;
                }
                break;
            case 'G':
                atacante->acertos_navio[2]--;
                if (atacante->acertos_navio[2] == 0){ printf("Navio G destruido!\n");
                destruido = 1;
                }
                break;
        }

        
        atacante->tabuleiro_oculto[linha][coluna] = 'X';// Marca o acerto no tabuleiro oculto do atacante

        if(!destruido){// Se o navio nao foi destruido, apenas acertado //
            printf("Acertou o navio!\n");
        }
        
        return 1;

    } else {//Caso agua seja atingida//
        atacante->tabuleiro_oculto[linha][coluna] = 'O';
        printf("Errou o navio, agua!\n");
        return 0;
    }
}
void jogar(Jogador jogador[2], int rodadas, int turno){//rodadas=1, turno=0
    int linha;
    int coluna;
    int vencedor = 2;
   while(vencedor == 2){
    system("clear||cls");
        printf("\n========================================\n");
        printf("=            RODADA DE BATALHA         =\n");
        printf("========================================\n");

        printf("Turno de ataque: %s (Jogador %d)\n", jogador[turno].nome, turno + 1);
        printf("Adversario: %s (Jogador %d)\n\n", jogador[1-turno].nome, (1-turno) + 1);
        printf("Seu mapa de alvos:\n");

        mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);

         printf("~ = agua   X = acertou   O = errou   P/M/G = navios\n\n");

        printf("Seus acertos ate agora: %d/9\n\n", jogador[turno].acertos);

        printf("Digite as coordenadas do seu ataque:\n");
        printf("LINHA (1-8) (digite 0 para salvar): ");
        scanf("%d", &linha);
        if (linha == 0) {
            salvar(jogador, rodadas, turno);
            printf("jogo salvo");
            system("clear||cls");
            menu();
            continue;
            }
        linha--;//Subtrai 1 para ajustar ao indice da matriz//
        if(linha < 0 || linha > 7){// Verifica se a linha e valida //
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
                printf("\nErro: Linha invalida! Digite um numero entre 1 e 8.\n\n");
                system("pause");
                continue;
            }
        if(jogador[turno].tabuleiro_oculto[linha][coluna] != '~'){// Verifica se a posicao ja foi atacada //
                system("clear||cls");
                printf("\nAviso: Essa posicao ja foi atacada!\n");
                printf("Tente outra coordenada.\n\n");
                system("pause");
                continue;
        }
        system("clear||cls");
        
        if (ataquex(linha,coluna, &jogador[!turno], &jogador[turno])) jogador[turno].acertos++;// Se acertou, incrementa os acertos do jogador //
        else{
            jogador[turno].erros++;
        }
        mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);// Mostra o tabuleiro oculto do jogador apos o ataque //
        system("pause");
        if (jogador[turno].acertos == 9) {// Verifica se o jogador venceu (9 navios para vencer) //
            vencedor = turno;// Define o vencedor //
            break;
        }
        

        if (turno == 1){
            rodadas++;
            turno = 0;
        } else turno = 1;
        
    }
    FILE *ganhador = fopen("ganhador.txt", "w");
    if(ganhador == NULL){
        printf("Erro ao abrir o arquivo!");
    }
    fprintf(ganhador,"\nParabens %s!\n", jogador[vencedor].nome);
    fprintf(ganhador,"Acertos de %s: %d\n", jogador[0].nome, jogador[0].acertos);
    fprintf(ganhador,"Acertos de %s: %d\n", jogador[1].nome, jogador[1].acertos);
    fprintf(ganhador,"Total de Rodadas Jogadas: %d\n", rodadas);
    fprintf(ganhador,"Total de erros do %s: %d\n",jogador[0].nome, jogador[0].erros);
    fprintf(ganhador,"Total de erros do %s: %d\n",jogador[1].nome, jogador[1].erros);

    fclose(ganhador);

    printf("\n--- ESTATISTICAS DO JOGO ---\n");

    printf("\nParabens %s!\n", jogador[vencedor].nome);
    printf("Acertos de %s: %d\n", jogador[0].nome, jogador[0].acertos);
    printf("Acertos de %s: %d\n", jogador[1].nome, jogador[1].acertos);
    printf("Total de Rodadas Jogadas: %d\n", rodadas);
    printf("Total de erros do %s: %d\n",jogador[0].nome, jogador[0].erros);
    printf("Total de erros do %s: %d\n",jogador[1].nome, jogador[1].erros);

    system("pause");
}
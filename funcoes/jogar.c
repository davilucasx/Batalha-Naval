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
    printf("Vamos jogar ! \n");
    int vencedor = 2;
   while(vencedor == 2){

        printf("jogador %d prepare-se para atacar o jogador %d \n",turno + 1, !turno + 1);// !turno inverte 0 para 1 
        printf("\n");
        printf("Jogador %d Escolha a linha para atacar: ",turno + 1);
        scanf("%d", &linha);
        if (linha == 0) {
            salvar(jogador, rodadas, turno);
            printf("jogo salvo");
            system("pause");
            continue;
            }
        linha--;//Subtrai 1 para ajustar ao indice da matriz//
        if(linha < 0 || linha > 7){// Verifica se a linha e valida //
                system("clear||cls");
                printf("Erro: Opcao de linha invalida! \n");
                mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);// Mostra o tabuleiro oculto do jogador //
                continue;
            }
        printf("Jogador %d Escolha a coluna para atacar: ", turno + 1);
        scanf("%d", &coluna);
        coluna--;
        if(coluna < 0 || coluna > 7){
                system("clear||cls");
                printf("Erro: Opcao de coluna invalida! \n");
                mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);
                continue;
            }
        if(jogador[turno].tabuleiro_oculto[linha][coluna] != '~'){// Verifica se a posicao ja foi atacada //
                system("clear||cls");
                printf("Erro: Posicao ja atacada! \n");
                mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);
                continue;
        }
        if (ataquex(linha,coluna, &jogador[!turno], &jogador[turno])) jogador[turno].acertos++;// Se acertou, incrementa os acertos do jogador //
        mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);// Mostra o tabuleiro oculto do jogador apos o ataque //
        
        if (jogador[turno].acertos == 9) {// Verifica se o jogador venceu (9 navios para vencer) //
            vencedor = turno;// Define o vencedor //
            break;
        }
        

        if (turno == 1){
            rodadas++;
            turno = 0;
        } else turno = 1;
        
    }
    printf("\nParabens %s!\n", jogador[vencedor].nome);
    system("pause");
}
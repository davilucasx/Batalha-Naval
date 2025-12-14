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
                defensor->acertos_navio[0]--;
                if (defensor->acertos_navio[0] == 0) { printf("Navio P destruido!\n");
                destruido = 1;
                }
                break;
            case 'M':
                defensor->acertos_navio[1]--;
                if (defensor->acertos_navio[1] == 0){ printf("Navio M destruido!\n");
                destruido = 1;
                }
                break;
            case 'G':
                defensor->acertos_navio[2]--;
                if (defensor->acertos_navio[2] == 0){ printf("Navio G destruido!\n");
                destruido = 1;
                }
                break;
        }

        
        atacante->tabuleiro_oculto[linha][coluna] = 'X';

        if(!destruido){
            printf("Acertou o navio!\n");
        }
        
        return 1;

    } else {
        atacante->tabuleiro_oculto[linha][coluna] = 'O';
        printf("Errou o navio, agua!\n");
        return 0;
    }
}



int ataque(int linha, int coluna, char tabuleiro[8][8], char tabuleiro_oculto[8][8]) {
    
    if(tabuleiro[linha][coluna] == 'P' || tabuleiro[linha][coluna] == 'M' || tabuleiro[linha][coluna] == 'G') {
        tabuleiro_oculto[linha][coluna] = 'X';  // acertou
        printf("Acertou o navio!\n");
        return 1;
    } else {
        tabuleiro_oculto[linha][coluna] = 'O';  // errou
        printf("Errou o navio, agua!\n");
        return 0;
    }
}

void jogar(Jogador jogador[2], int rodadas, int turno){
    int linha;
    int coluna;
    printf("Vamos jogar ! \n");
    int vencedor = 2;
    while(vencedor == 2){
        printf("jogador %d prepare-se para atacar o jogador %d \n",turno + 1, !turno + 1);
        printf("\n");
        printf("Jogador %d Escolha a linha para atacar: ",turno + 1);
        scanf("%d", &linha);
        linha--;
        if(linha < 0 || linha > 7){
                system("clear||cls");
                printf("Erro: Opcao de linha invalida! \n");
                mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);
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
        if(jogador[turno].tabuleiro_oculto[linha][coluna] != '~'){
                system("clear||cls");
                printf("Erro: Posicao ja atacada! \n");
                mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);
                continue;
        }
        if (ataquex(linha,coluna, &jogador[!turno], &jogador[turno])) jogador[turno].acertos++;
        mostrar_tabuleiro(jogador[turno].tabuleiro_oculto);
        
        if (jogador[turno].acertos == 9) {
            vencedor = turno;
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
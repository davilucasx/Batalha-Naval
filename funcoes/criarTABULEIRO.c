#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca/criarTABULEIRO.h"
#include "../biblioteca/matriz.h"
#include "../biblioteca/navio.h"

void criar_matriz_tabuleiro(){
    int linha, coluna, i = 0;
    char orientacao;
    char tabuleiro[8][8];
    // Inicializa o tabuleiro com '~' representando água
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tabuleiro[i][j] = '~';
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Inicial:\n");
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < 8; i++){
        printf("%d ", i);
        for(int j = 0; j < 8; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    //Monta os navios no tabuleiro
    printf("\n");
    while (i < 3){
    printf("Posicione o navio %i no tabuleiro!\n", i+1);
    printf("Digite H para horizontal ou V para vertical: ");
    scanf(" %c", &orientacao);
    printf("Digite as coordenadas\n");
    printf("LINHA: ");
    scanf("%d", &linha);
    printf("COLUNA: ");
    scanf("%d", &coluna);
    // Adiciona o navio ao tabuleiro escolhendo a posição inicial linha e coluna
    if(orientacao == 'H' || orientacao == 'h'){
        printf("O navio sera posicionado horizontalmente\n");
    // Horizontamente
        if(i == 0){
            for(int k = 0; k < 2; k++){
                tabuleiro[linha][coluna + k] = 'P';
            }
        }
        if(i == 1){
            for(int k = 0; k < 3; k++){
                tabuleiro[linha][coluna + k] = 'M';
             }   
        }
        if(i == 2){
            for(int k = 0; k < 4; k++){
                tabuleiro[linha][coluna + k] = 'G';
        }    
    }
    // Verticalmente
    }    
    else if(orientacao == 'V' || orientacao == 'v'){
        printf("O navio sera posicionado verticalmente\n");
        if(i == 0){
                 for(int k = 0; k < 2; k++){
                tabuleiro[linha + k][coluna] = 'P';
                }
            }
        if(i == 1){
                for(int k = 0; k < 3; k++){
                tabuleiro[linha + k][coluna] = 'M';
                }
            }
        if(i == 2){
                for(int k = 0; k < 4; k++){
                tabuleiro[linha + k][coluna] = 'G';
            }
            }
    } else {
        printf("Direcao invalida! Tente novamente.\n");
        continue;
    }
    system("clear||cls");
    if(i == 0){
        printf("TABULEIRO ATUALIZADO (+)( )( )\n");
    }else if(i == 1){
        printf("TABULEIRO ATUALIZADO (+)(+)( )\n");
    }else if(i == 2){
        printf("TABULEIRO ATUALIZADO (+)(+)(+)\n");
    }
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < 8; i++){
        printf("%d ", i);
        for(int j = 0; j < 8; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
     i++;
    }   
}
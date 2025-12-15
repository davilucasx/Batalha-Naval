#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/posicionarNavio.h"
// Funcao que verifica se a posicao do navio e valida no tabuleiro //
int posicionarNavio(char tabuleiro[8][8], int linha, int coluna, char orientacao, int i){
    if(orientacao == 'H' || orientacao == 'h'){
        if(i == 0){// Navio Pequeno
            if(coluna + 2 > 8){// Verifica se o navio cabe horizontalmente 
                return 0;
            }
        }
        if(i == 1){// Navio Medio
            if(coluna + 3 > 8){// Verifica se o navio cabe horizontalmente 
                return 0;
            }
            for (int j = 0; j < 3; j++){// Verifica se a posicao esta livre
                if (tabuleiro[linha][coluna+j] != '~'){// Se a posicao nao estiver livre, retorna 0
                    return 0;
                }
            }
        }// Verifica se o navio cabe horizontalmente e se a posicao esta livre
        if(i == 2){// Navio Grande
            if(coluna + 4 > 8){// Verifica se o navio cabe horizontalmente
                return 0;
            }
            for (int j = 0; j < 3; j++){// Verifica se a posicao esta livre
                if (tabuleiro[linha][coluna+j] != '~'){// Se a posicao nao estiver livre, retorna 0
                    return 0;
                }
            }
        }
        return 1;
    }

    if(orientacao == 'V' || orientacao == 'v'){
        if(i == 0){// Navio Pequeno
            if(linha + 2 > 8){// Verifica se o navio cabe verticalmente
                return 0;
            }
        }
        if(i == 1){// Navio Medio
            if(linha + 3 > 8){// Verifica se o navio cabe verticalmente
                return 0;
            }
            for (int j = 0; j < 3; j++){// Verifica se a posicao esta livre
                if (tabuleiro[linha][coluna+j] != '~'){// Se a posicao nao estiver livre,
                    return 0;
                }
            }
        }
        if(i == 2){// Navio Grande
            if(linha + 4 > 8){// Verifica se o navio cabe verticalmente
                return 0;
            }
            for (int j = 0; j < 3; j++){// Verifica se a posicao esta livre
                if (tabuleiro[linha][coluna+j] != '~'){// Se a posicao nao estiver livre,
                    return 0;
                }
            }
        }
        return 1;// Se a posicao for valida, retorna 1
    }
    return -1;// Retorna -1 caso a orientacao seja invalida
}


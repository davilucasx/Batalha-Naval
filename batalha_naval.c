#include <stdio.h>
int main() {
     int escolha;

    printf("-----------------------\n");
    printf("  BATALHA NAVAL\n");
    printf("-----------------------\n");
    printf("Menu:\n");
    printf("(0) Sair do Jogo\n");
    printf("(1) Novo Jogo\n");
    printf("(2) Continuar Jogando\n");
    printf("(3) Instrucoes\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    printf("\n-----------------------\n");
    
    switch(escolha) {
        case 1:
            printf("(1) Novo Jogo\n");
            break;
        case 2:
            printf("(2) Continuar Jogando\n");
            break;
        case 3:
            printf("(3) Instrucoes\n");
            break;
        default:
            printf("(0) Sair do Jogo\n");
            break;
    }
    return 0;
}

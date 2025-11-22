#include <stdio.h>
#include "funcoes/LeitorMD.c"
int main() {
     int escolha;
     int entrada_invalida;

// Exibe o menu e lê a escolha do usuário
    do{
        entrada_invalida = 0;
        printf("-----------------------\n");
        printf("  BATALHA NAVAL\n");
        printf("-----------------------\n");
        printf("Menu:\n");
        printf("(0) Sair do Jogo\n");
        printf("(1) Novo Jogo\n");
        printf("(2) Continuar Jogando\n");
        printf("(3) Instrucoes\n");
        printf("-----------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        system("clear||cls"); // Limpa a tela para melhor visualizacao do menu

        switch(escolha) {
            case 0:
                printf("(0) Sair do Jogo\n");
                break;
            case 1:
                printf("(1) Novo Jogo\n");
                break;
            case 2:
                printf("(2) Continuar Jogando\n");
                break;
            case 3:
                printf("(3) Instrucoes\n");
                printf("--- Conteúdo do Arquivo instrucoes.md ---\n");
                leitor_markdown("../instrucoes/instrucoes.md"); // Chama a função para ler e exibir o conteúdo do arquivo Markdown nas instruções
                printf("--------------------------------------\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                entrada_invalida = 1;
                while (getchar() != '\n'); // Limpa o buffer de entrada para evitar loop infinito com scanf em C
                break;
            }
    } while (entrada_invalida == 1);
    system("pause||read -p 'Pressione Enter para continuar...' -n 1");
    return 0;
}

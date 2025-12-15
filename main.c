#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/leitorTXT.h"
#include "biblioteca/criarTABULEIRO.h"
#include "biblioteca/menu.h"
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

/*
 * Estrutura global `Jogador` (declarada aqui para compatibilidade
 * com os arquivos que a incluem). Contém nome, tabuleiro visível,
 * tabuleiro oculto (o que o jogador vê dos ataques) e o contador
 * de acertos do jogador.
 */
struct Jogador
{
    char nome[50];
    char tabuleiro[8][8];
    char tabuleiro_oculto[8][8];
    int acertos;
};


/*
 * main(): loop principal que exibe o menu e permite ao usuário
 * escolher iniciar/continuar o jogo. Após cada retorno do menu,
 * pergunta se o jogador quer voltar ao menu (para iniciar outra
 * ação) ou encerrar o programa. Evita chamada recursiva em `main`.
 */
int main()
{
    char voltar;
    /* Ajusta locale para suportar saída UTF-8 em sistemas POSIX */
    setlocale(LC_ALL, "");

    /* No Windows, ajusta a code page do console para UTF-8 para
       que caracteres Unicode (box-drawing, acentos) sejam exibidos. */
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    while(1) {
        menu();

        /* Pergunta simples ao usuário se deseja voltar ao menu. */
        printf("Retornar ao menu inicial, Sim (s) ou Nao (n) ?");
        scanf(" %c", &voltar);
        system("clear||cls");
        if (voltar != 's' && voltar != 'S')
        {
            break; /* Sai do loop e encerra o programa */
        }
    }
    return 0;
}

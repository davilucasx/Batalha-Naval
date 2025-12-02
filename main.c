#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/leitorTXT.h"
#include "biblioteca/criarTABULEIRO.h"
#include "biblioteca/menu.h"
int main()
{
    char voltar;
    menu();

    // Comando para retornar ao menu inicial ou sair do programa
    printf("Retornar ao menu inicial, Sim (s) ou Nao (n) ?");
    scanf(" %c", &voltar);
    system("clear||cls");
    if (voltar == 's' || voltar == 'S')
    {
        main();
    }
    return 0;
}

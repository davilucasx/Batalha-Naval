#include <stdio.h>
#include "../biblioteca/leitorTXT.h"
void leitor_texto(const char* nomearquivo) {
    FILE* arquivo = fopen(nomearquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char ch;
    while ((ch = fgetc(arquivo)) != EOF) {
        putchar(ch);
    }

    fclose(arquivo);
}
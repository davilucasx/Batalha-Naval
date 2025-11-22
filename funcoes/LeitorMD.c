#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/leitorMD.h"
void leitor_markdown(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}
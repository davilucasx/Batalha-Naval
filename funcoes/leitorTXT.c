#include <stdio.h>
#include "../biblioteca/leitorTXT.h"
void leitor_texto(const char *nomearquivo)
{   // Funcao que le o arquivo de texto e exibe seu conteudo no console //
    FILE *arquivo = fopen(nomearquivo, "r");// Abre o arquivo em modo de leitura //
    if (arquivo == NULL)
    {   // se o arquivo falhou chamamos perror //
        perror("Erro ao abrir o arquivo");// Funcao da biblioteca stdio.h//
        return;
    }

    char ch;// Variavel para armazenar cada caractere lido //
    while ((ch = fgetc(arquivo)) != EOF) // Le o arquivo caractere por caractere ate o final do arquivo //
    {
        putchar(ch);// Exibe o caractere lido no console //
    }

    fclose(arquivo);// Fecha o arquivo apos a leitura //
    

}
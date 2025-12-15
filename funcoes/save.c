#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../biblioteca/save.h"

/*
 * save.c - implementação simples de salvar/carregar em binário.
 *
 * Formato do arquivo: cabeçalho "BNSAVE" (6 bytes com \0), int turno, Jogador[2]
 *
 * Implementação de múltiplos saves:
 * - arquivos de save em `save/<nome>.dat`
 * - índice em `save/index.txt` contendo uma linha por save (nome)
 *
 * Observação: essa abordagem evita depender de APIs de diretório
 * específicas do sistema; o índice mantém os saves registrados.
 */

/* cria a pasta save/ se nao existir (Windows) */
static void ensure_save_dir(){
#ifdef _WIN32
    system("if not exist save mkdir save");
#else
    mkdir("save", 0755);
#endif
}

/* escreve arquivo binário com header e dados do jogo */
static int write_save_file(const char *path, Jogador jogador[2], int turno){
    ensure_save_dir();
    FILE *f = fopen(path, "wb");
    if(!f) return 0;
    char magic[7] = "BNSAVE"; /* inclui terminador */
    fwrite(magic, sizeof(char), 7, f);
    fwrite(&turno, sizeof(int), 1, f);
    fwrite(jogador, sizeof(Jogador), 2, f);
    fclose(f);
    return 1;
}

/* lê arquivo binário de save */
static int read_save_file(const char *path, Jogador jogador[2], int *turno){
    FILE *f = fopen(path, "rb");
    if(!f) return 0;
    char magic[7] = {0};
    if (fread(magic, sizeof(char), 7, f) != 7){ fclose(f); return 0; }
    if(strcmp(magic, "BNSAVE") != 0){ fclose(f); return 0; }
    if(fread(turno, sizeof(int), 1, f) != 1){ fclose(f); return 0; }
    if(fread(jogador, sizeof(Jogador), 2, f) != 2){ fclose(f); return 0; }
    fclose(f);
    return 1;
}

int salvar_jogo_named(Jogador jogador[2], int turno, const char *nome){
    if(!nome || strlen(nome) == 0 || strlen(nome) > 60) return 0;
    char path[260];
    snprintf(path, sizeof(path), "save/%s.dat", nome);
    if(!write_save_file(path, jogador, turno)) return 0;

    /* Atualiza índice se necessário */
    const char *index_path = "save/index.txt";
    FILE *idx = fopen(index_path, "r");
    int exists = 0;
    if(idx){
        char line[128];
        while(fgets(line, sizeof(line), idx)){
            /* remover newline */
            line[strcspn(line, "\r\n")] = 0;
            if(strcmp(line, nome) == 0){ exists = 1; break; }
        }
        fclose(idx);
    }
    if(!exists){
        FILE *a = fopen(index_path, "a");
        if(!a) return 0;
        fprintf(a, "%s\n", nome);
        fclose(a);
    }
    return 1;
}

int carregar_jogo_named(Jogador jogador[2], int *turno, const char *nome){
    if(!nome || strlen(nome) == 0) return 0;
    char path[260];
    snprintf(path, sizeof(path), "save/%s.dat", nome);
    return read_save_file(path, jogador, turno);
}

int listar_saves(char names[][64], int max_names){
    const char *index_path = "save/index.txt";
    FILE *f = fopen(index_path, "r");
    if(!f) return 0;
    int count = 0;
    char line[128];
    while(count < max_names && fgets(line, sizeof(line), f)){
        line[strcspn(line, "\r\n")] = 0;
        strncpy(names[count], line, 63);
        names[count][63] = '\0';
        count++;
    }
    fclose(f);
    return count;
}

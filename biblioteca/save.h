#ifndef _SAVE_H
#define _SAVE_H

#include "menu.h"

/* Salvar com nome: cria `save/<nome>.dat` e registra no índice */
int salvar_jogo_named(Jogador jogador[2], int turno, const char *nome);
/* Carregar por nome: carrega `save/<nome>.dat` */
int carregar_jogo_named(Jogador jogador[2], int *turno, const char *nome);
/* Lista os saves registrados em save/index.txt. `names` deve
	comportar `max_names` strings de até 63 chars. Retorna número de saves. */
int listar_saves(char names[][64], int max_names);

#endif

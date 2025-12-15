# Relatório do Projeto — Batalha Naval

## Visão Geral

Este projeto implementa um jogo de Batalha Naval em C (console) com suporte a:
- Interface em ASCII compatível com Windows cmd.exe
- Sistema de salvamento/carregamento por arquivo (`save/<nome>.dat`) e índice (`save/index.txt`)
- Menu principal, criação/posicionamento de navios e jogo por turnos
- Menu de pausa durante o jogo permitindo salvar e sair no meio da partida

Linguagem: C (GCC/MinGW). Arquivos organizados em módulos sob `funcoes/` e headers em `biblioteca/`.

---

## Estrutura do projeto

- `main.c` — ponto de entrada; inicializa console/locale e chama `menu()`.
- `biblioteca/` — headers: `*.h` com declarações de funções e tipos (`menu.h`, `jogar.h`, `save.h`, etc.).
- `funcoes/` — implementações:
  - `criarTABULEIRO.c`, `mostrarTABULEIRO.c`, `posicionarNavio.c`, `navio.c`, `leitorTXT.c`, `menu.c`, `jogar.c`, `save.c`.
- `save/` — diretório onde são gravados os saves (`<nome>.dat`) e `index.txt`.
- `output/` — executável `main.exe` após compilação.

---

## Como compilar

Usando a task já configurada (VS Code) ou manualmente com `gcc`:

```bash
gcc -Wall -Wextra -g3 \
  main.c \
  funcoes/leitorTXT.c \
  funcoes/criarTABULEIRO.c \
  funcoes/mostrarTABULEIRO.c \
  funcoes/menu.c \
  funcoes/navio.c \
  funcoes/posicionarNavio.c \
  funcoes/jogar.c \
  funcoes/save.c \
  -o output/main.exe
```

Observação: a task do workspace foi atualizada para incluir `funcoes/save.c`.

# Relatório do Projeto — Batalha Naval

## Visão Geral

Jogo de Batalha Naval em C, orientado a terminal (Windows/PowerShell). Principais recursos:
- Interface em ASCII, compatível com cmd.exe/PowerShell
- Posicionamento manual ou aleatório de navios
- Sistema de salvamento/carregamento por arquivo (`save/<nome>.dat`) com índice (`save/index.txt`)
- Menu de pausa durante o jogo (salvar/continuar/sair)

Linguagem: C (GCC/MinGW). Código modular em `funcoes/` com headers em `biblioteca/`.

---

## Estrutura do projeto

- `main.c` — ponto de entrada; inicializa locale/console e chama `menu()`.
- `biblioteca/` — headers (`*.h`) com declarações de tipos e funções.
- `funcoes/` — implementações: `criarTABULEIRO.c`, `mostrarTABULEIRO.c`, `posicionarNavio.c`, `navio.c`, `leitorTXT.c`, `menu.c`, `jogar.c`, `save.c`.
- `save/` — diretório de saves (`<nome>.dat`) e `index.txt` (criado automaticamente no primeiro save).
- `output/` — executável `main.exe` após compilação.

---

## Como compilar

Usando a task do VS Code (atualizada) ou manualmente:

```bash
gcc -Wall -Wextra -g3 \
  main.c \
  funcoes/leitorTXT.c \
  funcoes/criarTABULEIRO.c \
  funcoes/mostrarTABULEIRO.c \
  funcoes/menu.c \
  funcoes/navio.c \
  funcoes/posicionarNavio.c \
  funcoes/jogar.c \
  funcoes/save.c \
  -o output/main.exe
```

---

## Como executar

No Windows (cmd.exe / PowerShell):

1. Abra o terminal no diretório do projeto.
2. Execute `output\main.exe`.
3. Se houver problemas de exibição no cmd.exe, executar `chcp 65001` antes (opcional).

---

## Sistema de salvamento

Formato do arquivo (binário): cabeçalho `"BNSAVE"`, `int turno`, `Jogador[2]`.

Implementação e detalhes (`funcoes/save.c`):
- `salvar_jogo_named(...)` — cria `save/<nome>.dat` e atualiza `save/index.txt`.
- `carregar_jogo_named(...)` — lê o arquivo e popula o estado do jogo.
- `listar_saves(...)` — lista saves registrados em `save/index.txt`.

Comportamento adicional:
- A pasta `save/` é criada automaticamente se não existir.
- Ao salvar, o sistema verifica se o arquivo já existe e pede confirmação de overwrite. A função retorna:
  - `1` — salvo com sucesso
  - `0` — erro de I/O
  - `-1` — cancelado pelo usuário (não sobrescreve)

---

## Menu de pausa (no jogo)

Implementado em `funcoes/jogar.c`. Ao digitar `0` no prompt de linha durante o ataque, aparece o menu com as seguintes opções:

- `[1] Salvar e continuar jogando` — solicita nome, salva (com confirmação) e retorna ao jogo.
- `[2] Salvar e sair` — solicita nome, salva (com confirmação) e retorna ao menu principal se o save ocorrer; se cancelado, retorna ao jogo.
- `[3] Voltar ao jogo sem salvar` — continua o jogo imediatamente.
- `[4] Sair sem salvar` — volta ao menu principal sem salvar.

As mensagens de sucesso, erro e cancelamento são tratadas e exibidas ao usuário.

---

## Posicionamento de navios

No fluxo de criação dos tabuleiros (`funcoes/criarTABULEIRO.c`) foi adicionada a opção de posicionamento aleatório:
- Antes do posicionamento manual, o jogador é perguntado: `Deseja posicionar os navios de forma aleatoria? (s/n)`.
- Resposta `s` preenche automaticamente o tabuleiro do jogador com posições válidas (sem sobreposição) e pula o restante do fluxo de posicionamento.

---

## Principais correções e melhorias realizadas

- Removida recursão em `main()` substituindo por loop principal.
- Corrigido acesso ao adversário em `jogar.c` (`1 - turno`).
- Corrigidas validações de posicionamento de navios em `posicionarNavio.c`.
- Removidos caracteres Unicode/emoji nos prompts (substituídos por ASCII).
- Implementado sistema de múltiplos saves com índice (`save/index.txt`).
- Implementada criação automática do diretório `save/`.
- Implementada confirmação de overwrite ao salvar.
- Menu de pausa estendido (salvar+continuar, salvar+sair, voltar sem salvar, sair sem salvar).
- Adicionado posicionamento aleatório de navios.
- Corrigido problema de múltiplas definições removendo `#include "save.c"` de `menu.c` e atualizando a task de build.

---

## Testes recomendados (prioritários)

1. Novo jogo → escolher posicionamento manual; verificar posicionamento e jogo normal.
2. Novo jogo → escolher posicionamento aleatório (s) para ambos jogadores; confirmar tabuleiros e iniciar jogo.
3. Durante o jogo, no prompt de linha digitar `0` e testar cada opção do menu de pausa:
   - `[1]` salvar e continuar (confirma overwrite quando aplicável)
   - `[2]` salvar e sair (carregar depois via menu)
   - `[3]` voltar sem salvar
   - `[4]` sair sem salvar
4. Verificar que `save/<nome>.dat` é criado e que `save/index.txt` contém o nome (quando salvo).
5. Testar carregar um save pelo Menu principal → `Continuar Jogo` e verificar restauração de estado e turno.

---

## Arquivos-chave para revisão

- [main.c](main.c)
- [funcoes/jogar.c](funcoes/jogar.c)
- [funcoes/save.c](funcoes/save.c)
- [funcoes/posicionarNavio.c](funcoes/posicionarNavio.c)
- [funcoes/criarTABULEIRO.c](funcoes/criarTABULEIRO.c)
- [funcoes/menu.c](funcoes/menu.c)

---

Se quiser, posso também atualizar o `README.md` com instruções resumidas ou adicionar exemplos de uso rápido. Deseja que eu atualize o `RELATORIO.md` com mais detalhes (ex.: formatos binários, layout de `Jogador`) ou que eu gere o `README.md` agora?
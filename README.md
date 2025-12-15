# Batalha Naval (Resumo)

Este é um jogo de Batalha Naval em C para terminal (Windows / PowerShell). Este README traz instruções rápidas para compilar, executar e usar as funcionalidades principais (saves, menu de pausa e posicionamento aleatório).

## Compilar

Use a task do VS Code (já configurada) ou rode manualmente:

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

## Executar

No PowerShell ou cmd.exe, no diretório do projeto:

```powershell
output\main.exe
```

Se estiver usando `cmd.exe` e tiver problemas de exibição, execute `chcp 65001` antes.

## Controles rápidos

- Durante o posicionamento de navios você pode optar por posicionamento aleatório respondendo `s` quando perguntado.
- Durante o jogo, no prompt `LINHA`, digite `0` para abrir o menu de pausa com opções:
  1. `Salvar e continuar jogando`
  2. `Salvar e sair`
  3. `Voltar ao jogo sem salvar`
  4. `Sair sem salvar`

## Sistema de Save

- Saves são gravados em `save/<nome>.dat` (binário). Um índice `save/index.txt` mantém os nomes.
- Ao salvar, o jogo pede confirmação caso o arquivo já exista (evite sobrescrever sem querer).

## Testes rápidos

1. Inicie novo jogo; teste posicionamento manual e aleatório.
2. Durante partida, pressione `0` e teste cada opção do menu de pausa.
3. Salve, saia e recarregue via menu principal → `Continuar Jogo`.

---

Se quiser, posso adicionar um tutorial passo-a-passo ou exemplos rápidos no arquivo.

# Xadrez Virtual Bonito em C

## Descrição do Projeto

Este projeto simula movimentos de peças de xadrez no console, utilizando conceitos avançados de programação em C, como **recursividade** e **loops complexos/aninhados**.  

O objetivo é permitir que o usuário escolha uma peça (Torre, Bispo, Rainha ou Cavalo) e veja seus movimentos simulados de forma clara e organizada, com cores, emojis e pausas entre os passos para melhorar a visualização.

---

## Funcionalidades

- **Torre (♖)**: Movimento recursivo para cima e para a direita.
- **Bispo (♗)**: Movimento recursivo em diagonal + loops aninhados para demonstrar deslocamentos.
- **Rainha (♕)**: Movimento recursivo combinando cima e direita.
- **Cavalo (♘)**: Movimento em "L" usando loops complexos (duas casas para cima e uma para a direita).

O programa imprime cada movimento no console, com cores e emojis para tornar a experiência mais visual.

---

## Como Compilar e Executar

1. Abra um terminal ou prompt de comando na pasta onde está o arquivo `xadrez.c`.

2. **Compile o código** usando o GCC:
   ```bash
   gcc xadrez.c -o xadrez.exe
3. Problemas de Codificação no Windows

  Se os emojis ou acentos aparecerem "feios" (como ÔÖƒ´©Å), siga estas etapas:
  chcp 65001
  .\xadrez.exe

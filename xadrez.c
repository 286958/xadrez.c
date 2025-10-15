#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h> // Sleep no Windows
#define PAUSA(ms) Sleep(ms)
#else
#include <unistd.h> // usleep no Linux/macOS
#define PAUSA(ms) usleep((ms)*1000)
#endif

/*
    ================================================
    PROGRAMA: Movimentos Interativos de Xadrez (Bonito)
    OBJETIVO: Permitir que o usuário escolha a peça
              e visualizar os movimentos de forma
              mais clara e colorida.
    ================================================
*/

// ---------- TORRE (recursiva) ----------
void moverTorreCima(int casas) {
    if (casas == 0) return;
    printf("\033[1;34m♖ Torre: Cima\033[0m\n"); // azul
    PAUSA(500);
    moverTorreCima(casas - 1);
}

void moverTorreDireita(int casas) {
    if (casas == 0) return;
    printf("\033[1;34m♖ Torre: Direita\033[0m\n"); // azul
    PAUSA(500);
    moverTorreDireita(casas - 1);
}

// ---------- BISPO (recursivo + loops aninhados) ----------
void moverBispoRecursivo(int casas) {
    if (casas == 0) return;
    printf("\033[1;32m♗ Bispo: Diagonal (Cima + Direita)\033[0m\n"); // verde
    PAUSA(500);
    moverBispoRecursivo(casas - 1);
}

void moverBispoLoops(int linhas, int colunas) {
    for (int i = 1; i <= linhas; i++) { // vertical
        for (int j = 1; j <= colunas; j++) { // horizontal
            printf("\033[1;32m♗ Bispo: Loop Diagonal (Cima + Direita)\033[0m\n");
            PAUSA(300);
        }
    }
}

// ---------- RAINHA (recursiva) ----------
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("\033[1;35m♕ Rainha: Cima\033[0m\n"); // magenta
    PAUSA(400);
    printf("\033[1;35m♕ Rainha: Direita\033[0m\n");
    PAUSA(400);
    moverRainha(casas - 1);
}

// ---------- CAVALO (loops complexos) ----------
void moverCavalo() {
    printf("\033[1;33m♘ Cavalo: Movimento em L\033[0m\n"); // amarelo
    for (int i = 1; i <= 2; i++) { // sobe duas casas
        printf("  Cavalo: Cima (%d)\n", i);
        PAUSA(300);
        if (i == 2) {
            for (int j = 1; j <= 1; j++) { // direita 1 casa
                printf("  Cavalo: Direita (%d)\n", j);
                PAUSA(300);
            }
        }
    }
}

// ---------- FUNÇÃO PRINCIPAL ----------
int main() {
    int opcao, casas;

    printf("=== ♟️ XADREZ VIRTUAL BONITO ♟️ ===\n");
    printf("Escolha uma peça para movimentar:\n");
    printf("1 - Torre ♖\n");
    printf("2 - Bispo ♗\n");
    printf("3 - Rainha ♕\n");
    printf("4 - Cavalo ♘\n");
    printf("Digite o número da peça: ");
    scanf("%d", &opcao);

    if (opcao != 4) {
        printf("Quantas casas deseja movimentar? ");
        scanf("%d", &casas);
    }

    printf("\n=== 🏁 MOVIMENTOS 🏁 ===\n\n");

    switch (opcao) {
        case 1:
            printf(">>> Movendo a TORRE ♖ <<<\n");
            moverTorreCima(casas);
            moverTorreDireita(casas);
            break;

        case 2:
            printf(">>> Movendo o BISPO ♗ <<<\n");
            moverBispoRecursivo(casas);
            printf("\n-- Usando loops aninhados --\n");
            moverBispoLoops(2, 2); // exemplo fixo
            break;

        case 3:
            printf(">>> Movendo a RAINHA ♕ <<<\n");
            moverRainha(casas);
            break;

        case 4:
            printf(">>> Movendo o CAVALO ♘ <<<\n");
            moverCavalo();
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }

    printf("\n=== ✅ FIM DO MOVIMENTO ✅ ===\n");
    return 0;
}

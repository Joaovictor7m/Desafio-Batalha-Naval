#include <stdio.h>

#define TABULEIRO 10    // Tamanho do tabuleiro escolhido
#define NAVIO 3     // Tamanho de cada navio

int main() {
    int tabuleiro[TABULEIRO][TABULEIRO]; 
    int x, y; // Usaremos 'x' para linha e 'y' para coluna

    // Inicializa o tabuleiro com 0 (água)
    for (x = 0; x < TABULEIRO; x++) {
        for (y = 0; y < TABULEIRO; y++) {
            tabuleiro[x][y] = 0;
        }
    }

    // ---  Definição das Posições ---
    
    // Navio Horizontal (Linha fixa, Coluna varia)
    int navioH_linha = 2; // Linha inicial (índice 2)
    int navioH_coluna = 1; // Coluna inicial (índice 1)

    // Navio Vertical (Coluna fixa, Linha varia)
    int navioV_linha = 5; // Linha inicial (índice 5)
    int navioV_coluna = 7; // Coluna inicial (índice 7)


   
    // --- Posicionamento dos Navios --- 


    if (navioH_coluna + NAVIO > TABULEIRO || navioH_linha >= TABULEIRO) {
        printf("Navio horizontal fora dos limites do tabuleiro!\n");
        return 1; 
    }

    
    if (navioV_linha + NAVIO > TABULEIRO || navioV_coluna >= TABULEIRO) {
        printf("Navio vertical fora dos limites do tabuleiro!\n");
        return 1; 
    }

    //  Posiciona navio horizontal
   
    for (int x = 0; x < NAVIO; x++) {
        tabuleiro[navioH_linha][navioH_coluna + x] = 1; // Marcando com 1 (Mais comum)
    }

   
    for (int x = 0; x < NAVIO; x++) {
        // Validação de sobreposição: verifica se já tem um navio (marcado com 1)
        if (tabuleiro[navioV_linha + x][navioV_coluna] == 1) {
            printf("Erro: navios sobrepostos!\n");
            return 1;
        }
        tabuleiro[navioV_linha + x][navioV_coluna] = 1; // Marcando com 1
    }

    // --- Exibição ---

    printf("== TABULEIRO BATALHA NAVAL ==\n\n");


    // Cabeçalho das colunas 
    printf("   "); 
    for (y = 0; y < TABULEIRO; y++) {
        printf("%c ", 'A' + y); // Letras de A a J
    }
    printf("\n");

    // Exibe o tabuleiro
    for (x = 0; x < TABULEIRO; x++) {
        printf("%2d ", x + 1); // Número da linha
        for (y = 0; y < TABULEIRO; y++) {
            printf("%d ", tabuleiro[x][y]);
        }
        printf("\n");
    }

    return 0;
}

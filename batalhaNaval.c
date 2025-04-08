#include <stdio.h>

int tabuleiro[10][10];  //Tamanho do tabuleiro

void Tabuleiro() {
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void navioHorizontal(int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (coluna + i <= 9)
            tabuleiro[linha][coluna + i] = 3;
    }
}

void navioVertical(int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i <= 9)
            tabuleiro[linha + i][coluna] = 3;
    }
}

void navioDiagonalPrincipal(int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i <= 9 && coluna + i <= 9)
            tabuleiro[linha + i][coluna + i] = 3;
    }
}

void navioDiagonalInversa(int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i <= 9 && coluna - i >= 0)
            tabuleiro[linha + i][coluna - i] = 3;
    }
}

//Cone = 6, Cruz = 4, Octaedro = 5
void habilidadeCone(int linha, int coluna) {
    for (int i = 0; i <= 9; i++) {
        for (int j = coluna - i; j <= coluna + i; j++) {
            if (j >= 0 && j <= 9 && tabuleiro[i][j] == 0)
                tabuleiro[i][j] = 6;
        }
    }
}

void habilidadeCruz(int linha, int coluna) {
    for (int i = 0; i <= 9; i++) {
        if (tabuleiro[linha][i] == 0)
            tabuleiro[linha][i] = 4;
        if (tabuleiro[i][coluna] == 0)
            tabuleiro[i][coluna] = 4;
    }
}

int valorabsoluto(int x) {
    if (x < 0)
        return -x;
    else
        return x;
}

void habilidadeOctaedro(int linha, int coluna) {
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            int distancia = valorabsoluto(i - linha) + valorabsoluto(j - coluna);
            if (distancia <= 2 && tabuleiro[i][j] == 0)
                tabuleiro[i][j] = 5;
        }
    }
}

int main() {

    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            tabuleiro[i][j] = 0;

    //navios
    navioHorizontal(1, 6);
    navioVertical(5, 5);
    navioDiagonalPrincipal(1, 1);
    navioDiagonalInversa(7, 8);

    //habilidades
    habilidadeCone(3, 5);
    habilidadeCruz(5, 5);
    habilidadeOctaedro(6, 4);

    printf("Tabuleiro:\n");
    Tabuleiro();

    return 0;
}
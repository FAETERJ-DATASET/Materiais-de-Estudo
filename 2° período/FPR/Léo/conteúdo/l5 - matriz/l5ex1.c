#include <stdio.h>

void matrizTransposta(int lin, int col, int vOriginal[][5], int vResultado[][8]);

int main() {
    int mT[5][8];
    int matriz[8][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19},
        {20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34},
        {35, 36, 37, 38, 39}
    };

    matrizTransposta(8, 5, matriz, mT);

    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d ", mT[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void matrizTransposta(int lin, int col, int vOriginal[][5], int vResultado[][8]) {
    int i, j;

    for (i = 0; i < col; i++) {
        for (j = 0; j < lin; j++) {
            vResultado[i][j] = vOriginal[j][i];
        }
    }
}


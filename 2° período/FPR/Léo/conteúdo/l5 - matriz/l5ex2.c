#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIN 15
#define COL 20

void preencherMatriz(int v[][COL]);
void exibirMatriz(int v[][COL]);
int procurarNum(int v[][COL], int N, int L);

int main() {
    int matriz[LIN][COL];
    int num;
    int linha;

    preencherMatriz(matriz);

    exibirMatriz(matriz);

    printf("\nDigite um numero: ");
    scanf("%d", &num);

    printf("\nEm qual linha deseja procurar? ");
    scanf("%d", &linha);
    
    linha--;

    if (procurarNum(matriz, num, linha)) {
        printf("\nO numero se encontra na linha especificada!");
    } else {
        printf("\nO numero nao se encontra na linha especificada.");
    }

    return 0;
}

void preencherMatriz(int v[][COL]) {
    srand(time(NULL));
    int i, j;

    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            v[i][j] = rand() % 100;
        }
    }
}

void exibirMatriz(int v[][COL]) {
    int i, j;

    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            printf("%2.d ", v[i][j]);
        }
        printf("\n");
    }
}

int procurarNum(int v[][COL], int N, int L) {
	int i;
    for (i = 0; i < COL; i++) { 
        if (N == v[L][i]) { 
            return 1; 
        }
    }
    return 0; 
}
#include <stdio.h>
#define N 3

int verificarGanhador(char m[][N]) {
    int i, j;

    // Verificar linhas e colunas
    for (i = 0; i < N; i++) {
        if (m[i][0] != ' ' && m[i][0] == m[i][1] && m[i][1] == m[i][2]) {
            printf("\n## JOGADOR %c GANHOU!!!! ##\n", m[i][0]);
            return 1; // Retorna 1 para indicar que o jogo acabou
        }
        if (m[0][i] != ' ' && m[0][i] == m[1][i] && m[1][i] == m[2][i]) {
            printf("\n## JOGADOR %c GANHOU!!!! ##\n", m[0][i]);
            return 1; // Retorna 1 para indicar que o jogo acabou
        }
    }

    // Verificar diagonais
    if (m[0][0] != ' ' && m[0][0] == m[1][1] && m[1][1] == m[2][2]) {
        printf("\n## JOGADOR %c GANHOU!!!! ##\n", m[0][0]);
        return 1; // Retorna 1 para indicar que o jogo acabou
    }
    if (m[0][2] != ' ' && m[0][2] == m[1][1] && m[1][1] == m[2][0]) {
        printf("\n## JOGADOR %c GANHOU!!!! ##\n", m[0][2]);
        return 1; // Retorna 1 para indicar que o jogo acabou
    }

    return 0; // Retorna 0 para indicar que o jogo continua
}

void inserir(char m[N][N], int L, int C, char escolha) {
    if (m[L][C] == ' ') {
        m[L][C] = escolha;
        exibirMatriz(m);
    } else {
        printf("Essa posição já está ocupada. Tente novamente.\n");
    }
}

void escolher(char m[N][N]) {
    int L, C;
    char escolha = ' ';
    int jogadas = 0;
    int vitoria = 0;

    while (jogadas < 9 && vitoria == 0) {
        printf("\nEscolha uma linha [1 a 3]: ");
        scanf("%d", &L);
        printf("\nEscolha uma coluna [1 a 3]: ");
        scanf("%d", &C);
        printf("\nEscolha [X] ou [O]: ");
        scanf(" %c", &escolha);

        if ((L > 3) || (L < 1) || (C > 3) || (C < 1) || (escolha != 'X' && escolha != 'O')) {
            printf("Insira valores válidos!\n\n");
        } else {
            L--;
            C--;
            inserir(m, L, C, escolha);
            jogadas++;
            vitoria = verificarGanhador(m);
        }
    }

    if (vitoria == 0) {
        printf("### DEU VELHA! ###\n");
    }
}

void exibirMatriz(char m[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            switch (j) {
                case 0:
                    printf("%-5c |", m[i][j]);
                    break;
                case 1:
                    printf("%-5c", m[i][j]);
                    break;
                case 2:
                    printf("| %-5c", m[i][j]);
                    break;
            }
        }
        switch (i) {
            case 0:
                printf("\n________________\n");
                break;
            case 1:
                printf("\n________________\n");
                break;
        }
        printf("\n");
    }
}

int main() {
    char matriz[N][N] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' }
    };

    printf("### JOGO DA VELHA ###\n\n\n");
    exibirMatriz(matriz);
    escolher(matriz);

    return 0;
}

/*Implementar uma função que, dada uma matriz
M10×8, gere um vetor V de tamanho 8, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.*/

#include <stdio.h>

int main()
{
    int lin = 5;
    int col = 4;
    int matriz[5][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };
    int vetor[4];

    somarMatriz(lin, col, matriz, vetor);

    int i;

    for(i=0; i<col; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}

int somarMatriz(int l, int c, int m[][c], int v[c])
{
    int i, j;
    for (j=0; j<c; j++)
    {
        v[j] = 0;

        for(i=0; i<l; i++)
        {
            v[j] += m[i][j];
        }
    }
}
/*Desenvolver uma função que gere a seguinte matriz M5x5:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9*/

#include <stdio.h>

int gerarMatriz (int l, int c, int m[][5]);

int main()
{
    int lin = 5;
    int col = 5;
    int matriz[5][5];
    gerarMatriz(lin, col, matriz);

    int i, j;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("%2.d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int gerarMatriz (int l, int c, int m[][5])
{
    int i, j, k=1;

    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            m[i][j] = k;
            k++;
        }
        k = k-4;
    }
    return 0;
}
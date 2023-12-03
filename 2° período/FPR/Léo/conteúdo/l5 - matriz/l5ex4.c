/* Fazer uma função que, dada uma matriz M6×6,
determine se ela é simétrica.
[1][2] = [2][1]
[1][3] = [3][1]
[2][3] = [3][2]
*/

#include <stdio.h>

int main()
{
    int lin = 6;
    int col = 6;
    int matriz[6][6] = 
    {
        {0, 1, 2, 3, 4, 5},
        {1, 0, 6, 7, 8, 9},
        {2, 6, 0, 1, 2, 3},
        {3, 7, 1, 0, 4, 5},
        {4, 8, 2, 4, 0, 6},
        {5, 9, 3, 5, 6, 0}
        /*{0, 1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10, 11},
        {12, 13, 14, 15, 16, 17},
        {18, 19, 20, 21, 22, 23},
        {24, 25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34, 35}*/
    };

    if(matrizSimetrica(lin, col, matriz))
    {
        printf("E simetrica.");
    }
    else
    {
        printf("Nao e simetrica.");
    }
    return 0;
}

matrizSimetrica(int l, int c, int m[][6])
{
    int i, j;

    for(i=0; i<l-1; i++)
    {
        for(j=i+1; j<c; j++)
        {
            if(m[i][j] != m[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
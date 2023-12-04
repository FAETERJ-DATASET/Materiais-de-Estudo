#include <stdio.h>

#define LIN 10
#define COL 10

void gerarM3(int m1[][COL], int m2[][COL], int m3[][COL]);
int somaLinhaColuna(int m[][COL], int l, int c);
void preencherMatrizM1(int m[][COL]);
void preencherMatrizM2(int m[][COL]);
void exibir(int m[][COL]);

int main()
{
    int m1[LIN][COL];
    int m2[LIN][COL];
    int m3[LIN][COL];

    preencherMatrizM1(m1);
    preencherMatrizM2(m2);

    printf("\nMatriz M1:\n ");
    exibir(m1);
    printf("\nMatriz M2:\n ");
    exibir(m2);

    gerarM3(m1, m2, m3);

    printf("\nMatriz M3:\n ");
    exibir(m3);
}

void gerarM3(int m1[][COL], int m2[][COL], int m3[][COL])
{
    int i, j; 

    for(i=0; i<LIN; i++)
    {
        for(j=0; j<COL; j++)
        {
            switch(m2[i][j])
            {
                case 0:
                    m3[i][j] = m1[i][j];
                    break;

                case 1:
                    m3[i][j] = somaLinhaColuna (m2, i, j);
                    break;

                default:
                    printf("AAa");
            }
        }
    }
}

int somaLinhaColuna(int m[][COL], int l, int c)
{
    int i, j, soma = 0;

    for(j=0; j<COL; j++)
    {
        soma += m[l][j];
    }

    for(i=0; i<LIN; i++)
    {
        soma += m[i][c];
    }
    return soma;
}

void preencherMatrizM1(int m[][COL])
{
    int i, j;   

    for(i=0; i<LIN; i++)
    {
        for(j=0; j<COL; j++)
        {
            m[i][j] = rand()%100;
        }
    }
}

void preencherMatrizM2(int m[][COL])
{
    int i, j;   

    for(i=0; i<LIN; i++)
    {
        for(j=0; j<COL; j++)
        {
            m[i][j] = rand()%2;
        }
    }
}

void exibir(int m[][COL])
{
    int i, j;

    for(i=0; i<LIN; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
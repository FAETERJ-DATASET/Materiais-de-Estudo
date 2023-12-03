#include <stdio.h>
#define LIN 6
#define COL 5

void exibirMatriz (int m[LIN][COL]);
int trocarColunas (int m[LIN][COL], int c1, int c2);

int main()
{
	int c1, c2;
	
	int matriz[LIN][COL] =
	{
		{1, 3, 5, 7, 9},
		{4, 6, 5, 8, 0},
		{3, 4, 5, 7, 8},
		{5, 9, 1, 2, 3},
		{7, 1, 5, 3, 5},
		{4, 0, 2, 1, 5}
	};
	
	exibirMatriz(matriz);
	
	printf("\n\n\nDigite colunas de 0 a 4.\n\nQual coluna sera trocada? ");
	scanf("%d", &c1);
	
	printf("\nQual outra coluna sera trocada? ");
	scanf("%d", &c2);
	
	if(trocarColunas(matriz, c1, c2))
	{
		exibirMatriz(matriz);
	}
	
	return 0;
}

int trocarColunas (int m[LIN][COL], int c1, int c2)
{
	if(c1 >= COL || c2 >= COL || c1 < 0 || c2 < 0 || c1 == c2)
	{
		return 0;
	}
	else
	{
		int i = 0;
		int vetor[LIN];
		
		// 1. Guardar os elementos de c1 em um vetor auxiliar
		/*
			m[0][c1] = vetor[0]
			...
			m[5][c1] = vetor[5]
			
		*/
		while(i < LIN)
		{
			vetor[i] = m[i][c1];
			i++;
		}
		
		
		
		
		// 2. Copiar inversamente os elementos de c2 para c1
		/*
			m[0][c1] =  m[5][c2]
			m[1][c1] = m[4][c2]
			m[2][c1] = m[3][c2]
			m[3][c1] = m[2][c2]
			m[4][c1] = m[1][c2]
			m[5][c1] = m[0][c2]
		*/
		i = 0;
		while(i < LIN)
		{
			m[i][c1] = m[5-i][c2];
			i++;
		}
		
		
		
		
		// 3. Copiar os elementos do vetor para c2
		/*
			m[0][c2] = vetor[0]
			...
			m[5][c2] = vetor[4]
		*/
		i = 0;
		while(i < LIN)
		{
			m[i][c2] = vetor[i];
			i++;
		}
		
		return 1;
	}
}

void exibirMatriz (int m[LIN][COL])
{
	int i, j;
	
	printf("\nMatriz:\n");
	
	for(i=0; i < LIN; i++)
	{
		for(j=0; j < COL; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

#include <stdio.h>
#define LIN 3
#define COL 3

int main()
{
	int matriz[LIN][COL] =
	{
		/*{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}*/
		
		{1, 2, 2, 3},
		{3, 4, 5, 6},
		{7, 8, 8, 9}
	};
	
	if(verificarCres(matriz))
	{
		printf("\nA matriz eh crescente!");
	}
	
	return 0;
}

int verificarCres(int m[LIN][COL])
{
	int i, j;
	int valor;
	
	/*
		1      // 2 > 1 // 3 > 2
		4 > 3 // 5 > 4 // 6 > 5
		7 > 6 // 8 > 7 // 9 > 8
		
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	*/
	
	//Comparando itens das linhas
	for(i=0; i < LIN; i++)
	{
		for(j=1; j < COL; j++)
		{
			if(m[i][j] < m[i][j-1])
			{
				return 0;
			}
		}
	}
	
	//Comparando o �ltimo item da linha com o primeiro da linha seguinte
	for(i=0; i < LIN-1; i++)
	{
		if(m[i][2] > m[i+1][0])
		{
			return 0;
		}
	}
	return 1;
}

#include <stdio.h>
#define N 5

int soma(int matriz[N][N]);

int main()
{
	int matriz[N][N] = 
	/*matriz que retornará 0:*/ 
	{
		{1, 8, 5, 9, 4},
		{2, 5, 4, 6, 5},
		{4, 1, 2, 3, 6},
		{4, 5, 5, 8, 7},
		{4, 2, 5, 6, 9}	
	};
	
	/* matriz que retornará 1: 
	{
		{6, 3, 1, 2, 6},
		{1, 3, 5, 4, 2},
		{3, 4, 4, 2, 2},
		{5, 9, 1, 9, 3},
		{4, 0, 2, 1, 8}
	};
	*/
	
	if(soma(matriz))
	{
		printf("\nA soma da diagonal principal eh igual a soma dos elementos inferiores e superiores.");
	}
	else
	{
		printf("\nA soma da diagonal principal NAO eh igual a soma dos elementos inferiores e superiores.");
	}
	return 0;
}

int soma(int matriz[N][N])
{
	int s = 0;
	int i, j;
	int somaDiag = 0;
	int somaSuper = 0;
	int somaInf = 0;
	
	while(s < N)
	{
		somaDiag += matriz[s][s];
		s++;
	}
	
	//Soma dos numeros superiores
	for(i=0; i<N-1; i++)
	{
		for(j=i+1; j<N; j++)
		{
			somaSuper += matriz[i][j];
		}
	}
	
	if(somaDiag == somaSuper)
	{
		//Soma dos numeros inferiores
		for(i=N-1; i>-1; i--)
		{
			for(j=i-1; j>-1; j--)
			{
				somaInf += matriz[i][j];
			}
		}
		
		if(somaInf == somaSuper)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turmas: Manhã e Noite
	Professor Leonardo Vianna
	
	Data: 21/10/2023 (aula extra)
	
	Questão 01 (AV1 - Manhã - 2023/1):
	
	Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o nº de linhas e o 
	nº de colunas são iguais a N), onde N é uma constante, desenvolver uma função que retorne 1 se 
	a seguinte regra for atendida por M (caso contrário, o valor 0 deverá ser retornado):
	
		- A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que 
		  estão acima desta diagonal, assim como à soma dos elementos abaixo da diagonal.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int questao01 (int n, int m[n][n]);

//main
void main ()
{
	int m1[5][5] = {{6,3,1,2,6},
	                {1,3,5,4,2},
	                {3,4,4,2,2},
	                {5,9,1,9,3},
	                {4,0,2,1,8}};
	                
	int m2[5][5] = {{1, 8, 5, 9, 4},
                    {2, 5, 4, 6, 5},
                    {4, 1, 2, 3, 6},
                    {4, 5, 5, 8, 7},
                    {4, 2, 5, 6, 9}};
                    
    //chamando a função
	printf ("M1: %d\n", questao01 (5, m1));
	printf ("M2: %d\n", questao01 (5, m2));	                
}

//implementação das funções
int questao01 (int n, int m[n][n])
{
	//declaração de variáveis
	int i, j;
	int somaDiagonal = 0, somaAbaixo = 0, somaAcima = 0;
	
	//variando as linhas
	for (i=0;i<n;i++)
	{
		//variando as colunas
		for (j=0;j<n;j++)
		{
			//verificando se o elemento está na diagonal principal
			if (i == j)
			{
				somaDiagonal += m[i][j];
			}
			else
			{
				//verificando se o elemento está abaixo da diagonal
				if (i > j)
				{
					somaAbaixo += m[i][j];
				}
				else
				{
					//o elemento está acima da diagonal
					somaAcima += m[i][j];
				}
			}
		}
	}	
	
	//verificando se as três somas são iguais
	if ((somaDiagonal == somaAbaixo) && (somaDiagonal == somaAcima))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

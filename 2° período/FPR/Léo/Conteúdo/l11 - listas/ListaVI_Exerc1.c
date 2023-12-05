/*
	FAETERJ-Rio
	Fundamentos de Programação
	Manhã - 2/2023
	Data: 13/09/2023
	
	Lista de Exercícios VI:
	
	Questão 01:
	Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o nº 
	de linhas e o nº de colunas são iguais a N), onde N é uma constante, desenvolver 
	uma função que retorne 1 se a seguinte regra for atendida por M (caso contrário, 
	o valor 0 deverá ser retornado):
	
		- A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que 
		  estão acima desta diagonal, assim como à soma dos elementos abaixo da diagonal.

	Exemplo 1:

	Para a seguinte matriz, a função retornará 1: 

		6	3	1	2	6	
		1	3	5	4	2	
		3	4	4	2	2	
		5	9	1	9	3	
		4	0	2	1	8	

	Exemplo 2:

	Para a seguinte matriz, a função retornará 0: 
	
		1	8	5	9	4	
		2	5	4	6	5	
		4	1	2	3	6	
		4	5	5	8	7	
		4	2	5	6	9
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos
int verificarMatriz (int n, int matriz[n][n]);

//main
void main ()
{
	//declaração de variáveis	
	int mat1[5][5] = {{6,3,1,2,6}, 
	                  {1,3,5,4,2},
	                  {3,4,4,2,2},
					  {5,9,1,9,3},
					  {4,0,2,1,8}};	
					  
	int mat2[5][5] = {{1,8,5,9,4}, 
	                  {2,5,4,6,5},
	                  {4,1,2,3,6},
					  {4,5,5,8,7},
					  {4,2,5,6,9}};	
					  
	//chamando a função para a primeira matriz
	if (verificarMatriz (5, mat1) == 1)
	{
		printf ("As somas dos elementos da matriz 1 sao iguais!\n\n");
	}
	else
	{
		printf ("As somas dos elementos da matriz 1 NAO sao iguais!\n\n");
	}
	
	//chamando a função para a segunda matriz
	if (verificarMatriz (5, mat2) == 1)
	{
		printf ("As somas dos elementos da matriz 2 sao iguais!\n\n");
	}
	else
	{
		printf ("As somas dos elementos da matriz 2 NAO sao iguais!\n\n");
	}
}

//implementação das funções
int verificarMatriz (int n, int matriz[n][n])
{
	//declaração de variáveis
	int i, j, aux, somarDiagonal = 0, acimaDiagonal = 0, abaixoDiagonal = 0;
	
	//somando os elementos da diagonal principal
	for (i=0;i<n;i++)
	{
		somarDiagonal += matriz[i][i];	
	}
	
	//somando os elementos acima da diagonal principal
	for(i=0;i<n-1;i++)
	{
    	aux =i+1;
    	for(j=aux;j<n;j++)
		{
    		acimaDiagonal += matriz[i][j];
		}
	}
	
	//somando os elementos abaixo da diagonal principal
	for(i=1;i<n;i++)
	{
    	aux = i-1;
    	for(j=0;j<=aux;j++)
		{
    		abaixoDiagonal += matriz[i][j];
		}
	}
	
	//verificando se as três somas são iguais
	if ((somarDiagonal == acimaDiagonal) && (acimaDiagonal == abaixoDiagonal))
	{
		return 1;		
	}
	else
	{
		return 0;
	}
}


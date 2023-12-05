/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 04/10/2023
	
	Questão 09:
	Desenvolver uma função recursiva que, dado um vetor V com quant números 
	inteiros, determine se seus elementos estão dispostos de maneira a 
	representar uma progressão aritmética. 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int verificarPA (int vetor[], int quant);
int verificarPA_Rec (int vetor[], int quant, int razao, int posicao);

//main
void main ()
{
	//declaração de variáveis
	int vet1[5] = {3,7,11,15,19};
	int vet2[5] = {2,6,10,13,18};
	
	//chamando a função
	printf ("\nVet1: %d\n", verificarPA (vet1, 5));
	printf ("\nVet2: %d\n", verificarPA (vet2, 5));
}

//implementação das funções
int verificarPA (int vetor[], int quant)
{
	//declaração de variáveis
	int razao;
	
	//calculando a razão da PA sobre os dois primeiros elementos do vetor
	razao = vetor[1]-vetor[0];
	
	//chamando a função recursiva
	return verificarPA_Rec (vetor, quant, razao, 2);
	//iniciando com 2, pois os dois primeiros elementos foram utilizados no cálculo da razão	
}

int verificarPA_Rec (int vetor[], int quant, int razao, int posicao)
{
	if (posicao < quant)
	{
		if (vetor[posicao] - vetor[posicao-1] == razao)  //caso geral
		{
			return verificarPA_Rec (vetor, quant, razao, posicao+1);
		}
		else	//caso base
		{
			return 0;
		}
	}
	else	//caso base
	{
		return 1;
	}
}

/*
	FAETERJ-Rio
	Fundamentos de Programação  -  2022/1
	Turma: Manhã
	Data: 26/05/2022
	
	Lista de Exercícios VIII (recursividade)
	
	Questão 02: Desenvolver uma função recursiva que exiba todos os 
	múltiplos do número N, inferiores ou iguais ao valor V.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void exibirMultiplos (int n, int v);
void exibir (int n, int v, int i);

//main
void main ()
{
	//declaração de variáveis
	int numero, limite;
	
	//leitura dos dados de entrada
	printf ("Entre com um numero: ");
	scanf ("%d", &numero);
	
	printf ("Entre com o limite: ");
	scanf ("%d", &limite);
	
	//chamando a função
	exibirMultiplos (numero, limite);
}

//implementação das funções
void exibirMultiplos (int n, int v)
{
	exibir (n, v, 0);  //começando o 'i' com o valor 0 (primeiro múltiplo de qualquer número)
}

void exibir (int n, int v, int i)
{
	if (i <= v)  //caso geral
	{
		//verificando se 'i' é múltiplo de 'n'
		if (i % n == 0)
		{
			printf ("%d ", i);
		}
		
		//chamando a função recursivamente, passando o próximo valor de 'i'
		exibir (n, v, i+1);
	}
	//caso base implícito: i > v
}

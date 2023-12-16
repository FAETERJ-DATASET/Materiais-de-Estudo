/*
	FAETERJ-Rio
	Fundamentos de Programação  -  2022/1
	Turma: Manhã
	Data: 26/05/2022
	
	Lista de Exercícios VIII (recursividade)
	
	Questão 03: Fazer uma função recursiva que, dado um número 
	inteiro N, exiba o mesmo na base 2 (binária).
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void binario (int n);

//main
void main ()
{
	//declaração de variáveis
	int numero;
	
	//leitura dos dados de entrada
	printf ("Entre com um numero: ");
	scanf ("%d", &numero);
	
	//chamando a função
	binario (numero);
}

//implementação das funções
void binario (int n)
{
	if (n > 0)	//caso geral
	{
		//chamando a função recursivamente
		binario (n/2);
		
		//exibindo, ao final, o resto da divisão de n por 2
		printf ("%d", n%2);
	}
}

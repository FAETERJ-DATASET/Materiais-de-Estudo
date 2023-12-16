/*
	FAETERJ-Rio
	Fundamentos de Programação  -  2022/1
	Turma: Manhã
	Data: 26/05/2022
	
	Lista de Exercícios VIII (recursividade)
	
	Questão 05:
	Dada uma string s, desenvolver uma função recursiva que 
	determine se s é ou não um palíndromo.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int palindromo (char s[]);
int palindromoAux (char s[], int inicio, int fim);

//main
void main ()
{
	//declaração de variáveis
	char str[30];
	
	//leitura dos dados de entrada
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (str);
	
	//chamando a função
	if (palindromo (str) == TRUE)
	{
		printf ("\nA string %s e' um palindromo!", str);
	}
	else
	{
		printf ("\nA string %s nao e' um palindromo!", str);
	}
}

//implementação das funções
int palindromo (char s[])
{
	return palindromoAux (s, 0, strlen(s)-1);
}

int palindromoAux (char s[], int inicio, int fim)
{
	if (inicio < fim)  //caso geral	
	{
		//verificando se os caracteres das posições 'inicio' e 'fim' são diferentes
		if (s[inicio] != s[fim])
		{
			return FALSE;  //não é um palíndromo
		}
		else
		{
			return palindromoAux (s, inicio+1, fim-1);
		}
	}
	else
	{
		//caso base
		return TRUE;
	}
}

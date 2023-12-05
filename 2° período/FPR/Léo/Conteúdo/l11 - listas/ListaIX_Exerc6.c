/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 04/10/2023
	
	Questão 06:
	Dada uma string s, desenvolver uma função recursiva que determine se s é ou 
	não um palíndromo. 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int palindromo (char s[]);
int palindromoRec (char s[], int inicio, int fim);

//main
void main ()
{
	//declaração de variáveis
	char s1[10], s2[10];
	int resp1, resp2;
	
	//inicializando as strings
	strcpy (s1, "TESTE");
	strcpy (s2, "OSSO");
	
	//chamando a função
	resp1 = palindromo (s1);
	resp2 = palindromo (s2);
	
	//verificando os resultados
	if (resp1 == 1)
	{
		printf ("\nA string %s e' um palindromo!\n", s1);
	}
	else
	{
		printf ("\nA string %s NAO e' um palindromo!\n", s1);
	}
	
	if (resp2 == 1)
	{
		printf ("\nA string %s e' um palindromo!\n", s2);
	}
	else
	{
		printf ("\nA string %s NAO e' um palindromo!\n", s2);
	}
}

//implementação das funções
int palindromo (char s[])
{
	return palindromoRec (s, 0, strlen(s)-1);
}

int palindromoRec (char s[], int inicio, int fim)
{
	if (inicio >= fim)	//caso base
	{
		return 1;
	}
	else
	{
		if (s[inicio] != s[fim])	//caso base
		{
			return 0;
		}
		else
		{
			return palindromoRec (s, inicio+1, fim-1);	//caso geral
		}
	}
}

/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 04/10/2023
	
	Questão 08:
	Desenvolver uma função recursiva que, dada uma string, exiba-a invertida. 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void exibirInvertida (char s[]);

//main
void main ()
{
	//declaração de variáveis
	char str[10];
	
	//inicializando a string
	strcpy (str, "ALGORITMO");
	
	//chamando a função
	exibirInvertida (str);
}

//implementação das funções
void exibirInvertida (char s[])
{
	if (*s)	//caso geral
	//ou   if (*s != '\0')
	{
		exibirInvertida (s+1);
		printf ("%c", *s);
	}
}

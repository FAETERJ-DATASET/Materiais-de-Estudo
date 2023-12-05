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
void exibirInvertidaRec (char s[], int fim);

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
	exibirInvertidaRec (s, strlen(s)-1);	
}

void exibirInvertidaRec (char s[], int fim)
{
	if (fim >= 0)	//caso geral
	{
		printf ("%c", s[fim]);
		exibirInvertidaRec (s, fim-1);
	}
}

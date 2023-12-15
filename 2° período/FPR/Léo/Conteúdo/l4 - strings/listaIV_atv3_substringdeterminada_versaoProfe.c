/*
	FPR - Professor Leonardo Vianna
	Turma: Manhã
	Data: 06/04/2022
	
	Lista de Exercícios IV (strings)
	
	Questão 03:
	Desenvolver uma função que, dada uma string s, crie uma substring que 
	inicie na posição p de s e contenha n caracteres.
	
	Observações: 
		i. se p e/ou n forem inválidos, a substring será vazia; 
		ii) se s não possuir n caracteres além de p, a substring a ser 
		criada começará em p e terminará no final de s.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void substring (char s[], int p, int n, char sub[]);

//main
void main ()
{
	//declaração de variáveis
	char string[30], sub[30];

	//inicializando
	strcpy (string, "FUNDAMENTOS DE PROGRAMACAO");
	
	//exemplos de chamadas
	substring (string, 4, 10, sub);
	printf ("Chamada 1 - sub: %s\n\n", sub);

	substring (string, -4, 8, sub);
	printf ("Chamada 2 - sub: %s\n\n", sub);

	substring (string, 8, 40, sub);
	printf ("Chamada 3 - sub: %s\n\n", sub);

	substring (string, 20, 10, sub);
	printf ("Chamada 4 - sub: %s\n\n", sub);
}

//implementação das funções
void substring (char s[], int p, int n, char sub[])
{
	//declaração de variáveis
	int i, j, tamanho = strlen(s);
	
	//testando se 'p' ou 'n' são inválidos
	if ((p<0) || (p>=tamanho) || (n<=0) || (n>tamanho))
	{
		//retornar substring vazia
		strcpy (sub, "");   //ou:   sub[0] = '\0';
	}
	else
	{
		for (i=p,j=0;(j<n)&&(i<tamanho);i++,j++)
		{
			sub[j] = s[i];
		}
	
		sub[j] = '\0';
	}
}

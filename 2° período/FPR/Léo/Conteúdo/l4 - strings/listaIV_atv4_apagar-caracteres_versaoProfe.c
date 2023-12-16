/*
	FPR - Professor Leonardo Vianna
	Turma: Manhã
	Data: 06/04/2022
	
	Lista de Exercícios IV (strings)
	
	Questão 04:
	Implementar uma função que remova todas as ocorrências de determinado 
	caracter em uma string.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void removerCaracteres (char s[], char ch);

//main
void main ()
{
	//declaração de variáveis
	char string[30];

	//inicializando
	strcpy (string, "FUNDAMENTOS DE PROGRAMACAO");
	
	//exemplo de chamada
	removerCaracteres (string, 'O');
	printf ("String apos a remocao da letra O: %s", string);
}

//implementação das funções
void removerCaracteres (char s[], char ch)
{
	//declaração de variáveis
	char aux[50];
	int i, j = 0;
	
	//copiando para 'aux' todos os caracteres diferentes de 'ch'
	for (i=0;i<strlen(s);i++)
	{
		//verificando se o caracter deve ser copiado para 'aux'
		if (s[i] != ch)
		{
			aux[j] = s[i];
			j++;
		}
	}
	
	//finalizando a string 'aux' com '\0'
	aux[j] = '\0';
	
	//copiando 'aux' para 's'
	strcpy (s, aux);
}

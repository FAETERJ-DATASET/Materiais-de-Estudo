/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022

	Lista de Exercícios VII (Arquivos)

	Questão 01:
	Desenvolver uma função que, dado um arquivo texto, verifique o número de caracteres
	no mesmo.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int contarCaracteres (char nomeArq[]);

//main
void main ()
{
	//declaração de arquivos
	char nomeArquivo[30];
	int quantidade;

	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);

	//chamando a função
	quantidade = contarCaracteres (nomeArquivo);

	//exibindo o resultado
	switch (quantidade)
	{
		case -1: printf ("\nErro na abertura do arquivo.");
		         break;

		case 0:  printf ("\nArquivo vazio.");
		         break;

		default: printf ("\nHa %d caracteres no arquivo %s.", quantidade, nomeArquivo);
	}
}

//implementação das funções
int contarCaracteres (char nomeArq[])
{
	//declaração de variáveis
	FILE *arq;
	int cont = 0;
	char caracter;

	//abrindo o arquivo
	arq = fopen (nomeArq, "r");

	//testando se houve sucesso na abertura ou não
	if (arq == NULL)
	{
		return -1;	//sinalizando que não foi possível abrir o arquivo
	}
	else
	{
		//lendo os caracteres do arquivo
		while (fscanf (arq, "%c", &caracter) != EOF)
		{
			cont++;
		}

		//fechando o arquivo
		fclose (arq);

		//retornando a quantidade de caracteres
		return cont;
	}
}

/*
	FAETERJ-Rio
	FPR - Manhã - 2022/1
	Data: 27/04/2022

	Arquivos

	Exemplo 4: considerando um arquivo contendo números inteiros, desenvolver uma função que leia o
	conteúdo deste arquivo e o exiba na tela.
*/

//importação de bibliotecas
#include<stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int leituraArquivo(char nomeArq[]);

//main
void main()
{
	//declaração de variáveis
	char nomeArq[30];

	//lendo o nome do arquivo cujos dados serão lidos
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArq);

	//chamando a função
	if (leituraArquivo (nomeArq) == TRUE)
	{
		printf("\nArquivo lido com sucesso!");
	}
	else
	{
		printf("\nErro na abertura do arquivo!");
	}
}

//implementação das funções
int leituraArquivo (char nomeArq[])
/*ATENÇÃO: as funções que manipulam arquivo receberão por parâmetro a string que representa o nome do arquivo; e
não uma variável FILE*
*/
{
	//declaração de variáveis
	FILE *arq;
	int numero;

	//tentativa de abrir o arquivo para leitura
	arq = fopen (nomeArq, "r");

	//verificando se houve erro na abertura do arquivo
	if (arq == NULL)
	{
		return FALSE;
	}
	else
	{
		//lendo os números do arquivo até se chegar ao seu final
		while (fscanf (arq, "%d", &numero) != EOF) //EOF = end of file
		{
			//exibindo na tela os valores lidos
			printf ("%d\n", numero);
		}

		//fechando o arquivo
		fclose(arq);

		return TRUE;
	}
}

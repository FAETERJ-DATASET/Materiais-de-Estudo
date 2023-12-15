/*
	FAETERJ-Rio
	FPR - Manhã - 2022/1
	Data: 27/04/2022

	Arquivos

	Exemplo 1: desenvolver um programa que escreva em um arquivo os números de 1 a N.
*/

//importação de bibliotecas
#include<stdio.h>

//main
void main()
{
	//declaração de variáveis
	FILE *arq;				//Passo 1: declarar uma variável do tipo FILE*
	char nomeArq[30];		//string contendo o nome do arquivo
	int i, n;

	//lendo o valor de N
	printf ("Entre com o valor de N: ");
	scanf ("%d", &n);

	//lendo o nome do arquivo a ser gerado
	printf ("Entre com o nome do arquivo a ser gerado: ");
	fflush (stdin);
	gets (nomeArq);

	//Passo 2: abrindo o arquivo para escrita
	arq = fopen (nomeArq, "w");					//Tipos de abertura:
												//		w - write (escrita): se existir conteúdo no arquivo, o mesmo será apagado
												//		r - read (leitura): se não existir arquivo, a função retornará NULL
												//		a - append: acrescenta informações ao final do arquivo, preservando o conteúdo anterior

	//testando se houve erro na abertura do arquivo
	if (arq != NULL)    //ou apenas:   if (arq)
	{
		//variando os números de 1 a N
		for (i=1; i<=n; i++)
		{
			//escrevendo cada 'i' no arquivo
			fprintf (arq, "%d\n", i);			//Passo 3: manipulando o arquivo
		}

		printf("Arquivo gerado com sucesso");

		//Passo 4: fechando o arquivo
		fclose(arq);
	}
	else
	{
		printf("Erro na abertura do arquivo");
	}
}

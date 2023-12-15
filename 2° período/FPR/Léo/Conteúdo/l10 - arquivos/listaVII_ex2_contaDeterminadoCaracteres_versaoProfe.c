/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022

	Lista de Exercícios VII (Arquivos)

	Questão 02:
	Desenvolver uma função que, dado um arquivo texto, verifique o número de vezes que
	um determinado caracter aparece no arquivo.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int ocorrenciasCaracter (char nomeArq[], char ch);

//main
void main ()
{
	//declaração de arquivos
	char nomeArquivo[30];
	int quantidade;
	char caracter;

	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);

	//lendo o caracter a ser buscado
	printf ("Entre com o caracter a ser buscado: ");
	fflush (stdin);
	scanf ("%c", &caracter);

	//chamando a função
	quantidade = ocorrenciasCaracter (nomeArquivo, caracter);

	//exibindo o resultado
	if (quantidade == -1)
	{
		printf ("\nErro na abertura do arquivo.");
	}
	else
	{
		printf ("\nForam encontradas %d ocorrencias do caracter %c no arquivo %s.", quantidade, caracter, nomeArquivo);
	}
}

//implementação das funções
int ocorrenciasCaracter (char nomeArq[], char ch)
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
			//verificando se o caracter lido é aquele sendo buscado
			if (caracter == ch)
			{
				cont++;
			}
		}

		//fechando o arquivo
		fclose (arq);

		//retornando a quantidade de caracteres
		return cont;
	}
}

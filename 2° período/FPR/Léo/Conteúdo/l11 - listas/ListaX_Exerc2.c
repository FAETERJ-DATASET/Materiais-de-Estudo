/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 29/11/2023
	
	Lista de Exercícios X (Arquivos)
	
	Questão 02:
	Desenvolver uma função que, dado um arquivo texto, verifique o número de 
	vezes que um determinado caracter aparece no arquivo.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//protótipos das funções
int numOcorrencias (char nomeArq[], char ch);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	char caracter;
	int quant;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//obtendo o caracter a ser buscado
	printf ("Entre com o caracter a ser buscado no arequivo: ");
	fflush (stdin);
	scanf ("%c", &caracter);
	
	//chamando a função
	quant = numOcorrencias (nomeArquivo, caracter);
	
	//exibindo o resultado
	if (quant != -1)
	{
		printf ("\n\nO caracter %c foi encontrado %d vezes no arquivo %s.", caracter, quant, nomeArquivo);
	}
	else
	{
		printf ("\n\nErro na abertura do arquivo %s.", nomeArquivo);
	}
}

//implementação das funções
int numOcorrencias (char nomeArq[], char ch)
{
	//declaração de variáveis
	FILE* arquivo;
	int cont = 0;
	char caracter;
	
	//tentando abriro arquivo
	arquivo = fopen (nomeArq, "r");
	
	//verificando se houve erro
	if (!arquivo)    //if (arq == NULL)
	{
		return -1;
	}
	else
	{
		while (fscanf (arquivo, "%c", &caracter) != EOF)  //EOF = End Of File
		{
			//verificando se o caracter lido é aquele sendo buscado
			if (caracter == ch)
			{
				cont++;
			}
		}
		
		//fechar o arquivo
		fclose (arquivo);
		
		return cont;
	}
}

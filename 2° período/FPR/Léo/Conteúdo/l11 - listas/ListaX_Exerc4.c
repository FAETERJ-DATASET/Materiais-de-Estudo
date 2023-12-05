/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 29/11/2023
	
	Lista de Exercícios X (Arquivos)
	
	Questão 04:
	Desenvolver uma função que, dado um arquivo texto contendo números, 
	determine se estes encontram-se ordenados crescentemente.
*/

//importação de bibliotecas
#include <stdio.h>
#include <limits.h>

//protótipos das funções
int verificarOrdenacao (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	int resposta;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a função
	resposta = verificarOrdenacao (nomeArquivo);
	
	//exibindo o resultado
	switch (resposta)
	{
		case 0: printf ("\n\nOs elementos do arquivo %s nao estao ordenados.", nomeArquivo);
		        break;
		        
		case 1: printf ("\n\nOs elementos do arquivo %s estao ordenados.", nomeArquivo);
		        break;
	
		case -1:printf ("\n\nErro na abertura do arquivo %s.", nomeArquivo);       
	}
}

//implementação das funções
int verificarOrdenacao (char nomeArq[])
{
	//declaração de variáveis
	FILE* arquivo;
	int atual, anterior = INT_MIN;
	
	//tentando abriro arquivo
	arquivo = fopen (nomeArq, "r");
	
	//verificando se houve erro
	if (!arquivo)    //if (arq == NULL)
	{
		return -1;
	}
	else
	{
		while (fscanf (arquivo, "%d", &atual) != EOF)  //EOF = End Of File
		{
			//verificando se o número atual é menor do que o anterior
			if (atual < anterior)
			{
				return 0;
			}
			
			//atualizando 'anterior'
			anterior = atual;
		}
		
		//fechar o arquivo
		fclose (arquivo);	
		
		return 1;	
	}
}

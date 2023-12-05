/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 29/11/2023
	
	Lista de Exercícios X (Arquivos)
	
	Questão 03:
	Desenvolver uma função que, dado um arquivo texto, verifique o número 
	de letras existentes no mesmo (entendendo que no arquivo podem existir 
	letras, algarismos e símbolos).
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//protótipos das funções
int numLetras (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	int quant;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a função
	quant = numLetras (nomeArquivo);
	
	//exibindo o resultado
	if (quant != -1)
	{
		printf ("\n\nForam encontradas %d letras no arquivo %s.", quant, nomeArquivo);
	}
	else
	{
		printf ("\n\nErro na abertura do arquivo %s.", nomeArquivo);
	}
}

//implementação das funções
int numLetras (char nomeArq[])
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
			//colocando o caracter lido para maiúscula
			caracter = toupper (caracter);
			
			//verificando se o caracter lido é uma letra
			if ((caracter >= 'A') && (caracter <= 'Z'))
			{
				cont++;
			}
		}
		
		//fechar o arquivo
		fclose (arquivo);
		
		return cont;
	}
}

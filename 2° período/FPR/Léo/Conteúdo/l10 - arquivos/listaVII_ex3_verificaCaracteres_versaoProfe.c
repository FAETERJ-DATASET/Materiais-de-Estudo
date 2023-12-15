/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 03:
	Desenvolver uma função que, dado um arquivo texto, verifique o número de letras 
	existentes no mesmo (entendendo que no arquivo podem existir letras, algarismos 
	e símbolos).
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int quantidadeLetras (char nomeArq[]);

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
	quantidade = quantidadeLetras (nomeArquivo);
	
	//exibindo o resultado
	if (quantidade == -1)
	{
		printf ("\nErro na abertura do arquivo.");
	}
	else
	{
		printf ("\nForam encontradas %d letras no arquivo %s.", quantidade, nomeArquivo);
	}
}

//implementação das funções
int quantidadeLetras (char nomeArq[])
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
			//jogando o caracter lido para maiúsculo
			caracter = toupper (caracter);
			
			//verificando se o caracter lido é uma letra
			if ((caracter >= 'A') && (caracter <= 'Z'))
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

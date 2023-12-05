/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 11/10/2023
	
	Arquivos
	
	Exemplo 4: lendo valores de um arquivo (porém, utilizando função)
	 
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int lerArquivo (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	gets (nomeArquivo);
	
	//chamando a função
	if (lerArquivo (nomeArquivo) == 0)
	{
		printf ("\n\nErro na abertura do arquivo!");
	}
	else
	{			
		printf ("\n\nLeitura realizada com sucesso!");
	}
}

//implementação das funções
int lerArquivo (char nomeArq[])
{
	//declaração de variáveis
	FILE* arquivo;	//Passo 1: declarar uma variável FILE* representando o arquivo
	char caracter;
		
	//Passo 2: abrir o arquivo, associando-o com um caminho
	arquivo = fopen (nomeArq, "r");   //w - write    r - read    a - append
	
	//verificando se houve erro na abertura do arquivo
	if (arquivo == NULL)
	{
		return 0;
	}
	else
	{			
		while (fscanf (arquivo, "%c", &caracter) != EOF)  //Passo 3: manipular o arquivo
		{
			printf ("%c", caracter);   //EOF - end of file
		}
		
		fclose (arquivo); //fechando o arquivo
		
		return 1;
	}	
}

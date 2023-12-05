/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 11/10/2023
	
	Arquivos
	
	Exemplo 6: copiar o conteúdo de um arquivo para outro.	 
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeOrigem[20], nomeDestino[20];
		
	//obtendo o nome do arquivo de origem
	printf ("Entre com o nome do arquivo a ser copiado: ");
	gets (nomeOrigem);
	
	//obtendo o nome do arquivo de destino
	printf ("Entre com o nome do novo arquivo: ");
	gets (nomeDestino);
	
	//chamando a função
	if (copiarArquivo (nomeOrigem, nomeDestino) == 1)
	{
		printf ("\n\nCopia realizada com sucesso!");
	}
	else
	{
		printf ("\n\nErro na abertura dos arquivos! Copia nao realizada.");
	}
}

//implementação das funções
int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[])
{
	//declaração de variáveis
	FILE *arqO, *arqD;
	char caracter;
	
	//abrindo os arquivos
	arqO = fopen (nomeArqOrigem, "r");
	arqD = fopen (nomeArqDestino, "w");
	
	//verificando se houve erro na abertura
	if ((!arqO) || (!arqD))
	{
		fclose (arqO);
		fclose (arqD);
		
		return 0;
	}
	else
	{
		//lendo cada caracter do arquivo de origem ...
		while (fscanf (arqO, "%c", &caracter) != EOF)
		{
			fprintf (arqD, "%c", caracter);
		}
		
		fclose (arqO);
		fclose (arqD);
		
		return 1;
	}
}

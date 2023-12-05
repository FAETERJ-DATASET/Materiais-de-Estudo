/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 11/10/2023
	
	Arquivos
	
	Exemplo 7: dados um arquivo texto (contendo números) e um valor inteiro
	'n', remover do arquivo todas as ocorrência de 'n' e retornar a quantidade
	de remoções.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int remover (char nomeArquivo[], int numero);
int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[20];
	int n, quant;
	
	//lendo os dados de entrada
	printf ("Nome do arquivo: ");
	fflush (stdin);
	gets (nomeArq);
	
	printf ("Valor a ser removido: ");
	scanf ("%d", &n);
	
	//chamando a função
	quant = remover (nomeArq, n);
	
	//verificando o retorno da função
	if (quant < 0)
	{
		printf ("\n\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\n\nForam realizadas %d remocoes do numero %d no arquivo %s.", quant, n, nomeArq);
	}
}

//implementação das funções
int remover (char nomeArquivo[], int numero)
{
	//declaração de variáveis
	FILE *arq, *tmp;
	int valor, cont = 0;
	
	//abrindo os arquivos
	arq = fopen (nomeArquivo, "r");
	tmp = fopen ("temp.txt", "w");
	
	//verificando se houve erro na abertura dos arquivos
	if ((!arq) || (!tmp))
	{
		fclose (arq);
		fclose (tmp);
		
		return -1;
	}
	else
	{
		//lendo todos os valores do arquivo de origem
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			//verificando se o valor lido deve ser copiado para o arquivo temporário
			if (valor != numero)
			{
				fprintf (tmp, "%d\n", valor);
			}
			else
			{
				cont++;
			}
		}
		
		//fechando os arquivos
		fclose (arq);
		fclose (tmp);
		
		//copiando os dados do arquivo temporário para o arquivo original
		copiarArquivo ("temp.txt", nomeArquivo);
		
		//apagando o arquivo temporário no disco
		remove ("temp.txt");
		
		//retornando a quantidade de remoções realizadas
		return cont;
	}
}

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

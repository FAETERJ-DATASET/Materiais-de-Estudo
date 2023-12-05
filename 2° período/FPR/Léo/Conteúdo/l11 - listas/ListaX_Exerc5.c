/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 30/11/2023
	
	Lista de Exercícios X (Arquivos)
	
	Questão 05:
	Faça uma função que, dado um arquivo A contendo números reais, um por 
	linha, crie um novo arquivo B contendo os mesmos elementos de A, porém 
	ordenados decrescentemente e sem repetição.
*/

//importação de bibliotecas
#include <stdio.h>
#include <limits.h>

//protótipos das funções
int gerarArquivoDecrescente (char nomeArqOriginal[], char nomeArqNovo[]);

int buscaMaior (char nomeArquivo[], int limite, int *maior);

//main
void main ()
{
	//declaração de variáveis
	int retorno;
	char original[20], novo[20];
	
	//obtendo os nomes dos arquivos
	printf ("Entre com o nome do arquivo original: ");
	fflush (stdin);
	gets (original);
	
	printf ("Entre com o nome do novo arquivo: ");
	fflush (stdin);
	gets (novo);
	
	//chamando a função
	retorno = gerarArquivoDecrescente (original, novo);
	
	//exibindo o resultado
	if (retorno == 1)
	{
		printf ("\n\nO arquivo %s foi gerado com sucesso!\n", novo);
	}
	else
	{
		printf ("\n\nO arquivo %s nao foi gerado!\n", novo);
	}
}

//implementação das funções
int gerarArquivoDecrescente (char nomeArqOriginal[], char nomeArqNovo[])
{
	//declaração de variáveis
	FILE *arqNovo;
	int retorno, limite, maior;
	
	//tentando abrir o novo arquivo para escrita
	arqNovo = fopen (nomeArqNovo, "w");
	
	//verificando se houve erro na abertura do arquivo
	if (!arqNovo)
	{
		return 0;
	}
	else
	{
		//inicializando 'limite' com um valor alto
		limite = INT_MAX;
		
		//enquanto existir valor a ser inserido no arquivo novo...
		while (retorno = buscaMaior (nomeArqOriginal, limite, &maior) == 1)
		{
			//escreva o maior valor encontrado no arquivo novo
			fprintf (arqNovo, "%d\n", maior);
			
			//atualizando o limite
			limite = maior;
		}

		//fechando o arquivo
		fclose (arqNovo);
	
		//testando o retorno da última chamada
		if (retorno == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}		
	}
}

int buscaMaior (char nomeArquivo[], int limite, int *maior)
{
	//declaração de variáveis
	FILE* arquivo;
	int numero;
	
	//tentando abrir o arquivo
	arquivo = fopen (nomeArquivo, "r");
	
	//verificando se houve erro na abertura do arquivo
	if (!arquivo)
	{
		return -1;
	}
	else
	{
		//inicializando 'maior' com um valor baixo
		*maior = INT_MIN;
		
		while (fscanf (arquivo, "%d", &numero) != EOF)
		{
			//verificando se o número lido é inferior a 'limite'
			if (numero < limite)
			{
				//verificando se 'numero' é o maior até o momento
				if (numero > *maior)
				{
					*maior = numero;
				}
			}
			
		}
		
		//verificando se foi encontrado um 'maior valor'
		if (*maior != INT_MIN)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
		//fechando o arquivo
		fclose (arquivo);
	}
}

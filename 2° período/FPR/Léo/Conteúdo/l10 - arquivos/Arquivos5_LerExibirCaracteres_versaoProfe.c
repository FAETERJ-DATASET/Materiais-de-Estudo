/*
	FAETERJ-Rio
	FPR - Manhã - 2022/1
	Data: 28/04/2022

	Arquivos

	Exemplo 5: ler o conteúdo de um arquivo e exibi-lo na tela, independente do tipo de informação que armazena.

	(neste caso, consideraremos que o arquivo é constituído por diversos caracteres)
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int leituraArquivo (char nomeArq[]);

//main
void main()
{
	//declaração de variáveis
	char nomeArquivo[30];

	//lendo o nome do arquivo cujos dados serão lidos
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);

	//chamando a função
	if (leituraArquivo (nomeArquivo) == TRUE)
	{
		printf("Arquivo lido com sucesso!");
	}
	else
	{
		printf("Erro na abertura do arquivo!");
	}
}

//implementação das funções
int leituraArquivo (char nomeArq[])
{
	//declaração de variáveis
	FILE *arq;
	char caracter;

	//tentativa de abrir o arquivo para leitura
	arq = fopen (nomeArq, "r");

	//verificando se houve erro na abertura do arquivo
	if (arq == NULL)
	{
		return FALSE;
	}
	else
	{
		//lendo os caracteres do arquivo até se chegar ao seu final
		while (fscanf (arq, "%c", &caracter) != EOF)
		{
			//exibindo na tela os caracteres lidos
			printf("%c", caracter);
		}

		//fechando o arquivo
		fclose(arq);

		return TRUE;
	}
}

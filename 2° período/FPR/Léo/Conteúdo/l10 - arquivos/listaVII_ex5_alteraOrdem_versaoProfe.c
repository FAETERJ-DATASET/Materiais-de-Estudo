/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022

	Lista de Exercícios VII (Arquivos)

	Questão 05:
	Faça uma função que, dado um arquivo A contendo números reais, um por linha,
	crie um novo arquivo B contendo os mesmos elementos de A, porém ordenados
	decrescentemente e sem repetição.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int gerarArquivoOrdenado (char nomeArqA[], char nomeArqB[]);

//main
void main ()
{
	//declaração de arquivos
	char nomeArquivoA[30], nomeArquivoB[30];
	int retorno;

	//lendo o nome do arquivo original
	printf ("Entre com o nome do primeiro arquivo: ");
	fflush (stdin);
	gets (nomeArquivoA);

	//lendo o nome do arquivo a ser criado
	printf ("Entre com o nome do segundo arquivo: ");
	fflush (stdin);
	gets (nomeArquivoB);

	//chamando a função
	retorno = gerarArquivoOrdenado (nomeArquivoA, nomeArquivoB);

	//exibindo o resultado
	if (retorno == TRUE)
	{
		printf ("\nArquivo gerado com sucesso.");
	}
	else
	{
		printf ("\nErro na bertura dos arquivos.");
	}
}

//implementação das funções
int gerarArquivoOrdenado (char nomeArqA[], char nomeArqB[])
{
	//declaração de variáveis
	FILE *arqA, *arqB;
	float maior, numero, ultimo = 99999;
	int sair;

	//abrindo os arquivos
	arqA = fopen (nomeArqA, "r");
	arqB = fopen (nomeArqB, "w");

	//testando se houve sucesso ou não na abertura do arquivo
	if ((arqA == NULL) || (arqB == NULL))
	{
		//garantindo que, caso algum arquivo tenha sido aberto, o mesmo será fechado antes da função terminar
		fclose (arqA);
		fclose (arqB);

		return FALSE;
	}
	else
	{
		do
		{
			//reposicionando o ponteiro de leitura do arquivo A para o seu início
			rewind (arqA);

			//inicializando a variável 'maior'
			maior = -99999;

			//variável de controle do do..while (repetição externa)
			sair = TRUE;

			//lendo os numeros do arquivo A
			while (fscanf (arqA, "%f", &numero) != EOF)
			{
				//para cada número lido, verificar: 1. se é menor do que o último inserido
				//no arquivo B; ii. se é o maior até então.
				if ((numero < ultimo) && (numero > maior))
				{
					//atualizando o maior
					maior = numero;

					//uma vez que um novo valor foi encontrado, registra-se que não é ainda o momento de terminar a busca
					sair = FALSE;
				}
			}

			//verificando se foi encontrado elemento para ser inserido no arquivo B
			if (sair == FALSE)
			{
				//escrevendo o valor no arquivo B
				fprintf (arqB, "%.1f\n", maior);

				//aramzenando o último valor inserido no arquivo B
				ultimo = maior;
			}
		}
		while (sair == FALSE);

		//fechando os arquivos
		fclose (arqA);
		fclose (arqB);

		return TRUE;
	}
}

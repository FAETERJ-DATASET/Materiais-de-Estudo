/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 04:
	Desenvolver uma função que, dado um arquivo texto contendo números, determine se 
	estes encontram-se ordenados crescentemente.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int verificarOrdenacao (char nomeArq[]);

//main
void main ()
{
	//declaração de arquivos
	char nomeArquivo[30];
	int retorno;
		
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a função
	retorno = verificarOrdenacao (nomeArquivo);
	
	//exibindo o resultado
	switch (retorno)
	{
		case -1: printf ("\nErro na abertura do arquivo.");
		         break;
		         
		case 0:  printf ("\nOs elementos do arquivo %s nao estao ordenados crescentemente.", nomeArquivo);
		         break;
		
		case 1:	 printf ("\nOs elementos do arquivo %s estao ordenados crescentemente.", nomeArquivo);
	}
}

//implementação das funções
int verificarOrdenacao (char nomeArq[])
{
	//declaração de variáveis
	FILE *arq;
	float menor, maior;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//testando se houve sucesso na abertura ou não
	if (arq == NULL)
	{
		return -1;	//sinalizando que não foi possível abrir o arquivo
	}
	else
	{
		//lendo o primeiro valor do arquivo
		fscanf (arq, "%f", &menor);
		
		//lendo os demais elementos do arquivo 
		while (fscanf (arq, "%f", &maior) != EOF)
		{			
			//verificando se os dois números estão desordenados
			if (menor > maior)
			{
				//fechando o arquivo
				fclose (arq);
				
				//retornando 0 para representar que o arquivo não está ordenado crescentemente
				return 0;
			}
			else
			{
				//atualizando o menor para que a próxima comparação seja possível
				menor = maior;				
			}
		}			
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando 1 para representar que o arquivo está ordenado crescentemente
		return 1;
	}	
}

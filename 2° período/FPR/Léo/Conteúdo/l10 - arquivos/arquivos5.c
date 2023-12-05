/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 11/10/2023
	
	Arquivos
	
	Exemplo 5: dados um arquivo texto (contendo números, um por linha) e 
	um valor inteiro 'n', determinar se 'n' existe ou não no arquivo.	 
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int buscar (char nomeArq[], int numero);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	int numero, retorno;
	
	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	gets (nomeArquivo);
	
	//obtendo o número a ser buscado no arquivo
	printf ("Entre com o numero a ser buscado: ");
	scanf ("%d", &numero);
	
	//chamando a função
	retorno = buscar (nomeArquivo, numero);
	
	//testando o retorno da função
	switch (retorno)
	{
		case -1: printf ("\n\nErro na abertura do arquivo %s!", nomeArquivo);
		         break;
		case  0: printf ("\n\nO valor %d NAO foi encontrado no arquivo %s.", numero, nomeArquivo);
		         break;
		case  1: printf ("\n\nO valor %d foi encontrado no arquivo %s.", numero, nomeArquivo);
	}	
}

//implementação das funções

/*
   Verifica se 'numero' existe no arquivo de nome 'nomeArq'.
   Retornará:
   		0	Se o número não existir no arquivo
   		1	Se o número existir no arquivo
   		-1	Se ocorrer erro na abertura do arquivo
*/
int buscar (char nomeArq[], int numero)
{
	//declaração de variáveis
	FILE* arquivo;
	int valor;
	
	//abrindo o arquivo
	arquivo = fopen (nomeArq, "r");
	
	//verificando se houve erro na abertura do arquivo
	//if (arquivo == NULL)   OU
	if (!arquivo)
	{
		return -1;
	}
	else
	{
		//lendo todos os valores que estão no arquivo
		while (fscanf (arquivo, "%d", &valor) != EOF)  //EOF - end of file
		{
			//verificando se o valor lido é o número sendo buscado
			if (valor == numero)
			{
				//fechando o arquivo
				fclose (arquivo);
				
				return 1;
			}			
		}
		
		//fechando o arquivo
		fclose (arquivo);
		
		//se chegou até aqui, conclui-se que o número não existe no arquivo
		return 0;
	}
}

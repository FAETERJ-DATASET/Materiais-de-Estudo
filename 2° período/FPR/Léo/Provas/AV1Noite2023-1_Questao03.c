/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turmas: Manhã e Noite
	Professor Leonardo Vianna
	
	Data: 21/10/2023 (aula extra)
	
	Questão 03 (AV1 - Noite - 2023/1):
	
	Considere a existência de um vetor de structs com quant posições, onde cada uma destas 
	armazena os seguintes dados sobre um grupo de pessoas: nome (string), gênero (char) e 
	idade (int). Pede-se uma função que determine se os elementos deste vetor estão ordenados 
	e retorne 1, caso estejam ordenados, e 0, caso contrário. 
	
	Observação: o vetor será considerado ordenado se estiver organizado crescentemente em função 
	da idade. Porém, no caso de pessoas com a mesma idade, estas devem estar ordenadas 
	crescentemente pelo nome. 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de tipos
typedef struct {
	char	nome[20];
	char	genero;
	int  	idade; 	
} TPessoa;

//protótipos das funções
int verificaOrdenacao (TPessoa vetor[], int quant);

void exibirPessoas (TPessoa vetor[], int quant);

//main
void main ()
{
	//declaração de variáveis
	TPessoa vetor[7];
	int quantidade = 7;
	
	//inicializando o vetor de structs
	strcpy (vetor[0].nome, "CARLOS");
	vetor[0].genero = 'M';
	vetor[0].idade = 20;
	
	strcpy (vetor[1].nome, "MARIA");
	vetor[1].genero = 'F';
	vetor[1].idade = 23;

	strcpy (vetor[2].nome, "ADRIANA");
	vetor[2].genero = 'F';
	vetor[2].idade = 25;

	strcpy (vetor[3].nome, "JOAO");
	vetor[3].genero = 'M';
	vetor[3].idade = 25;

	strcpy (vetor[4].nome, "PEDRO");
	vetor[4].genero = 'M';
	vetor[4].idade = 25;
	
	strcpy (vetor[5].nome, "CLARA");
	vetor[5].genero = 'F';
	vetor[5].idade = 28;
	
	strcpy (vetor[6].nome, "PATRICIA");
	vetor[6].genero = 'F';
	vetor[6].idade = 28;
	

	//exibindo o vetor antes da chamada à função
	exibirPessoas (vetor, quantidade);

	//lendo o genero
		
	//chamando a função
	printf ("\n\nOrdenado? %d\n", verificaOrdenacao (vetor, quantidade));
}
	
//implementação das funções
int verificaOrdenacao (TPessoa vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor (até a penúltima posição)
	for (i=0;i<quant-1;i++)
	{
		//verificando se a pessoa da posição 'i' é mais velha do que a da posição 'i+1'
		if (vetor[i].idade > vetor[i+1].idade)
		{
			return 0;
		}
		else
		{
			//verificando se as pessoas das posições 'i' e 'i+1' possuem a mesma idade
			if (vetor[i].idade == vetor[i+1].idade)
			{
				//verificando se, alfabeticamente, o nome da posição 'i' "vem depois" do 
				//da posição 'i+1'
				if (strcmp (vetor[i].nome, vetor[i+1].nome) > 0)
				{
					return 0;
				}
			}
		}
	}
	
	return 1;
}

void exibirPessoas (TPessoa vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//pulando linha
	printf ("\n\n");
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		printf ("Nome: %s\n", vetor[i].nome);
		printf ("Genero: %c\n", vetor[i].genero);
		printf ("Idade: %d\n\n", vetor[i].idade);
	}
}

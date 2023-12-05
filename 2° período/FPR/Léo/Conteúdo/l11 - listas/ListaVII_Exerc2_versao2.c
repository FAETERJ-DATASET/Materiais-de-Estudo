/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2
	Professor Leonardo Vianna
	Data: 23/09/2023
	
	Lista de Exercícios VII (Structs)
	
	Questão 02: 
	Suponha a existência de um vetor de tamanho TAM, cada posição 
	armazenando o nome da pessoa e a sua data de aniversário 
	(representada por um struct do tipo TData, contendo os campos dia 
	e mes). Pede-se o desenvolvimento das seguintes funções:
 	
	 	- Determinar a quantidade de pessoas que fazem aniversário no 
		  mês M;
 		- Exibir os nomes de todas pessoas que fazem aniversário entre 
		  as datas d1 e d2, ambas do tipo TData.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TAM 5

//definição de tipos
typedef struct {
	int dia;
	int mes;
} TData;

typedef struct {
	char nome[30];
	TData dataAniversario;
} TPessoa;

//protótipos das funções
int quantidadeAniversariantes (TPessoa pessoas[], int quantidade, int m);
void exibirAniversariantes (TPessoa pessoas[], int quantidade, TData d1, TData d2);
int verificarAniversariante (TData data, TData dataInferior, TData dataSuperior);
//main
void main ()
{
	//declaração de variáveis
	TPessoa pessoas[TAM];
}

//implementação das funções
int quantidadeAniversariantes (TPessoa pessoas[], int quantidade, int m)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo todas as posições do vetor
	for (i=0;i<quantidade;i++)
	{
		//verificando se a pessoa da posição 'i' faz aniversário no mês 'm'
		if (pessoas[i].dataAniversario.mes == m)
		{
			cont++;
		}
	}
	
	//retornando a quantidade
	return cont;
}

/*Exibir os nomes de todas pessoas que fazem aniversário entre 
  as datas d1 e d2, ambas do tipo TData.*/		  
void exibirAniversariantes (TPessoa pessoas[], int quantidade, TData d1, TData d2)
{
	//declaração de variáveis
	int i;
	
	//percorrendo todas as posições do vetor
	for (i=0;i<quantidade;i++)
	{
		//verificando se a pessoa da posição 'i' faz aniversário
		//entre as datas 'd1' e 'd2'
		if (verificarAniversariante (pessoas[i].dataAniversario, d1, d2) == 1)
		{
			printf ("%s\n", pessoas[i].nome);
		}
	}
}

int verificarAniversariante (TData data, TData dataInferior, TData dataSuperior)
{	
	//verificando se 'data' está entre os meses compreendidos pelo intervalo 
	//passado, porém não no mês da 'dataInferior' e nem da 'dataSuperior'
	if ((data.mes > dataInferior.mes) && (data.mes < dataSuperior.mes))
	{
		return 1;
	}

	//verificando se está no mês de 'dataInferior'. Além disso, o dia deve 
	//ser maior ou igual ao dia de 'dataInferior'
	if ((data.mes == dataInferior.mes) && (data.dia >= dataInferior.dia))
	{
		return 1;
	}
	
	//verificando se está no mês de 'dataSuperior'. Além disso, o dia deve 
	//ser menor ou igual ao dia de 'dataSuperior'
	if ((data.mes == dataSuperior.mes) && (data.dia <= dataSuperior.dia))
	{
		return 1;
	}

	return 0;
}

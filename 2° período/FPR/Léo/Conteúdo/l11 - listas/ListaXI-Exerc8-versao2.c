/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turmas: Manhã e Noite
	Professor Leonardo Vianna
	
	Data: 02/12/2023
	
	Lista de Exercícios XI (Listas Encadeadas)
	
	QUESTÃO 08:
	Implementar uma função que crie uma lista encadeada (dinâmica) com 
	os N primeiros termos de uma PA (progressão aritmética) de razão R 
	e primeiro termo igual a A1.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
void criarPA (int a1, int n, int r, TLista *PA);

int inserir (TLista *L, int numero);
void exibir (TLista L);

//main
void main ()
{
	//declaração de variáveis
	TLista PA;
	
	//chamando a função
	criarPA (2, 10, 3, &PA);
	
	exibir (PA);
}

//implementação das funções
void criarPA (int a1, int n, int r, TLista *PA)
{
	//declaração de variáveis
	int termo = a1, i;
	TLista aux, novoNo;
	
	//inicializando 'PA'
	*PA = (TLista) malloc (sizeof(TNo));
	(*PA)->valor = a1;
	(*PA)->prox = NULL;
	
	//incializando 'aux'
	aux = *PA;
	
	//inserindo os demais elementos da PA
	for (i=1;i<n;i++)
	{
		//atualizando 'termo'
		termo += r;
		
		//inserindo 'termo' no final da PA
		novoNo = (TLista) malloc (sizeof(TNo));
		
		//inserindo 'termo' no novo nó
		novoNo->valor = termo;
		
		//fazendo o campo 'prox' do novo nó apontar para NULL
		novoNo->prox = NULL;
		
		//fazendo o "antigo último nó" apontar para o novo nó
		aux->prox = novoNo;
		
		//atualizando 'aux'
		aux = novoNo;
	}		
}

int inserir (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocando memória para o novo nó
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se a memória foi alocada
	if (aux)
	{
		//Passo 2: inserir 'numero' no novo nó
		aux->valor = numero;
		
		//Passo 3: fazer o campo 'prox' do novo nó apontar para o "antigo primeiro nó"
		aux->prox = *L;
		
		//Passo 4: fazer L apontar para o novo nó
		*L = aux;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux = L;
	
	//verificando se a lista está vazia
	if (!L)
	{
		printf ("Lista vazia!\n\n");
	}
	else
	{
		printf ("Lista: ");
		
		//while (aux != NULL)
		while (aux)
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux', de modo que aponte para o próximo nó da lista
			aux = aux->prox;
		}
		
		printf ("\n\n");
	}
}


/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turmas: Manhã e Noite
	Professor Leonardo Vianna
	
	Data: 02/12/2023
	
	Considere a existência de uma lista encadeada L, do tipo TLista, e um número 
	inteiro n. Fazer uma função que crie duas novas listas, conforme descrito abaixo:
	
		L1: conterá todos os elementos de L que sejam inferiores a n;
		L2: conterá todos os elementos de L que sejam maiores ou iguais a n.
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
void criarListas (TLista L, int numero, TLista *L1, TLista *L2);

int inserir (TLista *L, int numero);
void exibir (TLista L);

//main
void main ()
{
	//declaração de variáveis
	TLista original = NULL, nova1 = NULL, nova2 = NULL;
	
	//inserindo valores na lista 'original'
	inserir (&original, 10);
	inserir (&original, 7);
	inserir (&original, 6);
	inserir (&original, 1);
	inserir (&original, 3);
	inserir (&original, 0);
	inserir (&original, 8);
	inserir (&original, 6);
	
	//chamando a função
	criarListas (original, 6, &nova1, &nova2);
	
	//exibindo as listas
	printf ("Lista original:\n");
	exibir (original);
	
	printf ("\n\nLista 1:\n");
	exibir (nova1);
	
	printf ("\n\nLista 2:\n");
	exibir (nova2);
}

//implementação das funções
void criarListas (TLista L, int numero, TLista *L1, TLista *L2)
{
	//declaração de variáveis
	TLista aux;
	
	//'aux' percorrerá a lista. Começando pelo primeiro nó.
	aux = L;
	
	//enquanto 'aux' não chegar ao final da lista
	while (aux)	
	{
		//verificando se o valor apontado por 'aux' é menor ou não do que 'numero'
		if (aux->valor < numero)
		{
			//inserir 'numero' em 'L1'
			inserir (/*&*L1*/L1, aux->valor);
		}
		else
		{
			//inserir 'numero' em 'L2'
			inserir (/*&*L2*/L2, aux->valor);
		}
		
		//atualizando 'aux' de forma que aponte para o próximo nó
		aux = aux->prox;
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


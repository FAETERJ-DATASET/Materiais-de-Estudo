/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 09/11/2023
	
	Listas encadeadas (Listas dinâmicas)
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
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int anterior, int novo);
TLista buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista L = NULL;  //representando a lista inicialmente vazia
	int num1, num2, op, quant;
	TLista resp;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&L, num1) == 1)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        quant = remover (&L, num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função
			        quant = alterar (L, num1, num2);
			        
			        if (quant > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        resp = buscar (L, num1);
			        
					if (resp != NULL)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}

//implementação das funções
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

int remover (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux1, aux2;
	int cont = 0;
	
	//verificando se o primeiro elemento da lista é igual a 'numero'
	while ((*L) && (*L)->valor == numero)
	{
		//salvando o endereço do nó que será removido
		aux1 = *L;
		
		//atualizando o valor de 'L'
		*L = (*L)->prox;	
		
		//liberando a memória ocupada pelo primeiro nó
		free (aux1);
		
		//atualizando a quantidade de remoções realizadas
		cont++;
	}
	
	//verificando se ainda existem nós na lista
	if (*L)
	{
		aux2 = *L;
		aux1 = (*L)->prox;   //ou   aux1 = aux2->prox;
		
		//percorrendo a lista
		while (aux1)
		{
			//verificando se 'numero' foi encontrado
			if (aux1->valor == numero)
			{
				//fazer o nó anterior apontar para o próximo nó
				aux2->prox = aux1->prox;
				
				//liberando a memória
				free (aux1);
				
				//atualizando a quantidade de remoções realizadas
				cont++;	
				
				//atualizando o ponteiro 'aux1'
				aux1 = aux2->prox;
			}
			else
			{
				//andar com os dois ponteiros
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	
	//retornando a quantidade de remoções realizadas
	return cont;
}

int alterar (TLista L, int anterior, int novo)
{
	//declaração de variáveis
	TLista aux;
	int cont = 0;
	
	//verificando se os valores são distintos
	if (anterior != novo)
	{
		//buscando a primeira ocorrência de 'anterior'
		aux = buscar (L, anterior);
		
		//enquanto o elemento existir na lista
		while (aux)
		{
			//atualizando o valor apontado pelo 'aux'
			aux->valor = novo;	
			
			//atualizando a quantidade de alterações realizadas
			cont++;
			
			//buscando novamente o 'anterior'
			aux = buscar (aux->prox, anterior);
		}	
	}
	
	return cont; //retornando a quantidade de alterações realizadas
}

TLista buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista
	while (aux)
	{
		//verificando se o elemento foi encontrado
		if (aux->valor == numero)
		{
			return aux;
		}
		
		//atualizando o 'aux'
		aux = aux->prox;	
	}	
	
	return NULL;	//elemento não se encontra na lista
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

//exibe um menu de opções ao usuário
int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

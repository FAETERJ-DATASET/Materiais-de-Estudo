/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 16/11/2023
	
	Filas encadeadas/linked (Filas dinâmicas)
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
int enfilar (TLista *inicio, TLista *final, int numero);
int desenfilar (TLista *inicio, TLista *final, int *numero);
int primeiro (TLista inicio, int *p);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista inicio = NULL, final = NULL;  //representando a fila inicialmente vazia
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser inserido na fila: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (enfilar (&inicio, &final, num) == 1)
			        {
			        	printf ("\n\tInsercao realizada com sucesso na fila!\n");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada na fila!\n");
					}
					break;

			//Desenfilar
			case 2: //chamando a função
			        if (desenfilar (&inicio, &final, &num) == 1)
			        {
			        	printf ("\n\tO elemento %d foi removido da fila!\n", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!\n");
					}
					break;

			//Primeiro
			case 3: //chamando a função
			        if (primeiro (inicio, &num) == 1)
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d\n", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!\n");
					}
					break;         
			        
			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//implementação das funções
int enfilar (TLista *inicio, TLista *final, int numero)
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
		
		//Passo 3: fazer o campo 'prox' do novo nó apontar para NULL (uma vez que será o último elemento da fila)
		aux->prox = NULL;
		
		if (*final)
		{
			//Passo 4: fazer o "antigo último nó" apontar para o novo
			(*final)->prox = aux;
		}
		else
		{
			*inicio = aux;
		}
		
		//Passo 5: atualizando 'final', de modo que aponte para o novo nó
		*final = aux;

		return 1;
	}
	else
	{
		return 0;
	}
}

int desenfilar (TLista *inicio, TLista *final, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a fila está vazia
	if (!(*inicio))
	{
		return 0;
	}
	else
	{
		//armazenando em 'aux' o endereço do primeiro elemento (que será removido)
		aux = *inicio;
		
		//atualizando o valor de 'inicio'
		*inicio = (*inicio)->prox;    //OU:    *inicio = aux->prox;
		
		//verificando se a fila se tornou vazia
		if (!(*inicio))
		{
			//atualizar 'final' para NULL também
			*final = NULL;
		}
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando a memória do nó apontado por 'aux'
		free (aux);
		
		return 1;
	}
}

//retornar em 'p' o primeiro elemento da fila, caso esta não esteja vazia
int primeiro (TLista inicio, int *p)
{
	//verificando se a fila está vazia
	if (!inicio)
	{
		return 0;
	}
	else
	{
		//armazenando em 'p' o primeiro elemento da fila
		*p = inicio->valor;
		
		return 1;
	}
}

//exibe um menu de opções ao usuário
int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

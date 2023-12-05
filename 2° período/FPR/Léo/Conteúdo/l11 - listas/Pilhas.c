/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 16/11/2023
	
	Pilhas encadeadas/linked (Pilhas dinâmicas)
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
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *t);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista P = NULL;  //representando a pilha inicialmente vazia
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser inserido na pilha: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (empilhar (&P, num) == 1)
			        {
			        	printf ("\n\tInsercao realizada com sucesso na pilha!\n");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada na pilha!\n");
					}
					break;

			//Desempilhar
			case 2: //chamando a função
			        if (desempilhar (&P, &num) == 1)
			        {
			        	printf ("\n\tO elemeto %d foi removido da pilha!\n", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!\n");
					}
					break;

			//Topo
			case 3: //chamando a função
			        if (topo (P, &num) == 1)
			        {
			        	printf ("\n\tTopo da pilha: %d\n", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!\n");
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
int empilhar (TLista *P, int numero)
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
		
		//Passo 3: fazer o campo 'prox' do novo nó apontar para o "antigo topo da pilha"
		aux->prox = *P;
		
		//Passo 4: fazer P apontar para o novo nó
		*P = aux;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int desempilhar (TLista *P, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a pilha 'P' está vazia
	if (!(*P))
	{
		return 0;
	}
	else
	{
		//armazenando em 'aux' o endereço do topo (que será removido)
		aux = *P;
		
		//atualizando o valor de 'P'
		*P = (*P)->prox;    //OU:    *P = aux->prox;
		
		//armazenando em 'numero' o valor sendo removido
		*numero = aux->valor;
		
		//liberando a memória do nó apontado por 'aux'
		free (aux);
		
		return 1;
	}
}

//retornar em 't' o elemento que está no topo da pilha 'P', caso esta não
//esteja vazia
int topo (TLista P, int *t)
{
	//verificando se a pilha 'P' está vazia
	if (!P)
	{
		return 0;
	}
	else
	{
		//armazenando em 't' o número que está no topo da pilha
		*t = P->valor;
		
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
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

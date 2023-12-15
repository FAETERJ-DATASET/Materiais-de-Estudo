/*
	FAETERJ-Rio
	Fundamentos de Programação  -  2022/1
	Turma: Manhã
	Data: 22/06/2022
	
	Listas dinâmicas (ou seja, listas por ponteiros), na qual
	repetição de elementos não é permitida.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;  //ou     typedef *TNo TLista;

//protótipos das funções
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int numeroIni, int numeroAlt);
TLista buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista L = NULL;
	int num1, num2, op;
	
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
			        if (inserir (&L, num1) == TRUE)
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
					if (remover (&L, num1) == TRUE)
			        {
			        	printf ("\n\tRemocao realizada com sucesso!");
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
			        if (alterar (L, num1, num2) == TRUE)
			        {
			        	printf ("\n\tAlteracao realizadas com sucesso!");
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
			        if (buscar (L, num1) != NULL)
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
	
	//verificando se o valor já existe na lista
	if (buscar (*L, numero) != NULL)
	{
		return FALSE;
	}
	else
	{	
		//Passo 1: alocar memória para o novo nó
		aux = (TLista) malloc (sizeof(TNo));
		
		//verificando se a memória foi alocada
		if (aux == NULL)
		{
			return FALSE;
		}
		else
		{
			//Passo 2: armazenar 'numero' no novo nó
			aux->valor = numero;
			
			//Passo 3: fazer o campo 'prox' do novo nó apontar para o "até então" primeiro nó da lista
			aux->prox = *L;
			
			//Passo 4: fazer '*L' apontar para o novo nó
			*L = aux;
			
			return TRUE;
		}
	}
}

int remover (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux1, aux2;
	
	//verificando se o primeiro elemento é o número a ser removido
	if ((*L != NULL) && ((*L)->valor == numero))
	{
		//passo 1: fazer 'aux1' apontar para o primeiro nó
		aux1 = *L;
		
		//passo 2: fazer o L apontar para o próximo elemento (aquele que até então era o segundo nó da lista)
		*L = (*L)->prox;   //ou  *L = aux1->prox;
		
		//passo 3: liberar a memória alocada ao nó a ser removido
		free (aux1);
		
		//finalizando a função
		return TRUE;
	}
	
	//verificando se a lista ainda existe
	if (*L != NULL)
	{
		//fazendo 'aux1' e 'aux2' apontarem para os dois primeiros nós
		aux2 = *L;
		aux1 = (*L)->prox;    //ou  aux1 = aux2->prox;
		
		//varrendo a lista até o seu final
		while (aux1 != NULL)
		{	
			//verificando se 'aux1' está apontando para o número a ser removido
			if (aux1->valor == numero)
			{
				//fazer com que o nó anterior ao que está sendo removido aponte para o próximo nó daquele sendo removido
				aux2->prox = aux1->prox;
				
				//liberar a memória alocada ao nó a ser removido
				free (aux1);
				
				//finalizando a função
				return TRUE;
			}
			else
			{
				//andar com os ponteiros 'aux1' e 'aux2'
				aux2 = aux1;		 //ou aux2 = aux2->prox; 
				aux1 = aux1->prox;   //ou aux1 = aux2->prox;
			}
		}
	}
	
	//finalizando a função
	return FALSE;
}

int alterar (TLista L, int numeroIni, int numeroAlt)
{
	//declaração de variáveis
	TLista posIni, posAlt;
	
	//verificando se o número a ser alterado existe na lista
	posIni = buscar (L, numeroIni);
	
	if (posIni != NULL)
	{
		//verificando se o novo número existe na lista
		posAlt = buscar (L, numeroAlt);
		
		if (posAlt == NULL)		//novo elemento não existe
		{
			//realizando a alteração
			posIni->valor = numeroAlt;
			
			return TRUE;			
		}
	/*	else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}*/
	}
	
	return FALSE;
}

TLista buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//fazer com que 'aux' aponte para o primeiro nó da lista
	aux = L;
		
	while (aux != NULL) //while (aux)
	{
		//verificando se o valor apontado por 'aux' é o número sendo buscado
		if (aux->valor == numero)
		{
			return aux;			
		}
						
		//atualizar o 'aux', de forma que aponte para o próximo nó
		aux = aux->prox;
	}
	
	//elemento não existe na lista
	return NULL;
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a lista está vazia
	if (L == NULL)   //if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos da lista: ");
		
		//fazer com que 'aux' aponte para o primeiro nó da lista
		aux = L;
		
		while (aux != NULL) //while (aux)
		{
			//exibindo cada elemento da lista
			printf ("%d ", aux->valor);
			
			//atualizar o 'aux', de forma que aponte para o próximo nó
			aux = aux->prox;
		}
		
		printf ("\n");	
	}
}

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

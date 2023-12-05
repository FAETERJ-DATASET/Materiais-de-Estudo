/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2
	Professor Leonardo Vianna
	Data: 23/09/2023
	
	Lista de Exercícios VII (Structs)
	
	Questão 01:
	Uma loja de automóveis mantém os carros à venda sob a forma de um 
	vetor de structs contendo as seguintes informações, para cada 
	veículo: placa, modelo, marca, cor, quilometragem, 
	ano modelo/fabricação (deve ser um struct), valor e 
	tipo (usado ou 0 km, conforme o valor do campo quilometragem). 

	Pede-se a declaração de uma variável que represente o estoque 
	de veículos da loja, incluindo todas as declarações de tipos 
	que possam ser necessárias.

	Além disso, implementar as seguintes funções: 
	i.	Exibir todos os carros do modelo m, ano de fabricação entre 
	    a1 e a2 (inclusive), com valor não superior a x reais;
	ii.	Reajustar os valores de todos os carros 0 km, considerando um 
	    aumento de p %;
	iii. Retirar do estoque um determinado veículo, dada a sua placa.	
*/

//importação de bibliotecas
#include <stdio.h>

//definição de tipos
typedef struct {
	int fabricacao;
	int modelo;
} TAno;

typedef struct {
	char placa[8];
	char modelo[20];
	char marca[20];
	char cor[20];
	float quilometragem;
	TAno ano;
	float valor;
	char tipo[6];	
} TCarro;

//protótipos das funções
void exibirFiltros (TCarro ag[], int quantidade, char m[], int a1, int a2, float x);
void exibirDadosCarro (TCarro carro);
void reajustarCarros0km (TCarro ag[], int quantidade, float p);
int  removerCarro (TCarro ag[], int *quantidade, char placa[]);

//main
void main ()
{
	//declaração de variáveis
	TCarro agencia[5];	
}

//implementação das funções

/* Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 
(inclusive), com valor não superior a x reais. */
void exibirFiltros (TCarro ag[], int quantidade, char m[], int a1, int a2, float x)
{
	//declaração de variáveis
	int i;
	
	//percorrendo todo o vetor de carros
	for (i=0;i<quantidade;i++)
	{
		//verificando se o carro da posição 'i' do vetor atende aos filtros
		if ((strcmp(ag[i].modelo,m)==0) &&
		    ((ag[i].ano.fabricacao >= a1) && (ag[i].ano.fabricacao <= a2)) &&
		    (ag[i].valor <= x))
		{
			exibirDadosCarro (ag[i]);
		}
	}
}

//Exibe os dados de determinado carro
void exibirDadosCarro (TCarro carro)
{
	printf ("Placa: %s\n", carro.placa);
	printf ("Marca/Modelo: %s/%s\n", carro.marca, carro.modelo);
	printf ("Cor: %s\n", carro.cor);
	printf ("Km: %.1f\n", carro.quilometragem);
	printf ("Ano (fabricacao/modelo): %d/%d\n", carro.ano.fabricacao, carro.ano.modelo);
	printf ("Valor: R$ %.2f\n", carro.valor);
	printf ("Tipo: %s\n\n", carro.tipo);
}

/* Reajustar os valores de todos os carros 0 km, considerando um 
   aumento de p %.*/
void reajustarCarros0km (TCarro ag[], int quantidade, float p)
{
	//declaração de variáveis
	int i;
	
	//percorrendo todo o vetor de carros
	for (i=0;i<quantidade;i++)
	{
		//verificando se o carro da posição 'i' é 0 km
		if (strcmp (ag[i].tipo, "0KM") == 0)
		{
			//reajustar o seu valor
			ag[i].valor = ag[i].valor + (ag[i].valor*(p/100));
			//ou: ag[i].valor += (ag[i].valor*(p/100));
			
			//ou: ag[i].valor = ag[i].valor * (1 + (p/100));
			//ou: ag[i].valor = ag[i].valor * ((p+100)/100);
			//ou: ag[i].valor *= ((p+100)/100);
		}
	}
}

//Retirar do estoque um determinado veículo, dada a sua placa.
//A função retornará 1 se a remoção for feita, ou 0, caso contrário.
int  removerCarro (TCarro ag[], int *quantidade, char placa[])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo todo o vetor de carros
	for (i=0;i<*quantidade;i++)
	{
		//verificando se o carro da posição 'i' é aquele a ser removido
		if (strcmp (ag[i].placa, placa) == 0)
		{
			//deslocando uma posição à esquerda todos os carros após a posição 'i'	
			for (j=i+1;j<*quantidade;j++)
			{
				ag[j-1] = ag[j];
			}
			
			//atualizando a quantidade de carros na agência
			(*quantidade)--;
			
			return 1;
		}
	}
	
	return 0;
}

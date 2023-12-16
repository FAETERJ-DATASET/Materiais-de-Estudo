/*
	FPR - Professor Leonardo Vianna
	Turma: Manhã
	Data: 14/04/2022

	Lista de Exercícios V (Matrizes)

	QUESTÃO 06:
	Considere uma loja que mantém em uma matriz o total vendido por cada funcionário pelos diversos meses do ano.
	Ou seja, uma matriz de 12 linhas (uma por mês) e 10 colunas (10 funcionários). Pede-se o desenvolvimento de uma
	função para cada item abaixo:

	a.	Calcular o total vendido durante o ano;
	b.	Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês;
	c.	Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano;
	d.	Determinar o mês com maior índice de vendas;
	e.	Determinar o funcionário que menos vendeu durante o ano.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 12
#define C 10

//protótipos das funções
float totalVendidoAno (float m[L][C]);
float totalVendidoMes (float m[L][C], int mes);
float totalVendidoFuncionario (float m[L][C], int funcionario);
int   mesMaiorIndiceVendas (float m[L][C]);
int   funcionarioMenorIndiceVendas (float m[L][C]);

void preencherMatriz (float m[L][C]);
void exibirMatriz (float m[L][C]);

//main
void main ()
{
	//declaração de variáveis
	float matriz[L][C];
	float total;
	int mes, funcionario;

	//preenchendo a matriz com números aleatórios
	preencherMatriz (matriz);

	//exibindo a matriz
	printf ("Exibindo a matriz:\n\n");
	exibirMatriz (matriz);

	//calculando o total vendido no ano
	total = totalVendidoAno (matriz);
	printf ("\n\nTotal vendido no ano: R$ %.2f\n", total);

	//lendo o mês desejado
	printf ("\nEntre com o mes desejado: ");
	scanf ("%d", &mes);

	//Calculando o total vendido no mês especificado
	total = totalVendidoMes (matriz, mes);
	printf ("\n\nTotal vendido no mes %d: R$ %.2f\n", mes, total);

	//lendo o funcionário desejado
	printf ("\nEntre com o numero do funcionario: ");
	scanf ("%d", &funcionario);

	//Calculando o total vendido pelo funcionário especificado
	total = totalVendidoFuncionario (matriz, funcionario);
	printf ("\n\nTotal vendido pelo funcionario %d: R$ %.2f\n", funcionario, total);

	//determinando o mês com maior índice de vendas
	mes = mesMaiorIndiceVendas (matriz);
	printf ("\n\nMes com maior indice de vendas: %d\n", mes);

	//determinando o funcionário com menor índice de vendas
	funcionario = funcionarioMenorIndiceVendas (matriz);
	printf ("\n\nFuncionario com menor indice de vendas: %d\n", funcionario);
}

//implementação das funções
void preencherMatriz (float m[L][C])
{
	//declaração de variáveis
	int i, j;

	//garantindo que as sequências aleatórias são diferentes
	srand (time(NULL));

	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			m[i][j] = rand()%1000 + 1;
		}
	}
}

void exibirMatriz (float m[L][C])
{
	//declaração de variáveis
	int i, j;

	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			printf ("%.2f\t", m[i][j]);
		}

		printf ("\n");
	}
}

//Calcular o total vendido durante o ano.
float totalVendidoAno (float m[L][C])
{
	//declaração de variáveis
	int i, j;
	float soma = 0;

	//percorrendo as linhas
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas
		for (j=0;j<C;j++)
		{
			//acumulando o somatório
			soma += m[i][j];
		}
	}

	//retornando a soma
	return soma;
}

//Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês.
float totalVendidoMes (float m[L][C], int mes)
{
	//declaração de variáveis
	int j;
	float soma = 0;

	//transformando o mês do intervalo de 1..12 para 0..11
	mes--;

	//percorrendo as colunas da matriz, na linha representada pelo mês
	for (j=0;j<C;j++)
	{
		soma += m[mes][j];
	}

	//retornando a soma
	return soma;
}

//Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano.
float totalVendidoFuncionario (float m[L][C], int funcionario)
{
	//declaração de variáveis
	int i;
	float soma = 0;

	//transformando o funcionário do intervalo de 1..10 para 0..9
	funcionario--;

	//percorrendo as linhas da matriz, na coluna representada pelo funcionário
	for (i=0;i<L;i++)
	{
		soma += m[i][funcionario];
	}

	//retornando a soma
	return soma;
}

//Determinar o mês com maior índice de vendas.
int   mesMaiorIndiceVendas (float m[L][C])
{
	//declaração de variáveis
	float maior, total;
	int mesMaior, mes;

	//inicializando 'maior' com o total vendido no primeiro mês (janeiro)
	maior = totalVendidoMes (m, 1);
	mesMaior = 1;

	//calculando o total vendido nos demais meses e comparando com 'maior'
	for (mes=2;mes<=L;mes++)
	{
		//calculando o total vendido em 'mes'
		total = totalVendidoMes (m, mes);

		//verificando se há necessidade de atualizar 'maior'
		if (total > maior)
		{
			maior = total;
			mesMaior = mes;
		}
	}

	//retornando o resultado
	return mesMaior;
}

//Determinar o funcionário que menos vendeu durante o ano.
int   funcionarioMenorIndiceVendas (float m[L][C])
{
	//declaração de variáveis
	float menor, total;
	int funcionarioMenor, funcionario;

	//inicializando 'menor' com o total vendido pelo primeiro funcionário
	menor = totalVendidoFuncionario (m, 1);
	funcionarioMenor = 1;

	//calculando o total vendido pelos demais funcionários e comparando com 'menor'
	for (funcionario=2;funcionario<=C;funcionario++)
	{
		//calculando o total vendido pelo 'funcionario'
		total = totalVendidoFuncionario (m, funcionario);

		//verificando se há necessidade de atualizar 'menor'
		if (total < menor)
		{
			menor = total;
			funcionarioMenor = funcionario;
		}
	}

	//retornando o resultado
	return funcionarioMenor;
}

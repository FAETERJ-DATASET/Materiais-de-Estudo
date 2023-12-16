/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna

	Lista de Exercícios VI (Structs)

	Questão 05:
	O histórico de um aluno é representado por um vetor de structs onde cada posição armazena o código da
	disciplina cursada, semestre e ano que a cumpriu e a média final na disciplina. Implementar uma função que
	exiba o histórico do aluno com o seguinte formato:

							NomeDisciplina1 (código1)	MédiaDisciplina1
							NomeDisciplina2 (código2)	MédiaDisciplina2
												.
												.
												.
							NomeDisciplinaN (códigoN)	MédiaDisciplinaN
							Coeficiente de rendimento: CR


	Observações:
		1. Para obter os dados da disciplina, um outro vetor de structs deve ser consultado. Este, por sua vez,
		   armazena para cada disciplina do curso as seguintes informações: código, nome e número de créditos;
		2. O coeficiente de rendimento consiste em uma média ponderada de todos os graus atribuídos às
		   disciplinas cursadas, onde os pesos são representados pelo número de créditos da disciplina;
		3. Todos os dados em negrito apresentados no formato do histórico devem ser obtidos a partir dos vetores.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define QUANT 30			//número de disciplinas no histórico do aluno
#define NUMDISC 50			//número de disciplinas do curso

//declaração de tipos
typedef struct {			//representando uma disciplina do curso
	char codigo[5];
	char nome[30];
	int creditos;
} TDisciplina;

typedef struct {			//representando um semestre/ano
	int semestre,
	    ano;
} TSemestre;

typedef struct {			//representando uma disciplina cursada pelo aluno
	char codDisc[5];
	TSemestre semestre;
	float media;
} TCursou;

//Implementar uma função que exiba o histórico do aluno com o formato especificado no cabeçalho deste arquivo

void exibirHistorico (TCursou H[], int quantH, TDisciplina D[], int quantD)
{
	int i, disciplina;
	float denominador = 0, numerador = 0, CR;

	//percorrendo todas as disciplinas cursadas pelo aluno
	for (i=0;i<quantH;i++)
	{
		disciplina = buscarDisciplina (D, quantD, H[i].codDisc);
		printf ("%s (%s)     %.1f\n", D[disciplina].nome, H[i].codDisc, H[i].media);

		//acumulando somatórios para o cálculo do coeficiente de rendimento
		denominador += H[i].media*D[disciplina].creditos;
		numerador += D[disciplina].creditos;
	}

	//Calculando o CR do aluno
	CR = denominador/numerador;

	//exibindo o CR ao final do histórico
	printf ("\nCoeficiente de rendimento: %.1f", CR);
}

//Dado um código de disciplina, determina o seu nome após percorrer o vetor de disciplinas
int buscarDisciplina (TDisciplina D[], int quantD, char codigo[5])
{
	int i;

	//percorrendo o vetor de disciplinas
	for (i=0;i<quantD;i++)
	{
		if (strcmp (D[i].codigo, codigo) == 0)
		{
			return i;
		}
	}

	//caso não seja encontrado o código
	return -1;
}

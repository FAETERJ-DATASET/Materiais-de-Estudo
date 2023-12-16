/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna

	Lista de Exercícios VI (Structs)

	Questão 02:
	Determinada zona eleitoral possui N eleitores inscritos que poderão votar, uma única vez, em um dos C candidatos para o único cargo a ser definido.
	Pede-se:

	a. A declaração de todo(s) o(s) tipo(s) de dados necessário(s) para o armazenamento dos números dos candidatos, assim como a quantidade de votos
	   brancos, nulos e votos para cada candidato;
	b. Uma função que leia o voto de cada eleitor, considerando que o processo terminará quando os N eleitores votarem ou quando o número -1 for
	   digitado como voto;
    c. Uma função que exiba:
    	i.   O total de votos para cada candidato, assim com a quantidade de votos brancos (código 0) e de nulos (código sem candidato associado);
    	ii.	 A quantidade de abstenções (eleitores que não votaram);
    	iii. O número do candidato vencedor (caso tenha mais de 50% dos votos válidos) ou dos que irão para o segundo turno (os dois mais votados).

    Notas:
    a) o número do candidato deve conter dois algarismos apenas;
	b) podem considerar que não haverá mais de um candidato com a mesma quantidade de votos.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define N 10  				//número de eleitores da zona eleitoral
#define C 3					//número de candidatos

//definição de tipos
typedef struct {
	int numero;				//número do candidato
	int totalVotos;			//total de votos que o candidato recebeu
} TCandidato;				//struct que representada cada candidato

typedef struct {
	TCandidato vetCand[C];	//armazenará, para cada candidato, o seu número e a quantidade de votos recebidos
	int totalVotos;			//total de votos
	int brancos;			//total de votos brancos (informar 0 para o número do candidato)
	int nulos;				//total de votos nulos (informar um valor inválido para o número do candidato)
} TVotacao;					//struct que representará a eleição e os diversos votos

//protótipos das funções

  //funções solicitadas
  void leituraVotos (TVotacao *eleicao, int numEleitores);
  void exibirResultadoEleicao (TVotacao eleicao);

  //funções auxiliares
  void preencherVetorCandidatos (TCandidato candidatos[], int tamanho);
  void inicializarVotacao (TVotacao *eleicao);
  int buscar (TCandidato candidatos[], int tamanho, int numeroCandidato);
  void candidatosMaisVotados (TCandidato candidatos[], int tamanho, int *primeiro, int *segundo);

//main
void main ()
{
	//declaração de variáveis
	TVotacao vetEleicao;

	//inicializando o vetor da Eleição, inclusive lendo os dados dos candidatos
	inicializarVotacao (&vetEleicao);

	//lendo os votos dos eleitores
	leituraVotos (&vetEleicao, N);

	//exibindo os resultados
  	exibirResultadoEleicao (vetEleicao);
}

//implementação das funções
void preencherVetorCandidatos (TCandidato candidatos[], int tamanho)
{
	//declaração de variáveis
	int i, numero;

	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//lendo o número de cada candidato
		do
		{
			printf ("Entre com o numero do %do. candidato: ", i+1);
			scanf ("%d", &numero);

			//verificando se o número digitado é inválido (pois deve ter dois algarismos)
			if ((numero < 10) || (numero > 99))
			{
				printf ("\n\n\tErro: o numero do candidato deve estar no intervalo de 10 a 99\nTente novamente.\n\n");
			}

		} while ((numero < 10) || (numero > 99));

		candidatos[i].numero = numero;
		candidatos[i].totalVotos = 0;
	}
}

void inicializarVotacao (TVotacao *eleicao)
{
	//inicializando os votos com zero no início da votação
	(*eleicao).totalVotos = 0;
	(*eleicao).brancos = 0;
	(*eleicao).nulos = 0;

	//lendo os dados de cada candidato
	preencherVetorCandidatos ((*eleicao).vetCand, C);
}

int buscar (TCandidato candidatos[], int tamanho, int numeroCandidato)
{
	//decloração de variáveis
	int i;

	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//verificando se o número do candidato foi encontrado
		if (candidatos[i].numero == numeroCandidato)
		{
			return i;	//retornando a posição do candidato no vetor
		}
	}

	//retornando -1, se o número do candidato não existir
	return -1;
}

void leituraVotos (TVotacao *eleicao, int numEleitores)
{
	//declaração de variáveis
	int numero, retorno;

	printf ("\n\n\n");

	do
	{
		//lendo o voto de cada eleitor
		printf ("Numero do candidato: ");
		scanf ("%d", &numero);

		//verificando se não foi o voto de saída do sistema
		if (numero != -1)
		{
			//atualizando o total de votos
			(*eleicao).totalVotos++;

			//trata-se de voto em branco?
			if (numero == 0)
			{
				(*eleicao).brancos++;
			}
			else
			{
				//buscando no vetor o candidato votado, para atualizar o seu total de votos
				retorno = buscar ((*eleicao).vetCand, C, numero);

				//verificando se o número do candidato foi encontrado
				if (retorno >= 0)
				{
					(*eleicao).vetCand[retorno].totalVotos++;	//atualizando o número de votos do candidato
				}
				else
				{
					//trata-se de voto nulo
					(*eleicao).nulos++;
				}
			}
		}
	}
	while (((*eleicao).totalVotos < numEleitores) && (numero != -1));
}

void exibirResultadoEleicao (TVotacao eleicao)
{
	//declaração de variáveis
	int i, primeiro, segundo, votosValidos;
	float percentualPrimeiro;

	//exibindo o resultado da eleição
	printf ("\n\n\nResultado da Eleicao:\n\n");

	printf ("No. Candidato\t\tTotal de votos\n");
	for (i=0;i<C;i++)
	{
		printf ("%d\t\t\t\t%d\n", eleicao.vetCand[i].numero,eleicao.vetCand[i].totalVotos);
	}

	printf ("\nVotos Brancos: %d\n", eleicao.brancos);
	printf ("\nVotos Nulos: %d\n", eleicao.nulos);
	printf ("\nAbstencoes: %d\n", N-eleicao.totalVotos);

	//determinando os dois candidatos mais votados
	candidatosMaisVotados (eleicao.vetCand, C, &primeiro, &segundo);

	votosValidos = eleicao.totalVotos-eleicao.brancos-eleicao.nulos;
	percentualPrimeiro = (float)eleicao.vetCand[primeiro].totalVotos/votosValidos;

	//verificando se o mais votado possui mai de 50% dos votos
	if (percentualPrimeiro > 0.5)
	{
		printf ("\nVencedor da Eleicao: candidato %d!!!\n", eleicao.vetCand[primeiro].numero);
	}
	else
	{
		printf ("\nCandidatos que concorrerao no segundo turno: %d e %d.\n", eleicao.vetCand[primeiro].numero, eleicao.vetCand[segundo].numero);
	}
}

void candidatosMaisVotados (TCandidato candidatos[], int tamanho, int *primeiro, int *segundo)
{
	//declaração de variáveis
	int i, maisVotos1, maisVotos2;

	//inicializado o candidato mais votado como o candidato da posição 0 do vetor
	*primeiro = 0;
	maisVotos1 = candidatos[0].totalVotos;

	for (i=1;i<tamanho;i++)
	{
		if (candidatos[i].totalVotos > maisVotos1)
		{
			maisVotos2 = maisVotos1;
			*segundo = *primeiro;

			maisVotos1 = candidatos[i].totalVotos;
			*primeiro = i;
		}
		else
		{
			if (candidatos[i].totalVotos > maisVotos2)
			{
				maisVotos2 = candidatos[i].totalVotos;
				*segundo = i;
			}
		}
	}
}

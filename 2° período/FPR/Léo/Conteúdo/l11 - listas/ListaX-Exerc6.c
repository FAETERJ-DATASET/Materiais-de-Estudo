/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turmas: Manhã e Noite
	Professor Leonardo Vianna
	
	Data: 02/12/2023
	
	Lista de Exercícios X (Arquivos)
	
	Questão 06:
	Desenvolver uma função que, dados dois arquivos textos arqA e arqB, crie um 
	novo arquivo arqC, considerando que:

	- arqA e arqB contém números reais, um por linha, ordenados crescentemente e 
	  sem repetição no arquivo; 
	- arqC deve conter todos os números dos dois arquivos originais;
	- Assim como arqA e arqB, arqC também não possuirá repetições de elementos e 
	  estes deverão estar ordenados de forma crescente.
	  
	Arquivo A: 1 5 8 9 10
	Arquivo B: 2 3 4 8 10 15 16
	
	Arquivo C: 1 2 3 4 5 8 9 10 15 16
	
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//protótipos das funções
int uniao (char nomeArqA[], char nomeArqB[], char nomeArqC[]);

//main
void main ()
{
	//chamando a função
	if (uniao ("A.txt", "B.txt", "C.txt") == 1)
	{
		printf ("\nArquivo uniao criado com sucesso!\n");
	}
	else
	{
		printf ("\nArquivo uniao nao criado!\n");
	}
}

//implementação das funções
int uniao (char nomeArqA[], char nomeArqB[], char nomeArqC[])
{
	//declaração de variáveis
	FILE *arqA, *arqB, *arqC;
	int fimA = 0, fimB = 0, numA, numB;
	
	//tentando abrir os arquivos
	arqA = fopen (nomeArqA, "r");
	arqB = fopen (nomeArqB, "r");
	arqC = fopen (nomeArqC, "w");
	
	//verificando se houve erro
	if ((!arqA) || (!arqB) || (!arqC))
	{
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 0;
	}
	else
	{
		//lendo o primeiro valor do arquivo A e o primeiro do arquivo B
		fscanf (arqA, "%d", &numA);
		fscanf (arqB, "%d", &numB);
		
		while ((!fimA) && (!fimB))
		{
			//comparando os valores dos dois conjuntos
			if (numA < numB)
			{
				//escreva no conjunto união o valor de A (que é o menor)
				fprintf (arqC, "%d\n", numA);
				
				//leia o próximo valor de A
				if (fscanf (arqA, "%d", &numA) == EOF)
				{
					fimA = 1;
				}
			}
			else
			{
				if (numB < numA)
				{
					//escreva no conjunto união o valor de B (que é o menor)
					fprintf (arqC, "%d\n", numB);
					
					//leia o próximo valor de B
					if (fscanf (arqB, "%d", &numB) == EOF)
					{
						fimB = 1;
					}
				}
				else
				{
					//se chegou aqui, os valores de A e de B são iguais
					
					//escreva no conjunto união o valor de A ou o de B (já que são iguais)
					fprintf (arqC, "%d\n", numA);
				
					//leia o próximo valor de cada arquivo
					if (fscanf (arqA, "%d", &numA) == EOF)
					{
						fimA = 1;
					}
					
					if (fscanf (arqB, "%d", &numB) == EOF)
					{
						fimB = 1;
					}
				}
			}
		}
		
		//neste ponto, pelo menos um dos arquivos terminou
		//if ((fimA) && (!fimB))
		if (!fimB)
		{
			fprintf (arqC, "%d\n", numB);
			
			while (fscanf (arqB, "%d", &numB) != EOF)
			{
				fprintf (arqC, "%d\n", numB);
			}
		}
		else
		{
			if (!fimA)
			{
				fprintf (arqC, "%d\n", numA);
				
				while (fscanf (arqA, "%d", &numA) != EOF)
				{
					fprintf (arqC, "%d\n", numA);
				}
			}
		}
		
		//fechando os arquivos
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 1;
	}
}

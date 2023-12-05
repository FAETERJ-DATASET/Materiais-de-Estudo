/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turmas: Manhã e Noite
	Professor Leonardo Vianna
	
	Data: 21/10/2023 (aula extra)
	
	Questão 02 (AV1 - Noite - 2023/1):
	
	Dadas duas strings s1 e s2, implementar uma função que verifique se todos os caracteres de s1 
	estão em s2. 
	Dependendo do resultado, os seguintes valores deverão ser retornados: 
			0: nem todos os caracteres de s1 estão em s2; 
			1: todos os caracteres de s1 estão em s2, porém não na mesma frequência; 
			2: todos os caracteres de s1 estão em s2, na mesma frequência. 
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int questao02 (char s1[], char s2[]);
int contagem (char s[], char caracter);

//main
void main ()
{
	printf ("CASA e ASSC: %d\n", questao02 ("CASA", "ASSC"));			//1
	printf ("CASA e ASAC: %d\n", questao02 ("CASA", "ASAC"));			//2
	printf ("CASADO e AADDSC: %d\n", questao02 ("CASADO", "AADDSC"));	//0
	printf ("CASA e CASADO: %d\n", questao02 ("CASA", "CASADO"));		//2
}

//implementação das funções
int questao02 (char s1[], char s2[])
{
	//declaração de variáveis
	int i, quant1, quant2, retorno = 2;
	
	//percorrendo todos os caracteres de 's1'
	for (i=0;s1[i];i++)
	{
		//contando o número de ocorrência de 's1[i]' em 's2'
		quant2 = contagem (s2, s1[i]);
				
		//verificando se s1[i] não existe em s2
		if (quant2 == 0)
		{
			return 0;
		}
		else
		{
			//contando o número de ocorrência de 's1[i]' na própria string 's1'
			quant1 = contagem (s1, s1[i]);
			
			//verificando se as quantidades são iguais
			if (quant1 != quant2)
			{
				retorno = 1;
			}
		}		
	}
	
	return retorno;
}

int contagem (char s[], char caracter)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo a string 's'
	for (i=0;s[i];i++)
	{
		if (s[i] == caracter)
		{
			cont++;
		}
	}
	
	return cont;
}

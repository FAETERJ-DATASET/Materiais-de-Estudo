/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turma: Manh�
	Professor Leonardo Vianna
	
	Data: 01/11/2023
	
	Ponteiros 
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declara��o de vari�veis
	int v[5] = {1,2,3,4,5};
	int *x;
	
	x = v;
	
	printf ("%d ", *x);
	printf ("%d ", *(x+1));
	printf ("%d ", *(x+2));
	printf ("%d ", *(x+3));
	printf ("%d ", *(x+4));
}


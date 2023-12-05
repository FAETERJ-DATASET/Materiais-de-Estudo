/*
	FAETERJ-Rio
	Fundamentos de Programação - 2023/2 - Turma: Manhã
	Professor Leonardo Vianna
	
	Data: 01/11/2023
	
	Ponteiros 
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int v[5] = {1,2,3,4,5};
	int *x;
	int i;
	
	x = v;
	
	for (i=0;i<5;i++)
	{
		printf ("%p\n", x+i);
		printf ("%d\n", *(x+i));
	}
	
	/*printf ("%d ", *x);
	printf ("%d ", *(x+1));
	printf ("%d ", *(x+2));
	printf ("%d ", *(x+3));
	printf ("%d ", *(x+4));	*/
}


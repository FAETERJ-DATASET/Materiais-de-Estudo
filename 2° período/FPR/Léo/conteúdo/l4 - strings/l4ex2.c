/*Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.*/

#include <stdio.h>
#include <string.h>

int palindromo(char string[]);

int main()
{
	char minhaString[20];
	
	printf("\nInsira sua string: ");
	gets(minhaString);
	
	if(palindromo(minhaString))
	{
		printf("\nA string '%s' eh um palindromo", minhaString);
	}
	else
	{
		printf("\nA string '%s' nao eh um palindromo", minhaString);
	}
	return 0;
}

int palindromo(char string[])
{
	int i = 0;
	int j = strlen(string) - 1;

	while (i < j)
	{
		if(string[i] != string[j])
		{
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

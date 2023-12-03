#include <stdio.h>

void converterBinario(int tot, char n[tot]);
int confirmarBinario(int tot, char n[tot]);

int main()
{
	char numero[12] = "101010";
	int total = 12;
	
	converterBinario(total, numero);
	
	return 0;
}

void converterBinario(int tot, char n[tot])
{
	confirmarBinario(tot, n);
}

int confirmarBinario(int tot, char n[tot])
{
	int tamStr = strlen(n);
	int i, j;
	int aux = 1;
	int decimal = 0;
	
	for(i=0; i<tamStr; i++)
	{
		if((n[i] != '0') && (n[i] != '1'))
		{
			return -1;
		}
	}
	
	for(i=tamStr-1; i>=0; i--)
	{
		if(n[i] == '1')
		{
			decimal += aux;
		}
		aux *= 2;
	}
	
	printf("\ndecimal: %d", decimal);
	return decimal;
}

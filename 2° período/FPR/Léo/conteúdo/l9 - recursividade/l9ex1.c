/*
	x = funcao(32, 6)
	
	return(26, 6);
	return(20,6);
	return(14,6);
	return(8,6);
	return(2,6);
	return 2;
*/

int funcao (int A, int B)
{
	if (A >= B)
	{
		return funcao (A-B, B);
	}
	else
	{
		return A;
	}
}

void main(){
	int x = funcao(32,6);
	printf("o valor de x eh %d", x);
}

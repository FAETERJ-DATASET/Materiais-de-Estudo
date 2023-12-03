#include <stdio.h>

void preencherMatriz(int L, int C, int m[L][C]){
	int i, j;
	srand(time(NULL));
	for(i=0; i<L; i++){
		for(j=0; j<C; j++){
			m[i][j] = rand()%10;
		}
	}
}

void exibirMatriz(int L, int C, int m[L][C]){
	int i, j;
	for(i=0; i<L; i++){
		for(j=0; j<C; j++){
			printf("%-4d", m[i][j]);
		}
		printf("\n");
	}
}

void criarVetor(int L, int C, int m[L][C]){
	int vetor[L], i, k, quant = 100, soma = 0;
	
	for(i=0; i<L; i++){//percorrendo o vetor (que também são as linhas da matriz)
		for(k=0; k<C; k++){//percorrendo colunas da matriz
			 soma += (m[i][k] * quant);
			 quant /= 10;
		}
		vetor[i] = soma;
		soma = 0, quant = 100;
	}
	
	printf("\nvetor: ");
	for(i=0; i<L; i++){
		printf("%-5d ", vetor[i]);
	}
}

void main(){
	int L = 5;
	int C = 3;
	int m[L][C];
	
	preencherMatriz(L, C, m);
	exibirMatriz(L, C, m);
	
	criarVetor(L, C, m);
}

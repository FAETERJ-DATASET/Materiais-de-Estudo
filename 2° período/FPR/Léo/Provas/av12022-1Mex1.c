#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void exibirMatriz(int m[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%-5d", m[i][j]);
		}
		printf("\n");
	}
}

void preencherMatriz(int m[N][N], int X){
	int i, j;
	srand(time(NULL));
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			m[i][j] = rand()%X;
		}
	}
}

void gerarM3(int m1[][N], int m2[][N], int m3[][N]){
	int i, j, k, soma = 0;
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(m2[i][j] == 0){
				m3[i][j] = m1[i][j];
			} else {
				soma = 0;
				for(k=0; k<N; k++){
					soma += m2[i][k]; //soma dos elementos da linha
					soma += m2[k][j]; //soma dos elementos da coluna
				} 
				m3[i][j] = soma;
			}
		}
	}
}

void main(){
	int m1[N][N];
	int m2[N][N];
	int m3[N][N];
	
	preencherMatriz(m1, 100);
	preencherMatriz(m2, 2);
	
	printf("matriz 1: \n");
	exibirMatriz(m1);
	printf("matriz 2: \n");
	exibirMatriz(m2);
	
	gerarM3(m1, m2, m3);
	
	printf("matriz 3: \n");
	exibirMatriz(m3);
	
	return 0;
}

#include <stdio.h>

void multiplos(int N, int V, int aux){
	if(N<=V){
		printf("%d ", N);
		multiplos(N+aux, V, aux);
	}
}

void main(){
	int N = 5;
	int V = 50;
	int aux = N;
	
	multiplos(5, 50, aux);
}

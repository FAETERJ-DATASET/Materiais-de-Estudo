#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[20];
	char genero;
	int idade;
} TPessoa;

int estaOrdenado(TPessoa p[], int tam){
	int i;
	
	for(i=1; i<tam; i++){
		if(p[i].idade < p[i-1].idade){
			return 0;
		} else {
			if (p[i].idade == p[i-1].idade){
				if (strcmp(p[i].nome, p[i-1].nome) < 0){
					return 0;
				}
			}
		}
	}
	return 1;
}

void main(){
	TPessoa p1 = {"A", 'F', 1};
	TPessoa p2 = {"B", 'M', 2};
	TPessoa p3 = {"D", 'M', 3};
	TPessoa p4 = {"C", 'F', 3};
	TPessoa p5 = {"E", 'F', 5};
	
	TPessoa p[5] = {p1, p2, p3, p4, p5};
	
	if(estaOrdenado(p, 5)){
		printf("\nEsta ordenado");
	} else {
		printf("\nNao esta ordenado");
	}
}

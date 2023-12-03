#include <stdio.h>

typedef struct{
	char nome[20];
	float av1;
	float av2;
	float media;
	char situacao[30];
} TAluno;

int ordenado(TAluno alu[], int tam){
	int i;
	
	for(i=1; i<tam; i++){
		if(alu[i].media > alu[i-1].media){
			return 0;
		} 
		if(alu[i].media == alu[i-1].media){
			if(strcmp(alu[i-1].nome, alu[i].nome) < 0){
				return 1;
			} else {
				return 0;
			}
		}
	}
	
	return 1;
}

void main(){
	TAluno a1 = {"Lumah", 10, 10, 10, "aprovado"};
	TAluno a2 = {"Silvia", 7, 7.5, 7, "aprovado"};
	TAluno a3 = {"Gekyume", 6, 6.3, 7.8, "aprovado"};
	TAluno alunos[3] = {a1, a2, a3};
	int tamA = 3;
	
	if(ordenado(alunos, tamA)){
		printf("ordenado");
	} else {
		printf("nao ordenado");
	}
}

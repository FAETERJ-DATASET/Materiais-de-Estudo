#include <stdio.h>

typedef struct {
	char nome[30];
	char nomeD[4];
	float av1;
	float av2;
} TAluno;

typedef struct {
	char nomeDisc[4];
} TNomeD;

typedef struct {
	char status[15];
} TStatusD;

typedef struct {
	TNomeD nome;
	TStatusD status;
	int qntd;
} TDisc;

void exibirStruct(TDisc *data, int num) {
	int i;
    for (i = 0; i < num; i++) {
        printf("Disciplina: %s\n", data[i].nome.nomeDisc);
        printf("Status: %s\n", data[i].status);
        printf("Quantidade: %d\n\n", data[i].qntd);
    }
}

void gerarStruct(TAluno *alunos, TNomeD *discs, int aT, int dT, TStatusD *statuses, int sT, TDisc *data){
	int i, j, k;
	
	for(i=0; i<dT; i++){ //percorrer as disciplinas
		int apr = 0;
		int emAVF = 0;
		int repr = 0;
		
		for(j=0; j<aT; j++){//percorrer os alunos
			if(strcmp(alunos[j].nomeD, discs[i].nomeDisc) == 0){ //se o aluno pertencer a materia atual
				float media = (alunos[j].av1 + alunos[j].av2)/2; //calcular a media
				if (media >= 6){
					apr++;
				} else {
					if(media >= 4){
						emAVF++;
					} else {
						repr++;
					}
				}
			}
		}
		
		for(k=0; k<sT; k++){//percorrer os status
			switch(k){
				case 0:
					strcpy(data[i*sT + k].nome.nomeDisc, discs[i].nomeDisc);
					strcpy(data[i*sT + k].status.status, statuses[k].status);
					data[i*sT + k].qntd = apr;
					break;
				case 1:
					strcpy(data[i*sT + k].nome.nomeDisc, discs[i].nomeDisc);
					strcpy(data[i*sT + k].status.status, statuses[k].status);
					data[i*sT + k].qntd = emAVF;
					break;
				case 2:
					strcpy(data[i*sT + k].nome.nomeDisc, discs[i].nomeDisc);
					strcpy(data[i*sT + k].status.status, statuses[k].status);
					data[i*sT + k].qntd = repr;
					break;
			}
		}
	}	
}

void main(){
	TAluno p1 = {"Joao", "FAC", 10, 8};
	TAluno p2 = {"Pedro", "ESD", 6, 7};
	TAluno p3 = {"Maria", "FPR", 10, 5};
	TAluno p4 = {"Ana", "FAC", 8, 3};
	TAluno p5 = {"Carlos", "FAC", 7, 7};
	TAluno p6 = {"Paulo", "FPR", 5, 2};
	TAluno p7 = {"Katia", "ESD", 5, 9};
	TAluno p8 = {"Silvia", "FAC", 2, 4};
	TAluno p9 = {"Gloria", "FPR", 4, 1};
	TAluno p10 = {"Antonio", "ESD", 3, 4};
	TAluno alunos[10] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10};
	int alunosTam = 10;
	
	TNomeD d1 = {"FAC"};
	TNomeD d2 = {"FPR"};
	TNomeD d3 = {"ESD"};
	TNomeD discs[3] = {d1, d2, d3};
	int discsTam = 3;
	
	TStatusD s1 = {"aprovado"};
	TStatusD s2 = {"em AVF"};
	TStatusD s3 = {"reprovado"};
	TStatusD statuses[3] = {s1, s2, s3};
	int statusTam = 3;
	
	TDisc data[discsTam*statusTam];
	gerarStruct(alunos, discs, alunosTam, discsTam, statuses, statusTam, data);
	
	exibirStruct(data, discsTam*statusTam);
	return 0;
}

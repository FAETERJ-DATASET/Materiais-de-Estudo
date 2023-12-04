#include <stdio.h>
#define Quant 7

typedef struct{
	int matricula;
	char nome[30];
	char genero;
	float salario;
} TFunc;

void deslocarFuncs(TFunc f[], char g) {
    int i, j;
    TFunc aux;

    for (i = 0; i < Quant; i++) {
        if (f[i].genero == g) {
            for (j = i; j > 0 && f[j - 1].genero != g; j--) {
                aux = f[j];
                f[j] = f[j - 1];
                f[j - 1] = aux;
            }
        }
    }

    for (i = 0; i < Quant; i++) {
        printf("%d %s %c %.1f\n", f[i].matricula, f[i].nome, f[i].genero, f[i].salario);
    }
}


int main(){
	
	TFunc f1 = {1, "Davi", 'M', 10.000};
	TFunc f2 = {2, "Lu", 'F', 10.000};
	TFunc f3 = {3, "Luana", 'F', 30.000};
	TFunc f4 = {4, "Teka", 'F', 30.000};
	TFunc f5 = {5, "Andre", 'M', 30.000};
	TFunc f6 = {6, "Isi", 'F', 30.000};
	TFunc f7 = {7, "Luis", 'M', 30.000};
	
	TFunc funcs[Quant] = {f1, f2, f3, f4, f5, f6, f7};
	
	/*
		Pede-se uma função que, dado um gênero,
	desloque todos os funcionários deste gênero
	para o início do vetor (e, consequentemente, os
	funcionários do outro gênero ficarão ao final do
	conjunto). 
													*/
													
	char genero = 'M';
	deslocarFuncs(funcs, genero);
	
	return 0;
}

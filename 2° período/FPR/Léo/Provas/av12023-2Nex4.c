#include <stdio.h>

float calDef(int v[], int n1, int n2, int i, int qntd, int soma){
	if(i <= n2){
		qntd++;
		soma += v[i];
		return calDef(v, n1, n2, i+1, qntd, soma);
	} else {
		return (float)soma/qntd;
	}
}

float calcularMedia(int v[], int n1, int n2){
	int i = n1; //contador
	int qntd = 0, soma = 0;
	return calDef(v, n1, n2, i, qntd, soma);
}

void main(){
	int vetor[5] = {10, 15, 18, 23, 8};
	int num1 = 0; //supondo que num1 < num 2
	int num2 = 1;
	int tam = 5;
	
	if((num2 > tam-1)||(num1 < 0)){
		printf("\ninvalido");
	} else {
		float res = calcularMedia(vetor, num1, num2);
		printf("%.2f", res);	
	}
}

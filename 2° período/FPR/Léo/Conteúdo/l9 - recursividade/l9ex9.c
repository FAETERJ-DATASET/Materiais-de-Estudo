#include <stdio.h>

int analisarVetDef(int v[], int quant, int r, int i, int rDef){
	if(i < quant-1){
		r = v[i+1] - v[i];
		
		if(r == rDef){
			return analisarVetDef(v, quant, r, i+1, rDef);
		} else {
			return 0;
		}
	}
	return 1;
}

int analisarVet(int v[], int quant){
	int r; //razão entre os numeros, variante
	int i = 0; //item a ser analisado
	int rDef = v[1] - v[0]; //a razao entre os 2 primeiros
	
	if(analisarVetDef(v, quant, r, i, rDef)){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int vetor[5] = {1, 2, 3, 4, 5};
	int quant = 5;
	
	if(analisarVet(vetor, quant)){
		printf("\neh PA");
	} else {
		printf("\nn eh PA");
	}
	return 0;
}

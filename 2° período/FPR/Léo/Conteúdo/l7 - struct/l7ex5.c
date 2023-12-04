#include <stdio.h>

typedef struct {
	int semestre;
	int ano;
	float media;
} THist;

typedef struct {
	char codigo[10];
	char nome[90];
	int creditos;
} TDisc;

void mostrarHistorico(TDisc d[], THist h[], int tamD, int tamH){
	int i;
	float numerador = 0;
	float denominador = 0;
	float CR;
	
	for(i=0; i<tamD; i++){
		printf("\n%s (%s)\t%.1f", d[i].nome, d[i].codigo, h[i].media);
		
		numerador += ((d[i].creditos) * (h[i].media));
		denominador += d[i].creditos;
	}
	
	CR = numerador/denominador;
	printf("\nCoeficiente de rendimento: %.1f", CR);
	
}

void main(){
	TDisc d1 = {"123", "REQ", 3};
	TDisc d2 = {"456", "LES", 2};
	TDisc d3 = {"789", "CAW", 5};
	TDisc d[3] = {d1, d2, d3};
	int tamD = 3;
	
	THist alu_d1 = {1, 2023, 8.3};
	THist alu_d2 = {2, 2022, 9};
	THist alu_d3 = {1, 2024, 7.5};
	THist h[3] = {alu_d1, alu_d2, alu_d3};
	int tamH = 3;
	
	mostrarHistorico(d, h, tamD, tamH);
}

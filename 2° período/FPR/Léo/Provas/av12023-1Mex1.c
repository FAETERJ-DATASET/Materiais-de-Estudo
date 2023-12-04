#include <stdio.h>
#define QUANT 5

int analisarMat(int m[QUANT][QUANT], int quant){
	int somaDP = 0;
	int somaAB = 0;
	int somaAC = 0;
	int i, j;
	
	//soma da diagonal principal
	for(i=0; i < quant; i++){
		somaDP += m[i][i];
	}
	printf("\nvalor de DP: %d", somaDP);
	
	//soma dos numeros acima
	for(i=0; i < quant-1; i++){
		for(j=1+i; j<quant; j++){
			somaAC += m[i][j];
		}
	}
	printf("\nvalor de AC: %d", somaAC);
	
	if(somaDP != somaAC){
		return 0;
	} else {
		//soma dos numeros abaixo
		for(i=quant-1; i>-1; i--){
			for(j=i-1; j >-1; j--){
				somaAB += m[i][j];
			}
		}
		printf("\nvalor de AB: %d", somaAB);
		
		if(somaAB != somaAC){
			return 0;
		} else {
			return 1;
		}
	}
}

void main(){
	int matriz[5][5] = {/*matriz que retorna 1
	{6, 3, 1, 2, 6},
	{1, 3, 5, 4, 2},
	{3, 4, 4, 2, 2},
	{5, 9, 1, 9, 3},
	{4, 0, 2, 1, 8}*/
	
	// matriz que retorna 0
	{1, 8, 5, 9, 4},
	{2, 5, 4, 6, 5},
	{4, 1, 2, 3, 6},
	{4, 5, 5, 8, 7},
	{4, 2, 5, 6, 9}
	};
	
	int quant = 5;
	
	if(analisarMat(matriz, quant)){
		printf("\ndeu 1");
	} else {
		printf("\ndeu 0");
	}
}

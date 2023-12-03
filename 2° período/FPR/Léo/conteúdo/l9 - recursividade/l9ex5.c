#include <stdio.h>

void pGeo2(int a1, int q, int n, int qntd){
	if(qntd < n){
		printf("%d ", a1);
		return pGeo2(a1*q, q, n, qntd+1);
	}	
}

void pGeometrica(int a1, int q, int n){
	int qntd=0;
	
	pGeo2(a1, q, n, qntd);
}

void main(){
	int a1 = 2;
	int q = 2;
	int n = 8;
	
	pGeometrica(a1, q, n);
}

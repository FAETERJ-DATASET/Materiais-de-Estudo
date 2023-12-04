#include <stdio.h>
#include <string.h>

int charDist(char s[], int tam){
	int i;
	int caracteres = 0;
	
	for(i=0; i<tam; i++){
		char letraAtual = s[i];
		int repetido = 0;
		int j;
		
		//compara com o que veio antes
		for(j=i; j>=0; j--){
			if((s[j] == letraAtual)&&(j != i)){
				repetido = 1;
				break;
			}
		}
		
		if(!repetido){
			caracteres++;
		}
	}
	
	return caracteres;
}

void main(){
	char s[] = "paralelepipedo";
	int tam = strlen(s);
	
	int caracteres = charDist(s, tam);
	
	printf("a quantidade de caracteres distintos eh %d", caracteres);
}

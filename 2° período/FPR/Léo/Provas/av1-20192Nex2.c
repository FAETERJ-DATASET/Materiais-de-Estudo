#include <stdio.h>
#include <string.h>

/*			licença poética: 

s1: string de informações ex. "Amarildo | 21 anos |";
s2: informação a ser buscada ex. "21 anos |"
s3: 1

	funcao deve verificar se s2 é a posição s3 em s1
*/

int verificar(char s1[], char s2[], int s3, int t1, int t2){
	int i, j, k, barraAntes = 0, barraNum = s3+1, barraFreq = 0, pos;
	//se s3=0, eu procuraria o 1° |...
	//se s3=1, eu procuraria o 2° |...
	
	for(i=0; i<t1; i++){
		if(s1[i] == '|'){
			
			barraFreq++;
			
			if(barraFreq == barraNum){
				pos = i;
				break; //ja achei oq procurava, fim
			} else {
				barraAntes = i;	
			}
		}
	}
	//printf("\nbarraFreq %d, barranum %d, barraantes %d, pos %d", barraFreq, barraNum, barraAntes, pos);
	//analisar se a informação que eu procuro está entre barraAntes e pos
	if(!barraAntes){
		barraAntes--;
	}
	
	for(j=barraAntes+1, k=0; j<=pos, k<t2; j++, k++){
		if(s1[j] != s2[k]){
			//printf("\ncomparando %c com %c", s1[j], s2[k]);
			return 0;
		}
	}
	return 1;
}

void main(){
	char s1[] = "Amarildo|21 anos|Homem|";//2 informações
	char s2[] = "21 anos";
	int s3 = 1; //s3 começa com 0 e vai até o número de informações presentes na string - 1
	int t1 = strlen(s1);
	int t2 = strlen(s2);
	
	if(verificar(s1, s2, s3, t1, t2)){
		printf("sim");
	} else {
		printf("nao");
	}
}

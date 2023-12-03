#include <stdio.h>
#include <string.h>

/*			licen�a po�tica: 

s1: string de informa��es ex. "Amarildo | 21 anos |";
s2: informa��o a ser buscada ex. "21 anos |"
s3: 1

	funcao deve verificar se s2 � a posi��o s3 em s1
*/

int verificar(char s1[], char s2[], int s3, int t1, int t2){
	int i, j, k, barraAntes = 0, barraNum = s3+1, barraFreq = 0, pos;
	//se s3=0, eu procuraria o 1� |...
	//se s3=1, eu procuraria o 2� |...
	
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
	//analisar se a informa��o que eu procuro est� entre barraAntes e pos
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
	char s1[] = "Amarildo|21 anos|Homem|";//2 informa��es
	char s2[] = "21 anos";
	int s3 = 1; //s3 come�a com 0 e vai at� o n�mero de informa��es presentes na string - 1
	int t1 = strlen(s1);
	int t2 = strlen(s2);
	
	if(verificar(s1, s2, s3, t1, t2)){
		printf("sim");
	} else {
		printf("nao");
	}
}

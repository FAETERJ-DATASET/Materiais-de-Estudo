#include <stdio.h>

int determinar(char s1[], char s2[], int t1, int t2){
	int i, j, k, freqs1 = 0, freqs2 = 0, repetida = 0;
	char letraAtual;
	
	for(i=0; i<t1; i++){
		freqs1 = 0, freqs2 = 0;
		letraAtual = s1[i];
		
		//caso repetida em s1, nao analise pq ja foi analisada
		if(i>0){
			for(j=0; j<i-1; j++){
				if(s1[j] == letraAtual){
					repetida = 1;
					printf("\nnao vou analisar pq '%c' eh repetida em s1!", s1[j]);
					break;
				}
			}	
		}
		
		if(!repetida){
			//ver quantas vezes essa letra (que aparece pela primeira vez) aparece em s1
			for(k=0; k<t1; k++){
				if(s1[k] == letraAtual){
					freqs1++;
				}
			}
			
			//ver se a freqs2 coincide com freqs1
			for(k=0; k<t2; k++){
				if(s2[k] == letraAtual){
					freqs2++;
				}
			}
			
			printf("\n%c --- freqs1 = %d e freqs2 = %d", letraAtual, freqs1, freqs2);
			
			if(freqs2 != freqs1){
				printf("\nsao diferentes!");
				return 0;
			}
		}
	}
	return 1;
	/*i=0; s1[0]=v*/
}

void main(){
	char s1[] = "ana maria braga";
	char s2[] = "a riama na gabra";
	int t1 = strlen(s1);
	int t2 = strlen(s2);
	
	if(determinar(s1, s2, t1, t2)){
		printf("\npossui na mesma quantidade");
	} else {
		printf("\nnao possui na mesma quantidade");
	}
}

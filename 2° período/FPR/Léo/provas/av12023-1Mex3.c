#include <stdio.h>
#include <string.h>

void criarStrings(char s1[], char s2[], int t1, int t2){
	int i, j, k;
	char s3[t1+t2]; //tamanho provisorio
	char s4[t1+t2]; //tamanho provisorio
	int t3 = 0;
	int t4 = 0;

	for(i=0; i<t1; i++){
		char letraAtual = s1[i];
		int repetidaS2 = 0;
		int repetidaS3 = 0;
		int repetidaS4 = 0;
		
		//checar se a letraAtual (caso repetida em s1) ja nao exista em s3
		for(j=0; j<t3; j++){
			if(s3[j] == letraAtual){
				repetidaS3 = 1;
				break;
			}
		}
		
		//checar se a letraAtual (caso repetida em s1) ja nao exista em s4
		for(j=0; j<t4; j++){
			if(s4[j] == letraAtual){
				repetidaS4 = 1;
				break;
			}
		}
		
		if((!repetidaS3) && (!repetidaS4)){//caso a letra nao exista em s3 nem s4, ver se existe em s2
			for(k=0; k<t2; k++){
				if(s2[k] == letraAtual){//se existir, adicionar a s3
					s3[t3] = letraAtual;
					repetidaS2 = 1;
					t3++;
					break;
				}
			}
			
			if(!repetidaS2){//se nao existir, adicionar a s4
				s4[t4] = letraAtual;
				t4++;
			}
		}
	}
	s3[t3] = '\0'; //terminar t3
	s4[t4] = '\0'; //terminar t4
	
	printf("s3 sera igual a %s", s3);
	printf("\ns4 sera igual a %s", s4);
}

void main(){
	char s1[] = "paralelepipedo";
	char s2[] = "dentista";
	int tam1 = strlen(s1);
	int tam2 = strlen(s2);
	
	criarStrings(s1, s2, tam1, tam2);
	
	return 0;
}

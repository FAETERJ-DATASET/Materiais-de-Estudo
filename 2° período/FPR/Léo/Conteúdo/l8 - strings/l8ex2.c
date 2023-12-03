#include <stdio.h>
#include <string.h>

int criarString(char s1[], char s2[], char s3[], int t1, int t2);

int criarString(char s1[], char s2[], char s3[], int t1, int t2){
	//vai entrar em s3 apenas caracteres que pertençam a s1 que não pertençam a s2
	//ou seja: S, U, H
	
	int i;
	int t3 = 0;
	
	for(i=0; i<t1; i++){ //varrer s1
		char letraAtual = s1[i];
		int repetido = 0;
		int j;
		
		for(j=0; j<t2; j++){ //varrer s2
			if(s2[j] == letraAtual){
				repetido = 1;
				break;
			}
		}
		
		//verificar se a letra ja existe em s3
		if(!repetido){
			int repetidoS3 = 0;
			for(j=0; j<t3; j++){//varrer s3
				if(s3[j] == letraAtual){
					repetidoS3 = 1;
					break;
				}
			}
			
			if(!repetidoS3){
				s3[t3] = letraAtual;
				t3++;
			}
		}
	}
	
	s3[t3] = '\0';
	return t3;
}

void main(){
	char s1[] = "sushi";
	char s2[] = "davi";
	char s3[0];
	int tam1 = strlen(s1);
	int tam2 = strlen(s2);
	
	int tam3 = criarString(s1, s2, s3, tam1, tam2);
	
	int i;
	printf("imprimindo s3:\n");
	for(i=0; i<tam3; i++){
		printf("%c", s3[i]);
	}
}

#include <stdio.h>
#include <string.h>

int charComum(char s1[], char s2[], int t1, int t2, int i, char s3[], int t3){
	if(i < t1){
		//verificar se a letra (caso repetida em s1) ja nao se encontra em S3
		int j;
		int repetida = 0;
		
		for(j=0; j<t3; j++){
			if(s1[i] == s3[j]){
				repetida = 1;
				break;
			}
		}
		
		if(!repetida){//verificar se a letra em s1 pertence a s2
			int k;
			for(k=0; k<t2; k++){
				if(s1[i] == s2[k]){
					s3[t3] = s2[k];
					t3++;
					break;
				}
			}
		}
		return charComum(s1, s2, t1, t2, i+1, s3, t3);
	}
	return t3;
}

int charComumSis(char s1[], char s2[], int t1, int t2){
	int i = 0;//qntd de letras analisadas de s1
	char s3[100]; //vetor que armazenara as letras em comum
	int tam3 = 0; //futuro tamanho de s3
	
	return charComum(s1, s2, t1, t2, i, s3, tam3);
}

void main(){
	char s1[] = "lumah";
	char s2[] = "acerola";
	int tam1 = strlen(s1);
	int tam2 = strlen(s2);
	
	int retorno = charComumSis(s1, s2, tam1, tam2);
	
	printf("%d", retorno);
}

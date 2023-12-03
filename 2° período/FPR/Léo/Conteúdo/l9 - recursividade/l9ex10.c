#include <stdio.h>
#include <string.h>

int remocoesDef(char s[], int tam, char ch, int i, int remov){
	if(i < tam){
		if(s[i] == ch){
			remov++;
			int j;
			for(j=i; j<tam-1; j++){
				s[j] = s[j+1];
			}
			tam--;
			s[tam] = '\0';
		} else {
			i++;
		}
		return remocoesDef(s, tam, ch, i, remov);
	}
	return remov;
}

int remocoes(char s[], int tam, char ch){
	int i = 0;
	int remov = 0;
	
	return remocoesDef(s, tam, ch, i, remov);
}

void main(){
	char string[] = "abba";
	int tam = strlen(string);
	char ch = 'a';
	
	int resultado = remocoes(string, tam, ch);
	printf("resultado = %d\n", resultado);
	printf("string = %s", string);
	
	return 0;
}

#include <stdio.h>
#include <string.h>

void exibirS(char s[], int t);
void exibirS2(char s[], int t, int i);

void exibirS2(char s[], int t, int i){
	if ((i <= t) && (i >= 0)){
		printf("%c", s[i]);
		exibirS2(s, t, i-1);
	}
}

void exibirS(char s[], int t){
	int i=t; //variavel contadora
	
	exibirS2(s, t, i);
}

void main(){
	char string[] = "lumah";
	int tam = strlen(string);
	
	exibirS(string, tam);
} 

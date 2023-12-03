#include <stdio.h>
#include <string.h>

int palin(char s[], int tam, int qntd, int aux){
	if(aux <= qntd){
		printf("comparando %c - %c...\n", s[aux], s[tam-aux]);
		if(s[aux] == s[tam-aux]){
			return palin(s, tam, qntd, aux+1);
		} else {
			printf("Nao eh palindromo !!!");
			return 0;
		}
	}
	return 1;
	
	/*
		"renner", 5, 2, 0 
		s[0] == s[5-0] ?
		return(s, 5, 2, 1)
		s[1] == s[4]?
		return(s, 5, 2, 2)
		s[2] == s[3]?
		return(s, 5, 2, 3)
	*/
}

void palindromo(char s[], int tam){
	/*como conferir se é um palindromo?
	renner, tam 5
	s[0] == s[5]?
	s[1] == s[4]?
	s[2] == s[3]?
	
	caso fosse par, abba
	s[0] == s[3]
	s[1] == s[2]
	*/
	
	//excluindo o '\0' da comparacao
	tam--;
	
	//variavel que determina ate que letra eu vou analisar
	int qntd = tam/2;
	
	//variavel contadora
	int aux = 0;
	
	if(palin(s, tam, qntd, aux)){
		printf("Eh palindromo !!!");
	}
	
}

void main(){
	char s[] = "renner";
	int tam = strlen(s);
	
	palindromo(s, tam);
}

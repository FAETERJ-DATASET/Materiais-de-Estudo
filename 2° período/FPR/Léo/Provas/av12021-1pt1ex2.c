#include <stdio.h>
#include <string.h>

int validarSenha(char s[], int tam){
	//variaveis
	int i, j, algarismos = 0, letraMaiu = 0, letraMinu = 0, freq = 0;

	for(i=0; i < tam; i++){
		if((s[i] >= '0')&&(s[i] <= '9')){
			algarismos++;
			//algarismos em posicoes vizinhas
			if((s[i-1] >= '0')&&(s[i-1]<='9')&&(i >= 1)){
				printf("\nregra 3");
				return 0;
			}
		}
		if((s[i] >= 'A')&&(s[i] <= 'Z')){
			letraMaiu++;
		}
		if((s[i] >= 'a')&&(s[i] <= 'z')){
			letraMinu++;
		}
		
		//analisar caracteres repetidos
		freq = 0;
		for(j=0; j < tam; j++){
			if(s[i] == s[j]){
				freq++;
			}
			
			if(freq > 2){
				printf("\nregra 7");
				return 0;
			}
		}
	}
	
	//1 a 3 algarismos
	if((algarismos < 1)||(algarismos > 3)){
		printf("\nregra 2");
		return 0;
	}
	//pelo menos 1 letra maiuscula
	if(!letraMaiu){
		printf("\nregra 5");
		return 0;
	}	
	//pelo menos 1 letra minuscula
	if(!letraMinu){
		printf("\nregra 6");
		return 0;
	}
	//6 a 10 caracteres
	if((tam < 6) || (tam > 10)){
		printf("\nregra 1");
		return 0;
	}
	return 1;
}

void main(){
	char senha[11] = "Lum4ha#2";
	int tam = strlen(senha);
	
	if(validarSenha(senha, tam)){
		printf("eh valida");
	} else {
		printf("n eh valida");
	}
}

#include <stdio.h>
#include <string.h>

int determinar(char s[], int tam){
	int i, j, distinto = 0;
	
	for(i=0; i<tam; i++){
		char letraAtual = s[i];
		int repetido = 0;
		
		for(j=i+1; j<tam; j++){
			if(s[j] == letraAtual){
				repetido = 1;
				break;
			}
		}
		
		if(!repetido){
			distinto++;
		}
	}
	return distinto;
}

void main(){
	char string[] = "abababab";
	int tam = strlen(string);
	int res;
	
	res = determinar(string, tam);
	
	printf("%d", res);
	return 0;
}

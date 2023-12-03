#include <stdio.h>

int binario(int num){
	if(num/2 == 1){
		printf("1");
	} 
	if(num>=2){
		binario(num/2);
		printf("%d", num%2);
	}
}

void main(){
	int num = 2603;
	binario(num);
}

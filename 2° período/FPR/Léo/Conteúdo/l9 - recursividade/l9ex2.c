/*
	return funcao(9,7)//16 					+						 funcao (5,5)
	return funcao(8,9) 		+ 		funcao(2,7) /// 9+7 = 16		 funcao(3,5)
	return funcao(6,9)				funcao(0,7)						 funcao(1,5)
	return funcao(4,9)				return  7;						funcao(-1,5)
	return funcao(2,9)												return 5;
	return funcao(0,9)
	return 9;
	
	16+5=21

*/

#include <stdio.h>
int funcao (int a, int b) {
	if (a > 0) {
		if (a > b) {
			return funcao (a-1, b+2) + funcao (b-a, b);
		} else {
		return funcao (a-2, b);
		}
	} else {
		return b;
	}
}

void main () {
	printf ("Resposta = %d", funcao (10, 5));
}

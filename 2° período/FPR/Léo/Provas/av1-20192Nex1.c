#include <stdio.h>

/*int funcao (int a, int b){
	if (a>0){
		if (a>b){
			return funcao(a-1, b+2) + funcao (b-a, b);
		} else {
			return funcao (a-2, b);
		}
	} else {
		return b;
	}
}

void main(){
	printf("resposta = %d", funcao(10,5));
}*/



/*
funcao(10,5)
return funcao(9,7) == [9+7] == [16]         +                     funcao (5,5) == [5]
return funcao (8,9) == [9]    +     funcao(2, 7) == [7]           funcao (3,5)
return (6, 9)						funcao(0,7)					  funcao (1, 5)
return (4, 9)						return 7;					  funcao (-1, 5)
return (2, 9)													  return 5	
return (0, 9)
return 9

16+5 = 21
resposta = 21
*/

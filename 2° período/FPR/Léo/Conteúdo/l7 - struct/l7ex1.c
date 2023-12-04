/*		Uma loja de automóveis mantém os carros à
		venda sob a forma de um vetor de structs
		contendo as seguintes informações, para cada
		veículo: placa, modelo, marca, cor,
		quilometragem, ano modelo/fabricação (deve
		ser um struct), valor e tipo (usado ou 0 km,
		conforme o valor do campo quilometragem).
		
		Pede-se a declaração de uma variável que
		represente o estoque de veículos da loja,
		incluindo todas as declarações de tipos que
		possam ser necessárias.
		
		Além disso, implementar as seguintes funções:
		i. Exibir todos os carros do modelo m, ano de
		fabricação entre a1 e a2 (inclusive), com
		valor não superior a x reais;
		
		ii. Reajustar os valores de todos os carros 0
		km, considerando um aumento de p %;
		
		iii. Retirar do estoque um determinado veículo,
		dada a sua placa. 								*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int fabricacao;
    int modelo;
} TAno;

typedef struct {
    char placa[9];
    char modelo[20];
    char marca[20];
    char cor[20];
    float quilometragem;
    TAno ano;
    float valor;
    char tipo[10];
} TCarro;

void filtrarCarros(TCarro car[], char m[], int ano1, int ano2, float x, int quant);
void reajusteValor(TCarro car[], float x, int quant);
void retirarDoEstoque(TCarro car[], char pl[], int quant);

void filtrarCarros(TCarro car[], char m[], int ano1, int ano2, float x, int quant){
    int i;
    for (i = 0; i < quant; i++) {
        if ((strcmp(car[i].modelo, m) == 0) && (car[i].ano.fabricacao >= ano1) && (car[i].ano.fabricacao <= ano2) && (car[i].valor <= x)) {
            printf("%-4s\t %-23s %-23s %-15s %-5.1f %-5d %-5d %-6.1f %-7s \n", car[i].placa, car[i].modelo, car[i].marca, car[i].cor, car[i].quilometragem, car[i].ano.fabricacao, car[i].ano.modelo, car[i].valor, car[i].tipo);
        }
    }
}

void reajusteValor(TCarro car[], float x, int quant){
	int i;
	x = x/100 + 1;
	for(i=0; i<quant; i++){
		if(car[i].quilometragem == 0){
			car[i].valor *= x;
			printf("%-4s\t %-23s %-23s %-15s %-5.1f %-5d %-5d %-6.1f %-7s \n", car[i].placa, car[i].modelo, car[i].marca, car[i].cor, car[i].quilometragem, car[i].ano.fabricacao, car[i].ano.modelo, car[i].valor, car[i].tipo);
		}
	}
}

void retirarDoEstoque(TCarro car[], char pl[], int quant){
	int i, j;
    for (i = 0; i < quant; i++) {
        if (strcmp(car[i].placa, pl) == 0) {
            //substituir a entrada atual pela próxima e assim por diante
            for (j = i+1; j < quant; j++){
            	car[i] = car[j];
			}
			
			quant--;
        }
    }
    /*for(i=0; i<quant; i++){
    	printf("%-4s\t %-23s %-23s %-15s %-5.1f %-5d %-5d %-6.1f %-7s \n", car[i].placa, car[i].modelo, car[i].marca, car[i].cor, car[i].quilometragem, car[i].ano.fabricacao, car[i].ano.modelo, car[i].valor, car[i].tipo);
	}*/
}

int main() {
    TCarro carro1 = {"12345678", "Peugeot 208", "Peugeot", "Grafite", 0, {2022, 2022}, 25000, "Novo"};
    TCarro carro2 = {"87654321", "Fusca", "Volkswagen", "Azul", 200, {2010, 2010}, 10000, "Seminovo"};
    int quant = 2;
    TCarro carros[2] = {carro1, carro2};
    // i. Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor não superior a x reais;
    char modelo[] = "Fusca";
    int a1 = 2010;
    int a2 = 2011;
    float valor = 24000;
    //filtrarCarros(carros, modelo, a1, a2, valor, quant);
    //ii. Reajustar os valores de todos os carros 0 km, considerando um aumento de p %;
    float p = 10;
    //reajusteValor(carros, p, quant);
    //iii. Retirar do estoque um determinado veículo, dada a sua placa.
    char placa[] = "12345678";
    //retirarDoEstoque(carros, placa, quant);
    return 0;
}

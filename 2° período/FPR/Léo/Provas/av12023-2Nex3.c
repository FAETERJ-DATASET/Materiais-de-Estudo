#include <stdio.h>
#include <string.h>

typedef struct {
    char palavras[30];
    int vogais;
    int consoantes;
} TStruct;

void criarVetor(char s[], TStruct v[], int *quant) {
    int i, j, k, inicio = 0, vogais = 0, consoantes = 0, fim;

    for (i=0; s[i] != '\0'; i++) {
        if ((s[i] >= 'A') && (s[i] <= 'Z')) { // é letra
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vogais++;
            } else {
                consoantes++;
            }
        } else { // fim da palavra
            if ((i > 0)&&(s[i - 1] >= 'A')&&(s[i - 1] <= 'Z')){
                fim = i;

                for (j = inicio, k = 0; j < fim; j++, k++) {
                    v[*quant].palavras[k] = s[j];
                }
                v[*quant].palavras[k] = '\0';
                v[*quant].vogais = vogais;
                v[*quant].consoantes = consoantes;
                (*quant)++;
                vogais = 0;
                consoantes = 0;
            }
            inicio = i + 1;
        }
    }

    // Check if there's a word at the end of the string
    if (vogais > 0 || consoantes > 0) {
        fim = i;
        
        for (j = inicio, k = 0; j < fim; j++, k++) {
            v[*quant].palavras[k] = s[j];
        }
        v[*quant].palavras[k] = '\0';
        v[*quant].vogais = vogais;
        v[*quant].consoantes = consoantes;
        (*quant)++;
    }
}

int main() {
    char string[] = "CARALHO-DE!ASA";

    TStruct vetor[100]; //tamanho provisório
    int quant = 0;

    criarVetor(string, vetor, &quant);

    int m;
    for (m = 0; m < quant; m++) {
        printf("\n%s %d %d", vetor[m].palavras, vetor[m].vogais, vetor[m].consoantes);
    }

    return 0;
}


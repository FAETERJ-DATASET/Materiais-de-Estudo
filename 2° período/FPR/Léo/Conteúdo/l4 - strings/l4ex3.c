/*Desenvolver uma função que, dada uma string
s, crie uma substring que inicie na posição p de
s e contenha n caracteres.

Observações: se p e/ou n forem inválidos, a
substring será vazia; ii) se s não possuir n
caracteres além de p, a substring a ser criada
começará em p e terminará no final de s.*/

#include <stdio.h>
#include <string.h>

void criarSubstring(char string[], int pos, int quant, char subString[]);

int main() {
    char s[20];
    char subS[20];
    int p, n;

    printf("\nInsira uma string (até 20 char): ");
    gets(s);

    printf("\nEm qual posição se iniciará a substring? ");
    scanf("%d", &p);
    p--;

    printf("\nQuantos caracteres terá a substring? ");
    scanf("%d", &n);

    if (p < 0 || n <= 0 || p >= strlen(s)) {
        printf("\nValores inválidos!");
    } else {
        criarSubstring(s, p, n, subS);
        printf("\nSubstring: %s", subS);
    }

    return 0;
}

void criarSubstring(char string[], int pos, int quant, char subString[]) {
    int i, j = 0;

    for (i = pos; j < quant; i++, j++) {
        subString[j] = string[i];
    }
    subString[j] = '\0';
}

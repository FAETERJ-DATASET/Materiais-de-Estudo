#include <stdio.h>
#include <string.h>

int removeCaracteres(char s[], int p1, int p2) {
    int tam = strlen(s);
    int i, j;

    if (p1 < 0 || p2 < 0 || p1 >= tam || p2 >= tam || p1 > p2) {
        return 0; 
    }

    // Mover os caracteres da posição p2+1 até o final da string
    for (i = p2 + 1, j = p1; i <= tam; i++, j++) {
        s[j] = s[i];
    }

    return 1;
}

int main() {
    char s[] = "Exemplo de string";
    int p1 = 7; 
    int p2 = 9; 

    int resultado = removeCaracteres(s, p1, p2);

    if (resultado == 1) {
        printf("String apos a remocao: %s\n", s);
    } else {
        printf("Posições invalidas, a remoção não foi realizada.\n");
    }

    return 0;
}


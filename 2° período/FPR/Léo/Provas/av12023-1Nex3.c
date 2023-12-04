#include <stdio.h>
#include <string.h>

typedef struct {
	char letra;
	int qntd;
} TLetra;

int analisarStringsDef(char s1[], char s2[], int t1, int t2, TLetra letras[], int *tL) {
    int i, j;

    for (i = 0; i < t1; i++) {
        char letraAtual = s1[i];
        int repetidaS1 = 0;
        int repetidaS2 = 0;

        // Verificar se a letra atual (caso repetida em s1) já não está no struct de caracteres
        for (j = 0; j < *tL; j++) {
            if (letras[j].letra == letraAtual) {
                repetidaS1 = 1;
                letras[j].qntd += 1;
                break;
            }
        }

        // Verificar se a letra não repetida se encontra em s2
        if (!repetidaS1) {
            for (j = 0; j < t2; j++) {
                if (s2[j] == letraAtual) {
                    repetidaS2 = 1;
                    letras[*tL].letra = letraAtual;
                    letras[*tL].qntd = 1;
                    (*tL)++;
                    break;
                }
            }
            // Nem todos os caracteres de s1 estão em s2
            if (!repetidaS2) {
                return 0;
            }
        }
    }

    // Ver quantas vezes a letra em comum a s1 e s2 aparece em s2
    for (i = 0; i < *tL; i++) {
        char letraAtual = letras[i].letra;
        int frequencia = 0;

        for (j = 0; j < t2; j++) {
            if (s2[j] == letraAtual) {
                frequencia++;
            }
        }

        if (frequencia != letras[i].qntd) {
            return 1;
        }
    }
    return 2;
}

int analisarStrings(char s1[], char s2[], int t1, int t2) {
    TLetra letras[10]; // Tamanho provisório
    int tamL = 0;

    return analisarStringsDef(s1, s2, t1, t2, letras, &tamL);
}

int main() {
    char s1[] = "sapo gordo";
    char s2[] = "ordo gaspo";
    int tam1 = strlen(s1);
    int tam2 = strlen(s2);

    int resultado = analisarStrings(s1, s2, tam1, tam2);

    if (resultado == 0) {
        printf("Não todos os caracteres de s1 estão em s2.\n");
    } else if (resultado == 1) {
        printf("A frequência de caracteres em s2 não coincide com s1.\n");
    } else {
        printf("As strings s1 e s2 são anagramas.\n");
    }
    return 0;
}


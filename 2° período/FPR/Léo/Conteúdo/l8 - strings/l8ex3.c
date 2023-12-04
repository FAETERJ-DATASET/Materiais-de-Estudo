#include <stdio.h>
#include <string.h>

int criarStrings(char s[], int p, char s1[], char s2[], int tamS);

int criarStrings(char s[], int p, char s1[], char s2[], int tamS) {
    // Creating s1
    int i;
    for (i = 0; i < p; i++) {
        s1[i] = s[i];
    }
    s1[p] = '\0';

    printf("\nexibindo S1: ");
    for (i = 0; i < p; i++) {
        printf("%c", s1[i]);
    }

    // Creating s2
    int j = 0;
    for (i = p; i < tamS; i++) {
        s2[j] = s[i];
        j++;
    }
    s2[j] = '\0';

    printf("\nexibindo S2: ");
    for (i = 0; i < j; i++) {
        printf("%c", s2[i]);
    }

    return 1;
}

int main() {
    char string[] = "marmelada";
    int p = 5;
    int tamS = strlen(string);

    char s1[100]; // Provide an initial size for s1, it can be adjusted as needed
    char s2[100]; // Provide an initial size for s2, it can be adjusted as needed

    if ((p < 0) || (p > tamS)) {
        return 0;
    } else {
        criarStrings(string, p, s1, s2, tamS);
    }

    return 0;
}


#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    char genero;
    int idade;
} TEntr;

int retornarPos(TEntr *pessoas, int tam, char g) {
    int i, pos = -1;
    int idadeMaisNova = 200;
    char nomeMaisCedo = 'Z';

    for (i = 0; i < tam; i++) {
        if (pessoas[i].genero == g) {
            if (pessoas[i].idade < idadeMaisNova || 
                (pessoas[i].idade == idadeMaisNova && pessoas[i].nome[0] < nomeMaisCedo)) {
                pos = i;
                idadeMaisNova = pessoas[i].idade;
                nomeMaisCedo = pessoas[i].nome[0];
            }
        }
    }

    return pos;
}

int main() {
    TEntr p1 = {"Josisvaldo", 'H', 24};
    TEntr p2 = {"Menarcules", 'H', 24};
    TEntr p3 = {"Nousilda", 'M', 37};
    TEntr p4 = {"Papisca", 'M', 13};
    TEntr pessoas[4] = {p1, p2, p3, p4};
    int tamP = 4;
    char genero = 'H';

    int res = retornarPos(pessoas, tamP, genero);
    printf("%d", res);

    return 0;
}


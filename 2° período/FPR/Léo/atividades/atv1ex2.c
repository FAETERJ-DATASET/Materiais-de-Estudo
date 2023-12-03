#include <stdio.h>

typedef struct {
    int valor;
    int ocorrencia;
    int posicao;
} TV2;

int preencherV2(int v1[], TV2 v2[], int quant);

int preencherV2(int v1[], TV2 v2[], int quant) {
    int i, j, k = 0;

    for (i = 0; i < quant; i++) {
        int valorAtual = v1[i];
        int valorRepetido = 0;

        // Verificar se o valor já está em V2
        for (j = 0; j < k; j++) {
            if (v2[j].valor == valorAtual) {
                valorRepetido = 1;
                v2[j].ocorrencia++;
                break;
            }
        }

        if (!valorRepetido) {
            v2[k].valor = valorAtual;
            v2[k].ocorrencia = 1;
            v2[k].posicao = i;
            k++;
        }
    }
    return k;
}

int main() {
    int V1[10] = {4, 9, 5, 1, 1, 2, 4, 8, 5, 4};
    TV2 V2[10];
    int quant = 10;

	int j;
    for (j = 0; j < 10; j++) {
        V2[j].valor = 0; // Inicialize todos os valores de V2 com 0
        V2[j].ocorrencia = 0;
        V2[j].posicao = 0;
    }

    int novoTam = preencherV2(V1, V2, quant);

    // Exibir o conteúdo de V2
    for (j = 0; j < novoTam; j++) {
        printf("Valor: %d, Ocorrencia: %d, Posicao: %d\n", V2[j].valor, V2[j].ocorrencia, V2[j].posicao);
    }

    return 0;
}


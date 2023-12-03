#include <stdio.h>
#define TAM 4

typedef struct {
    int dia;
    int mes;
} TData;

typedef struct {
    char nome[15];
    TData aniv;
} TPessoa;

void qntdMes(TPessoa p[], int m){
    int i;
    int quant = 0;
    
    for(i=0; i<TAM; i++){
        if(p[i].aniv.mes == m){
            quant++;
        }
    }
    printf("%d pessoas fazem aniversario no mes %d", quant, m);
}

void pessoasAniv(TPessoa p[], TData d1, TData d2){
    int i;
    for(i=0; i<TAM; i++){
        if(verificar(p[i], d1, d2) == 1){
            printf("\n- %s", p[i].nome);
        }
    }
}

int verificar(TPessoa pessoa, TData d1, TData d2){
    //supondo que data1 < data2
    int data1 = ((d1.mes)-1)*30 + d1.dia;
    int data2 = ((d2.mes)-1)*30 + d2.dia;
    int pessoaData = ((pessoa.aniv.mes)-1)*30 + pessoa.aniv.dia;
        
    if((pessoaData >= data1) && (pessoaData <= data2)){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    TPessoa p1 = {"Lumah", {26, 3}};
    TPessoa p2 = {"Luana", {25, 9}};
    TPessoa p3 = {"Isis", {12, 1}};
    TPessoa p4 = {"Davi", {26, 4}};
    
    TPessoa pessoas[TAM] = {p1, p2, p3, p4};
    
    // Determinar a quantidade de pessoas que fazem aniversário no mês M;
    int mes = 4;
    qntdMes(pessoas, mes);
    
    /* Exibir os nomes de todas pessoas que fazem aniversário
    entre as datas d1 and d2, ambos do tipo TData. */
    TData d1 = {1, 1};
    TData d2 = {31, 1};
    
    printf("\nQuem faz aniversario entre %d/%d e %d/%d", d1.dia, d1.mes, d2.dia, d2.mes);
    pessoasAniv(pessoas, d1, d2);

    return 0;  
}


#include <stdio.h>
#include <stdlib.h>
#define N 100

void InverteVetor(int *vet, int qtd){
    int i, aux;
    for(i=0; i<qtd/2; i++){
        aux = vet[i];
        vet[i] = vet[qtd-(i+1)];
        vet[qtd-(i+1)] = aux;
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i;

    printf("{");

    for(i=0; i<qtd; i++){
        if(i != qtd-1)
            printf("%d, ", vet[i]);
        else
            printf("%d", vet[i]);
    }
    
    printf("}");
}

int main(){
    int vet[N], x, i, n;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &x);
        vet[i] = x;
    }
    
    InverteVetor(vet, n);
    ImprimeDadosDoVetor(vet, n);

    return 0;
}
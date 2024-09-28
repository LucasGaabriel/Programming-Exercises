#include <stdio.h>
#include <stdlib.h>
#define N 100

void OrdenaCrescente(int vet[], int qtd){
    int i, j, aux;

    for(j=0; j<qtd-1; j++){
        for(i=0; i<qtd-1; i++){
            if(vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
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
    int vet[N], i, n, x;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &x);
        vet[i] = x;
    }

    OrdenaCrescente(vet, n);
    ImprimeDadosDoVetor(vet, n);

    return 0;
}
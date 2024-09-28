#include <stdio.h>
#include <stdlib.h>
#define N 100

void TrocaParEImpar(int vet[], int qtd){
    int i, aux;

    for(i=0; i<qtd-1; i+=2){
        aux = vet[i];
        vet[i] = vet[i+1];
        vet[i+1] = aux;
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
    int vetA[N] = {0}, n, i, x;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &x);
        vetA[i] = x;
    }

    TrocaParEImpar(vetA, n);
    ImprimeDadosDoVetor(vetA, n);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define N 100

void lerNumeros(int *vet, int n){
    int i, w;
    for(i=0; i<n; i++){
        scanf("%d", &w);
        vet[i] = w;
    }
}

int ocorrencia(int *vet, int n, int x){
    int i;
    for(i=0; i<n; i++){
        if(vet[i] == x)
            return i;
    }

    return n;
}

int main(){
    int vet[N], n, x, indice;
    
    scanf("%d%d", &x, &n);

    lerNumeros(vet, n);
    indice = ocorrencia(vet, n, x);

    printf("RESP:%d", indice);

    return 0;
}
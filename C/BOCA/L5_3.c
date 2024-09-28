#include <stdio.h>
#include <stdlib.h>
#define N 100

void lerPostes(int *vet, int n){
    int i, x;

    for(i=0; i<n; i++){
        scanf("%d", &x);
        vet[i] = x;
    }
}

void verificaMaiores(int *vet, int n){
    int i, maior = 0;

    for(i=0; i<n-1; i++){
        if(abs(vet[i]-vet[i+1]) > maior)
        maior = abs(vet[i]-vet[i+1]);
    }

    for(i=0; i<n-1; i++){
        if(abs(vet[i]-vet[i+1]) == maior)
            printf("(%d %d) ", i, i+1);
    }

    if(n == 1)
        printf("IMPOSSIVEL");
}

int main(){
    int vet[N], n;

    scanf("%d", &n);

    lerPostes(vet, n);

    verificaMaiores(vet, n);

    return 0;
}
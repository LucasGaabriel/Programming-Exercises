#include <stdio.h>
#include <stdlib.h>
#define N 100

void ordenaVetores(int *vetA, int *vetB, int n1, int n2){
    int i, j, aux;

    for(i=0; i<n1-1; i++){
        for(j=0; j<n1-1; j++){
            if(vetA[j] > vetA[j+1]){
                aux = vetA[j];
                vetA[j] = vetA[j+1];
                vetA[j+1] = aux;
            }
        }
    }

    for(i=0; i<n2-1; i++){
        for(j=0; j<n2-1; j++){
            if(vetB[j] > vetB[j+1]){
                aux = vetB[j];
                vetB[j] = vetB[j+1];
                vetB[j+1] = aux;
            }
        }
    }
}

void saida(int *vetA, int *vetB, int n1, int n2){
    int i;
    ntotal = n1+n2;
    for(i=0; i<ntotal; i++){
        
    }
}

int main(){
    int vetA[N], vetB[N], i, x, n1, n2;

    scanf("%d", &n1);

    for(i=0; i<n1; i++){
        scanf("%d", &x);
        vetA[i] = x;
    }

    scanf("%d", &n2);

    for(i=0; i<n2; i++){
        scanf("%d", &x);
        vetB[i] = x;
    }

    ordenaVetores(vetA, vetB, n1, n2);
    saida(vetA, vetB, n1, n2);


    return 0;
}
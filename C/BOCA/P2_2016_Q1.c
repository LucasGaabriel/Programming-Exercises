#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
    int n, numeros[N], i, x, pares = 0, impares = 0;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &x);
        numeros[i] = x;
    }

    if(numeros[0] % 2 == 0){
        for(i=0; i<n; i++){
            if(numeros[i] % 2 == 0)
                pares++;
        }
        printf("QTD PARES:%d", pares);
    }
    else{
        for(i=0; i<n; i++){
            if(!(numeros[i] % 2 == 0))
                impares++;
        }
        printf("QTD IMPARES:%d", impares);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define N 100

void verificaProg(int *vet, int n){
    int i, y, ok = 0, razao1, razao;
    
    razao = vet[1] - vet[0];

    for(i=0; i<n-1; i++){
        razao1 = vet[i+1] - vet[i];

        if(razao1 == razao){
            ok++;
        }
    }

    if(ok == n-1 && n != 1)
        printf("RESP:%d", razao);
    else
        printf("NAO");
}

int main(){
    int vet[N], n, x, i;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &x);
        vet[i] = x;
    } 

    verificaProg(vet, n);

    return 0;
}
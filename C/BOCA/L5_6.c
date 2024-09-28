#include <stdio.h>
#include <stdlib.h>
#define N 100

void contidos(int *vet1, int *vet2, int n1, int n2){
    int ok = 0, i, j;

    for(i=0; i<n1; i++){
        for(j=0; j<n2; j++)
            if(vet1[i] == vet2[j])
                ok++;
    }

    if(ok >= n1)
        printf("TODOS");
    else if(ok < n1 && ok != 0)
        printf("PARCIAL");
    else
        printf("NENHUM");
}

int main(){
    int vet1[N], vet2[N], n1, n2;

        int i, x1, x2;

    scanf("%d", &n1);

    for(i=0; i<n1; i++){
        scanf("%d", &x1);
        vet1[i] = x1;
    }

    scanf("%d", &n2);

    for(i=0; i<n2; i++){
        scanf("%d", &x2);
        vet2[i] = x2;
    }

    contidos(vet1, vet2, n1, n2);

    return 0;
}
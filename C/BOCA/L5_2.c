#include <stdio.h>
#include <stdlib.h>

int crescente(int *notas, int n){
    int i, ok = 0;

    for(i=1; i<n; i++){
        if(notas[i] >= notas[i-1])
            ok++;
    }

    if(ok == n-1)
        return 1;
    else
        return 0;
}

int decrescente(int *notas, int n){
    int i, ok = 0;

    for(i=1; i<n; i++){
        if(notas[i] <= notas[i-1])
            ok++;
    }

    if(ok == n-1)
        return 1;
    else
        return 0;
}

int igual(int *notas, int n){
    int i, ok = 0;

    for(i=1; i<n; i++){
        if(notas[i] == notas[i-1])
            ok++;
    }

    if(ok == n-1)
        return 1;
    else
        return 0;
}

void verificaCrescente(int *notas, int n){
    if(crescente(notas, n) && n != 1 && !(igual(notas, n)))
        printf("CRESCENTE");
    else if(decrescente(notas, n) && n != 1 && !(igual(notas, n)))
        printf("DECRESCENTE");
    else if(igual(notas, n) || n == 1)
        printf("CRESCENTE&DECRESCENTE");
    else
        printf("DESORDENADO");
}

int main(){
    int notas[100], n, nota, i;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &nota);
        notas[i] = nota;
    }

    verificaCrescente(notas, n);

    return 0;
}
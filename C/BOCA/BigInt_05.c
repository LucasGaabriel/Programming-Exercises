#include <stdio.h>
#include <string.h>

typedef struct {
    char numero[100];
    int n;
} tIntGrande;

void inverteString(tIntGrande *bigInt){
    char aux;

    for(int i=0; i<bigInt->n/2; i++){
        aux = bigInt->numero[i];
        bigInt->numero[i] = bigInt->numero[bigInt->n-i-1];
        bigInt->numero[bigInt->n-i-1] = aux;
    }
}

int main(){
    tIntGrande bigInt;
    int multiplicador, result[100];
    int U, D, C;

    scanf("%s", bigInt.numero);
    scanf("%d", &multiplicador);
    
    return 0;
}
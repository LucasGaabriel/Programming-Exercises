#include <stdio.h>
#include <string.h>

typedef struct {
    char numero[100];
    int n;
} tIntGrande;

tIntGrande inverteString(tIntGrande bigInt){
    int i;
    char aux;

    for(i=0; i<bigInt.n/2; i++){
        aux = bigInt.numero[i];
        bigInt.numero[i] = bigInt.numero[bigInt.n-i-1];
        bigInt.numero[bigInt.n-i-1] = aux;
    }

    return bigInt;
}

void removeZero(tIntGrande *bigInt){
    for(int i=0; i<bigInt->n; i++){
        bigInt->numero[i] = bigInt->numero[i+1];
    }

    bigInt->n--;
}

int main(){
    tIntGrande bigInt;
    int i, n;
    
    scanf("%s", bigInt.numero);
    bigInt.n = strlen(bigInt.numero);

    bigInt = inverteString(bigInt);

    bigInt.numero[0] -= 1;
    
    for(i=0; i<bigInt.n; i++){

        if(bigInt.numero[i] == '/'){
            bigInt.numero[i] = '9';
            if(bigInt.numero[i+1] != '\0')
                bigInt.numero[i+1] -= 1;
        }
    }

    bigInt = inverteString(bigInt);

    if(bigInt.numero[0] == '0'){
        removeZero(&bigInt);
    }   

    printf("%s", bigInt.numero);

    return 0;
}
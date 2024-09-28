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

int main(){
    tIntGrande bigInt1, bigInt2;
    int i, D, U;
    int maior;
    int igual = 0;
    int soma[100] = {0};
    int n = 0;
    int result;
    int aux;

    scanf("%s", bigInt1.numero);
    scanf("%s", bigInt2.numero);

    bigInt1.n = strlen(bigInt1.numero);
    bigInt2.n = strlen(bigInt2.numero);

    bigInt1 = inverteString(bigInt1);
    bigInt2 = inverteString(bigInt2);

    if(bigInt1.n == bigInt2.n)
        igual = 1;

    maior = bigInt1.n;
    if(bigInt2.n > bigInt1.n){
        maior = bigInt2.n;
    }

    if(maior == bigInt1.n && !igual){
        for(i=bigInt2.n; i<bigInt1.n; i++){
            bigInt2.numero[i] = '0';
        }
        bigInt2.numero[bigInt1.n] = '\0';
    }

    if(maior == bigInt2.n && !igual){
        for(i=bigInt1.n; i<bigInt2.n; i++){
            bigInt1.numero[i] = '0';
        }
        bigInt1.numero[bigInt2.n] = '\0';
    }

    for(i=0; i<maior; i++){
        result = (bigInt1.numero[i] - '0') + (bigInt2.numero[i] - '0');

        D = result/10;
        U = result%10;
        
        if(i != maior-1){
            soma[i] += U;
            soma[i+1] += D;
        }
        else{
            soma[i] += result;
        }
         
        n++;
    }

    for(i=0; i<n; i++){
        if(soma[i] > 9){
            D = soma[i]/10;
            U = soma[i]%10;

            if(i != n-1){
                soma[i] = U;
                soma[i+1] += D;
            }
            
            else{
                soma[i] = U;
                soma[i+1] += D;
                n++;
            }
            
        }
        
    }

    for(i=0; i<n/2; i++){
        aux = soma[i];
        soma[i] = soma[n-i-1];
        soma[n-i-1] = aux;
    }

    for(i=0; i<n; i++){
        printf("%d", soma[i]);
    }
    
    return 0;
}
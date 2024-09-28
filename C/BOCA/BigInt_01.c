#include <stdio.h>

typedef struct {
    char numero[100];
    int n;
} tIntGrande;


int main(){
    tIntGrande bigInt1, bigInt2;
    int i;
    
    scanf("%s", &bigInt1.numero[0]);
     
    scanf("%s", &bigInt2.numero[0]);

    for(i=0; bigInt1.numero[i] != '\0'; i++)
    bigInt1.n = i+1;

    for(i=0; bigInt2.numero[i] != '\0'; i++)
    bigInt2.n = i+1;

    if(bigInt1.n > bigInt2.n){
        printf("MAIOR");
    }
    else if(bigInt1.n < bigInt2.n){
        printf("MENOR");
    }
    else if(bigInt1.n == bigInt2.n){
        for(i=0; i<bigInt1.n; i++){
            if(bigInt1.numero[i] > bigInt2.numero[i]){
                printf("MAIOR");
                return 0;
            }
            else if(bigInt1.numero[i] < bigInt2.numero[i]){
                printf("MENOR");
                return 0;
            }
        }
        printf("IGUAL");
    }

    return 0;
}
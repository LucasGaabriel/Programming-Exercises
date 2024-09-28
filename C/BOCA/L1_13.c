#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int pessoas, itens, resto;
    scanf("%d %d", &pessoas, &itens);

    resto = itens % pessoas;

    if(itens < pessoas){
        printf("RESP:%d", itens);
        return 0;
    }

    if(resto == 0){
        printf("RESP:%d", pessoas);
    }
    
    if (resto != 0){
        printf("RESP:%d", resto);
    }

    return 0;
}
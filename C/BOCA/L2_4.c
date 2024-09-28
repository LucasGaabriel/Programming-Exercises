#include <stdio.h>
#include <stdlib.h>

int main(){

    int x=1, maior=0, cont=0;
    float soma, media;

    while(x != 0){
        scanf("%d", &x);

        if(x == 0)
            break;

        cont++;

        if(x > maior)
            maior = x;

        soma += x;

        media = soma/cont;

        printf("%d %f\n", maior, media);
    }

    

    return 0;
}
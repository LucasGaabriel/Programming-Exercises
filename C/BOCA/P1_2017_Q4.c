#include <stdio.h>
#include <stdlib.h>

int main(){
    int h1, min1, seg1, h2, min2, seg2, maior = 0, soma = 0, C, rC, D, maior2 = 2, maior1 = 1;

    scanf("%d %d %d %d %d %d", &h1, &min1, &seg1, &h2, &min2, &seg2);

    if(h1 > h2)
        maior = maior1;
    else if(h2 > h1)
        maior = maior2;
    else if(min1 > min2)
        maior = maior1;
    else if(min2 > min1)
        maior = maior2;
    else if(seg1 > seg2)
        maior = maior1;
    else if(seg2 > seg1)
        maior = maior2;

    if(h1 == h2 && min1 == min2 && seg1 == seg2)
        printf("IGUAIS");
    else if(maior == maior1){
        soma = h1+min1+seg1;

        C = soma/100;
        rC = soma%100;
        D = rC/10;

        printf("RESP:%d", D);
    }
    else{
        soma = h2+min2+seg2;

        C = soma/100;
        rC = soma%100;
        D = rC/10;

        printf("RESP:%d", D);        
    }

    return 0;
}
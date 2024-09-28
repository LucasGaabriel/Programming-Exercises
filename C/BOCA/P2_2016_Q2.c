#include <stdio.h>
#include <stdlib.h>

int EhPrimo(int num){
    int i, cont = 0;

    for(i=1; i<=num; i++){
        if(num%i == 0)
            cont++;
    }

    if(cont == 2)
        return 1;
    else
        return 0;
}

int MaiorDigitoPrimo(int a, int b, int c, int d, int e ,int f){
    int maior = 0;

    if(EhPrimo(a))
        if(a > maior)
            maior = a;
    if(EhPrimo(b))
        if(b > maior)
            maior = b;
    if(EhPrimo(c))
        if(c > maior)
            maior = c;
    if(EhPrimo(d))
        if(d > maior)
            maior = d;
    if(EhPrimo(e))
        if(e > maior)
            maior = e;
    if(EhPrimo(f))
        if(f > maior)
            maior = f;

    return maior;
}


int main(){
    int num, CM, rCM, DM, rDM, UM, rUM, C, rC, D, U, maior = 0, soma = 0;

    while(scanf("%d", &num) == 1){
        maior = 0;

        CM = num/100000;
        rCM = num%100000;
        DM = rCM/10000;
        rDM = rCM%10000;
        UM = rDM/1000;
        rUM = rDM%1000;
        C = rUM/100;
        rC = rUM%100;
        D = rC/10;
        U = rC%10;

        if(num >= 1 && num <= 9)
            U = num;

        maior = MaiorDigitoPrimo(CM, DM, UM, C, D, U);

        soma += maior;
    }

    printf("SOMA:%d", soma);
    return 0;
}
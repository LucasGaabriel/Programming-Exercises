#include <stdio.h>
#include <stdlib.h>

void parImpar(int n){
    if(n%2 == 0)
        printf("Par ");
    else
        printf("Impar ");
}

void valorPrimo(int n){
    int i, cont = 0;

    for(i=1; i<=n; i++){
        if(n%i == 0)
            cont++;
    }

    if(cont == 2)
        printf("Primo\n");
    else
        printf("Nao e primo\n");
}

int somadosdigitos(int n){
    int CM, RCM, DM, RDM, uM, RuM, C, RC, D, RD, U;

    if(n <= 9){
        
        printf("%d ", n);

        parImpar(n);
        valorPrimo(n);
    }

    while(n > 9){
        CM = n/100000;
        RCM = n%100000;
        DM = RCM/10000;
        RDM = RCM%10000;
        uM = RDM/1000;
        RuM = RDM%1000;
        C = RuM/100;
        RC = RuM%100;
        D = RC/10;
        U = RC%10;

        n = CM+DM+uM+C+D+U;

        printf("%d ", n);

        parImpar(n);
        valorPrimo(n);
    } 
}

int main(){
    int num;

    scanf("%d", &num);

    somadosdigitos(num);
    
    return 0;
}
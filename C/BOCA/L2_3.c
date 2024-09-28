#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd, i, numero, pares=0, impares=0, maior=0, menor=999999;
    float soma=0, media;
    scanf("%d", &qtd);

    for(i=0; i<qtd; i++){
        scanf("%d", &numero);

        //Pares e Impares
        if(numero%2 == 0)
            pares++;
        else
            impares++;
        
        //Soma p/ usar na média
        soma += numero;

        //Maior
        if (numero > maior)
        maior = numero;

        //Menor
        if (numero < menor)
        menor = numero;
    }

    //Média
    media = soma/qtd;

    printf("%d %d %d %d %f", maior, menor, pares, impares, media);

    return 0;
}
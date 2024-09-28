#include <stdio.h>
#include <stdlib.h>

int verificaPrimo(int n){
    int i, cont = 0;
    for(i=1; i<=n; i++){
        if(n%i == 0)
            cont++;
    }

    if(cont == 2)
        return 1;
    else
        return 0;
}

int transformaPrimo(int n, int neg, int pri){
    int i, j, cont = 0;

    if(pri) //Se o numero for primo, retorna ele mesmo.
        return n;
    else if(neg){ //Se não for primo e for negativo, retorna o próximo primo menor.
        for(i=n-1; i >= -32000; i--){
            cont = 0;
            for(j=-1; j >= i; j--){
                if(i%j == 0)
                    cont++;
            }
            if(cont == 2)
                return i;
        }
    }
    else{ //Se não for primo e for positivo, retorna o próximo primo maior.
        for(i=n+1; i <= 32000; i++){
            cont = 0;
            for(j=1; j <= i; j++){
                if(i%j == 0)
                    cont++;
            }
            if(cont == 2)
                return i;
        }
    }
    //Caso não encontre nenhum valor acima, é porque o próximo número primo é maior que o intervalo permitido (-32000 <= x <= 32000).
    return n;
}

int verificaNegativo(int n){
    if(n >= 0)
        return 0;
    else
        return 1;
}

int main(){
    int l, c, i, j, num, negativo, primo, x;

    scanf("%d %d", &l, &c);

    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            scanf("%d", &num);

            negativo = verificaNegativo(num);
            primo = verificaPrimo(num);
            x = transformaPrimo(num, negativo, primo);

            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}
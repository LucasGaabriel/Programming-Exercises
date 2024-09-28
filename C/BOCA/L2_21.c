#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, quant, elementos[10], x;
    char texto;

    scanf("%d", &quant);

    for(i=0; i<10; i++){
        elementos[i] = 0;
    }

    for(i=1; i<=quant; i++){
        scanf("%d", &elementos[i]);
    }

    scanf("%*c");

    while(scanf("%c", &texto) == 1 && texto != '\n'){

        if(texto == '%'){

            scanf("%d", &x);
            x = elementos[x];

            if(x != 0)
                printf("%d", x);
            else
                printf("ERRO");
        }

        if(texto != '%' && texto != '"')
        printf("%c", texto);
    }
    
    return 0;
}
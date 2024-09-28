#include <stdio.h>
#include <stdlib.h>

int primeira(int menor){
    char x;

    while(scanf("%d", &x) == 1){
        if(x < menor)
            menor = x;
    }

    return menor;
}

void segunda(void){
    char y;
    while(scanf("%d", &y) == 1){
        
    }
    printf("%d", y);
}

int main(){
    int menor = 32000, primeiro, ultimo, i;
    char x, y;

    

    menor = primeira(menor);
    segunda();

    printf("%d %d %d", menor, primeiro, ultimo);




    return 0;
}
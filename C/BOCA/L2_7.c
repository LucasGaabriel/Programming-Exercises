#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, x = 1, cont = 0;
    scanf("%d", &num);

    while(x <= num){

        if(num % x == 0){
            cont++;
        }

        x++;
    }
    if(cont==2){
        printf("Primo");
    }
    else{
        printf("Nao primo");
    }
    return 0;
}
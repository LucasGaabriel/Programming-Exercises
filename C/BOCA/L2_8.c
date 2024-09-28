#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, x = 1, cont = 0;

    scanf("%d%d", &a, &b);
    printf("RESP:");

    a = a+1;
    
    while(a < b){
        x = 1;
        cont = 0;
        while(a >= x){
            if(a % x == 0){
                cont++;
            }
            x++;
        }
        if(cont == 2){
            printf("%d ", a);
        } 
        a++;
    }
    
}
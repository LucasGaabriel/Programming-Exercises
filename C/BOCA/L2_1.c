#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int m, n, numeros;
    scanf("%d %d", &m, &n);

    if(m%2 == 0){
        m=m+2;
        printf("RESP:");
        while (m < n){
            numeros = printf("%d ", m);
            m=m+2;
        }    
    }  
    else{
        m=m+1;
        printf("RESP:");
        while (m < n){
            numeros = printf("%d ", m);
            m=m+2;
        }  
    }
}
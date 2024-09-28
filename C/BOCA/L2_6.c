#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double um(void){
    double i, j, soma = 0, result = 0;
    
    for(i=1, j=1; i<=99, j<=50; i+=2, j++){
        result = i/j;
        soma += result;
    }

    return soma;
}

double dois(void){
    double i, j, soma = 0, result = 0;

    for(i=1, j=50; i<=50, j>=1; i++, j--){
        result = (pow(2, i)/j);
        soma += result;
    }

    return soma;
}

double tres(void){
    double i, j, soma = 0, result = 0, den = 1;

    for(i=1, j=1; i<=10, j<=100; i++, j+=den){
        result = i/j;
        soma += result;
        den+=2;
    }

    return soma;
}

int main(){
    int n;
    double result;

    scanf("%d", &n);

    if(n == 1)
        result = um();
    else if(n == 2)
        result = dois();
    else
        result = tres();

    printf("%.6f", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float operacao(float result, float num, char operador){
    if(operador == '+')
        result += num;
    else if(operador == '-')
        result -= num;
    else if(operador == '/')
        result /= num;
    else
        result *= num;

    return result;
}

int main(){
    float num1, num2, num, result;
    char operador, c;

    scanf("%f %f %c", &num1, &num2, &operador);

    result = operacao(num1, num2, operador);
    
    scanf("%c", &c);

    while(c != '\n'){
        scanf("%f %c", &num, &operador);
        result = operacao(result, num, operador);
        scanf("%c", &c);
    }
    
    printf("%.2f", result);

    return 0;
}
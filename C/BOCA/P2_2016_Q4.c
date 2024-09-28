#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float FazOperacao(float num1, float num2, char op){

    if(op == '+')
        num1 += num2;
    else if(op == '-')
        num1 -= num2;
    else if(op == '/')
        num1 /= num2;
    else
        num1 *= num2;

    return num1;
}

float ResolveExpressao(){
    float num1, num2, num, result;
    char operador, c;

    scanf("%f %f %c", &num1, &num2, &operador);

    result = FazOperacao(num1, num2, operador);
    
    scanf("%c", &c);

    while(c != ')'){
        scanf("%f %c", &num, &operador);
        result = FazOperacao(result, num, operador);
        scanf("%c", &c);
    }

    return result;
}

int main(){
    char texto;
    float maior = 0, result;

    scanf("%c", &texto);

    while(texto != '.'){
        if(texto == '('){

            result = ResolveExpressao();

            if(result > maior)
                maior = result;

            printf("%.2f", result);
        }

        if(texto != '(' && texto != ')'){
            printf("%c", texto);
        }

        scanf("%c", &texto);
    }

    printf(". MAIOR:%.2f", maior);
    
    return 0;
}
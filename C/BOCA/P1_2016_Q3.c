#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
a) Primeiro - Caractere Maiúsculo -------------> 65 a 90
b) Segundo - Digito ---------------------------> 0 a 9
c) Terceiro - vogal ---------------------------> (65,69,73,79,85), (97,101,105,111,117)
d) Quarto - Consoante minúscula ---------------> (98 a 100, 102 a 104, 106 a 110, 112 a 116, 118 a 122)
*/

int main(){
    int b;
    char a, c, d;
    
    scanf("%c %d %c %c", &a, &b, &c, &d);
    
    if(a >= 65 && a <= 90){
        if(b >= 0 && b <= 9){
            if(c == 65 || c == 69 || c == 73 || c == 79 || c == 85 || c == 97 || c == 101 || c == 105 || c == 111 || c == 117){
                if(c == 97 || c == 101 || c == 105 || c == 111 || c == 117){
                    c=c-32;
                }
                    if((d>=98 && d<=100) || d>=102 && d<=104 || d>=106 && d<=110 || d>=112 && d<=116 || d>= 118&& d<=122){
                        printf("%c%d%c%c", a, b, c, d-32);
                    }
                    else{
                        printf("Invalido");
                    }
            }
            else{
                printf("Invalido");
            } 
        }
        else{
            printf("Invalido");
        }
    }
    else{
        printf("Invalido");
    }
    return 0;
}
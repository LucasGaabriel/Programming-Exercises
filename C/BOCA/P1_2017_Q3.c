#include <stdio.h>
#include <stdlib.h>

int main(){
    char a1, a2, b1, b2;
    scanf("%c %c %c %c", &a1, &a2, &b1, &b2);

    if(a1 >= 'A' && a1 <= 'Z')
        a1 += 32;
    if(a2 >= 'A' && a2 <= 'Z')
        a2 += 32;
    if(b1 >= 'A' && b1 <= 'Z')
        b1 += 32;
    if(b2 >= 'A' && b2 <= 'Z')
        b2 += 32;


    if(a1 == b1 && a2 == b2){
        if(((a1 >= 'a' && a1 <= 'z') || (a1 >= '0' && a1 <= '9')) && ((a2 >= 'a' && a2 <= 'z') || (a2 >= '0' && a2 <= '9')))
            printf("IGUAIS");
        else
            printf("Invalido");
    }
    else
        printf("DIFERENTES");


    return 0;
}
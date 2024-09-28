#include <stdio.h>
#include <stdlib.h>

int main(){
    char c;

    scanf("%c", &c);

    while(c != '.' && c != '?' && c != '!'){
        if (c >= 'a' && c <= 'z'){
            c -= 32;
        }
        putchar(c);
        scanf("%c", &c);
    }
    printf("%c", c);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    char c;

    scanf("%c", &c);
    printf("RESP:");

    while(c != '.' && c != '?' && c != '!'){
        if (c != ' '){  
        	printf("%c", c);
        }
        scanf("%c", &c);
    }
    printf("%c", c);
    return 0;
}


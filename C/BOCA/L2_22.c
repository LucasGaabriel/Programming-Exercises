#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, dezm, restdezm, unim, restunim, cent, restcent, dez, uni; 

    scanf("%d", &x);

    while(x>9){
        dezm = x/10000;
        restdezm = x%10000;
        unim = restdezm/1000;
        restunim = restdezm%1000;
        cent = restunim/100;
        restcent = restunim%100;
        dez = restcent/10;
        uni = restcent%10;

        x = dezm + unim + cent + dez + uni;
    }

    printf("RESP:%d", x);

    return 0;
}
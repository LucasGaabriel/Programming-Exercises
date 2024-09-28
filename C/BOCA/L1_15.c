#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, ordem, uni, dez, cen;
    scanf ("%d %d", &num, &ordem);

    switch (ordem){
        case 1: uni = ((num%100)%10);
            if(uni%2==0)
            printf("PAR");
            else
            printf("IMPAR");
                break;
        case 2: dez = ((num%100)/10);
            if(dez%2==0)
            printf("PAR");
            else
            printf("IMPAR");
                break;
        case 3: cen = num/100;
            if(cen%2==0)
            printf("PAR");
            else
            printf("IMPAR");
                break;
    }

    return 0;
}
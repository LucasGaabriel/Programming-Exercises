#include <stdio.h>
#include <stdlib.h>

int EhPalindromo(int num);

int main(){
    int n;
    
    while(scanf("%d", &n) == 1){
        if(EhPalindromo(n) == 1)
            printf("S\n");
        else
            printf("N\n");

    }

    return 0;
}

int EhPalindromo(int num){
    int uB, RuB, cMi, RcMi, dMi, RdMi, uMi, RuMi, cM, RcM, dM, RdM, uM, RuM, C, RC, D, U, cont = 0;

    //Algarismos do Número
    uB = num/1000000000;
    RuB = num%1000000000;
    cMi = RuB/100000000;
    RcMi = RuB%100000000;
    dMi = RcMi/10000000;
    RdMi = RcMi%10000000;
    uMi = RdMi/1000000;
    RuMi = RdMi%1000000;
    cM = RuMi/100000;
    RcM = RuMi%100000;
    dM = RcM/10000;
    RdM = RcM%10000;
    uM = RdM/1000;
    RuM = RdM%1000;
    C = RuM/100;
    RC = RuM%100;
    D = RC/10;
    U = RC%10;

    // 10 Algarismos
    if((num/1000000000) >= 1 && (num/1000000000) <= 9){
        if(U - uB != 0)
        cont++;
        if(D - cMi != 0)
        cont++;
        if(C - dMi != 0)
        cont ++;
        if(uM - uMi != 0)
        cont ++;
        if(dM - cM != 0)
        cont ++;
    }
    // 9 Algarismos
    if((num/100000000) >= 1 && (num/100000000) <= 9){
        if(U - cMi != 0)
        cont++;
        if(D - dMi != 0)
        cont++;
        if(C - uMi != 0)
        cont ++;
        if(uM - cM != 0)
        cont ++;
    }
    // 8 Algarismos
    if((num/10000000) >= 1 && (num/10000000) <= 9){
        if(U - dMi != 0)
        cont++;
        if(D - uMi != 0)
        cont++;
        if(C - cM != 0)
        cont ++;
        if(uM - dM != 0)
        cont ++;
    }
    // 7 Algarismos
    if((num/1000000) >= 1 && (num/1000000) <= 9){
        if(U - uMi != 0)
        cont++;
        if(D - cM != 0)
        cont++;
        if(C - dM != 0)
        cont ++;
    }
    // 6 Algarismos
    if((num/100000) >= 1 && (num/100000) <= 9){
        if(U - cM != 0)
        cont++;
        if(D - dM != 0)
        cont++;
        if(C - uM != 0)
        cont ++;
    }
    // 5 Algarismos
    if((num/10000) >= 1 && (num/10000) <= 9){
        if(U - dM != 0)
        cont++;
        if(D - uM != 0)
        cont++;
    }
    // 4 Algarismos
    if((num/1000) >= 1 && (num/1000) <= 9){
        if(U - uM != 0)
        cont++;
        if(D - C != 0)
        cont++;
    }
    // 3 Algarismos
    if((num/100) >= 1 && (num/100) <= 9){
        if(U - C != 0)
        cont++;
    }
    // 2 Algarismos
    if((num/10) >= 1 && (num/10) <= 9){
        if(U - D != 0)
        cont++;
    }
    // 1 Algarismo
    if(num >= 1 && num <= 9)
        return 1;

    if(cont == 0)
        return 1;
    else
        return 0;
}

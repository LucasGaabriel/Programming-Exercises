#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int EhPrimo(int num){
    int x, cont = 0;
    for(x=1; x<=num; x++){
            if(num % x == 0)
                cont++;
    }
    
    if(cont == 2){
        return 1;
    }

    if(cont != 2){
        return 0;
    }
}

void ImprimeMultiplos(int num, int max){
    int mult, contm;
    mult = num;
    contm = 0;
            
    while(mult < max){
    mult += num;
            	
        if(mult < max){
            printf("%d ", mult);
            contm++;
        }
	}
			
	if(((mult + mult) >= max) && contm == 0){
		printf("*");
	}

    printf("\n"); 
}

int main(){

    int n, m, x = 1, cont = 0, z = 0, mult, contm = 0;
    scanf("%d%d", &n, &m);

    n+=1;
    while(n < m){

        if(EhPrimo(n) == 1){

            printf("%d\n", n);
            
            ImprimeMultiplos(n, m);
            
        }
        n++;
    }
    return 0;
}

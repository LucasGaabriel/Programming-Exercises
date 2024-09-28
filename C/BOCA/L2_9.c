#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int n, m, x = 1, cont = 0, z = 0, mult, contm = 0;
    scanf("%d%d", &n, &m);

    n+=1;
    while(n < m){

        cont = 0;

        for(x=1; x<=n; x++){
            if(n % x == 0)
                cont++;
        }

        if(cont == 2){

            printf("%d\n", n);
            
            mult = n;
            contm = 0;
            
            while(mult < m){
            	mult += n;
            	
            	if(mult < m){
            		printf("%d ", mult);
            		contm++;
            	}
			}
			
			if(((mult + mult) >= m) && contm == 0){
				printf("*");
			}



            printf("\n"); 
        }
        n++;
    }
    return 0;
}

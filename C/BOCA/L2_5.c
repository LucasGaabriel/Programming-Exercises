#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, k=1;
    float pi=0, somatorio=0;

    scanf("%d", &n);

    for(k=1; k<=n; k++){
        somatorio = (6/(pow(k, 2)));

        pi = pi+somatorio;
    }

    pi = sqrt(pi);

    printf("%f", pi);

    return 0;
}



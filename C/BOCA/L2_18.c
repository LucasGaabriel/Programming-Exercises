#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, m, n, num, maior = -32767, iMaior, jMaior;

    scanf("%d%d", &m, &n);

    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &num);

            if(num >= maior){
            maior = num;
            iMaior = i;
            jMaior = j;
            }
        }
    }

    printf("%d (%d, %d)", maior, iMaior, jMaior);

    return 0;
}
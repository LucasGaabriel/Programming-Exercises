#include <stdio.h>
#include <stdlib.h>

int Propriedade(int num);

int main(){
    int n, m, i;
    scanf("%d%d", &n, &m);

    n+=1;

    for (i=n; i<m; i++){
        if(Propriedade(i) == 1)
            printf("%d\n", i);
    }

    return 0;
}

int Propriedade(int num){
    int ab, cd, soma;
    ab = num/100;
    cd = num%100;

    soma = ab+cd;

    if(soma*soma == num)
        return 1;
    else
        return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x, y;

    scanf("%d %d", &x, &y);

    if(x%3==0 || x%4==0 || x%7==0){
        x=x+1;
    }

    while(x<y){
        if(x%3==0 || x%4==0 || x%7==0){
            printf("%d ", x);
        }
        x=x+1;
    }
    return 0;
}
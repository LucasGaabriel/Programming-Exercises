#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, b, x1, x2, x3, y1, y2, y3;
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);
    if (a*x1+b==y1 && a*x2+b==y2 && a*x3+b==y3){
        printf("Todos");
    }  
    else{
        if((a*x1+b==y1 && a*x2+b==y2) || (a*x1+b==y1 && a*x3+b==y3) || (a*x2+b==y2 && a*x3+b==y3)){
            printf("Dois");
        }
        else{
            if(a*x1+b==y1 || a*x2+b==y2 || a*x3+b==y3){
                printf("Um");
                }
            else{
                printf("Nenhum");
                }
            }
        }
}
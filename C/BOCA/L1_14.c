#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x1, y1, x2, y2, xponto, yponto;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &xponto, &yponto);

    if((x1 <= xponto && xponto <= x2) && (y1 <= yponto && yponto <= y2)){
        printf("Dentro");
    }
    else if((x1 <= xponto && xponto <= x2) && (y2 <= yponto && yponto <= y1)){
        printf("Dentro");
    }
    else if((x2 <= xponto && xponto <= x1) && (y1 <= yponto && yponto <= y2)){
        printf("Dentro");
    }
    else if((x2 <= xponto && xponto <= x1) && (y2 <= yponto && yponto <= y1)){
        printf("Dentro");
    }
    else{
        printf("Fora");
    }
    return 0;
}
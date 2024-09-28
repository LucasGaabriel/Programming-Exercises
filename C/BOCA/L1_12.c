#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if(a < b && b < c)
        printf("N1 = %d, N2 = %d, N3 = %d", a, b, c);

    if(a < c && c < b)
        printf("N1 = %d, N3 = %d, N2 = %d", a, c, b);
    
    if(b < a && a < c)
        printf("N2 = %d, N1 = %d, N3 = %d", b, a, c);

    if(b < c && c < a)
        printf("N2 = %d, N3 = %d, N1 = %d", b, c, a);

    if(c < a && a < b)
        printf("N3 = %d, N1 = %d, N2 = %d", c, a, b);

    if(c < b && b < a)
        printf("N3 = %d, N2 = %d, N1 = %d", c, b, a);

    return 0;

}
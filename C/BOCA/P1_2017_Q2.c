#include <stdio.h>
#include <stdlib.h>

/*
1 a 5 = Homens
6 a 10 = Mulheres

Um homem
Uma mulher
Um casal
Par de homens
Par de mulheres
*/

int main(){
    int x, y;
    scanf("%d%d", &x, &y);

    if((x >= 1 && x <= 5) && x == y)
        printf("Um homem");
    if((x >= 6 && x <= 10) && x == y)
        printf("Uma mulher");
    if(((x >= 1 && x <= 5) && (y >= 6 && y<= 10)) || ((x >= 6 && x <= 10) && (y >= 1 && y<= 5)))
        printf("Um casal");
    if((x >= 1 && x <= 5) && (y >= 1 && y <= 5) && x != y)
        printf("Par de homens");
    if((x >= 6 && x <= 10) && (y >= 6 && y <= 10) && x != y)
        printf("Par de mulheres");
    if((x < 1 || x > 10) || y < 1 || y > 10){
        printf("Invalido");
    }

    return 0;
}
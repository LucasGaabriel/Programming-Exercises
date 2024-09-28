#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, quantNeg = 0, quantPos = 0, SomaNeg = 0, SomaPos = 0;
    
    while(scanf("%d", &n) == 1){
        if(n > 0){
            quantPos++;
            SomaPos += n;
        }

        if(n < 0){
            quantNeg++;
            SomaNeg += n;
        }
    }
    
    printf("%d %d %d %d", quantNeg, quantPos, SomaNeg, SomaPos);
    
    return 0;
}
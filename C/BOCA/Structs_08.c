#include <stdio.h>

typedef struct {
    float x, y, z;
} Vetor;


float dot (Vetor v1, Vetor v2){
    return (v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z);
}

void main(){
    Vetor v1, v2;
    v1.x = 1.0;
    v1.y = 2.0;
    v1.z = 2.0;

    v2.x = 2.0;
    v2.y = -1.0;
    v2.z = 2.0;

    printf("%.1f", dot(v1, v2));
}
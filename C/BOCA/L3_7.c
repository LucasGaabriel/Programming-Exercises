#include <stdio.h>
#include <stdlib.h>

int area (int x1, int y1, int x2, int y2){
    return (x2-x1)*(y2-y1);
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){
    int area1, area2, intersecao;
    
    area1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
    area2 = area(r2_x1, r2_y1, r2_x2, r2_y2);

    if((r1_x2-r2_x1) <= 0 && (r1_y2-r2_y1) <= 0)
        intersecao = -((r1_x2-r2_x1)*(r1_y2-r2_y1));
    else
        intersecao = (r1_x2-r2_x1)*(r1_y2-r2_y1);


    if(intersecao <= 0)
        return area1+area2;
    else
        return (area1+area2)-intersecao;

}

int main(){
    int r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2, total;

    scanf("%d %d %d %d", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
    scanf("%d %d %d %d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

    total = area_total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);

    printf("RESP:%d", total);

    return 0;
}
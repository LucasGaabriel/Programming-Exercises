#include <stdio.h>

typedef struct {
int dia;
int mes;
int ano;
} data;

data leData (){
    data x;
    scanf("%d %d %d", &x.dia, &x.mes, &x.ano);
    return x;
}

void imprimeData (data atual){
    printf("A data informada eh %d/%d/%d.", atual.dia, atual.mes, atual.ano);
}

void main(){
    data atual = leData();
    imprimeData (atual);
}
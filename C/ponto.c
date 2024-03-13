#include <stdio.h>
#include <math.h>

struct ponto {
	float x;
	float y;
};
typedef struct ponto Ponto;


/* Funcao cria 
** Retorna um ponto com coordenadas (x,y)
*/
Ponto pto_cria (float x, float y){
    Ponto p;

    p.x = x;
    p.y = y;

    return p;
}

/* Funcao acessa x
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_x (Ponto p){
    return p.x;
}

/* Funcao acessa y
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_y (Ponto p){
    return p.y;
}

/* Funcao atribui x
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_x (Ponto p, float x){
    p.x = x;

    return p;
}

/* Funcao atribui y
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_y (Ponto p, float y){
    p.y = y;

    return p;
}

/* Funcao distancia
** Retorna a distancia entre dois pontos
*/
float pto_distancia (Ponto p1, Ponto p2){
    return sqrt( pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2) );
}

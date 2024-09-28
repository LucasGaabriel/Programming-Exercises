#include <stdio.h>
#include "trapezoidal.h"
#include "terreno.h"

//Calculo da Area para um Terreno tipo 'Trapezoidal'
float calculaAreaTrapezoidal(tTrapezoidal *t){
    return (((t->base1+t->base2) * t->altura)/2);
}

//Calcula o preco de um Terreno 'Trapezoidal'
float calculaPrecoTrapezoidal(tTrapezoidal *t){
    //preço = preçoMetroQuadradoTerreno * área * fatorMultiplicativo
    return (t->precoMetroQuadradoTerreno*calculaAreaTrapezoidal(t)*verificaSolo(t->solo));
}

//Faz a leitura de um terreno tipo 'Trapezoidal'
void lerTrapezoidal(FILE *f, tTrapezoidal *t){
    fscanf(f, "%c\n", &t->solo);
    fscanf(f, "%d\n", &t->precoMetroQuadradoTerreno);
    fscanf(f, "%f\n", &t->base1);
    fscanf(f, "%f\n", &t->base2);
    fscanf(f, "%f\n", &t->altura);
}
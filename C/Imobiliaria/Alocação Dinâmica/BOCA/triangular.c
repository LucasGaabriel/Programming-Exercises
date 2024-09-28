#include <stdio.h>
#include "triangular.h"
#include "terreno.h"

//Faz o calculo da Area de um Terreno tipo 'Triangular'
float calculaAreaTriangular(tTriangular *t){
    return (t->base*t->altura)/2;
}

//Faz o Calculo do Preco de um terreno tipo 'Triangular'
float calculaPrecoTriangular(tTriangular *t){
    //preço = preçoMetroQuadradoTerreno * área * fatorMultiplicativo
    return (t->precoMetroQuadradoTerreno*calculaAreaTriangular(t)*verificaSolo(t->solo));
}

//Faz a leitura de um terreno tipo 'Triangular'
void lerTriangular(FILE *f, tTriangular *t){
    fscanf(f, "%c\n", &t->solo);
    fscanf(f, "%d\n", &t->precoMetroQuadradoTerreno);
    fscanf(f, "%f\n", &t->base);
    fscanf(f, "%f\n", &t->altura);
}

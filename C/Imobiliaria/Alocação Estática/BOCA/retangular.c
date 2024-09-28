#include <stdio.h>
#include "retangular.h"
#include "terreno.h"

//Calcula Area de um Terreno Retangular
float calculaAreaRetangular(tRetangular *r){
    return r->lado1*r->lado2;
}

//Calcula Preco de um Terreno Retangular
float calculaPrecoRetangular(tRetangular *r){
    //preço = preçoMetroQuadradoTerreno * área * fatorMultiplicativo
    return (r->precoMetroQuadradoTerreno*calculaAreaRetangular(r)*verificaSolo(r->solo));
}

//Faz a leitura de um terreno Retangular
void lerRetangular(FILE *f, tRetangular *r){
    fscanf(f, "%c\n", &r->solo);
    fscanf(f, "%d\n", &r->precoMetroQuadradoTerreno);
    fscanf(f, "%f\n", &r->lado1);
    fscanf(f, "%f\n", &r->lado2);
}
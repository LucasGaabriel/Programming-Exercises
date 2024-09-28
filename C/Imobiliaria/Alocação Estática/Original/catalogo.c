#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "imobiliaria.h"

//Faz a leitura do tipo do Imovel
void lerTipo(FILE *f, tCatalogo *c){
    fscanf(f, "%s\n", c->tipo);
}

//Faz a leitura do Identificador do Imovel
void lerIdentificador(FILE *f, tCatalogo *c){
    fscanf(f, "%d\n", &c->identificador);
}

//Faz a Leitura do Proprietario do Imovel
void lerProprietario(FILE *f, tCatalogo *c){
    fscanf(f, "%[^\n]\n", c->proprietario);
}
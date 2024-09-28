#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imobiliaria.h"
#include "triangular.h"
#include "retangular.h"
#include "trapezoidal.h"
#include "casa.h"
#include "apartamento.h"

//Leitura de informacoes referentes ao TIPO de Imovel: Terrenos (triangular, retangular ou trapezoidal) ou Imovel (Casa ou Apartamento)
void lerInfoTipo(FILE *file, tImobiliaria *im, int i){

    if(strcmp(im->imoveis[i].tipo, "triang") == 0){
        lerTriangular(file, &im->imoveis[i].categoria.triang);
    }
    else if(strcmp(im->imoveis[i].tipo, "retang") == 0){
        lerRetangular(file, &im->imoveis[i].categoria.retang);
    }
    else if(strcmp(im->imoveis[i].tipo, "trapez") == 0){
        lerTrapezoidal(file, &im->imoveis[i].categoria.trapez);
    }
    else if(strcmp(im->imoveis[i].tipo, "casa") == 0){
        lerCasa(file, &im->imoveis[i].categoria.casa);
    }
    else if(strcmp(im->imoveis[i].tipo, "apto") == 0){
        lerApartamento(file, &im->imoveis[i].categoria.apto);
    }

    fscanf(file, "\n");
}

//Leitura das informacoes Comuns p/ todos os tipos do Catalogo
void lerInfoImovel(FILE *file, tImobiliaria *im, int i){ // i = Numero do imovel a ser lido

    lerTipo(file, &im->imoveis[i]);
    lerIdentificador(file, &im->imoveis[i]);
    lerProprietario(file, &im->imoveis[i]);

    fscanf(file, "\n");
}

//Faz a leitura de todos os dados do arquivo "Catalogo.txt"
void lerDados(tImobiliaria *im){
    FILE *file;
    int i;
    char catalogo_path[150];
    scanf("%s", catalogo_path);
    
    im->imoveis[1].identificador = 0;

    file = fopen(catalogo_path, "r");
    
    if(!file){ //Se o programa nao conseguir ler o arquivo, o programa e encerrado.
        printf("Nao foi possivel abrir o arquivo 'catalogo.txt'. Encerrando o programa.\n");
        exit (1);
    }
    
    for(i=1; !feof(file); i++){
        lerInfoImovel(file, im, i);
        lerInfoTipo(file, im, i);
    }
    
    fclose(file);
    i--;

    if(im->imoveis[1].identificador == 0){ //Se o identificador do 1º item do Catalogo continuar 0, significa que nao houve leitura do arquivo "Catalogo.txt", portanto, possui 0 imoveis
        i = 0;
    }

    im->numImoveis = i;
}

void removeImovel(tImobiliaria *im, int j){
    for(int i=j; i<im->numImoveis; i++){ //Remove o Identificador copiando todos os itens a frente dele
        im->imoveis[i] = im->imoveis[i+1];
    }

    im->numImoveis -= 1; //Remove o numero de Imoveis do Catalogo
}

//Faz a leitura de todas as operacoes do arquivo "atual.txt"
void lerOperacoes(tImobiliaria *im){
    FILE *file;
    char operacao;
    char tipoAux[tipoMax];
    int identAux;
    char atual_path[150];
    scanf("%s", atual_path);

    file = fopen(atual_path, "r");
    
    if(!file){ //Se o programa nao conseguir ler o arquivo, o programa e encerrado.
        printf("Nao foi possivel abrir o arquivo 'atual.txt'. Encerrando o programa.\n");
        exit (1);
    }

    while(!feof(file)){
        fscanf(file, "%c\n", &operacao);

        if(operacao == 'i'){ //Inclusao
            im->numImoveis+=1; //Adiciona mais um item no catalogo
            lerInfoImovel(file, im, im->numImoveis);
            lerInfoTipo(file, im, im->numImoveis);
        }
        else if(operacao == 'e'){ //Exclusao
            fscanf(file, "%d\n", &identAux); //Leitura do identificador a ser excluido

            for(int i=1; i<=im->numImoveis; i++){ //Busca pelo Identificador no Catalogo
                if(im->imoveis[i].identificador == identAux){
                    removeImovel(im, i); //Quando encontra o Identificador, ele e removido do Catalogo
                }
            }

            fscanf(file, "\n");
        }
        else if(operacao == 'a'){ //Alteracao
            fscanf(file, "%s\n", tipoAux); //Leitura do tipo a ser alterado
            fscanf(file, "%d\n", &identAux); //Leitura do Identificador a ser alterado

            for(int i=1; i<=im->numImoveis; i++){
                if(im->imoveis[i].identificador == identAux){ //Busca o Identificador no Catalogo para alterar suas informacoes
                    strcpy(im->imoveis[i].tipo, tipoAux); //Faz a copia do tipo lido para o tipo do imovel do catalogo
                    fscanf(file, "%[^\n]\n", im->imoveis[i].proprietario); //Faz a leitura do proprietario alterado
                    lerInfoTipo(file, im, i);
                }
            }
        }
    }

    fclose(file);
}

//Adiciona o Preco a todos os Imoveis
void adicionarPreco(tImobiliaria *im){

    for(int i=1; i<=im->numImoveis; i++){
        if(strcmp(im->imoveis[i].tipo, "triang") == 0){//Se for triangulo, acessa a opcao triangulo
            im->imoveis[i].preco = calculaPrecoTriangular(&im->imoveis[i].categoria.triang);
        }
        else if(strcmp(im->imoveis[i].tipo, "retang") == 0){//Se for retangulo, acessa a opcao retangulo
            im->imoveis[i].preco = calculaPrecoRetangular(&im->imoveis[i].categoria.retang);
        }
        else if(strcmp(im->imoveis[i].tipo, "trapez") == 0){//Se for trapezio, acessa a opcao trapezio
            im->imoveis[i].preco = calculaPrecoTrapezoidal(&im->imoveis[i].categoria.trapez);
        }
        else if(strcmp(im->imoveis[i].tipo, "casa") == 0){//Se for casa, acessa a opcao casa
            im->imoveis[i].preco = calculaPrecoCasa(&im->imoveis[i].categoria.casa);
        }
        else if(strcmp(im->imoveis[i].tipo, "apto") == 0){//Se for apartamento, acessa a opcao apartamento
            im->imoveis[i].preco = calculaPrecoApartamento(&im->imoveis[i].categoria.apto);
        }
    }
}

//Ordenacao do Catalogo de acordo com a funcao passada
void ordenarCatalogo(tImobiliaria *im, int (*troca)(tCatalogo *, tCatalogo *) ){
    tCatalogo aux;
    
    for(int i=1; i<=im->numImoveis-1; i++){
        for(int j=1; j<=im->numImoveis-1; j++){
            if(troca(&im->imoveis[j], &im->imoveis[j+1])){
                aux = im->imoveis[j];
                im->imoveis[j] = im->imoveis[j+1];
                im->imoveis[j+1] = aux;
            }
        }
    }
}

//Compara Preco dos Imoveis
int comparaPreco(tCatalogo *c1, tCatalogo *c2){
    if(c1->preco > c2->preco){
        return 1;
    }
    if(c1->preco == c2->preco && c1->identificador > c2->identificador){
        return 1;
    }
    return 0;
}

//Compara Quantidade de Quarto das Casas
int comparaQuartos(tCatalogo *c1, tCatalogo *c2){
    if(c1->categoria.casa.quartos < c2->categoria.casa.quartos){
        return 1;
    }
    if(c1->categoria.casa.quartos == c2->categoria.casa.quartos && c1->identificador < c2->identificador){
        return 1;
    }
    return 0;
}

//Faz Ordenacao por Area dos Imoveis
void ordenarPorAreas(tImobiliaria *im, float *areas){
    tCatalogo auxIm;
    float auxAreas;
    
    
    for(int i=1; i<=im->numImoveis-1; i++){
        for(int j=1; j<=im->numImoveis-1; j++){
            if( (areas[j] < areas[j+1]) || (areas[j] == areas[j+1] && im->imoveis[j].identificador < im->imoveis[j+1].identificador) ){
                auxAreas = areas[j];
                areas[j] = areas[j+1];
                areas[j+1] = auxAreas;

                auxIm = im->imoveis[j];
                im->imoveis[j] = im->imoveis[j+1];
                im->imoveis[j+1] = auxIm;
            }
        }
    }
}
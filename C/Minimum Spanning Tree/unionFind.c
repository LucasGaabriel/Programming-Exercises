#include <stdio.h>
#include "unionFind.h"

//Inicializa uma UnionFind
UnionFind* init_UF(int qtdPontos){
  UnionFind* uf = (UnionFind*) malloc (sizeof(UnionFind));

  uf->id = (int*) malloc (sizeof(int) * qtdPontos);
    
  uf->sz = (int*) malloc (sizeof(int) * qtdPontos);

  //Inicializa cada ponto com sua propria componente (id) e a quantidade de objetos em 1
  for(int i=0; i<qtdPontos; i++){
    uf->id[i] = i;
    uf->sz[i] = 1;
  }

  return uf;
}

//Busca a componente de um ponto
int find_UF(UnionFind* uf, int p){
  int raiz = p;
  int prox;

  //Busca o pai até a raiz
  while(raiz != uf->id[raiz]){
    raiz = uf->id[raiz];
  }

  //Compressão de Caminho
  while(p != raiz){
    prox = uf->id[p];
    uf->id[p] = raiz;
    p = prox;
  }

  return raiz;
}

//Faz a uniao de 2 pontos
void union_UF(UnionFind* uf, int p, int q){

  int i = find_UF(uf, p);

  int j = find_UF(uf, q);

  if(i == j)
    return;

  //Verifica qual grupo tem menos componentes
  if(uf->sz[i] < uf->sz[j]){ 
    uf->sz[j] += uf->sz[i];
    uf->id[i] = j;
  }
  else {
    uf->sz[i] += uf->sz[j];
    uf->id[j] = i;
  }
}

//Verifica se 2 pontos estão conectados
int connected_UF(UnionFind* uf, int p, int q){
  return find_UF(uf, p) == find_UF(uf, q);
}

//Gera a MST e "retira" as k-1 arestas de maior peso
UnionFind* algoritmoDeKruskal(Graph* grafo, int k){
  if(grafo == NULL){
    return NULL;
  }

  UnionFind* uf = init_UF(grafo->V);

  //Vetor de inteiros para guardar os indices das arestas que serão conectadas.
  int* indicesConexao = malloc (sizeof(int) * grafo->E);
  int nIndices = 0;

  //Conecta os vertices a partir das arestas de menor peso
  for(int i=0; i < (grafo->E); i++){
    if(!connected_UF(uf, grafo->edge[i].in, grafo->edge[i].out)){

      // Se os pontos da aresta não estão conectados, faz a união dos pontos
      union_UF(uf, grafo->edge[i].in, grafo->edge[i].out);

      indicesConexao[nIndices] = i;
      nIndices++;
    }
  }

  //Libera a UnionFind para ser inicializada do zero novamente
  liberaUnionFind(uf);

  //Inicializa a unionFind novamente
  uf = init_UF(grafo->V);

  //Encontra o limite para fazer a conexao das arestas, levando em consideracao o inteiro 'k'
  int limConexao = indicesConexao[nIndices - k];

  //Faz a conexao a partir dos vertices de menor peso novamente, porém agora com um limite definido
  for(int i=0; i <= limConexao; i++){
    if(!connected_UF(uf, grafo->edge[i].in, grafo->edge[i].out)){

      // Se os pontos da aresta não estão conectados, faz a união dos pontos
      union_UF(uf, grafo->edge[i].in, grafo->edge[i].out);
    }
  }

  free(indicesConexao);

  return uf;
}

//Libera memoria da UnionFind
void liberaUnionFind(UnionFind* uf){
  free(uf->id);
  free(uf->sz);
  free(uf);
}

//Imprime os grupos encontrados no arquivo de saida ordenados
void imprimeGrupos(UnionFind* uf, char* nomePontos[], Graph* grafo, char* nome_arquivo_saida){

  FILE* arquivo_saida = fopen(nome_arquivo_saida, "w");

  int i, j;
  
  //Variaveis auxiliares para ordenacao
  char* aux;
  int auxUF;

  //Ordenando os nomes e ID da UF
  for(i=0; i<grafo->V-1; i++){
    for(j=0; j<grafo->V-1; j++){
      if(strcmp(nomePontos[j], nomePontos[j+1]) > 0){
        aux = nomePontos[j];
        nomePontos[j] = nomePontos[j+1];
        nomePontos[j+1] = aux;

        auxUF = uf->id[j];
        uf->id[j] = uf->id[j+1];
        uf->id[j+1] = auxUF;
      }
    }
  }

  //Variavel auxiliar que identifica se foi encontrado um grupo
  //Essa variável auxilia na escrita do arquivo, evitando caracteres de nova linha excessivos
  int find = 0;
  
  //Busca os pontos do mesmo grupo e escreve no arquivo
  for(i=0; i<grafo->V; i++){
    find = 0;

    //Busca todos os pontos do mesmo grupo e escreve no arquivo
    for(j=i; j<grafo->V; j++){

      if(uf->id[j] == uf->id[i] && uf->id[j] != -1){
        fprintf(arquivo_saida, "%s,", nomePontos[j]);

        //Para os pontos já escritos no arquivo, define sua id como -1, garantindo que o mesmo ponto não será escrito várias vezes no arquivo
        if(j != i)
          uf->id[j] = -1;

        find = 1;

      }
    }

    uf->id[i] = -1;

    if(find){
      //Reposiciona o ponteiro para apagar a vírgula que sobrou.
      fseek(arquivo_saida, -1, SEEK_CUR ); 

      //Substitui a vírgula por uma quebra de linha.
      fputc('\n', arquivo_saida); 
    }
  }

  fclose(arquivo_saida);
}
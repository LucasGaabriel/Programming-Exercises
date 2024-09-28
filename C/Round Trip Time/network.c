//Nome: Lucas Gabriel de Oliveira Costa
//Matrícula: 2019109482
//Disciplina: Estruturas de Dados II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "network.h"
#include "pq.h"

//Estrutura da Rede (Guarda um Conjunto específico, que pode ser de Servidores, Monitores ou Clientes)
struct network {
    double** weights;   // Pesos das arestas entre os nós do Conjunto com os demais Nós
    int* map;           // Identificadores dos nós que formam o conjunto
    int qtd;            // Quantidade de nós do conjunto
};

//Estrutura auxiliar para guardar as inflações e ordenar
typedef struct {
    int source;
    int target;
    double value;
} Inflacao;

//Inicializa uma matriz de double
static double** Array_init(int linhas, int colunas){
    double** a = (double**) malloc (sizeof(double*) * linhas);

    for(int i=0; i<linhas; i++){
        a[i] = (double*) calloc (colunas, sizeof(double));
    }

    return a;
}

//Inicializa uma matriz "sem colunas" (Um vetor de ponteiros com tamanho 'linhas')
static double** Array_initWithoutColumns(int linhas){
    double** a = (double**) malloc (sizeof(double*) * linhas);

    return a;
}

//Libera memoria de uma matriz
static void Array_finish(double** array, int linhas){
    for(int i=0; i<linhas; i++){
        free(array[i]);
    }
    free(array);
}

//Inicializa um tipo Network
Network* Network_init(int* map, int qtd){
    Network* n = (Network*) malloc (sizeof(Network));

    //Inicializa uma matriz de pesos "sem colunas" (Vetor de ponteiros)
    //As colunas serão preenchidas e alocadas depois usando Dijkstra
    double** weights = Array_initWithoutColumns(qtd);

    n->weights = weights;
    n->map = map;
    n->qtd = qtd;

    return n;
}

//Libera a memoria do tipo Network
void Network_finish(Network* network){
    Array_finish(network->weights, network->qtd);
    free(network->map);
    free(network);
}

//Calcula o peso de um Conjunto usando Dijkstra
static void CalculateWeightsArrays(Graph* graph, Network* network){
    for(int i=0; i<network->qtd; i++){
        network->weights[i] = Dijkstra(graph, network->map[i]);
    }
}

//Cálculo do RTT entre 2 conjuntos
static double** CalculateRTTs_BetweenSets(Network* set1, Network* set2){
    double** RTT_Set1Set2 = Array_init(set1->qtd, set2->qtd);

    for(int i=0; i < set1->qtd; i++){
        for(int j=0; j < set2->qtd; j++){
            RTT_Set1Set2[i][j] = set1->weights[i][set2->map[j]] + set2->weights[j][set1->map[i]];
        }
    }

    return RTT_Set1Set2;
}

//Compara inflações para ordenação
static int comparaInflacoes(const void* x, const void* y){
    Inflacao* a = (Inflacao*)x;
    Inflacao* b = (Inflacao*)y;

    if(a->value < b->value)
        return -1;
    else if(a->value == b->value)
        return 0;
    else
        return 1;
}

//Cálculo das inflações dos RTTs
void InflacaoRTTs(char* arquivoEntrada, char* arquivoSaida){

    //Abre arquivo de entrada para leitura
    FILE* entrada = fopen(arquivoEntrada, "r");

    if(!entrada){
        printf("Não foi possível ler o arquivo de entrada.\n");
        exit(EXIT_FAILURE);
    }

    int qtdVertices, qtdArestas, id;
    int qtdServidores, qtdClientes, qtdMonitores;

    //Leitura das primeiras linhas do arquivo
    fscanf(entrada, "%d %d", &qtdVertices, &qtdArestas);
    fscanf(entrada, "%d %d %d", &qtdServidores, &qtdClientes, &qtdMonitores);

    //Inicializa um grafo com V = qtdVertices; E = qtdArestas
    Graph* graph = Graph_init(qtdVertices, qtdArestas);

    //Vetores para guardar os nós que são servidores, clientes e monitores
    int* id_servidores = malloc(sizeof(int) * qtdServidores);
    int* id_clientes = malloc(sizeof(int) * qtdClientes);
    int* id_monitores = malloc (sizeof(int) * qtdMonitores);

    //Guarda os nós que são servidores
    for(int i=0; i<qtdServidores; i++) {
        fscanf(entrada, "%d", &id);
        id_servidores[i] = id;
    }

    //Guarda os nós que são clientes
    for(int i=0; i<qtdClientes; i++){
        fscanf(entrada, "%d", &id);
        id_clientes[i] = id;
    }

    //Guarda os nós que são monitores
    for(int i=0; i<qtdMonitores; i++){
        fscanf(entrada, "%d", &id);
        id_monitores[i] = id;
    }

    int sourceVert, targetVert;
    double value;

    //Adiciona os nós com seus pesos no grafo
    for(int i=0; i<Graph_getNumE(graph); i++){
        fscanf(entrada, "%d %d %lf", &sourceVert, &targetVert, &value);
        Graph_newNode(graph, sourceVert, targetVert, value);
    }
    
    //Fecha o arquivo de entrada
    fclose(entrada);

    //Inicializa o conjunto de Servidores, Clientes e Monitores
    Network* servidores = Network_init(id_servidores, qtdServidores);
    Network* clientes = Network_init(id_clientes, qtdClientes);
    Network* monitores = Network_init(id_monitores, qtdMonitores);

    //Calcula os menores caminhos entre os nós do grafo partindo de cada conjunto
    CalculateWeightsArrays(graph, servidores);
    CalculateWeightsArrays(graph, clientes);
    CalculateWeightsArrays(graph, monitores);

    //Matrizes para cálculo dos RTTs entre 2 conjuntos
    double** RTT_ServidoresClientes = CalculateRTTs_BetweenSets(servidores, clientes);
    double** RTT_MonitoresClientes = CalculateRTTs_BetweenSets(monitores, clientes);
    double** RTT_MonitoresServidores = CalculateRTTs_BetweenSets(monitores, servidores);

    //Matriz para cálculo dos RTTs Estimados
    double** RTT_ServidoresClientes_Estimated = Array_init(servidores->qtd, clientes->qtd);

    //Inicializa toda a Matriz com Infinito (Necessário para buscar o menor caminho)
    for(int i=0; i<servidores->qtd; i++){
        for(int j=0; j<clientes->qtd; j++){
            RTT_ServidoresClientes_Estimated[i][j] = INFINITY;
        }
    }

    //Para guardar os nós e as inflações
    Inflacao* inflacoes = malloc (sizeof(Inflacao) * qtdServidores * qtdClientes);

    //Cálculo dos RTTs Estimados
    for(int i=0, x=0; i<servidores->qtd; i++){
        for(int j=0; j<clientes->qtd; j++){

            //Inclui os nós no vetor de inflações
            inflacoes[x].source = servidores->map[i];
            inflacoes[x].target = clientes->map[j];
            x++;

            //Passa pelos monitores, buscando dentre eles o que possui o menor caminho
            for(int k=0; k<monitores->qtd; k++){

                double weight = RTT_MonitoresServidores[k][i] + RTT_MonitoresClientes[k][j];

                //Se o caminho encontrado for menor que o menor caminho (peso) já encontrado, substitui
                if(weight < RTT_ServidoresClientes_Estimated[i][j]) {
                    RTT_ServidoresClientes_Estimated[i][j] = weight;
                }
            }
        }
    }

    //Calcula as inflações { RTT*(a,b) / RTT(a,b) } e coloca no vetor de inflações
    for(int i=0, x=0; i<servidores->qtd; i++){
        for(int j=0; j<clientes->qtd; j++){
            inflacoes[x].value = RTT_ServidoresClientes_Estimated[i][j]/RTT_ServidoresClientes[i][j];
            x++;
        }
    }

    //Abre o arquivo de saida para escrita
    FILE* saida = fopen(arquivoSaida, "w");

    if(!saida){
        printf("Não foi possível criar o arquivo para escrita.\n");
        exit(EXIT_FAILURE);
    }

    //Ordena crescentemente as inflações pelo valor
    qsort(inflacoes, (servidores->qtd * clientes->qtd), sizeof(Inflacao), comparaInflacoes);

    //Escreve no arquivo de saida os nós e as inflações
    for(int i=0; i<(servidores->qtd * clientes->qtd); i++){
        fprintf(saida, "%d %d %lf\n", inflacoes[i].source, inflacoes[i].target, inflacoes[i].value);
    }
    
    //Fecha o arquivo de saída
    fclose(saida);

    //Liberação de memória
    Array_finish(RTT_ServidoresClientes, servidores->qtd);
    Array_finish(RTT_MonitoresClientes, monitores->qtd);
    Array_finish(RTT_MonitoresServidores, monitores->qtd);

    Array_finish(RTT_ServidoresClientes_Estimated, servidores->qtd);

    Network_finish(servidores);
    Network_finish(clientes);
    Network_finish(monitores);

    free(inflacoes);

    Graph_finish(graph);
}

double* Dijkstra(Graph* graph, int source){

    //Inicializa um vetor de distâncias (peso)
    double* dist = (double*) malloc (sizeof(double) * Graph_getNumV(graph));

    //Inicializa a Fila de Prioridades
    PriorityQueue* pq = PQ_init(Graph_getNumV(graph));
    Item t;

    //Inicializa todos os nós na Fila de Prioridades (Exceto o 'source')
    for(int i=0; i<Graph_getNumV(graph); i++){
        if(i != source){
            dist[i] = INFINITY; //Distancia de 'source' até 'i' desconhecida
            t = make_item(i, dist[i]);
            PQ_insert(pq, t);
        }
    }

    //Inicializa o peso de 'source' -> 'source' como 0
    dist[source] = 0;
    t = make_item(source, 0);
    PQ_insert(pq, t);

    double alt;

    while(!PQ_empty(pq)){
        Item u = PQ_delmin(pq); //Recebe o Item com maior prioridade (menor peso) e remove da Fila de Prioridade

        for(List* p = Graph_getListAdjNode(graph, id(u)); p != NULL; p = List_getNextNode(p)){

            alt = dist[id(u)] + (List_getValue(p));

            if(alt < dist[List_getVert(p)] && dist[id(u)] != INFINITY){

                dist[List_getVert(p)] = alt;
                PQ_decrease_key(pq, List_getVert(p), alt);

            }
        }
    }

    //Libera memória da Fila de Prioridade
    PQ_finish(pq);

    //Retorna o vetor contendo as menores distâncias entre os nós
    return dist;
}

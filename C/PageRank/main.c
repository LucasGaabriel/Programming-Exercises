#include "graph.h"
#include "index.h"
#include "vPagina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_INIC 20
#define TAM 1000

int main(int argc, char *argv[]) {
    if (argc < 2) return EXIT_FAILURE;

    //Leitura do 'graph.txt'
    char *enderecoGraph = malloc(sizeof(char) * TAM);
    strcpy(enderecoGraph, argv[1]);
    enderecoGraph = strcat(enderecoGraph, "/graph.txt");
    Graph *graph = Graph_ReadFile(enderecoGraph);

    //Cálculo dos PageRanks
    double *pageRanks = Graph_pageRanks(graph);

    Index *index = index_leitura(argv[1]);

    size_t size = SIZE_INIC;
    char *line = (char *) malloc(sizeof(char) * size);
    vPagina *vPag;

    while (getline(&line, &size, stdin) > 0) {
        fprintf(stdout, "search:%spages:", line);
        vPag = index_consulta(index, line);
        inserePageRanks(graph, vPag, pageRanks);
        qsort(vPag_pags(vPag), vPag_len(vPag), sizeof(Pagina*), compPag); //Ordena os pageranks.
        vPag_imprime(vPag, stdout);
        vPag_libera_mantemPags(vPag); // Libera o vetor paginas sem liberar as paginas.
    }

    //Liberação da memória alocada
    Graph_finish(graph);
    free(pageRanks);
    free(enderecoGraph);
    free(line);
    index_libera(index);

    return 0;
}
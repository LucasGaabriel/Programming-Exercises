//  Nome: Lucas Gabriel de Oliveira Costa
//  Disciplina: Estruturas de Dados I
//  Exercicio 12

#include <stdio.h>
#include "listaAlunos.h"

int main() {
    Aluno* lucas = inicializaAluno("Lucas", 100, 6.7);
    Aluno* carla = inicializaAluno("Carla", 101, 7.3);
    Aluno* felipe = inicializaAluno("Felipe", 102, 5.4);
    Aluno* claudia = inicializaAluno("Claudia", 103, 4.7);
    Aluno* ana = inicializaAluno("Ana", 104, 7.1);
    Aluno* patricia = inicializaAluno("Patricia", 105, 6.5);

    ListaGenerica* lista = inicializaLista();

    printf("Inserindo todos os alunos na Lista:\n");

    inserirNaLista(lista, lucas);
    inserirNaLista(lista, carla);
    inserirNaLista(lista, felipe);
    inserirNaLista(lista, claudia);
    inserirNaLista(lista, ana);
    inserirNaLista(lista, patricia);

    imprimeListaAlunos(lista);

    printf("\nAluno Lucas pertence a lista?\n");
    if(!pertenceAluno(lista, 100))
        printf("Sim!\n");
    else
        printf("Nao!\n");


    printf("\nAluno -Matricula Inexistente- pertence a lista?\n");
    if(!pertenceAluno(lista, 108))
        printf("Sim!\n");
    else
        printf("Nao!\n");


    printf("\nRetirando Felipe e Ana da Lista:\n");
    retiraAluno(lista, 102);
    retiraAluno(lista, 104);

    imprimeListaAlunos(lista);

    printf("\nMedia da Turma: %.2f\n", mediaTurma(lista));

    liberaAluno(lucas);
    liberaAluno(carla);
    liberaAluno(felipe);
    liberaAluno(claudia);
    liberaAluno(ana);
    liberaAluno(patricia);

    liberarLista(lista);

    return 0;
}

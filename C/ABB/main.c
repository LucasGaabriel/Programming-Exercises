// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio 10

#include <stdio.h>
#include "abb.h"

int main() {
    Aluno* lucas = inicializaAluno("Lucas", 100, 6.7);
    Aluno* carla = inicializaAluno("Carla", 101, 7.3);
    Aluno* felipe = inicializaAluno("Felipe", 102, 5.4);
    Aluno* claudia = inicializaAluno("Claudia", 103, 4.7);
    Aluno* ana = inicializaAluno("Ana", 104, 7.1);
    Aluno* patricia = inicializaAluno("Patricia", 105, 6.5);

    printf("Criando uma arvore e inserindo alunos em uma ordem aleatoria:\n");
    Arvore* arvore = criaAbb(felipe);
    inserirAbb(arvore, claudia);
    inserirAbb(arvore, patricia);
    inserirAbb(arvore, ana);
    inserirAbb(arvore, lucas);
    inserirAbb(arvore, carla);

    printf("Verificando insercao e ordenamento por matricula:\n");
    imprimeAbb(arvore);

    printf("\nMatricula %d esta na arvore?\n", 104);
    if(buscaAbb(arvore, 104))
        printf("Sim\n");
    else
        printf("Nao\n");


    printf("\nMatricula %d esta na arvore?\n", 106);
    if(buscaAbb(arvore, 106))
        printf("Sim\n");
    else
        printf("Nao\n");


    printf("\nMatricula %d esta na arvore?\n", 101);
    if(buscaAbb(arvore, 101))
        printf("Sim\n");
    else
        printf("Nao\n");


    printf("\nRetirando Felipe e Patricia:\n");
    retirarAbb(arvore, 102);
    retirarAbb(arvore, 105);

    imprimeAbb(arvore);

    liberarAbb(arvore);

    liberaAluno(lucas);
    liberaAluno(carla);
    liberaAluno(felipe);
    liberaAluno(claudia);
    liberaAluno(ana);
    liberaAluno(patricia);

    return 0;
}

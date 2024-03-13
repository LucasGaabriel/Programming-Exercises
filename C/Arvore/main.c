// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_9

#include <stdio.h>
#include "arvore.h"

int main() {
    Aluno* lucas = inicializaAluno("Lucas", 100, 6.7);
    Aluno* carla = inicializaAluno("Carla", 101, 7.3);
    Aluno* felipe = inicializaAluno("Felipe", 102, 5.4);
    Aluno* claudia = inicializaAluno("Claudia", 103, 4.7);
    Aluno* ana = inicializaAluno("Ana", 104, 7.1);
    Aluno* patricia = inicializaAluno("Patricia", 105, 6.5);

    Arvore* arvore;

    printf("Criando uma arvore com 6 Alunos:\n\n");
    arvore = criaArvore(lucas,
               criaArvore(carla,
                          criaArvore(felipe, criaArvoreVazia(), criaArvoreVazia()),
                          criaArvoreVazia()),
               criaArvore(claudia,
                          criaArvore(ana, criaArvoreVazia(), criaArvoreVazia()),
                          criaArvore(patricia, criaArvoreVazia(), criaArvoreVazia())));

    printf("Imprimindo a arvore:\n");
    imprimeArvore(arvore);
    printf("\n\n");

    printf("Quantidade de folhas da arvore: %d\n\n", folhas(arvore));

    printf("Altura da arvore: %d\n\n", altura(arvore));

    printf("Claudia pertence a arvore? (%d)\n", pertence(arvore, "Claudia"));
    printf("Joao pertence a arvore? (%d)\n", pertence(arvore, "Joao"));
    printf("\n");

    printf("Quantidade de ocorrencias do Aluno %s: %d\n\n", retornaNomeAluno(lucas), ocorrencias(arvore, lucas));

    printf("Criando +1 nó com o Aluno %s:\n", retornaNomeAluno(lucas));
    arvore = criaArvore(lucas, arvore, criaArvoreVazia());
    printf("Imprimindo a arvore:\n");
    imprimeArvore(arvore);
    printf("\n\n");

    printf("Quantidade de ocorrencias do Aluno %s: %d\n\n", retornaNomeAluno(lucas), ocorrencias(arvore, lucas));

    printf("Altura da arvore: %d\n\n", altura(arvore));

    printf("Pai do(a) %s: %s\n\n", retornaNomeAluno(patricia), retornaNomeAluno(retornaAlunoDoNo(retornaPai(arvore, patricia))));

    printf("Pai do(a) %s: %s\n\n", retornaNomeAluno(carla), retornaNomeAluno(retornaAlunoDoNo(retornaPai(arvore, carla))));

    liberaArvore(arvore);

    liberaAluno(lucas);
    liberaAluno(carla);
    liberaAluno(felipe);
    liberaAluno(claudia);
    liberaAluno(ana);
    liberaAluno(patricia);

    return 0;
}

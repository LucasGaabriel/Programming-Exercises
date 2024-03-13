// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_8

#include <stdio.h>
#include "fila.h"

/*  Esse testador funciona para a implementacao de Fila com Vetor e Fila com Lista;
 *  Só deve ser levado em consideracao que na implementacao de Fila com vetor, ha limite no tamanho da fila,
 *  entao se o vetor estiver cheio, nao vai ser possivel inserir elemento na fila, o que nao acontece com a Fila com Lista,
 *  que possui um limite "infinito" (limitado ao hardware)!
 */

int main() {
    Fila* fila1 = inicializaFila();

    Aluno* marcia = inicializaAluno("Marcia", 111, 7.55);
    Aluno* carla = inicializaAluno("Carla", 112, 6.87);
    Aluno* lucas = inicializaAluno("Lucas", 113, 8.32);
    Aluno* felipe = inicializaAluno("Felipe", 114, 9.17);

    inserirNaFila(fila1, marcia);
    inserirNaFila(fila1, carla);
    inserirNaFila(fila1, lucas);
    inserirNaFila(fila1, felipe);

    printf("Imprimindo Fila 1:\n");
    imprimirFila(fila1);

    printf("Retirando 2 Alunos da Fila 1 e adicionando na Fila 2:\n");
    Fila* fila2 = inicializaFila();
    inserirNaFila(fila2, retirarDaFila(fila1));
    inserirNaFila(fila2, retirarDaFila(fila1));

    printf("Imprimindo Fila 1:\n");
    imprimirFila(fila1);
    printf("Imprimindo Fila 2:\n");
    imprimirFila(fila2);

    printf("Retirando os Alunos restantes da Fila 1 e Adicionando na Fila 2:\n");
    inserirNaFila(fila2, retirarDaFila(fila1));
    inserirNaFila(fila2, retirarDaFila(fila1));

    printf("Imprimindo Fila 1:\n");
    imprimirFila(fila1);
    printf("Imprimindo Fila 2:\n");
    imprimirFila(fila2);

    Aluno* andre = inicializaAluno("Andre", 115, 5.5);
    Aluno* ana = inicializaAluno("Ana", 116, 6.21);

    printf("Tentando inserir na Fila cheia:\n");
    inserirNaFila(fila2, andre);
    inserirNaFila(fila2, ana);

    printf("Imprimindo Fila 2:\n");
    imprimirFila(fila2);

    printf("Tentando retirar de uma fila vazia:\n");
    retirarDaFila(fila1);

    printf("Imprimindo Fila 1:\n");
    imprimirFila(fila1);
    printf("Imprimindo Fila 2:\n");
    imprimirFila(fila2);

    liberaAluno(marcia);
    liberaAluno(carla);
    liberaAluno(lucas);
    liberaAluno(felipe);
    liberaAluno(andre);
    liberaAluno(ana);

    liberarFila(fila1);
    liberarFila(fila2);

    return 0;
}

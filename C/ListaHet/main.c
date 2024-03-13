// Nome: Lucas Gabriel de Oliveira Costa
// Disciplina: Estruturas de Dados I
// Exercicio_6

#include <stdio.h>
#include "listahet.h"

int main() {
    Aluno* marcia = inicializaAluno("Marcia", 111, 7.55);
    Aluno* carla = inicializaAluno("Carla", 112, 6.87);
    Aluno* lucas = inicializaAluno("Lucas", 113, 8.32);

    Professor* patricia = inicializaProfessor("Patricia", 211, 6200);
    Professor* jose = inicializaProfessor("Jose", 212, 5600);
    Professor* claudia = inicializaProfessor("Claudia", 213, 6800);

    Lista* churrasco = inicializaLista();

    inserirAlunoNaLista(churrasco, marcia);
    inserirProfessorNaLista(churrasco, patricia);
    inserirAlunoNaLista(churrasco, carla);
    inserirProfessorNaLista(churrasco, jose);
    inserirAlunoNaLista(churrasco, lucas);
    inserirProfessorNaLista(churrasco, claudia);

    printf("Imprimindo a Lista do Churrasco:\n");
    imprimirLista(churrasco);

    printf("\nRetirando no Meio, Inicio e Fim:\n");
    retirarDaLista(churrasco, "Jose");
    retirarDaLista(churrasco, "Marcia");
    retirarDaLista(churrasco, "Claudia");
    imprimirLista(churrasco);

    printf("\nInserindo novamente na lista:\n");
    inserirProfessorNaLista(churrasco, jose);
    inserirAlunoNaLista(churrasco, marcia);
    inserirProfessorNaLista(churrasco, claudia);
    imprimirLista(churrasco);

    printf("\nChurrasco CANCELADO - Retirando TODO MUNDO da lista:\n");
    retirarDaLista(churrasco, "Marcia");
    retirarDaLista(churrasco, "Patricia");
    retirarDaLista(churrasco, "Carla");
    retirarDaLista(churrasco, "Jose");
    retirarDaLista(churrasco, "Lucas");
    retirarDaLista(churrasco, "Claudia");
    imprimirLista(churrasco);

    printf("\nRemarcando o churrasco! Chamando a galera de volta :)\n");
    inserirAlunoNaLista(churrasco, marcia);
    inserirProfessorNaLista(churrasco, patricia);
    inserirAlunoNaLista(churrasco, carla);
    inserirProfessorNaLista(churrasco, jose);
    inserirAlunoNaLista(churrasco, lucas);
    inserirProfessorNaLista(churrasco, claudia);
    imprimirLista(churrasco);

    printf("\nValor total arrecadado para o Churrasco: %.2f\n", valorChurrasco(churrasco));

    liberarLista(churrasco);

    liberaAluno(marcia);
    liberaAluno(carla);
    liberaAluno(lucas);
    liberaProfessor(patricia);
    liberaProfessor(jose);
    liberaProfessor(claudia);

    printf("\nChurrasco finalizado!\n");
    return 0;
}

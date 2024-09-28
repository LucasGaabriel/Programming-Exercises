#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define TAM_MAX 500
#define ARRAY_SIZE_MAX 10

// Função para imprimir o array de inteiros
void ImprimirArray(int arr[], int size) {
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {

    // Definição dos Pipes
    int to_p1[2];
    int to_p2[2];

    // Criação dos Pipes
    if (pipe(to_p1) < 0 || pipe(to_p2) < 0) {
        perror("Erro ao criar pipes");
        exit(EXIT_FAILURE);
    }

    pid_t p0 = getpid();

    // Criando o primeiro filho (P1)
    pid_t p1 = fork();

    if (p1 < 0) {

        perror("Erro ao criar P1");
        exit(EXIT_FAILURE);

    } else if (p1 == 0) { // Filho P1

        close(to_p1[1]); // Fecha a extremidade de escrita do pipe usado pelo P1

        // Recebe e imprime a mensagem enviada pelo pai P0
        int x;
        read(to_p1[0], &x, sizeof(x));
        printf("Mensagem recebida pelo P1: ");
        char message[TAM_MAX];
        read(to_p1[0], message, sizeof(message));
        printf("%s\n", message);

        // Cria e envia o array para P2
        srand(time(NULL));
        int array_size = rand() % 10 + 1;
        int array[ARRAY_SIZE_MAX] = {0};
        for (int i = 0; i < array_size; i++) {
            array[i] = rand() % x + 1;
        }

        close(to_p1[0]); // Fechando a extremidade de leitura do pipe usado pelo P1
        close(to_p2[0]); // Fechando a extremidade de leitura do pipe usado pelo P2

        write(to_p2[1], &array_size, sizeof(array_size)); // Envia o tamanho do array
        write(to_p2[1], array, sizeof(int) * array_size); // Envia o array para P2
        

        close(to_p2[1]); // Fechando a extremidade de escrita do pipe usado pelo P2

        exit(EXIT_SUCCESS);

    } else { // Processo Pai (P0)

        int x;
        printf("Digite um valor inteiro entre 1 e 5: ");
        scanf("%d", &x);

        close(to_p1[0]); // Fecha a extremidade de leitura do pipe usado pelo P0

        // Enviando o valor X para P1
        write(to_p1[1], &x, sizeof(x));

        // Enviando a mensagem para P1
        char message[] = "Meu filho, crie e envie para o seu irmão um array de inteiros com valores randômicos entre 1 e o valor enviado anteriormente.";
        write(to_p1[1], message, sizeof(message));

        close(to_p1[1]); // Fechando a extremidade de escrita do pipe usado pelo P0

        // Criando o segundo filho (P2)
        pid_t p2 = fork();
        if (p2 < 0) {

            perror("Erro ao criar P2");
            exit(EXIT_FAILURE);

        } else if (p2 == 0) { // Filho P2

            int array_size;
            read(to_p2[0], &array_size, sizeof(array_size)); // Recebe o tamanho do Array

            int array[array_size];
            read(to_p2[0], array, sizeof(array)); // Recebe o array de P1

            ImprimirArray(array, array_size);
            
            int sum = 0;
            for (int i = 0; i < array_size; i++) {
                sum += array[i];
            }

            close(to_p2[0]); // Fechando a extremidade de leitura do pipe usado pelo P2

            // Enviando o resultado da soma para P0
            write(to_p2[1], &sum, sizeof(int));

            close(to_p2[1]); // Fechando a extremidade de escrita do pipe usado pelo P2

            exit(EXIT_SUCCESS);

        } else { // Continuação do Pai P0

            int status;

            close(to_p2[1]); // Fecha a extremidade de escrita do pipe usado pelo P0

            // Esperando que P2 termine
            waitpid(p2, &status, 0);

            int sum;
            read(to_p2[0], &sum, sizeof(int)); // Recebendo o resultado da soma de P2
            printf("Resultado da soma dos valores do array: %d\n", sum);

            close(to_p2[0]); // Fechando a extremidade de leitura do pipe usado pelo P0

            int to_p3[2];

            if (pipe(to_p3)) {
                perror("Erro ao criar pipes");
                exit(EXIT_FAILURE);
            }

            // Criando o terceiro filho (P3)
            pid_t p3 = fork();
            if (p3 < 0) {

                perror("Erro ao criar P3");
                exit(EXIT_FAILURE);

            } else if (p3 == 0) { // Filho P3

                close(to_p3[0]);

                dup2(to_p3[1], 1);
                close(to_p3[1]);

                execlp("date", "date", NULL); // Executando o comando "date"

                exit(EXIT_FAILURE);

            } else { // P0
                
                // Espera o filho P3 Terminar
                waitpid(p3, NULL, 0);

                close(to_p3[1]);
                dup2(to_p3[0], 0);

                char message[TAM_MAX];
                read(to_p3[0], message, sizeof(message));
                printf("P0: Mensagem recebida pelo Filho P3: %s", message);

            }
        }
    }

    return 0;
}

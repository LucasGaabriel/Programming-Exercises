#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

/* Criamos a estrutura Monkey apenas para passar
*  esses dois valores quando chamamos pthread_creat()
*/
typedef struct {
    int id;
    char side;
} Monkey;

#define QTD_MONKEYS 10
#define QTD_GORILAS 2
#define SIDE_A 'A'
#define SIDE_B 'B'

// Garante exclusão mutua a ponte
sem_t mutex;

// Bloqueia gorila se tiver macaco ainda passando
sem_t free_gorila;

// Bloqueia macaco quando gorila deseja passar
sem_t free_monkey;

// Libera a passagem para o outro lado
sem_t free_side;

// Armazena o sentido atual da ponte
char side = 'N';

int monkey_count = 0;
int gorila_count = 0;

void* monkey_f(void* args) {
    // Sleepa um tempo randomico para representar a vontade de atravessar
    usleep(10000*(rand()%10)); // Sleep 0.01 to 0.1 sec
    Monkey *m = (Monkey*) args;
    printf("Monkey %d on side %c want to cross\n", m->id, m->side);

    // Acessa a região critica representada por 'monkey_count' e 'side'
    sem_wait(&mutex);
        if(side == 'N') {
            // Caso ponte vazia
            side = m->side;
            monkey_count++;       
            if(monkey_count == 1) {
               sem_wait(&free_side);
        }
        } else if(side == m->side) {
            // Caso deseja passar no msm sentido da ponte
            monkey_count++;
            if(monkey_count == 1) {
               sem_wait(&free_side);
        }
        } else {
            // Caso deseja passar mas o sentido está contrário
            sem_post(&mutex);
            sem_wait(&free_side);
            side = m->side;
            monkey_count++; 
        }
    sem_post(&mutex);

    // Crossing the Bridge indeed

    usleep(10000); // Sleepa 0.01 sec para representar o tempo atravessando

    // Acessando a região critica para atualizar os valores de 'monkey_count' e 'side' ao sair da ponte
    sem_wait(&mutex);
        printf("Monkey %d on side %c finish crossing\n", m->id, m->side);
        monkey_count--;
        if(monkey_count == 0) {
            side = 'N';
            sem_post(&free_side);
        }
    sem_post(&mutex);
}

/*
*   Não deu tempo de implementar, mas estava tranquilo,
*   iamos usar o free_gorila e mutex para controlar o acesso
*   e dar wait em free_monkey para bloquea-lo quando o gorila 
*   deseja passar.
*/ 
void* gorila_f(void* args) {
    usleep(10000*(rand()%10)); // Sleep 0.01 to 0.1 sec
    Monkey *g = (Monkey*) args;
    //printf("Gorila %d on side %c want to cross\n", g->id, g->side);


}

int main () {
    pthread_t th[QTD_MONKEYS];
    pthread_t th2[QTD_GORILAS];
    Monkey monkeys[QTD_MONKEYS];
    Monkey gorilas[QTD_GORILAS];

    // Inicializando os semáforos
    sem_init(&mutex, 0, 1);
    sem_init(&free_gorila, 0, 1);
    sem_init(&free_monkey, 0, 1);
    sem_init(&free_side, 0, 1);

    // Armazenando os sentido da ponte
    char side_a = SIDE_A;
    char side_b = SIDE_B;

    // Cria as threads dos Monkeys
    for(int i=0; i< QTD_MONKEYS; i++) {
        monkeys[i].id = i;
        if(i%2 == 0) {
            monkeys[i].side = side_a;
            pthread_create(&th[i], NULL, monkey_f, (void*)&monkeys[i]);
        } else {
            monkeys[i].side = side_b;
            pthread_create(&th[i], NULL, monkey_f, (void*)&monkeys[i]);
        }
    }

    // Cria as threads dos Gorilas
    for(int i=0; i< QTD_GORILAS; i++) {
        gorilas[i].id = i;
        if(i%2 == 0) {
            gorilas[i].side = side_a;
            pthread_create(&th2[i], NULL, gorila_f, (void*)&gorilas[i]);
        } else {
            gorilas[i].side = side_b;
            pthread_create(&th2[i], NULL, gorila_f, (void*)&gorilas[i]);
        }
    }

    // Esperando o fim das threads Monkeys
    for(int i=0; i< QTD_MONKEYS; i++) {
        pthread_join(th[i], NULL);
    }

    // Esperando o fim das threads Gorilas
    for(int i=0; i< QTD_GORILAS; i++) {
        pthread_join(th2[i], NULL);
    }

    return 0;
}

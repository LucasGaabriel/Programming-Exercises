#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

#define ADDKEY 123

typedef struct {
    int x;
    int y;
} Coord;

int main() {
    int shmid;
    int size = 10 * sizeof(Coord);
    Coord *mycoords;

    char* path = "./";

    if ((shmid = shmget(321, size, 0)) == -1) {
        perror("Erro no shmget");
        exit(1);
    }

    mycoords = (Coord*)shmat(shmid, NULL, 0);

    // Imprimindo o endereço de memória retornado pelo shmat
    printf("Endereço do segmento de memória anexado: %p\n", (void*)mycoords);

    for(;;);

    exit(0);
}

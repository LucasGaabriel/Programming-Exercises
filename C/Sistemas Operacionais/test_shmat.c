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

    shmid = shmget(ftok(path,ADDKEY), size, IPC_CREAT|0600);
   
    mycoords = (Coord*)shmat(shmid, NULL, 0);

    // mycoords[2].x = 5;
    // mycoords[2].y = 10;

    printf("Endereço do segmento de memória anexado: %p\n", (void*)mycoords);

    for(;;);

    exit(0);
}

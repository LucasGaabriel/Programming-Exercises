#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int a;

int fn() {
    a++;
    printf("X %d\n", a);
    exit(0);
}

void main(int argc, char **argv) {
    int val;
    a = 0;
    printf("Y %d\n", a);
    
    if (fork() == 0) {
        fn();
    }
    
    wait(&val);
    printf("Z %d - PID: %d, PAI: %d\n", a, getpid(), getppid());
}

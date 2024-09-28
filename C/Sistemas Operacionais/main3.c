#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pai = getpid();

    if(fork() || fork())
        fork();

    //printf("Sou o PID: %d, meu Pai é: %d\n", getpid(), getppid());

    printf("1 ");
    return 0;
}
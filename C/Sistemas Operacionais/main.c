#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int mypid = getpid();
    int a, b, c;
    int status;

    (a = fork()) && (b = fork()) && (c = fork());
    
    if(mypid == getpid()){
        for(int i=1; i<=3; i++){
            int filho = wait(&status);

            if(WIFEXITED(status)){
                printf("Filho(%d) terminado normalmente pelo sinal: %d\n", filho, WEXITSTATUS(status));
            }

            if(WIFSIGNALED(status)){
                printf("Filho(%d) terminado por um sinal: %d\n", filho, WTERMSIG(status));
            }
        }
        printf("Todos os filhos encerrados\n");
    }

    return 0;
}
#include <stdio.h>
#include <unistd.h>

int main(){
    int pid, pid2;
    printf("Hello world\n");
    printf("I am the parent process %d.\n",getpid());
    printf("Here i am b4 forking\n");
    pid=fork();
    printf("Here i am after forking\n");
    if(pid==0) {
        printf("I am the child process %d\n",getpid());
        
    }
    else {
        pid2 = fork();
        if(pid2==0) {
            printf("I am the second child process %d\n",getpid());
        }
        else {
            printf("I am the parent process %d.\n",getpid());
        }
    }
}

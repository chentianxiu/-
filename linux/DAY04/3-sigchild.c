#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void signal_handler()
{
    printf("child is ended!");
    fflush(stdout);
    wait(NULL);
}

int main()
{
    pid_t pid = fork();
    if (pid<0)
    {
        perror("fork error");
        return 1;
    }

    if (pid==0)
    {
        for (int i = 0; i < 5; i++)
        {
            printf("i am child...\n");
            sleep(1);
        }
        
    }
    else{

        if (signal(SIGCHLD,signal_handler)<0)
        {
            perror("signal error");
        }
        while(1);
    }
    
    return 0;
}
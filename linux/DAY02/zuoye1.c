#include<unistd.h> 
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid<0)
    {
        perror("pid error");
        return 1;
    }
    if (pid==0)
    {
        printf("Hello, World!\n");
    }
    else{
        printf("Child process ID: %d\n",pid);
        //pid_t pid2 = wait(NULL);
        //printf("child pid %d is end!\n",pid);

    }
    return 0;
}
#include<unistd.h> 
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    int k = 0;

    if (pid<0)
    {
        perror("pid error");
        return 1;
    }
    if (pid==0)
    {
        k++;
        printf("子进程k的值%d\n",k);
        printf("Child process ID: %d\n",getpid());
    }
    else{
        printf("父进程k的值%d\n",k);
        printf("parent process ID: %d\n",getpid());
        //pid_t pid2 = wait(NULL);
        //printf("child pid %d is end!\n",pid);
        
    }
    return 0;
}
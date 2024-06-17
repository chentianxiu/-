#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void signal_handler()
{   //收到信号之后
    printf("press ctrl+c\n");
    exit(EXIT_SUCCESS);
}

int main()
{
    if (signal(SIGINT,signal_handler)<0)
    {
        perror("signal error");
        exit(EXIT_FAILURE);
    }
    
    printf("running....\n");

    char buff[] = "-\\|/";
    char *p = buff;
    while (1)
    {
        if (*p =='\0')
            p = buff;
            printf(" ");
            printf("\b%c\b",*p);
            fflush(stdout);
            p++;
            usleep(500000);//0.5秒
    }
    return 0;
}


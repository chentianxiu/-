#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void siganl_handler()
{
    //收到信号之后
    printf("press ctrl+c\n");
    exit(EXIT_SUCCESS);
}


int main()
{
    if (signal(SIGINT,siganl_handler)<0)
    {
        perror("signal error");
        exit(EXIT_FAILURE);
    }

    printf("running...");
    char buff[] = "-\\|/";
    char *p = buff;
    while (1)
    {
        if (*p =='\0')
            p = buff;
            printf("\b%c",*p);
            fflush(stdout);
            p++;
            usleep(500000);//0.5秒
    }

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char cmd[100] = "ps -o ppid,pid,command";

    int res = system(cmd);

    if(res<0)
    {
        printf("run command failuer\n");
    }else{
        printf("run command success\n");
    }


    return 0;
}
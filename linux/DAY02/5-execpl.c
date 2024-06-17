#include<stdio.h>
#include<unistd.h>

int main()
{
    int res = execlp("ps","ps","-o","pid,ppid,command",NULL);

    if(res<0)
    {
        printf("run command failuer\n");
    }else{
        printf("run command success\n");
    }


    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    //创建管道
    int pipefd[2];
    if (pipe(pipefd)<0)
    {
        perror("pipe error");
        return 1;
    }

    //创建子进程
    pid_t pid = fork();
    if (pid<0)
    {
        perror("fork error");
        return 1;
    }

    if (pid==0)
    {
        //接受消息
        char buf[128]={0};
        read(pipefd[0],buf,sizeof(buf));
        printf("child receive:%s\n",buf);
    }
    else
    {
        //发送信息
        char * str = "i am parent\n";
        write(pipefd[1],str,strlen(str));
    }
    

    return 0;
    
}
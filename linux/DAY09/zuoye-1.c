/*
1、编写2个进程，进程1负责循环输出 “hello world”，并且使用进程间信号量进行阻塞
(只输出1次“hello world”)，进程2负责当按ctrl+c的时候，解除进程1的阻塞。也就是说：
当进程2按一次 ctrl+c的时候，进程1循环就解除一次阻塞，输出“hello world”(信号1分，
进程间信号量的使用1分，信号量删除1分)
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int num = 0;

void sem_post(int semid,int num)
{
    struct sembuf sops = {};
    sops.sem_flg = SEM_UNDO;
    sops.sem_num = num;
    sops.sem_op = 1;
    semop(semid,&sops,1);
}

void sem_wait(int semid,int num)
{
    struct sembuf sops={};
    sops.sem_flg = SEM_UNDO;
    sops.sem_num = num;
    sops.sem_op = -1;
    semop(semid,&sops,1);
}

void signal_handler(int sig)
{
    num++;
}

int main(){

    //创建key
    key_t mykey = ftok("zuoye-1.c",1);
    int semid = semget(mykey,2,IPC_CREAT|0666);
    semctl(semid,0,SETVAL,1);
    semctl(semid,1,SETVAL,0);

    
    pid_t pid=fork();
    if (pid<0)
    {
        perror("fork error");
        return 1;
    }
    if (pid==0)//子进程操作 循环输出helloworld
    {
        while (1)
        {
            sem_wait(semid,1);
            printf("hello world\n");
            sem_post(semid,0);
        }
        
    }else//父进程 输出ctrl+c s
    {
        signal(SIGINT,signal_handler);
        int flag = 1;
        while (flag)
        {
        printf("请输入ctrl+c解除子进程阻塞,输入1继续,输入2退出\n");
        int a = 0;
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            while (num>0)
                {
                sem_wait(semid,0);
                sem_post(semid,1);
                num--;
                }
            break;
        case 2:
            flag = 0;
            break;
        default:
            break;
        }
        }
        // while(1){
        //     while (num>0)
        //     {
        //         sem_wait(semid,0);
        //         sem_post(semid,1);
        //         num--;
        //     }
        // }
    }
    return 0;
}
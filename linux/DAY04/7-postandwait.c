#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void sem_post(int semid, int num)
{
    struct sembuf sop = {};
    sop.sem_flg = SEM_UNDO;
    sop.sem_num = num;
    sop.sem_op = 1;
    semop(semid, &sop, 1);
}
void sem_wait(int semid, int num)
{
    struct sembuf sop = {};
    sop.sem_flg = SEM_UNDO;//信号量自动回收
    sop.sem_num = num;
    sop.sem_op = -1;
    semop(semid, &sop, 1);
}

int main()
{
    key_t mykey = ftok(__FILE__ ,1);
    int semid = semget(mykey,2,IPC_CREAT|0666);
    semctl(semid,0,SETVAL,1);//给数组第一个（下标为0）元素设置初始量1
    semctl(semid,1,SETVAL,0);//给数组第二个元素设置初始量0
    
    pid_t pid = fork();
    if (pid<0)
    {
        perror("fork error\n");
        exit(EXIT_FAILURE);
    }

    if (pid==0)
    {
        for (int i = 0; i < 10; i++)
        {
            sem_wait(semid,1);
            printf("\033[31m child process %d active...\033[0m\n",i);
            sleep(1);
            sem_post(semid,0);
        }
        semctl(semid,1,IPC_RMID);
    }
    else{
        for (int i = 0; i < 10; i++)
        {
            sem_wait(semid,0);
            printf("\033[32m parent process %d active...\033[0m\n",i);
            sleep(1);
            sem_post(semid,1);
        }
        wait(NULL);
        semctl(semid,0,IPC_RMID);
        
    }

    return 0;
}
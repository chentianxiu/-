#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void sem_post(int semid,int num) //+1
{
    struct sembuf sops = {};
    sops.sem_flg = SEM_UNDO;
    sops.sem_num = num;
    sops.sem_op = 1;
    semop(semid,&sops,1);
}

void sem_wait(int semid,int num) //-1
{
    struct sembuf sops = {};
    sops.sem_flg = SEM_UNDO;
    sops.sem_num = num;
    sops.sem_op = -1;
    semop(semid,&sops,1);
}

int main()
{
    key_t mykey = ftok("./8-test.c",1); //get key 文件一样，key值一样
    int semid = semget(mykey,2,IPC_CREAT|0666); //get semid

    semctl(semid,0,SETVAL,1);

    while (1)
    {
        sem_wait(semid,0);
        printf("hello ");
        fflush(stdout);
        sleep(1);
        sem_post(semid,1);
    }

    semctl(semid,0,IPC_RMID);

    return 0;
}
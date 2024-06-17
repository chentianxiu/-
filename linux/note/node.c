/*
子进程和父进程之间交替完成任务，可以用flag或者sem

sem:

void sem_post : 信号量的值加一
{
    struct sembuf sop = {};
    sop.sem_flag = SEM_UNDO;
    sop.sem_num = num;
    sop.sem_op = 1;
    semop(semid,&sop,1);
}

void sem_wait : 信号量的值减一
{
    struct sembuf sop = {};
    sop.sem_flag = SEM_UNDO;
    sop.sem_num = num;
    sop.sem_op = -1;
    semop(semid,&sop,1);
}

ket_t mykey = fotk(__FILE__,1);(文件名,信道id)

int semid = simget(mykey,2,IPC_CREAT|0666) //(通信密钥，变量数量，创建|权限)

smectl(semid,0,SETVAL,1);(信号名字,下标为0,设置值,初始值为1);
smectl(semid,1,SETVAL,0);(信号名字,下标为1,设置值,初始值为0);

创建子进程

子进程
对变量2(下标为1)进行-操作
semid1 -1;//sem_wait(semid,1);信号下标1减一

semid0 +1//sem_post(semid,0);信号下标0加一

semctl(semid,1,IPC_RMID)//删除信号

父进程
对变量1(下标为0)进行-操作
semid0 -1;//sem_wait(semid,0);信号下标0减一

semid1 +1;//sem_post(semid,1);信号下标1加一

semctl(semid,0,IPC_RMID)

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

struct buf
{
    char buf[128];
    int wflag;//写标记
    int rflag;//读标记
};

int main()
{
    key_t mykey = ftok("1-shmrmw.c",1);  //get key
    //get share memory
    int shmid = shmget(mykey,sizeof(struct buf),IPC_CREAT|0666);
    if (shmid <0)
    {
        perror("shm error");
        return 1;
    }

    struct buf* shm_buf = shmat(shmid,NULL,0);//连接共享内存
    if (shm_buf==NULL)
    {
        perror("link error");
        return 1;
    }
    //初始化
    memset(shm_buf,0,sizeof(struct buf));
    //向共享内存中写入
    while (1)
    {
        while (shm_buf->wflag ==1);//0 can write
        
        printf("please input:");
        fgets(shm_buf->buf,128,stdin);
        shm_buf->wflag = 1;
        shm_buf->rflag = 0;
        if (strcmp(shm_buf->buf,"/exit\n")==0)
        {
            break;
        }
    }

    shmdt(shm_buf);//断开连接
    shmctl(shmid,IPC_RMID,NULL);//删除共享内存 remove shm

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/*
管道:从一个进程连接数据到另一个进程,单向;管道内数据被读取后清空,只能读一遍;
    管道内无内容,阻塞,等待内容读取,可设置阻塞;管道两端,0为读取端;1为写入端;
FILE* popen(管道打开的进程,管道打开的类型);打开管道
int pclose(文件流指针);关闭管道
匿名管道:不能传递无血缘关系的文件的数据;
命名管道:能传递无血缘关系的文件的数据;
*/
/*
命令: mkfifo 管道名;//创建管道
    int 文件描述符 = open("创建管道名",打开模式(O_WRONLY...));
int 匿名管道名[2] = {};//[0]读出端,[1]写入端;
    (pipe(匿名管道名) < 0);//判断条件
共享内存(与信号量相似):
    创建共享结构体(1个存储空间、2个标志位);
    key_t mykey = stok("a.c",0);
    int shmid = shmget(mykey,sizeof(共享内存结构体),IPC_CREAT|0666);
    if(shmid < 0)
    {
        perror("shm error\n");
        retuen 1;
    }
    定义共享内存结构体指针 = shmat(shmid,0,NULL);
    if(共享内存结构体指针 == NULL)
    {
        perror("link error\n");
        retuen 1;
    }
    memset(shm_buf,0,sizeof(struct buf));
    while(1)
    {
        交互内容；
    }
    shmdt(共享内存结构体指针);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
*/

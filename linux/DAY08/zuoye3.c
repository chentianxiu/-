/*
编写一个程序，创建5个线程，这5个线程要求按照一定的顺序执行，使用信号量来保证线程的执行顺序。
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem[5] = {};

// 第一个进程打印10个1，第二个进程打印是10个2....
// 第一个进程打印了一个1就会解锁第二个线程，第二个打印一个2解锁第三个....
void pthread_func(int arg)
{
    for (int i = 0; i < 5; i++)
    {
        sem_wait(&sem[arg]); // 阻塞
        printf("%d\n", arg);
        if (arg == 4)
        {
            sem_post(&sem[0]);
        }
        else
        {
            sem_post(&sem[arg + 1]);
        }
    }

    pthread_exit(NULL); // 线程退出
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        sem_init(&sem[i], 0, 0);
    }
    sem_init(&sem[0], 0, 1);
    pthread_t tid[10];

    for (int i = 0; i < 5; i++)
    {
        pthread_create(tid + i, NULL, (void *)pthread_func, (void *)(__intptr_t)(i));
    }

    for (int i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);

    for (int i = 0; i < 5; i++)
        sem_destroy(&sem[i]);

    return 0;
}

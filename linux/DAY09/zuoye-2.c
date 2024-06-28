/*
2、有2个线程，可以创建火车（以及列车号），火车长度5~50米随机，
有一个桥洞，该桥洞限速5米/秒。要求，每秒输出当前哪列火车正在通过
（任意线程里的火车，随便哪个先运行）（3分）
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

int carid = 0;
pthread_mutex_t mutex;

void *func1(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        carid++;
        int longnum = rand() % 46 + 5;
        double time = 0;
        time = (double)longnum / 5;
        printf("列车%d的长度为%d\n", carid, longnum);
        while (time > 0)
        {
            printf("线程1的列车%d,正在通行\n", carid);
            time--;
            sleep(1);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *func2(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        carid++;
        int longnum = rand() % 46 + 5;
        double time = 0;
        time = (double)longnum / 5;
        printf("列车%d的长度为%d\n", carid, longnum);
        while (time > 0)
        {
            printf("线程2的列车%d,正在通行\n", carid);
            time--;
            sleep(1);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid[2];
    srand(time(NULL));

    pthread_create(&tid[0], NULL, func1, NULL);
    pthread_create(&tid[1], NULL, func2, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&mutex);
}

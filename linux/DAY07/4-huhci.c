#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// 返回值

struct arg
{
    int len;
    char a;
};

int func(struct arg *arg)
{
    printf("len:%d\n", arg->len);
    for (int i = 0; i < arg->len; i++)
    {
        printf("\033[32m我是子线程\033[0m\n");
    }
    return 10;
}

int main()
{
    pthread_t tid = 0;
    struct arg a = {3, 'a'};

    for (int i = 0; i < 3; i++)
    {
        printf("%p\n",&a);
        a.len = i;
        if (pthread_create(&tid, NULL, (void *)func, (void *)&a) < 0)
        {
            perror("pthread error");
            return 1;
        }
    }

    for (int i = 0; i <5; i++)
    {
        printf("\033[35m我是父线程\033[0m\n");
    }

    // pthread_join(tid,NULL);//没有返回值
    int retval = 0;
    pthread_join(tid, (void **)&retval); // 有返回值
    printf("子线程返回值:%d\n", retval);

    return 0;
}

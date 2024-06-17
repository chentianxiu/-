#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *func(int *len)//子线程函数
//2.void func(int len)
//3.void *func(void *len)
{
    printf("len:%d\n",*len);
    //2.printf("len:%d\n",len);
    //3.int lenth =*(int*)len;
    //3.printf("len:%d\n",lenth);
    for (int i = 0; i < *len; i++)
    //2.for (int i = 0; i < len; i++)
    //3.for (int i = 0; i < lenth; i++)
    {
        printf("\033[32m我是子线程\033[0m\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid = 0;

    int arg = 4;

    if (pthread_create(&tid,NULL,(void*)func,&arg)<0)
    //2.if (pthread_create(&tid,NULL,(void*)func,(void*)(__intptr_t)arg)<0)//只针对整数有效
    //3.if(pthread_create(&tid,NULL,func,(void*)&arg)<0)//(void*)func也行
    {
        perror("pthread error");
        return 1;
    }
    
    for (int i = 0; i < arg; i++)
    {
        printf("\033[35m我是父线程\033[0m\n");
        system("ps -L -o pid,lwp,nlwp,command");
        sleep(1);
    }
    
    return 0;
}

// 解释
// 函数签名：

// 当线程函数的签名为 void *func(void *arg) 时，它已经符合 pthread_create 的要求，可以直接使用。
// 当线程函数的签名为 void *func(int *arg) 时，虽然参数类型是 int *，但需要将其强制转换为 void * 类型以符合 pthread_create 的要求。
// 类型转换：

// pthread_create 的第三个参数必须是一个函数指针，类型为 void *(*)(void *)。因此，当您的线程函数不符合这个类型时，需要进行类型转换。
// 例如，将 void *func(int *arg) 转换为 void *(*)(void *) 类型。
// 为什么需要类型转换
// pthread_create 的接口设计是为了允许灵活传递任意类型的参数。通过使用 void * 类型，开发者可以传递指向任何数据类型的指针，而不必局限于某一种特定的数据类型。

// 强制类型转换是告诉编译器“我知道这是一个不同的函数签名，但请将它视为合适的签名”。这样，编译器会忽略签名的不匹配并生成相应的代码。这种做法虽然有效，但需要小心确保类型转换的正确性，以避免潜在的错误。

// 总结
// 当线程函数的参数是 void * 类型时，可以直接传递参数。
// 当线程函数的参数是其他类型时，需要将其转换为 void * 类型，并在 pthread_create 调用中进行类型转换，以确保符合函数签名的要求。
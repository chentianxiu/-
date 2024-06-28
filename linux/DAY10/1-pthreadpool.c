#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

typedef struct task//任务节点
{
    void* (*task)(void*); //任务函数
    void* arg;  //使用参数
    struct task* next;
}Task;

struct pthread_pool //线程池
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_t *pool;  //线程数组-存放用于执行任务的线程号
    Task* head;   //任务队列的开始
    Task* tail;   //任务队列的结束
    int task_max;   //任务队列的上限
    int task_num;   //当前任务的数量
    int pool_num;   //线程的数量
    int shut_flag;  //停止标记符
};


void work(struct pthread_pool* pool)
{
    while (1)
    {
        //获取任务
        pthread_mutex_lock(&(pool->mutex));
        while (pool->task_num==0&&pool->shut_flag==0)
        {
            pthread_cond_wait(&(pool->cond),&(pool->mutex));
        }
        if (pool->shut_flag==1)//判断停止条件
        {
            pthread_mutex_unlock(&(pool->mutex));
            break;
        }
        Task *t = pool->head;
        pool->head = pool->head->next;
        pool->task_num--;
        pthread_mutex_unlock(&(pool->mutex));

        //执行任务
        t->task(t->arg);
        free(t);
    }
}

//线程池初始化
void pthread_pool_init(struct pthread_pool* pool,int pool_num,int task_max)
{
    pool->shut_flag = 0;    //设置为不停止
    pool->task_max = task_max;  
    pool->task_num = 0;
    pool->head = NULL;
    pool->tail = NULL;
    pool->pool_num = pool_num;
    pthread_mutex_init(&(pool->mutex),NULL);
    pthread_cond_init(&(pool->cond),NULL);
    pool->pool = calloc(sizeof(pthread_t),pool_num);//线程池申请堆空间

    //创建线程
    for (int i = 0; i < pool_num; i++)
    {
        pthread_create(pool->pool+i,NULL,(void*)work,(void*)pool);
    }
}

//添加任务
int pthread_pool_task_append(struct pthread_pool*pool,void*(*task)(void*),void* arg)
{
    //生成任务节点
    Task* t = calloc(sizeof(Task),1);
    t->task = task;
    t->arg = arg;
    t->next = NULL;

    //插入链表
    pthread_mutex_lock(&(pool->mutex));
    if (pool->task_max == pool->task_num)//当前任务满了,添加失败
    {
        pthread_mutex_unlock(&(pool->mutex));
        return -1;
    }
    if (pool->task_num==0)
    {
        pool->head = t;
        pool->tail = t;
    }
    else{
        pool->tail->next = t;
        pool->tail = t;
    }
    
    pool->task_num++;//当前任务数量增加
    pthread_cond_signal(&(pool->cond));//唤醒一条正在等待任务的线程
    pthread_mutex_unlock(&(pool->mutex));

    return 0;
}

//销毁线程池
void pthread_pool_destroy(struct pthread_pool *pool)
{
    //结束线程
    pool->shut_flag = 1;
    pthread_cond_broadcast(&(pool->cond));
    for (int i = 0; i < pool->pool_num; i++)
    {
        pthread_join(pool->pool[i],NULL);
    }
    free(pool->pool);

    //销毁锁
    pthread_mutex_destroy(&(pool->mutex));
    pthread_cond_destroy(&(pool->cond));

    //释放堆内存
    Task* p = pool->head;
    Task* q = NULL;
    while (p!=NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    
}

void func(int num)
{
    printf("[线程%ld]\t%d\n",pthread_self(),num);
}

int main()
{
    struct pthread_pool * pool = calloc(sizeof(struct pthread_pool),1);
    pthread_pool_init(pool,3,100);
    for(int i=0;i<100;i++)
    {
        pthread_pool_task_append(pool,(void*)func,(void*)(__intptr_t)(i+1));
    }
    sleep(3);
    pthread_pool_destroy(pool);
    free(pool);

    return 0;
}
#include "deal.h"
#include "../server/server.h"

//建立与客户端的连接
void deal(int server_sockfd)
{
    signal(SIGINT,sig_handler);
    printf("服务器运行中...\n");

    fp_log = fopen("log.txt","a");
    userhead = calloc(1,sizeof(User_link));//用户头节点
    userhead->next = NULL;
    convhead = calloc(1,sizeof(Conv_link));//会话头节点
    convhead->next = NULL;

    load_user();//载入用户文件
//--------------------------------------------------
    User_link* ptr = userhead;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        printf("%s:%s\n",ptr->data.name,ptr->data.pwd);
        
    }
//--------------------------------------------------
    struct sockaddr_in r_addr;
    socklen_t len = sizeof(r_addr);

    int client = 0;
    
    while (1)
    {
        pthread_attr_t attr;//创建线程属性
        pthread_attr_init(&attr);//初始化线程属性
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);//设置线程分离属性

        client = accept(server_sockfd,(struct sockaddr*)&r_addr,&len);
        fprintf(fp_log,"客户端<%d>连接时间:%s\n",client,time_record());
        if(client < 0)
        {
            perror("accept error\n");
            continue;
        }
        out_addr(&r_addr);

        pthread_t tid;
        pthread_create(&tid,&attr,(void*)read_fun,(void*)(__intptr_t)client);
        pthread_attr_destroy(&attr);//销毁线程属性
    }
    return;
}

//信号处理
void sig_handler(int signo)
{
    if(signo == SIGINT)
    {
        printf("服务器正在退出...\n");
        sleep(1);

        close(server_sockfd);//关闭套接字
        fclose(fp_log);//关闭日志文件
        fp_log = NULL;
        destroy_Conv_link();//销毁会话链表
        destroy_User_link();//销毁用户链表
    }
    exit(0);
}

//线程处理
void read_fun(int arg)
{
    int client = arg;
    pthread_mutex_init(&mutex,NULL);
    Data data;//接受客户端的结构体
    Heart heart_data;//统计心跳包
    heart_data.count = 0;
    heart_data.client_sockfd = client;

    while (1) //接受客户端发送的请求
    {
        pthread_t tid;
        pthread_create(&tid,NULL,heart_fun,(void*)&heart_data);//创建新线程用于心跳统计

        memset(&data,0,sizeof(data));
        int retval = read(client,&data,sizeof(Data));
        pthread_cancel(tid);//处理线程数据,停心跳
        
        if(retval == -1)
        {
            printf("读取失败!\n");
            break;
        }
        if(retval == 0)
        {
            printf("用户已关闭!\n");
            break;
        }

        pthread_mutex_lock(&mutex);//操作时上锁
        switch (data.type)
        {
        case TYPE_LOG:
            login_type(data,client);
            break;
        case TYPE_REG:
            regist_type(data,client);
            break;
        case TYPE_HRT:
            {
                heart_data.count = 0;//心跳置0
                Conv_link* ptr = convhead;

                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
        printf("%d:%s\n",ptr->data.client_sockfd,ptr->data.username);
                    if(heart_data.client_sockfd == ptr->data.client_sockfd)
                    {
                        printf("客户端<%d>用户<%s>在线...",ptr->data.client_sockfd,ptr->data.username);
                        break;
                    }
                }
            }
            break;
        case TYPE_CMD:
            command_type(data,client);
            break;
        case TYPE_ONL:
            // online_type(data,client);
            break;
        case TYPE_CHT_SIG:
            // chat_singal_type(data,client);
            break;
        case TYPE_CHT_GRP:
            // chat_group_type(data,client);
            break;
        case TYPE_QUT:
            // delete_node(data);
            fprintf(fp_log,"用户<%s>退出时间:%s\n",data.username,time_record());
            printf("用户<%s>退出...\n",data.username);
            break;
        case TYPE_EXIT:
            printf("客户端<%d>已关闭\n",client);
            break;
        default:
            printf("无此数据类型!\n");
            break;
        }
        pthread_mutex_unlock(&mutex);
        if(TYPE_EXIT == data.type)
        {
            break;//结束线程
        }
    }
    //日志
    fprintf(fp_log,"客户端<%d>断开时间:%s\n",client,time_record());
    close(client);
    pthread_mutex_destroy(&mutex);
    return ;
}

//心跳异常处理
void* heart_fun(void* arg)
{
    Heart* heart_date = (Heart*)arg;
    Conv_link* P_convhead = convhead;
    Conv_link* pre_convhead = P_convhead;
    P_convhead = P_convhead->next;

    while (P_convhead != NULL)
    {
        if(heart_date->client_sockfd == P_convhead->data.client_sockfd)
        {
            break;
        }
        pre_convhead = P_convhead;
        P_convhead = P_convhead->next;
    }
    
    while (1)
    {
        sleep(3);
        heart_date->count++;
        if (heart_date->count == 15) //找到该用户，删除节点和套接字
        {
            if(P_convhead != NULL)
            {
                fprintf(fp_log,"用户<%s>异常退出时间:%s\n",P_convhead->data.username,time_record());
                printf("客户端<%d>用户<%s>退出...\n",heart_date->client_sockfd,P_convhead->data.username);
                pre_convhead->next = P_convhead->next;
                free(P_convhead);
                P_convhead = NULL;
                close(heart_date->client_sockfd);
            }
            else
            {
                printf("客户端<%d>用户(无)异常退出!\n",heart_date->client_sockfd);
                fprintf(fp_log,"客户端<%d>异常退出时间:%s\n",heart_date->client_sockfd,time_record());   
            }
        }
    }
    return NULL;
}

//用户登录
void login_type(Data data,int client)
{
    //重复登录判断
    Conv_link* c_ptr = convhead;
    while (c_ptr->next != NULL)
    {
        c_ptr = c_ptr->next;
        if(strcmp(c_ptr->data.username,data.username) == 0)
        {
            data.retval = 1;
            strcpy(data.shell_rec,"该用户已登录!");
            send(client,&data,sizeof(Data),0);
            return;
        }
    }
    //登录用户及密码配对
    int a = 0;
    User_link* p_userhead = userhead;
    while (p_userhead->next != NULL)
    {
        p_userhead = p_userhead->next;
        if (strcmp(data.username, p_userhead->data.name) == 0 && strcmp(data.passwd, p_userhead->data.pwd) == 0)
        {
            a = 1;
            data.retval = 0;
            send(client,&data,sizeof(Data),0); 
            insert_conv(data,client);
            //日志文件写入
            fprintf(fp_log,"用户<%s>登录成功!时间:%s\n",data.username,time_record());
            printf("用户<%s>登录成功!时间:%s\n",data.username,time_record());
        }
        else
        {
            data.retval = 1;
            strcpy(data.shell_rec,"用户名或密码输入有误!");
            send(client,&data,sizeof(Data),0);
        }
    }
//-----------------------------------------
Conv_link* ptr = convhead;
while (ptr->next != NULL)
{
    ptr = ptr->next;
    printf("%d:  %s\n",ptr->data.client_sockfd,ptr->data.username);
}
//--------------------------------------------------
    return;
}
//会话链表插入函数
void insert_conv(Data data,int client)
{
    Conv_link* ptr = convhead;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    Conv_link* newconv = calloc(1,sizeof(Conv_link));
    newconv->data.client_sockfd = client;
    // newconv->data.flag = 1;
    strcpy(newconv->data.username,data.username);
    strcpy(newconv->data.login_time,time_record());
    ptr->next = newconv;
    return;
}


//用户注册
void regist_type(Data data,int client_sockfd)
{
    User_link* p_userhead = userhead;
    User_link* pre_userhead = p_userhead;
    p_userhead = p_userhead->next;

    while (p_userhead != NULL)
    {
        pre_userhead = p_userhead;
        if(strcmp(data.username,p_userhead->data.name) != 0)
        {
            p_userhead = p_userhead->next;
        }
        else
        {
            data.retval = 1; //用户已存在，注册失败
            write(client_sockfd,&data,sizeof(Data));
            return;
        }
    }
    //日志文件写入
    fprintf(fp_log,"用户<%s>注册成功!时间:%s\n",data.username,time_record());

    data.retval = 0;
    write(client_sockfd,&data,sizeof(Data));

    User_link* newuser = calloc(1,sizeof(User_link));
    pre_userhead->next = newuser;
    strcpy(newuser->data.name,data.username);
    strcpy(newuser->data.pwd,data.passwd);
    save_user();//保存用户数据
    return;
}

//输出客户端地址
void out_addr(struct sockaddr_in* clientaddr)
{
    char addr_ip[16] = {};
    int port = ntohs(clientaddr->sin_port);
    
    inet_ntop(AF_INET,&clientaddr->sin_addr.s_addr,addr_ip,sizeof(addr_ip));
    printf("客户端:%s\t端口:%d\n",addr_ip,port);
    return;
}

//获取当前时间
char* time_record()
{
    time_t local_time;
    local_time = time(NULL);
    return ctime(&local_time);
}

//注销链表处理:用户、在线
void destroy_User_link()
{
    User_link* ptr = NULL;
    User_link* pre_ptr = userhead;
    while (pre_ptr != NULL)
    {
        ptr = pre_ptr;
        pre_ptr = pre_ptr->next;
        free(ptr);
        ptr = NULL;
    }
    return;
}
void destroy_Conv_link()
{
    Conv_link* ptr = NULL;
    Conv_link* pre_ptr = convhead;
    while (pre_ptr != NULL)
    {
        ptr = pre_ptr;
        pre_ptr = pre_ptr->next;
        free(ptr);
        ptr = NULL;
    }
    return;
}

//用户文件加载和保存
void load_user()
{
    if(userhead == NULL)
    {
        printf("空链表!\n");
        return;
    }
    FILE* fp = fopen("user.txt","r");
    if(fp == NULL)
    {
        printf("该文件不存在,请创建!\n");
        return;
    }
    User load_user;
    while (fscanf(fp,"用户名:%s\t密码:%s\n",load_user.name,load_user.pwd) != EOF)
    {
        printf("111\n");
        sleep(1);
        insert_user(load_user);
        // User_link* ptr = userhead;
        // while (ptr->next != NULL)
        // {
        //     ptr = ptr->next;
        // }
        // User_link* newnode = calloc(1,sizeof(User_link));
        // newnode->next = NULL;
        // strcpy(newnode->data.name,load_user.name);
        // strcpy(newnode->data.pwd,load_user.pwd);
        // ptr->next = newnode;
    }
    fclose(fp);
    fp = NULL;
    return;
}


void save_user()
{
    if(userhead == NULL)
    {
        printf("空链表!\n");
        return;
    }
    FILE* fp = fopen("user.txt","w");
    if(fp == NULL)
    {
        printf("文件打开失败!\n");
        return;
    }
    User_link* ptr = userhead;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        fprintf(fp,"用户名:%s\t密码:%s\n",ptr->data.name,ptr->data.pwd);
    }
    fclose(fp);
    return;
}
/*//用户链表添加
void insert_user(User load_user)
{
    User_link* ptr = userhead;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    User_link* newnode = calloc(1,sizeof(User_link));
    strcpy(newnode->data.name,load_user.name);
    strcpy(newnode->data.pwd,load_user.pwd);
    ptr->next = newnode;
    return;
}
*/
//插入链表
void insert_user(User data)
{
    User_link* cur = userhead;
    while (cur->next!=NULL)
    {
        cur = cur->next;//循环遍历到最后的节点
    }
    User_link* newnode = calloc(1,sizeof(User_link));
    newnode->data = data;
    newnode->next = NULL;
    cur->next = newnode;
}

//命令数据包处理
void command_type(Data data,int client_sockfd)
{
    fprintf(fp_log,"用户<%s>发送%s命令!时间:%s",data.username,data.shell_send,time_record());
    system("touch shell.db");//创建缓存文件
    int fd = open("shell.db",O_RDWR,0777);
    int fd2 = open("/dev/tty",O_WRONLY);
    dup2(fd,STDOUT_FILENO);

    int retval = system(data.shell_send);//执行命令写入文件
    //freopen("/dev/stdout9", "w", stdout);
    dup2(fd2,STDOUT_FILENO);
    if(retval != 0)
    {
        data.retval = 2;
        send(client_sockfd,&data,sizeof(Data),0);
        return;
    }
    lseek(fd,0,SEEK_SET);
    read(fd,data.shell_rec,sizeof(data.shell_rec));

    close(fd);
    close(fd2);
    system("rm shell.db");
    send(client_sockfd,&data,sizeof(Data),0);
    return;
}

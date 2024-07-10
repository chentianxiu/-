#include"server.h"
#include"deal.h"
#include "data_type.h"

FILE * fp_log;
pthread_mutex_t mutex;
pthread_cond_t cond;
Userlink * userhead;
Chatlink * chathead;
char ip[20];
int mora1 = 0 ;
int mora2 = 0 ;
int flag111 = 0;

//服务器处理客户端请求函数
void deal(int server_socket)
{
    signal(SIGINT,sig_handler);
    printf("服务器开始运行....\n");
    fp_log = fopen("log.txt","a");//以追加的方式打开日志文件

    userhead = calloc(1,sizeof(Userlink));//用户头节点的创建

    userhead->next = NULL;
    chathead = calloc(1,sizeof(Chatlink));//会话头节点创建

    chathead->next = NULL;

    load_user();//载入用户文件

    struct sockaddr_in clientaddr;
    socklen_t len = sizeof(clientaddr);

    int client_sockfd;
    while (1)//不断接受客户端请求,没有accept会阻塞
    {
        pthread_attr_t attr; //创建线程属性
        pthread_attr_init(&attr);//初始化线程属性
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);//设置线程的分离属性 
        client_sockfd = accept(server_sockfd,(struct sockaddr*)&clientaddr,&len);
        //inet_ntop(AF_INET, clientaddr.sin_addr,ip,20);
        //printf("%s",ip);
        fprintf(fp_log,"时间：%s 客户端:%d 连接了服务器\n",time_record(),client_sockfd);
        if (client_sockfd<0)
        {
            perror("accept error");
            continue;
        }
        out_addr(&clientaddr);//输出连接的客户端地址
        pthread_t client_id;
        pthread_create(&client_id,&attr,(void *)readfun,(void *)(__intptr_t)client_sockfd);//创建线程
        pthread_attr_destroy(&attr);//销毁线程属性
    }
    

    return ;
}

//信号处理函数

void sig_handler(int signo)
{
    if (signo==SIGINT)
    {
        printf("服务器正在退出...\n");
        sleep(1);

        close(server_sockfd);//关闭套接字
        fclose(fp_log);
        fp_log = NULL;
        destroy_Chatlink();//销毁会话链表
        destroy_Userlink();//销毁用户链表
        exit(0);
    }
}

//线程处理函数
void  readfun(int  arg)
{
    pthread_mutex_init(&mutex,NULL);
    int client_sockfd = arg;

    Data data;//接受来自客户端的结构体;
    Heart heart_data;//用来统计心跳包
    heart_data.count = 0;
    heart_data.client_sockfd  = client_sockfd;

    while (1)//循环接受请求
    {
        pthread_t pthread_id;
        pthread_create(&pthread_id,NULL,heart_fun,(void*)&heart_data);//心跳线程
        memset(&data,0,sizeof(data));
        int retval = read(client_sockfd,&data,sizeof(Data));
        pthread_cancel(pthread_id); //在处理本线程数据的时候，把心跳线程停掉

        if (retval == -1)
        {
            printf("读取失败\n");
            break;
        }
        if (retval == 0)
        {
            printf("用户已关闭!\n");
            break;
        }
        //上锁，处理数据
        pthread_mutex_lock(&mutex);//对所有共享操作进行上锁

        switch (data.type)//判断数据类型
        {
        case TYPE_LOG:  login_type(data,client_sockfd);
            break;
        case TYPE_REG:  regist_type(data,client_sockfd);
            break;
        case TYPE_HRT:  //心跳包
            {
                //printf("111\n");
                heart_data.count = 0;//心跳清零
                Chatlink *cur = chathead;
                cur = cur->next;
                while (cur != NULL)
                {
                    if (heart_data.client_sockfd == cur->data.client_sockfd)
                    {
                        printf("客户端：%d\t 用户:%s\tis alive\n",heart_data.client_sockfd,cur->data.username);
                        break;
                    }
                    cur = cur->next;
                }
                break;
            }
            
        case TYPE_CMD:  command_type(data,client_sockfd);
            break;
        case TYPE_ONL:  online_type(data,client_sockfd);
            break;
        case TYPE_CHT_SIG:  chat_single_type(data,client_sockfd);
            break;
        case TYPE_CHT_GRP:  chat_group_type(data,client_sockfd);
            break;
        case TYPE_ROOT:  chat_root_group(data,client_sockfd);//发送判断是否为管理员
            break;
        case TYPE_UROOT:  chat_uroot_group(data,client_sockfd);//是禁言还是解禁
            break;
        case TYPE_MSG:  users_mora(data,client_sockfd);//发起猜拳请求
            break;
        case TYPE_CHT_REC:  users_moraback(data,client_sockfd);//接受猜拳请求
            break;
        case TYPE_QUT:  delete_node(data);
                            fprintf(fp_log,"时间:%s用户%s退出\n",time_record(),data.username);
                            printf("用户%s已经退出\n",data.username);
                            break;//用户关闭处理函数，删除节点
        case TYPE_EXIT: printf("客户端：%d 已关闭\n",client_sockfd);//用户关闭
            break;
        default:
            printf("无此类型\n");
            break;
        }
        pthread_mutex_unlock(&mutex);
        if (TYPE_EXIT == data.type)
        {
            break;//线程结束,退出
        }
    }
    //日志
    fprintf(fp_log,"时间%s客户端%d断开连接\n",time_record(),client_sockfd);
    close(client_sockfd);
    pthread_mutex_destroy(&mutex);

    return ;
}

//上面正常心跳清零，下面是心跳异常处理函数
void *heart_fun(void * arg)
{
    Heart* heart_data = (Heart*)arg;//处理心跳包
    Chatlink * p_chathead = chathead;
    Chatlink * pre_chathead = p_chathead;
    p_chathead = p_chathead->next;

    while (p_chathead != NULL)//在会话列表中找到这个用户
    {
        if (heart_data->client_sockfd == p_chathead->data.client_sockfd)
        {
            break;
        }
        pre_chathead = p_chathead;
        p_chathead = p_chathead->next;
    }
    //找到的话
    while (1)
    {
        sleep(3);
        heart_data->count++;
        if (heart_data->count==15)//找到对应的客户，删除节点和套接字
        {
            if (p_chathead !=NULL)
            {
                fprintf(fp_log,"时间：%s>客户: %s异常退出\n",time_record(),p_chathead->data.username);
                printf("客户端 %d\t用户: %s 已经退出\n",heart_data->client_sockfd,p_chathead->data.username);
                pre_chathead->next = p_chathead->next;
                free(p_chathead);
                p_chathead = NULL;
                close(heart_data->client_sockfd);
            }else
            {
                printf("客户端:%d\t用户(无)异常退出\n",heart_data->client_sockfd);
                fprintf(fp_log,"时间：%s>客户: %s用户(无)异常退出\n",time_record(),p_chathead->data.username);
            }
            
            return NULL;
        }
    }
    return NULL;
}

//输出客户端地址信息
void out_addr(struct sockaddr_in* clientaddr)
{
    int port = ntohs(clientaddr->sin_port);
    char client_ip[16];
    memset(client_ip,0,sizeof(client_ip));

    inet_ntop(AF_INET,&clientaddr->sin_addr.s_addr,client_ip,sizeof(client_ip));

    printf("客户端：%s\t端口：%d\t连接到服务器.....\n",client_ip,port);
}

//获取当前时间函数
char *time_record(){
    time_t now_time;    //记录当前时间
    now_time = time(NULL);
    return ctime(&now_time);
}


//注销用户链表处理函数
void destroy_Userlink()
{
    Userlink* p_userhead = userhead;
    Userlink* pre_userhead = userhead;
    p_userhead = p_userhead->next;
    while (p_userhead!=NULL)
    {
        pre_userhead = p_userhead->next;
        free(p_userhead);
        p_userhead = pre_userhead;
    }

    free(userhead);
    userhead = NULL;
    return;
}

//注销会话链表
void destroy_Chatlink()
{
    Chatlink* p_chathead = chathead;
    Chatlink* pre_chathead = chathead;
    p_chathead = p_chathead->next;
    while (p_chathead!=NULL)
    {
        pre_chathead = p_chathead->next;
        free(p_chathead);
        p_chathead = pre_chathead;
    }

    free(chathead);
    chathead = NULL;
    return;
}

//注册数据包处理函数
void regist_type(Data data,int client_sockd)
{
    Userlink* cur = userhead;
    Userlink * precur = userhead;
    cur = cur->next;

    while (cur != NULL)//遍历
    {
        precur = cur;
        if (strcmp(data.username,cur->data.username)==0)
        {
            data.retval = 1;//1表示用户已经存在，注册失败
            write(client_sockd,&data,sizeof(Data));
            return;
        }
        cur = cur->next;
    }
    //此时用户可以注册
    fprintf(fp_log,"时间：%s用户：%s注册成功\n",time_record(),data.username);

    data.retval = 0;//0表示注册成功
    write(client_sockd,&data,sizeof(Data));

    //插入用户链表
    User user;
    strcpy(user.username,data.username);
    strcpy(user.passwd,data.passwd);

    Userlink* newnode = calloc(1,sizeof(Userlink));
    precur->next =newnode;
    newnode->data = user;
    newnode->next =NULL;

    save_user();//保存数据
}



/********************************登录之后的用户界面 ***********************************************/
//登录数据包处理函数
void login_type(Data data,int client_sockfd)
{
    Chatlink * cur = chathead;
    cur = cur->next;
    while (cur != NULL)//遍历查找是否有用户在线
    {
        if (strcmp(cur->data.username,data.username)==0)
        {
            data.retval = 2;//客户已经登录
            write(client_sockfd,&data,sizeof(data));
            return;
        }
        cur = cur->next;
    }//没有查到当前有用户在线，在判断账号密码是否正确

    Userlink * cur1 = userhead;
    cur1 = cur1->next;
    while (cur1!=NULL)//遍历查找账号密码是否正确
    {
        if (strcmp(cur1->data.username,data.username)==0&&strcmp(cur1->data.passwd,data.passwd)==0)
        {
            data.retval = 0;//登录成功
            write(client_sockfd,&data,sizeof(data));
            insert_chat(data,client_sockfd);//插入会话链表
            return ;
        }
        cur1 = cur1->next;
    }
    data.retval = 1;//账号密码不匹配,返回0
    write(client_sockfd,&data,sizeof(data)); 
    return ;
}	

//会话链表插入函数
void insert_chat(Data data,int client_sockfd)
{
    Chatlink * cur = chathead;
    while (cur->next!=NULL)//遍历到链表尾部
    {
        cur = cur->next;
    }
    
    Chatlink * newnode = calloc(1,sizeof(Chatlink));
    
    strcpy(newnode->data.username,data.username);//写入用户名
    newnode->data.client_sockfd = client_sockfd;//写入套接字
    
    
    strcpy(newnode->data.login_time,time_record());//写入登陆时间
    if(strcmp(data.username,"123")==0)
    {
        newnode->data.flag = 1;//1是管理员,0是正常,2是被禁言
    }else{
        newnode->data.flag = 0;//在线状态置为0
    }
    cur->next = newnode;
    newnode->next = NULL;
    //打印信息，写入日志

    fprintf(fp_log,"时间:%s 用户:%s 登录成功....\n",time_record(),data.username);
    printf("客户端%d 的用户:%s 在%s 登录了\n",client_sockfd,data.username,newnode->data.login_time);

    return;

}

//删除在线节点函数(会话链表删除函数)
void delete_node(Data data)
{
    Chatlink * cur = chathead;
    Chatlink * precur = chathead;

    cur = cur->next;
    while (cur != NULL)
    {
        if (strcmp(data.username,cur->data.username)==0)
        {
            precur->next = cur->next;
            free(cur);
            cur = NULL;
            break;
        }
        precur = cur;
        cur = cur->next;
    }
    return ;
}

//命令数据包处理函数
void command_type(Data data,int client_sockd)
{
    fprintf(fp_log,"时间:%s 用户:%s 发送了shell命令:%s\n",time_record(),data.username,data.shell_send);
    system("touch shell.db");//创建一个缓存文件
    int fd = open("shell.db",O_RDWR,0777);
    int save_fd = dup(1);
    dup2(fd,1);//重定向输出流

    int retval = system(data.shell_send);//执行客户端传来的指令,写进fd
    dup2(save_fd,1);//输出流重定向到屏幕

    if (retval !=0)//system命令错误，返回2
    {
        data.retval = 2;
        write(client_sockd,&data,sizeof(data));
    }
    lseek(fd,0,SEEK_SET);//移动文件光标到头部
    read(fd,data.shell_rec,sizeof(data.shell_rec));//将执行结果读到shell_rec
    close(fd);

    system("rm shell.db");//删除缓存文件
    write(client_sockd,&data,sizeof(data));

    return;
}

//在线用户数据包处理函数
void online_type(Data data,int client_sockd)
{
    system("touch online.db");//创建一个缓存文件
    int fd = open("online.db",O_RDWR,0777);//创建一个临时的文件
    int save_fd = dup(1);
    dup2(fd,1);//重定向输出流

    Chatlink * cur = chathead;
    cur = cur->next;
    while (cur!=NULL)
    {
        printf("用户:%s 端口:%d 上线时间:%s",cur->data.username,cur->data.client_sockfd,cur->data.login_time);
        cur = cur->next;
    }

    dup2(save_fd,1);//输出流重定向到屏幕
    lseek(fd,0,SEEK_SET);//移动文件光标到头部
    read(fd,data.user_online,sizeof(data.user_online));//将执行结果读到shell_rec
    close(fd);
    system("rm online.db");//删除缓存文件
    write(client_sockd,&data,sizeof(data));//发送到客户端

    return ;
}

//用户单聊天函数
void chat_single_type(Data data,int client_sockd)
{
    //初始话化返回值为1
    data.retval = 1;
    //查看是否存在这个用户
    Userlink * p = userhead;
    p = p->next;
    while (p != NULL)
    {
        if (strcmp(p->data.username,data.username)==0)
        {
            data.retval = 2;
        }
        p =p->next;
    }
    
    //查看用户是否在线，在线发消息，不在线返回不在线
    Chatlink * cur = chathead;
    cur = cur->next;
    while (cur !=NULL)
    {
        if (strcmp(data.chat_name_send,cur->data.username)==0)
        {
            //将消息发送给指定用户
            data.retval = 0;
            strcpy(data.chat_time,time_record());
            write(cur->data.client_sockfd,&data,sizeof(data));
            fprintf(fp_log,"用户:%s时间:%s给用户:%s发了一条消息\n",data.username,data.chat_time,cur->data.username);
        }
        cur = cur->next;
    }
    write(client_sockd,&data,sizeof(data));
    return;
}


//群聊函数
void chat_group_type(Data data,int client_sockd)
{

    Chatlink * cur1 = chathead;//查看发消息的人是否被禁言
    cur1 = cur1->next;
    while (cur1!=NULL)
    {
        if (cur1->data.client_sockfd==client_sockd&&cur1->data.flag==2)
        {
            data.retval = 11;
            write(client_sockd,&data,sizeof(data));
            return;
        }
        cur1 = cur1->next;
    }
    //没有被禁言
    Chatlink * cur = chathead;
    cur = cur->next;
    while (cur !=NULL)
    {
        //将消息发送给所有用户
        data.retval = 1;
        strcpy(data.chat_time,time_record());
        write(cur->data.client_sockfd,&data,sizeof(data));
        cur = cur->next;
    }
    write(client_sockd,&data,sizeof(data));
    fprintf(fp_log,"用户:%s时间:%s群发了一条消息\n",data.username,data.chat_time);
    return;
}


//管理群聊函数
void chat_root_group(Data data,int client_sockfd)
{
    Chatlink * cur = chathead;
    cur  = cur->next;
    while (cur != NULL)
    {
        
        if (cur->data.flag==1&&cur->data.client_sockfd==client_sockfd)
        {   
            data.retval = 1;//是管理员
            write(client_sockfd,&data,sizeof(data));
            //send(cur->data.client_sockfd,&data,sizeof(data),0);
            sleep(1);
            return ;
        }
        cur = cur->next;
    }
    data.retval = 0;//不是管理员
    write(client_sockfd,&data,sizeof(data));
    return ;
}

//管理群聊函数(解除禁言)
void chat_uroot_group(Data data,int client_sockfd)
{
    if (data.retval == 10)//禁言
    {
        Chatlink* cur = chathead;
        cur = cur->next;
        while (cur != NULL)
        {
            if (strcmp(cur->data.username,data.chat_name_send)==0)
            {
                cur->data.flag = 2;//2是禁言
                data.retval = 1;
                write(client_sockfd,&data,sizeof(data));
                return ;
            }
            cur = cur->next;
        }
        data.retval = 0;
        write(client_sockfd,&data,sizeof(data));
    }
    if(data.retval == 20)//解禁
    {
        Chatlink* cur1 = chathead;
        cur1 = cur1->next;
        while (cur1 != NULL)
        {
            if (strcmp(cur1->data.username,data.chat_name_send)==0)
            {
                cur1->data.flag = 0;
                data.retval = 1;
                write(client_sockfd,&data,sizeof(data));
                return ;
            }
            cur1 = cur1->next;
        }
        data.retval = 0;
        write(client_sockfd,&data,sizeof(data));
    }
    
    return ;
}

//发送猜拳
void users_mora(Data data,int client_sockfd)
{

    mora1 = 0;
    flag111 = 0;
    Chatlink *cur = chathead;   //找到发送请求的对象
    cur = cur->next;
    while (cur != NULL)
    {
        if (strcmp(cur->data.username,data.chat_name_send)==0)
        {
            data.type = TYPE_CHT_REC;
            write(cur->data.client_sockfd,&data,sizeof(data));//向猜拳对手发送请求
            break;
        }
        cur = cur->next;
    }

    data.type = TYPE_MSG;
    //memset(&data,0,sizeof(data));
    if (cur == NULL)
    {
        data.retval = 0;
        write(client_sockfd,&data,sizeof(data));//向客户端发送用户不存在
    }else{
        data.retval = 1;
        //write(client_sockfd,&data,sizeof(data));//向客户端发送用户在线
        if (write(client_sockfd, &data, sizeof(data)) < 0) {
            perror("write error");
            return;
        }
    }
    //memset(&data,0,sizeof(data));

    //read(client_sockfd,&data,sizeof(data));//接受发起者的猜拳是什么
    // if (read(client_sockfd, &data, sizeof(data)) < 0) {
    //     perror("read error");
    //     return;
    // }
    mora1 = data.mora;
    pthread_cond_wait(&cond,&mutex);
    while(flag111==0);
    //memset(&data,0,sizeof(data));
    //printf("%d\t%d\n",mora1,mora2);
   
    if (mora1==mora2)
    {
        data.retval = 100;
    }else if ((mora1 == 1 && mora2 == 2) || (mora1 == 2 && mora2 == 3) || (mora1 == 3 && mora2 == 1))
    {
        data.retval = 200;
    }else
    {
        data.retval = 300;
    }
    if (mora2 == 0)
    {
        data.retval = 400;
    }
    write(client_sockfd,&data,sizeof(data));//向客户端发送结果
    
}

//接受猜拳
void users_moraback(Data data,int client_sockfd)
{
    //接受邀请者的猜拳
    //read(client_sockfd,&data,sizeof(data));
    //printf("%d\n",data.mora);
    mora2 = data.mora;
    if (data.mora == 0)
    {
        pthread_cond_signal(&cond);
        return ;
    }
    flag111 = 1;
    memset(&data,0,sizeof(data));
    if (mora2==mora1)
    {
        data.retval = 100;
    }else if((mora1 == 1 && mora2 == 2) || (mora1 == 2 && mora2 == 3) || (mora1 == 3 && mora2 == 1))
    {
        data.retval = 200;
    }else
    {
        data.retval = 300;
    }
    write(client_sockfd,&data,sizeof(data));//向客户端发送结果
    pthread_cond_signal(&cond);
    return ;
}
#include "client.h"

//套接字写成全局变量
int client_sockfd;

int main()
{
    signal(SIGINT,sig_handler);//注册中断,控制客户端退出

    signal(SIGALRM,sig_handler);//注册定时，控制客户端

    client_sockfd = socket(AF_INET,SOCK_STREAM,0);//创建套接字
    if (client_sockfd<0)
    {
        perror("socket error");
        exit(1);
    }
    
    struct sockaddr_in serveraddr;//地址结构体

    memset(&serveraddr,0,sizeof(serveraddr));//初始化
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8888);
    inet_pton(AF_INET,"127.0.0.1",&serveraddr.sin_addr.s_addr);

    if (connect(client_sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0)
    {
        perror("connect error");
        exit(1);
    }
    
    alarm(3);//触发定时信息，给服务器发心跳包

    function(); //功能模块，界面

    Data data; //正常退出客户端，给服务器发一个退出的包

    data.type = TYPE_EXIT;

    write(client_sockfd,&data,sizeof(data));

    close(client_sockfd);

    printf("\t \t\033[33m您已退出《IOTEK》客户端！欢迎下次光临！\033[0m\n");

    return 0;
}

//信号捕捉控制函数

void sig_handler(int signo)
{
    if (signo == SIGINT)//捕捉ctrl+c
    {
        printf("\t \t\033[33m您已退出《IOTEK》客户端！欢迎下次光临！\033[0m\n");
        Data data;//正常退出客户端，给服务器发送一个退出的包
        data.type = TYPE_EXIT;

        write(client_sockfd,&data,sizeof(data));
        close(client_sockfd);
        exit(0);
    }
    if (signo == SIGALRM)//捕捉定时信号，发送心跳包
    {
        Data data;
        data.type = TYPE_HRT;//设置数据包为心跳类型
        int retval = write(client_sockfd,&data,sizeof(data));
        if (retval == -1)
        {
            printf("服务器端已经关闭,即将退出客户端\n");
            sleep(3);
            exit(0);
        }
        alarm(3);
    }
    return ;
}

void function()
{
    while (1)
    {
        system("clear");
        printf("\t\t\033[34m***********欢迎进入《IOTEK》客户端************\033[0m\n");
		printf("\t\t\033[34m***         1：用户注册			***\033[0m\n");
		printf("\t\t\033[34m***         2：用户登录			***\033[0m\n");
		printf("\t\t\033[34m***         0：退出客户端		***\033[0m\n");
		printf("\t\t\033[34m***********************************\033[0m\n");

        printf("请输入选项：");
        int choose = -1;
        scanf("%d",&choose);
        while(getchar() != '\n');

        switch (choose)
        {
        case 1:
            regist();   
            break;
        case 2:
            login();   
            break;
        case 0: 
            break;
        default:
            printf("输入错误，请重新输入\n");
        }
        if (choose == 0)
        {
            break;	//登录过，如果失败，就退出界面，重新登录客户端;
        }
    }
    return ;
}

//注册
void regist()
{
    Data data;  //定义一个数据包
    memset(&data,0,sizeof(Data));

    printf("请输入用户名：\n");
    scanf("%s",data.username);
    while(getchar()!='\n');

    printf("请输入密码\n");
    scanf("%s",data.passwd);
    while(getchar()!='\n');

    data.type = TYPE_REG;

    write(client_sockfd,&data,sizeof(data));//发送数据给服务器处理
    memset(&data,0,sizeof(Data));
    read(client_sockfd,&data,sizeof(data));//接受服务器发送回来的数据

    if (data.retval == 0)//返回值为0时成功注册
    {
        printf("注册成功,正在返回主菜单\n");
        sleep(1);
        system("clear");
    }
    else{
        printf("该用户已存在，无法注册，正在返回主菜单\n");
        sleep(2);
        system("clear");
    }
    return ;
}

//用户登录函数
void login()
{
    Data data ;//定义一个数据包
    int count = 1;
    while (1)//控制输入账号密码次数，3次不对返回
    {
        memset(&data,0,sizeof(Data));//初始化
        printf("请输入用户名\n");
        scanf("%s",data.username);

        printf("请输入密码\n");
        scanf("%s",data.passwd);
        data.type = TYPE_LOG;
        data.retval = 1;

        write(client_sockfd,&data,sizeof(data));//把数据发送给服务器
        memset(&data,0,sizeof(Data));//初始化来接受服务器返回的值
        read(client_sockfd,&data,sizeof(data));
        if (data.retval == 0)
        {
            printf("登录成功,正在进入...\n");
            sleep(2);
            userlogin(client_sockfd,data);//进入用户登录模块
            break;
        }
        else if (data.retval == 2)
        {
            printf("这个账号已经在其他客户端登录！请先退出其他的客户端\n");
            printf("正在退出客户端....\n");
            sleep(2);
            return ;
        }
        else{
            printf("输入错误%d\n次，请重新输入账号密码！\033[33m（3次自动退出客户端）\33[0m\n",count);
            count++;
        }

        if (count == 4)
        {
            printf("您已经输错三次,将被强制退出客户端\n");
            sleep(2);
            break;
        }
    }
    return ;
}
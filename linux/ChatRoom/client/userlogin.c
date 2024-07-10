#include "data_type.h"
#include "client.h"
#include "userlogin.h"

// 定义一个全局变量，之后控制信号函数用，因为传不了参数
Data data2;
int fd2;

int mora;

// 登录成功后的操作函数(单独分离出来的)
void userlogin(int client_sockfd, Data data)
{
    signal(SIGINT, sig_handler2); // 注册型号接受器
    data2 = data;
    fd2 = client_sockfd;
    function2(client_sockfd, data);
    return;
}

void sig_handler2(int signo)
{
    if (signo == SIGINT)
    {
        printf("\n\t\t\33[33m正在退出客户端，欢迎下次加入\33[0m\n");
        data2.type = TYPE_QUT;
        write(fd2, &data2, sizeof(data2));

        printf("\t\t\33[33m您已经成功退出客户端\33[0m\n");
        data2.type = TYPE_EXIT;
        write(fd2, &data2, sizeof(data2));

        close(fd2);
        exit(0);
    }
}

// 客户端界面
void function2(int client_sockfd, Data data)
{
    int flag = 1;
    while (flag)
    {
        system("clear");

        printf("\t\t\t\33[33m*****欢迎进入IOTEK终端*****\33[0m\n");
        printf("\t\t\t\33[33m***  1:向服务器发送命令****\33[0m\n");
        printf("\t\t\t\33[33m***  2:单独聊天         ***\33[0m\n");
        printf("\t\t\t\33[33m***  3:群聊             ***\33[0m\n");
        printf("\t\t\t\33[33m***  4:查询在线客户     ***\33[0m\n");
        printf("\t\t\t\33[33m***  5:群聊管理          ***\33[0m\n");
        printf("\t\t\t\33[33m***  6:发起猜拳           ***\33[0m\n");
        printf("\t\t\t\33[33m***  7:接受猜拳           ***\33[0m\n");
        printf("\t\t\t\33[33m***  0:退出             ***\33[0m\n");
        printf("\t\t\t\33[33m***************************\33[0m\n");

        printf("请输入您的选项\n");
        int choose = -1;
        scanf("%d", &choose);
        while (getchar() != '\n')
            ;
        switch (choose)
        {
        case 1:
            // shell命令函数
            shellsym(client_sockfd, data);
            break;
        case 2:
            // 聊天函数-单聊
            single_chat(client_sockfd, data);
            break;
        case 3:
            // 聊天函数-群聊
            group_chat(client_sockfd, data);
            break;
        case 4:
            // 查看在线用户
            user_online(client_sockfd, data);
            break;
        case 5:
            // 管理群聊用户
            root_online(client_sockfd, data);
            break;
        case 6:
            // 发起猜拳
            user_mora(client_sockfd, data);
            break;
        case 7:
            // 接受猜拳
            user_moraback(client_sockfd, data);
            break;
        case 0:
            flag = 0;
            user_updown(client_sockfd, data);
            break;
        default:
            printf("输入错误,请重新输入\n");
            sleep(1);
            break;
        }
    }
    return;
}

// 退出登录
void user_updown(int client_sockfd, Data data)
{
    data.type = TYPE_QUT;
    write(client_sockfd, &data, sizeof(data));

    return;
}

// shell命令函数
void shellsym(int client_sockfd, Data data)
{
    pthread_t client_id3; // 创建线程，读取聊天信息
    // 干别的事也可以读取聊天信息，所以创建线程
    pthread_create(&client_id3, NULL, (void *)fun, (void *)(__intptr_t)client_sockfd);

    data.type = TYPE_CMD; // 给定数据包类型
    printf("请输入要发送给服务器的命令:");
    fgets(data.shell_send, sizeof(data.shell_send), stdin);

    pthread_cancel(client_id3); // 终止接受聊天信息线程

    write(client_sockfd, &data, sizeof(data));
    memset(&data, 0, sizeof(data)); // 初始化，用来接收服务器返回的信息
    read(client_sockfd, &data, sizeof(data));

    if (data.retval == 2)
    {
        printf("命令输入错误！按回车键返回主菜单...\n");
        char a = '\0';
        scanf("%c", &a);
        return;
    }
    printf("服务器返回结果:\n%s\n", data.shell_rec);
    char a = '\0';
    printf("请查看结果，按回车键返回主菜单");
    scanf("%c", &a);

    return;
}

// 读取聊天的线程函数
void fun(int arg)
{
    int client_sockfd = arg;
    Data data;

    while (1)
    {
        int retval = read(client_sockfd, &data, sizeof(data));
        if (retval == 0 || retval == -1) // 没有读到数据，服务器关闭，断开连接
        {
            printf("服务器已经关闭，即将退出客户端\n");
            sleep(2);
            exit(1);
        }
        if (data.type == TYPE_CHT_GRP)
        {
            printf("\n用户:%s群发了一条消息:%s时间:%s", data.username, data.chat_data, data.chat_time);
        }
        if (data.type == TYPE_CHT_SIG)
        {
            printf("\n用户:%s给你发了一条消息:%s时间:%s", data.username, data.chat_data, data.chat_time);
        }
        if (data.type == TYPE_CHT_REC) // 猜拳的包
        {
            while(getchar()!='\n');
            printf("用户%s给你发送了猜拳邀请，请问是否接受(输入Y/y接受)\n", data.username);
            char a;
            scanf("%c", &a);
            if (a == 'Y' || a == 'y')
            {
                mora = 1;
                break;
            }
            else
            {
                mora = 2;
                break;
            }
        }
    }
}

// 聊天函数-单聊
void single_chat(int client_sockfd, Data data)
{
    int flag = 1;
    while (flag)
    {
        pthread_t client_id1; // 创建线程，读取聊天信息
        // 干别的事也可以读取聊天信息，所以创建线程
        pthread_create(&client_id1, NULL, (void *)fun, (void *)(__intptr_t)client_sockfd);

        data.type = TYPE_CHT_SIG; // 给定数据包类型
        printf("请输入要发送的对象(输入exit退出):");
        scanf("%s", data.chat_name_send);
        while (getchar() != '\n')
            ;
        pthread_cancel(client_id1); // 终止接受聊天信息线程
        if (strcmp(data.chat_name_send, "exit") == 0)
        {
            break;
        }
        printf("请输入想要发送的信息:");
        fgets(data.chat_data, sizeof(data.chat_data), stdin);
        write(client_sockfd, &data, sizeof(data));
        memset(&data, 0, sizeof(data)); // 初始化，方便接受消息

        read(client_sockfd, &data, sizeof(data));
        if (data.retval == 1)
        {
            printf("没有这个用户,按回车键退出\n");
            char a = '\0';
            scanf("%c", &a);
            return;
        }
        if (data.retval == 2)
        {
            printf("这个用户不在线，按回车键退出\n");
            char a = '\0';
            scanf("%c", &a);
            return;
        }
    }
    return;
}

// 聊天函数-群聊
void group_chat(int client_sockfd, Data data)
{
    int flag = 1;
    while (flag)
    {
        pthread_t client_id4; // 创建线程，读取聊天信息
        // 干别的事也可以读取聊天信息，所以创建线程
        pthread_create(&client_id4, NULL, (void *)fun, (void *)(__intptr_t)client_sockfd);

        data.type = TYPE_CHT_GRP; // 给定数据包类型
        memset(data.chat_data, 0, sizeof(data.chat_data));
        printf("请输入想要发送的信息(输入exit退出):");
        fgets(data.chat_data, sizeof(data.chat_data), stdin);
        pthread_cancel(client_id4); // 终止接受聊天信息线程
        if (strcmp(data.chat_data, "exit\n") == 0)
        {
            break;
        }
        write(client_sockfd, &data, sizeof(data));
        memset(&data, 0, sizeof(data)); // 初始化，方便接受消息
        read(client_sockfd, &data, sizeof(data));
        if (data.retval == 1)
        {
            printf("发送成功\n");
        }
        if (data.retval == 0)
        {
            printf("发送失败，按回车键退出\n");
            char a = '\0';
            scanf("%c", &a);
            return;
        }
        if (data.retval == 11)
        {
            printf("你已经被禁言\n");
            sleep(2);
            return;
        }
    }
    return;
}

// 管理群聊用户
void root_online(int client_sockfd, Data data)
{
    data.type = TYPE_ROOT;
    write(client_sockfd, &data, sizeof(data));
    memset(&data, 0, sizeof(data));
    read(client_sockfd, &data, sizeof(data));
    if (data.retval == 0)
    {
        printf("您不是管理员\n");
        return;
    }
    int flag = 1;
    while (flag)
    {
        system("clear");

        printf("\t\t\t\33[33m*****欢迎进入管理员界面*****\33[0m\n");
        printf("\t\t\t\33[33m***  1:禁言用户        ****\33[0m\n");
        printf("\t\t\t\33[33m***  2:解禁用户         ***\33[0m\n");
        printf("\t\t\t\33[33m***  0:退出             ***\33[0m\n");
        printf("\t\t\t\33[33m***************************\33[0m\n");

        printf("请输入您的选项\n");
        int choose = -1;
        scanf("%d", &choose);
        while (getchar() != '\n')
            ;
        switch (choose)
        {
        case 1:
            // 禁言用户
            memset(&data, 0, sizeof(data));
            data.type = TYPE_UROOT;
            printf("请输入你想要禁言的用户名字:\n");
            scanf("%s", data.chat_name_send);
            while (getchar() != '\n')
                ;
            data.retval = 10;
            write(client_sockfd, &data, sizeof(data));
            memset(&data, 0, sizeof(data));
            read(client_sockfd, &data, sizeof(data));
            // recv(client_sockfd, &data, sizeof(data),0);
            if (data.retval == 1)
            {
                printf("禁言成功,输入回车键退出\n");
            }
            else
            {
                printf("禁言失败，输入回车键退出\n");
            }
            char a = '\0';
            scanf("%c", &a);
            break;
        case 2:
            // 解禁用户
            memset(&data, 0, sizeof(data));
            data.type = TYPE_UROOT;
            printf("请输入你想要解除禁言的用户名字:\n");
            scanf("%s", data.chat_name_send);
            while (getchar() != '\n')
                ;
            data.retval = 20;
            write(client_sockfd, &data, sizeof(data));
            memset(&data, 0, sizeof(data));
            read(client_sockfd, &data, sizeof(data));
            if (data.retval == 1)
            {
                printf("解除禁言成功，输入回车键退出\n");
            }
            else
            {
                printf("解除禁言失败，输入回车键退出\n");
            }
            char b = '\0';
            scanf("%c", &b);
            break;
        case 0:
            flag = 0;
            printf("按回车键退出\n");
            char e = '\0';
            scanf("%c", &e);
            break;
        default:
            printf("输入错误,请重新输入\n");
            char c = '\0';
            scanf("%c", &c);
            break;
        }
    }

    return;
}

// 发起猜拳
void user_mora(int client_sockfd, Data data)
{
    while (1)
    {

        data.type = TYPE_MSG; // 信息包类型
        data.retval = 0;
        printf("你需要猜拳的对象(输入exit退出):\n");
        scanf("%s", data.chat_name_send);
        
        while (getchar() != '\n')
            ;
       
        if (strcmp(data.chat_name_send, "exit") == 0)
        {
            return;
        }
        printf("请输入1.[石头]or2.[剪刀]or3.[布]\n");
        scanf("%d", &data.mora);
        
        write(client_sockfd, &data, sizeof(data));
        memset(&data, 0, sizeof(data)); // 初始化用来接受服务器返回的消息
        read(client_sockfd, &data, sizeof(data));
        sleep(1);
       
        if (data.retval == 0)
        {
            printf("查不到此人/此人不在线，请重新开始\n");
            break;
        }
        else
        {
            printf("已经发送邀请\n");
        }
       
        // send(client_sockfd, &data, sizeof(data),0);
        // write(client_sockfd, &data, sizeof(data));
        // printf("7..\n");
        memset(&data, 0, sizeof(data)); // 初始化用来接受服务器返回的消息
        printf("等待对面出拳中...\n");
        read(client_sockfd, &data, sizeof(data));
        if (data.retval == 100)
        {
            printf("平局\n");
        }
        else if (data.retval == 200)
        {
            printf("你赢了\n");
        }else if (data.retval == 400)
        {
            return ;
        }
        else
        {
            printf("你输了\n");
        }
        printf("按回车键继续\n");
        char e = '\0';
        scanf("%c", &e);
    }

    return;
}

// 接受猜拳

void user_moraback(int client_sockfd, Data data)
{
    while (1)
    {
        mora = 0;
        system("clear");
        pthread_t client_id3; // 创建线程，读取聊天信息
        // 干别的事也可以读取聊天信息，所以创建线程
        pthread_create(&client_id3, NULL, (void *)fun, (void *)(__intptr_t)client_sockfd);
        // pthread_cancel(client_id3); // 终止接受聊天信息线程
        pthread_join(client_id3, NULL);
        if (mora == 2)
        {
            break;
        }
        while (1)
        {
            data.type = TYPE_CHT_REC;
            printf("请输入1.[石头]or2.[剪刀]or3.[布](0退出)\n");
            scanf("%d", &data.mora);
            if (data.mora == 0)
            {
                write(client_sockfd, &data, sizeof(data));
                return;
            }
            else if (data.mora == 1 || data.mora == 2 || data.mora == 3)
            {
                write(client_sockfd, &data, sizeof(data));
                memset(&data, 0, sizeof(data)); // 初始化用来接受服务器返回的消息
                read(client_sockfd, &data, sizeof(data));
                if (data.retval == 100)
                {
                    printf("平局\n");
                    break;
                }
                else if (data.retval == 200)
                {
                    printf("你赢了\n");
                    break;
                }
                else
                {
                    printf("你输了\n");
                    break;
                }
            }
            else
            {
                printf("输入错误\n");
            }
        }

    }

    return;
}

// 查看在线用户
void user_online(int client_sockfd, Data data)
{

    pthread_t client_id3; // 创建线程，读取聊天信息
    // 干别的事也可以读取聊天信息，所以创建线程
    pthread_create(&client_id3, NULL, (void *)fun, (void *)(__intptr_t)client_sockfd);

    pthread_cancel(client_id3); // 终止接受聊天信息线程

    data.type = TYPE_ONL;
    write(client_sockfd, &data, sizeof(data));
    memset(&data, 0, sizeof(data)); // 初始化，用来接收服务器返回的信息
    read(client_sockfd, &data, sizeof(data));

    printf("服务器返回结果:\n%s\n", data.user_online);
    char a = '\0';
    printf("请查看结果，按回车键返回主菜单");
    scanf("%c", &a);

    return;
}
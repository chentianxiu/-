#include "client.h"

int client_sockfd = 0;

int main()
{
    signal(SIGINT, handler);
    signal(SIGALRM, handler);

    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd < 0)
    {
        perror("sock error\n");
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8899);
    // addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);

    if (connect(client_sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect error\n");
        exit(1);
    }

    alarm(3);

    func(); // 界面

    Data data;
    data.type = TYPE_EXIT;

    write(client_sockfd, &data, sizeof(data));
    close(client_sockfd);

    printf("已退出,感谢您的使用!\n");

    return 0;
}

// 中断处理
void handler(int signo)
{
    if (signo == SIGINT)
    {
        printf("您已退出客戶端,感謝您的使用!");
        Data data;
        data.type = TYPE_EXIT;
        send(client_sockfd,&data,sizeof(Data),0);
        close(client_sockfd);
        exit(0);
    }
    if (signo == SIGALRM)
    {
        Data a_data;
        a_data.type = TYPE_HRT;
        int res = write(client_sockfd, &a_data, sizeof(Data));
        if (res < 0)
        {
            printf("服务器已关闭,即将退出客户端!\n");
            sleep(2);
            exit(0);
        }
        alarm(3);
    }
    return;
}

// 用户界面
void func()
{
    int choose = -1;
    while (1)
    {
        choose = -1;
        system("clear");
        printf("┏━━━━━━━━━━欢迎使用<IOTEK>客户端━━━━━━━━━┓\n");
        printf("┃             1、用户注册                ┃\n");
        printf("┃             2、用户登录                ┃\n");
        printf("┃             0、退出                    ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("请选择编号[0-2]:");
        scanf("%d", &choose);
        while(getchar()!='\n');
        switch (choose)
        {
        case 0:
            break;
        case 1:
            // 用户注册
            regist();
            break;
        case 2:
            // 用户登录
            login();
            break;
        default:
            printf("输入错误!\n");
            break;
        }
        if(choose == 0)
        {
            break;
        }
    }
    return;
}

// 用户注册
void regist()
{
    Data registData = {};
    int flag = 1;
    char name[20] = {}, password[20] = {}, confirm_password[20] = {};
    fflush(stdin);
    printf("请输入您的用户名:");
    scanf("%s", name);
    while (flag) // 注册,密码输入和确认
    {
        int a = 0, b = 0;
        fflush(stdin);
        printf("请输入你的密码(8~19,必须由数字和字母组成):");
        scanf("%s", password);
        // password_preserve(password, 1);                            // 注册,密码输入
        if (strlen(password) - 1 > 19 || strlen(password) - 1 < 3) // 密码长度判断
        {
            printf("你的密码长度不符合要求,请重新输入!\n");
        }
        else
        {
            for (int i = 0; i < strlen(password) - 1; i++) // 密码字符判断
            {
                if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z'))
                {
                    a = 1;
                }
                if (password[i] >= '0' && password[i] <= '9')
                {
                    b = 1;
                }
            }
            if (a == 1 && b == 1) // 密码合规,确认密码
            {
                fflush(stdin);
                printf("请确认你的密码(8~19,必须由数字和字母组成):");
                scanf("%s", confirm_password);
                // password_preserve(confirm_password, 2); // 注册,密码确认
                if (strcmp(password, confirm_password) == 0)
                {
                    strcpy(registData.username, name);
                    strcpy(registData.passwd, password);
                    registData.type = TYPE_REG;
                    printf("正在注册...\n");
                    send(client_sockfd, &registData, sizeof(Data), 0);
                    memset(&registData, 0, sizeof(Data));
                    int res = recv(client_sockfd, &registData, sizeof(Data), 0);
                    if (res <= 0)
                    {
                        printf("未收到服务器的响应!\n");
                    }
                    else
                    {
                        if (registData.retval == 0)
                        {
                            printf("注册成功!\n");
                            sleep(1);
                            flag = 0;
                        }
                        else
                        {
                            printf("注册失败!用户名已存在!\n");
                            sleep(1);
                        }
                    }
                }
                else
                {
                    printf("你输入的密码不正确!\n");
                }
            }
            else
            {
                printf("你的密码必须由数字和字母组成!\n");
            }
        }
    }
    return;
}

// 用户登录
void login()
{
    int num = 3;
    char arr1[8] = {}, arr2[8] = {}, password[20] = {};
    Data loginData = {};
    while (num > 0)
    {
        printf("您有%d次登录机会\n", num);
        printf("请输入用户名:");
        scanf("%s", loginData.username);
        fflush(stdin);
        printf("请输入密码:");
        scanf("%s", password);
        // password_preserve(password, 0);
        strcpy(loginData.passwd, password);
        // while (1)
        // {
        //     login_captcha(arr1);
        //     fflush(stdin);
        //     printf("输入验证码:");
        //     scanf("%s", arr2);
        //     if (strcmp(arr1, arr2) == 0)
        //     {
        //         break;
        //     }
        // }
        loginData.type = TYPE_LOG;
        printf("登录中...\n");
        send(client_sockfd, &loginData, sizeof(Data), 0);
        memset(&loginData, 0, sizeof(Data));
        int res = recv(client_sockfd, &loginData, sizeof(Data), 0);
        if (res <= 0)
        {
            printf("未收到服务器的响应!\n");
        }
        else
        {
            if (loginData.retval == 0)
            {
                printf("登录成功!\n");
                sleep(1);
                choose();
                num = 0;
            }
            else
            {
                printf("登录失败!\n");
                sleep(1);
                printf("%s\n", loginData.shell_rec);
            }
        }
        num--;
    }
    return;
}

// 登录验证码
void login_captcha(char *arr)
{
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        if (i == 0 || i == 2)
        {
            arr[i] = '0' + rand() % 10;
            arr[i + 1] = '\0';
        }
        else
        {
            arr[i] = 'a' + rand() % 26;
            arr[i + 1] = '\0';
        }
    }
    printf("登录验证码:%s\n", arr);
    return;
}

/*// 密码保护
void password_preserve(char *password, int num)
{
    int i = 0;
    char ch;
    fflush(stdin);
    if (num == 0)
    {
        printf("请输入密码:");
    }
    else if (num == 1)
    {
        printf("请输入你的密码(8~19,必须由数字和字母组成):");
    }
    else if (num == 2)
    {
        printf("请再次输入密码(8~19,必须由数字和字母组成):");
    }
    else if (num == 3)
    {
        printf("请输入新密码(8~19,必须由数字和字母组成)(输入[0]退出):");
    }
    else
    {
        printf("请确认新密码(8~19,必须由数字和字母组成):");
    }
    while (1)
    {
        ch = getch();
        if (ch == '\b')
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == '\r')
        {
            password[i] = '\0';
            break;
        }
        else
        {
            printf("*");
            password[i] = ch;
            i++;
        }
    }
    printf("\n");
    return;
}
*/
// 用户选择界面
void choose()
{
    signal(SIGINT, handler);
    int flag = 1, choose = 0;
    while (flag)
    {
        system("clear");
        printf("┏━━━━━━━━━━欢迎登录<IOTEK>客户端━━━━━━━━━┓\n");
        printf("┃             1、客户端命令              ┃\n");
        printf("┃             2、私聊                    ┃\n");
        printf("┃             3、聊天室                  ┃\n");
        printf("┃             4、查看在线用户            ┃\n");
        printf("┃             0、退出                    ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("请选择编号[0-2]:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            flag = 0;
            break;
        case 1:
            // 客户端命令
            shellSercer();
            break;
        case 2:
            // 私聊
            break;
        case 3:
            // 聊天室
            break;
        case 4:
            // 查看在线用户
            break;
        default:
            printf("输入错误!\n");
            break;
        }
    }
    return;
}

//客戶端命令
void shellSercer()
{
    pthread_t commun;
    pthread_create(&commun,NULL,funCommun,NULL);

    Data shellData = {};
    shellData.type = TYPE_CMD;
    fflush(stdin);
    printf("请输入shell命令:");
    scanf("%s",shellData.shell_send);
    // fgets(shellData.shell_send,sizeof(shellData.shell_send),stdin);
    send(client_sockfd,&shellData,sizeof(Data),0);
    //memset(&shellData,0,sizeof(Data));
    //int res = recv(client_sockfd,&shellData,sizeof(Data),0);
    return;
}

//聊天读取线程
void* funCommun()
{
    Data re_data = {};
    while (1)
    {
        int res = recv(client_sockfd,&re_data,sizeof(Data),0);
        if(res <= 0)
        {
            printf("服务器已关闭,即将退出客户端!\n");
            sleep(1);
            exit(1);
        }
        if(re_data.type == TYPE_CHT_SIG)
        {
            printf("%s\n用户<%s>: %s",re_data.chat_time,re_data.chat_name_send,re_data.chat_data);
        }
        else if(re_data.type == TYPE_CHT_GRP)
        {
            printf("%s\n聊天室<%s>: %s",re_data.chat_time,re_data.chat_name_rec,re_data.chat_data);
        }
        else if(re_data.type == TYPE_CMD)
        {
            if(re_data.retval == 2)
            {
                printf("您输入的命令有误!\n");
            }
            else
            {
                printf("%s\n",re_data.shell_rec);
                break;
            }
        }
    }
    return NULL;
}

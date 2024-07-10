/*
5.编写一个UDP客户端和服务器程序，实现客户端向服务器发送一个整数
服务器接收后判断是否为质数，并将结果发送回客户端，客户端打印出判断结果。
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

const char* ISornot(int num)
{
    const char * str1 = "yes";
    const char * str2 = "no";
    if (num == 1||num==2)
    {
        return str1;
    }
    for ( int i = 2; i < num; i++)
    {
        if (num%i==0)
        {
            return str2;
        }
    }
    return str1;
}

int main()
{
    //创建套接字
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sockfd<0)
    {
        perror("socket error");
        return 1;
    }

    //创建当前地址
    struct sockaddr_in seAddr;
    seAddr.sin_family = AF_INET;
    seAddr.sin_port = htons(8888);
    seAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //绑定
    if (bind(sockfd,(struct sockaddr*)&seAddr,sizeof(seAddr))<0)
    {
        perror("bind error");
        close(sockfd);
        return 1;
    }
    //接收信息
    while(1)
    {
    struct sockaddr_in cli_Arr;
    socklen_t cli_Arr_len = sizeof(cli_Arr);
    int num = 0;
    recvfrom(sockfd,&num,sizeof(int),0,(struct sockaddr*)&cli_Arr,&cli_Arr_len);
    //ISornot(num);

    //发送回客户端
    sendto(sockfd,ISornot(num),strlen(ISornot(num)),0,(struct sockaddr*)&cli_Arr,sizeof(cli_Arr));
    }
    close(sockfd);

    return 0;
}
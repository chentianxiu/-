#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
    //创建套接字
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sockfd<0)
    {
        perror("socket error");
        return 0;
    }
    //创建接收方地址
    struct sockaddr_in recvAdrr;
    recvAdrr.sin_family = AF_INET;
    recvAdrr.sin_port = htons(8888);
    recvAdrr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //发送消息
    int num = 0;
    printf("请输入一个数\n");
    scanf("%d",&num);

    sendto(sockfd,&num,sizeof(int),0,(struct sockaddr*)&recvAdrr,sizeof(recvAdrr));

    //接收消息
    char buf[128] = {};
    struct sockaddr_in r_addr = {};
    socklen_t r_addr_len = sizeof(r_addr);
    recvfrom(sockfd,buf,127,0,(struct sockaddr*)&r_addr,&r_addr_len);

    printf("%s质数\n",buf);
    return 0;
}
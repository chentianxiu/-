#include "server.h"

int main()
{
    /*
    server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(server_sockfd < 0)
    {
        perror("sock error\n");
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10010);
    inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr.s_addr);
    */
    
    server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serveraddr;
    set_serveraddr(&serveraddr); //获取服务器地址IP信息
    
    int opt = 1;
    int retOfset = 0;//防止address被占用
    if(retOfset = setsockopt(server_sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt)) < 0)
    {
        perror("setsocket error\n");
        exit(1);
    }

    if(bind(server_sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) < 0)
    {
        perror("bind error\n");
        exit(1);
    }
    if(listen(server_sockfd,20) < 0)
    {
        perror("listen error\n");
        exit(1);
    }

    deal(server_sockfd);//接受客户端连接请求

    printf("退出服务器!\n");
    sleep(2);
    close(server_sockfd);
    return 0;
}

//创建套接字
void socket_create()
{
    server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(server_sockfd < 0)
    {
        perror("socket error\n");
        return;
    }
}

//配置服务器地址
void set_serveraddr(struct sockaddr_in* serveraddr)
{
    FILE* fp = fopen("setting.txt","r");//打开配置文件127.0.0.1  10010
    char ip[20] = {};
    fscanf(fp,"%s",ip);
    printf("服务器ip:%s\n",ip);

    int port = 0;
    fscanf(fp,"%d",&port);
    printf("服务器port:%d\n",port);

    memset(serveraddr,0,sizeof(struct sockaddr_in));
    serveraddr->sin_family = AF_INET;
    serveraddr->sin_port = htons(port);
    inet_pton(AF_INET,ip,&serveraddr->sin_addr.s_addr);

    fclose(fp);
    fp = NULL;
}

/*
TCP通信流程
发送方：
1.创建套接字
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
2.准备接收方的地址
    struct sockaddr_in recvAddr;
3.连接
    connect(sockfd,(struct sockaddr*)&recvAdrr,sizeof(recvAddr));
4.给对方发送信息
    send(sockfd,buf,strlen(buf),0);

接收方:
1.创建套接字：
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
2.准备自己的地址:
    struct sockaddr_in localAddr;
3.绑定套接字和地址
    bind(fd,localAddr);
4.监听
    if (listen(sockfd, 10) < 0)
    {
        perror;
    }
5.接受信息
创建一个地址来接收//struct sockaddr_in cli_addr = {};
得到地址的长度//socklen_t cli_addr_len = sizeof(cli_addr);
创建套接字来接受信息//int cli_fd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_addr_len);
之后用cli_fd来接受信息
recv(cli_fd,buf,sizeof(buf),0);
*/
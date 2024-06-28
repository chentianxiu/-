#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sockfd<0)
	{
		perror("socket error");
		return 1;
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");	//reveiver's ip address

	if(bind(sockfd,(struct sockaddr*)&addr,sizeof(addr))<0)
	{
		perror("bind error");
		close(sockfd);
		return 1;
	}
	
	if(listen(sockfd,20)<0)
	{
		perror("listen error");
		close(sockfd);
		return 1;
	}

	struct sockaddr_in r_addr = {};
	socklen_t addr_len = sizeof(r_addr);
	int client_fd = accept(sockfd,(struct sockaddr*)&r_addr,&addr_len);
	if(client_fd<0)
	{
		perror("accept error");
		close(sockfd);
		return 1;
	}
	else
	{
		printf("client %s:%d connected...\n",inet_ntoa(r_addr.sin_addr),ntohs(r_addr.sin_port));
	}


	while(1)
	{
		char buf[128] = {};
		int bytes = recv(client_fd,buf,127,0);
		if(bytes<=0)
		{
			printf("client %s:%d disconnected...\n",inet_ntoa(r_addr.sin_addr),ntohs(r_addr.sin_port));
			break;
		}
		else
		{
			printf("receive %d bytes \"%s\" by client %s:%d\n",bytes,buf,inet_ntoa(r_addr.sin_addr),ntohs(r_addr.sin_port));
		}
	}

	close(client_fd);
	close(sockfd);

	return 0;
}

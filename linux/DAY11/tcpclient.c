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

	if(connect(sockfd,(struct sockaddr*)&addr,sizeof(addr))<0)
	{
		perror("connect error");
		close(sockfd);
		return 1;
	}

	int bytes = send(sockfd,"hello server!",13,0);
	printf("send %d bytes msg to server\n",bytes);

	close(sockfd);

	return 0;
}

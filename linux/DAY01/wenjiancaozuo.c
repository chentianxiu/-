#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int r_fd = open("a.txt",O_RDONLY);
    if (r_fd <0)
    {
        perror("文件[a.txt]打开失败");
        return 1;
    }
    int w_fd = open("b.txt",O_WRONLY|O_CREAT,0666);
    if (w_fd < 0)
    {
        perror("文件[b.txt]打开失败");
        return 1;
    }

    char buf[128] = {0};
    int bytes = 0;

    while (1)
    {
        bytes = read(r_fd,buf,127);//读第一个文件
        if(bytes<=0){
			break;
        }
		printf("%s",buf);
		fflush(stdout);//清除缓存

		write(w_fd,buf,bytes);//写入第二个文件
		memset(buf,0,128);
    }

    close(w_fd);
	close(r_fd);
	return 0;
    


    
}
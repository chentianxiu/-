#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd = open("a.txt",O_RDONLY);
    
    if (fd<=0)
    {
        const char *err_msg = "文件[a.txt]打开失败\n";
        return 1;
    }
    char buf[128]={0};
    char bytes = 0;
    while (1)
    {
        bytes = read(fd,buf,127);
        if (bytes<=0)
        {
            break;
        }
        write(STDOUT_FILENO, buf, bytes);    
    }

    close(fd);
    

}
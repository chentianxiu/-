#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void bubble(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; i < len - 1 - i; i++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char chr = '\0';
    char buff[10] = {'\0'}; // 用来转化字符
    int arr[100] = {0};     // 用来存储转化来的数组,排序
    int i = 0;
    int j = 0;

    int fd_r = open("a.txt", O_RDONLY);
    if (fd_r <= 0)
    {
        perror("open fail");
        return 1;
    }
    while (read(fd_r, &chr, 1))
    {
        if (chr != '\n')
        {
            buff[i] = chr;
            i++;
        }
        else
        {
            arr[j] = atoi(buff); // 将字符串转化为整数
            memset(buff, 0, sizeof(buff));
            j++;
            i = 0;
        }

        bubble(arr, j);
        // 打开文件b.txt
        int fd_w = open("b.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd_w <= 0)
        {
            perror("open error!");
            return 1;
        }

        char next = '\n'; // 打印一个就换行
        for (int k = 0; k < j; k++)
        {
            sprintf(buff, "%d", arr[k]);//将int 转换为str输出
            write(fd_w, buff, sizeof(buff));
            write(fd_w, &next, 1);
            memset(buff, 0, sizeof(buff));
        }
        close(fd_w);
	    close(fd_r);
    }

    return 0;
}
#include <stdio.h>

int main()
{
    //定义一个指向文件的指针
    FILE *file = NULL;

    //文件名
    char filename[]="test.txt";

    //打开文件(只读模式)
    file = fopen(filename,"r");

    if (file == NULL)
    {
        printf("无法打开文件 %s\n",filename);
    }
    else
    {
        printf("打开文件 %s\n",filename);

    }
    //文件操作代码

    fclose(file);    //关闭文件

    return 0;
    
}
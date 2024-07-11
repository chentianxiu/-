#include <stdio.h>

int main()
{
    //1、定义一个指向文件的指针，创建一个FILE类
    FILE *file = NULL;

    //文件名
    char filename[]="test.txt";

    //2.打开文件(只读模式)
    file = fopen(filename,"r");

    //3.判断是否打开文件
    if (file == NULL)
    {
        printf("无法打开文件 %s\n",filename);
    }

    //4.文件操作代码
    printf("打开文件 %s\n",filename);

    
    //5.文件关闭

    fclose(file);    //关闭文件

    return 0;
    
}
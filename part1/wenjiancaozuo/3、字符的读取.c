#include <stdio.h>

int main()
{
    //创建FILE结构体
    FILE * file = NULL;

    //打开文件
    file = fopen("test.txt","r");

    //判断文件是否存在

    if(file == NULL){
        printf("文件打开失败");
        return 1;
    }
    //定义一个字符，表示每次读取的字符
    char ch;
    //逐个字符读取并且输出
    while((ch = fgetc(file))!=EOF){
        printf("%c",ch);
    }

    //关闭文件
    fclose(file);
    return 0;
    
}
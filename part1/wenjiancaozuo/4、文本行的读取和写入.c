#include <stdio.h>

int main()
{
    FILE * file = NULL;

    file = fopen("test.txt","w");

    if(file == NULL){
        printf("文件打开失败\n");
        return 1;
    }

    //定义一个字符串，表示需要写入的内容
    char * str = "hello world,你好世界\n";

    //文本写入

    fputs(str,file);

    fclose(file);

    return 0;
    
}
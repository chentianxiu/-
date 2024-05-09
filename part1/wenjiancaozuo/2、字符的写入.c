#include <stdio.h>

int main()
{
    FILE *file = fopen("test.txt","w");
    if (file == NULL)
    {
        printf("文件打开失败\n");
        return 1;
    }
    
    int num = fputc('A',file);//向文件写入字符'A'

    printf("%d",num);//ascll 对应的数字

    fclose(file);

    return 0;
    
}
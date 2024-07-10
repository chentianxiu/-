#include <stdio.h>

int main()
{
    char ch = 'a';
    //打印字符
    printf("%c\n",ch);
    //字符地址
    printf("%p\n",&ch);
    //定义字符指针
    char *ptr = &ch;
    //打印字符指针
    printf("%p\n",ptr);
    //解引用
    printf("%c\n",*ptr);

    return 0;
    
}
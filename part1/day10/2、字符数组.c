#include <stdio.h>

int main()
{
    //字符数组
    char arr[]="hello";

    //将字符数组赋值给指针
    char *ptrs = arr;

    //打印数组的首元素地址
    printf("%p\n",&arr[0]);
    //打印数组名
    printf("%p\n",arr);

    //打印指针
    printf("%p\n",ptrs);

    printf("%p\n",*ptrs);

    //指针移动并且赋值
    *(ptrs+2)='o';
    printf("%s\n",arr);
    printf("%c\n",*(ptrs+1));

    return 0;
    
}
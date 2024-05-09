#include <stdio.h>

int main()
{
    //字符数组
    char arr[]="hello";

    //将字符数组赋值给指针
    char *ptrs = arr;


    char *ptrs2 = "hello world";//这个就不能修改，指针指向的常量不能修改
    const char *ptrs2 = "hello world";//和上面一样，都是不能修改的
    //打印数组的首元素地址
    printf("%p\n",&arr[0]);
    //打印数组名
    printf("%p\n",arr);

    //打印指针
    printf("%p\n",ptrs);

    printf("%p\n",*ptrs);//无意义

    //指针移动并且赋值
    *(ptrs+2)='o';
    //*(ptrs2+2)='o'; //会报错
    printf("%s\n",arr );
    printf("%c\n",*(ptrs+1));

    return 0;
    
}
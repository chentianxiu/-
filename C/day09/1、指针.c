#include <stdio.h>

int main()
{
    int a = 10;
    printf("%p\n",&a);

    int *ptr = &a;
    printf("%p\n",ptr);
//指针等于首地址

    int b=0;
    int size_int = sizeof(b);
    printf("int类型的大小:%d\n",size_int);

    int *ptr2 = &b;
    int size_ptr2 = sizeof(ptr2);//指针大小为8 与操作平台有关
    printf("指针类型大小:%d",size_ptr2);
    return 0;
    // 指针的类型就是指针指向地址中保存数据的类型
}


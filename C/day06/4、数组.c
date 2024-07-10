#include <stdio.h>

int main()
{
    int age[4]={25,26,27,28};

    double high[5]={1.82,1.58,1.92,1.95,2.14};

    printf("age的数组名是%p\n",age);//会打印出数组额地址，数组的地址是首元素的地址，%p用来打印指针地址
    //age的数组名是000000000061FE10，16进制 地址=指针（c语言）

    return 0;
    
}
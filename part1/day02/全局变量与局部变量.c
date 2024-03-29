#include <stdio.h>

int main()
{   
    int a = sizeof(int);
    printf("基本类型所占字节：%d\n",a);
    int b = sizeof(short);
    printf("基本类型所占字节：%d\n",b);
    int c = sizeof(long);
    printf("基本类型所占字节：%d\n",c);

    return 0;

}
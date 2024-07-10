#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;
    int a = x>y;//先运行x>y,在运行把x>y的值赋值给a
    printf("a的值是%d",a);



    return  0;

}
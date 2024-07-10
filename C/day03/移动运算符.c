#include <stdio.h>

int main()
{
    int a = 4;
    int b = a<<1;
    int d = a<<2;
    int c = a>>3;

    printf("b的值是%d\n",b);

    printf("d的值是%d\n",d);

    printf("c的值是%d\n",c);

    return 0;

}
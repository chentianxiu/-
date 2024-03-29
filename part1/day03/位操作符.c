#include <stdio.h>

int main()
{   
    int a = 10;//0000 1010
    int b = 5; //0000 0101
    int c = a&b;
    printf("a与b是%d\n",c);
    
    int d = a|b;
    printf("a或b是%d\n",d);

    int e = ~a;//反码加一的形式 11111111 ...11110101-->10000000 ... 00001010+1 --> 1010+1 = 1011
    printf("非a是%d\n",e);//即-11

    int f = a^b;
    printf("a异或b是%d\n",f);
    return 0;

}
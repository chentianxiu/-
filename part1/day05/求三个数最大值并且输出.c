#include <stdio.h>

int  getmax(int a, int b, int c){
    a = a>b?a:b;
    a = a>c?a:c;
    return a;
}

int main()
{
    int a , b , c = 0;
    printf("请输入三个数：\n");
    scanf("%d%d%d",&a,&b,&c);
    printf("最大值是%d",getmax(a,b,c));
    

    return 0;
    
}
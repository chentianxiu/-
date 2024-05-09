#include <stdio.h>

void function(){
    printf("i am good\n");
}

int maxNum(int a,int b){
    printf("%d\n",a>b?a:b);
    return a>b?a:b;
    //printf("%d",a>b?a:b);
}

int main()
{
    //定义指针函数
    void (*p)()=function;
    void (*p2)() = &function;

    int (*ptr)(int, int) = maxNum;

    //调用
    (*p)();
    p();
    ptr(5,6);
    (*ptr)(5,6);
    
    return 0;
    
}
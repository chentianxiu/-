#include <stdio.h>

//递归输出
void reseverSTR(){
    char c;
    scanf("%c",&c);
    if(c!='\n'){
        reseverSTR();
        printf("%c",c);
    }
}

int main()
{
    printf("请输入一串字符串:\n");
    reseverSTR();

    return 0;
    
}
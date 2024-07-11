#include <stdio.h>

int main()
{
    int age = 0;
    printf("请输入您的年龄\n");
    scanf("%d",&age);

    if(age>=18){
        printf("您已经成年，需要付费\n");
        }
    else{
        printf("您未成年，免除费用\n");
        }
    printf("祝您游玩愉快\n");
    return 0;
    
}
#include <stdio.h>

int main()
{
    //用数组来展示字符串

    char str1[]="12345";
    //数组长度
    int length = sizeof(str1)/sizeof(str1[0]);

    printf("%s\n",str1);
    printf("字符串长度%d\n",length);
    //从数组长度来打印字符串
    //倒着输出
    for(int i = length-1;i>=0;i--){
        printf("%c",str1[i]);
    }
    printf("\n");

    //用指针来展示数组

    char str2[]= "nihao,shijie";
    char *ptr;

    int length2 = sizeof(str2)/sizeof(str2[0]);
    printf("字符串长度%d\n",length2);

    printf("%s\n",str2);

    printf("倒着输出是:\n");
    //初始化ptr指向数组最后一个元素
    ptr = str2 + length2 -1;
    //打印数组长度的字符，所以i=length2
    for(int i = 0;i<length2;i++){
        printf("%c",*ptr);
        ptr--;//指针向前移动一位
    }
    printf("\n");

    return 0;
    
}
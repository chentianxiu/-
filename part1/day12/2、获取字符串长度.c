#include <stdio.h>
#include<string.h>

int my_strlen(char* ptr){
    int len = 0;
    //遍历指针，当指针指向空，字符串被遍历完成，同时计数完字符串长度
    while (*ptr != '\0')
    {
        len++;
        ptr++;
    }

    return len;
    
}

int main()
{
    char str[]="hei1hei2hei3";
    int len  = my_strlen(str);
    printf("字符串长度为%d",len);
    

    return 0;
    
}
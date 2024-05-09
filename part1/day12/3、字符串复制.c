#include <stdio.h>
#include<string.h>

void my_strcpy( const char *ptr1,  char *ptr2){
    while (*ptr1 != '\0')
    {
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;

    }
    *ptr2 = '\0';
    
    return;
    
}

int main()
{
    char str1[] = "hello";
    char str2[50];
    my_strcpy(str1,str2);
    printf("复制完成的字符串是:%s\n",str2);

    char str3[50];
    //调用string.h库函数的输出结果
    strcpy(str3,str1);
    printf("调用库函数复制完成的字符串是:%s\n",str3);

    return 0;
    
}
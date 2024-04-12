#include <stdio.h>
#include <string.h> 
#define MAX_INPUT_SIZE 100

int main()
{
    char ch[MAX_INPUT_SIZE];
    char quit[]="quit";
    char hello[]="hello";
    /*
    strcmp 函数会比较两个 C 风格的字符串 s1 和 s2。比较是基于字符的ASCII值进行的。
    如果 s1 和 s2 完全相同，函数返回 0。
    如果 s1 在字典顺序上小于 s2，函数返回一个负数。
    如果 s1 在字典顺序上大于 s2，函数返回一个正数。
    */
    while(1){
 
        //if (scanf("%s", ch) != 1) {  
         //   break; // 输入错误或EOF，退出循环  
        //}  
        printf("请输入一串字符串：\n");
        scanf("%s",&ch);
        printf("输入的字符串是%s\n",ch);
  
        if (strcmp(ch, quit) == 0) {  
            printf("程序结束。\n");  
            break;  
        } else if (strcmp(ch, hello) == 0) {  
            printf("world\n");  
        } else {  
            printf("wrong input\n");  
        }  
  
        // 清除输入缓冲区中的剩余字符  
        while (getchar() != '\n');
       
    }

    return 0;
    
}
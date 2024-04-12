#include <stdio.h>  
#include <string.h>  
  
#define MAX_INPUT_SIZE 100  
  
int main() {  
    char input[MAX_INPUT_SIZE];  
    char quit[] = "quit";  
    char hello[] = "hello";  
  
    while (1) {  
        printf("请输入一行字符串: ");  
        if (scanf("%99s", input) != 1) {  
            break; // 输入错误或EOF，退出循环  
        }  
  
        if (strcmp(input, quit) == 0) {  
            printf("程序结束。\n");  
            break;  
        } else if (strcmp(input, hello) == 0) {  
            printf("world\n");  
        } else {  
            printf("wrong input\n");  
        }  
  
        // 清除输入缓冲区中的剩余字符  
        while (getchar() != '\n');  
    }  
  
    return 0;  
}
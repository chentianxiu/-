#include <stdio.h>  
  
int main() {  
    char str[101]; // 大小为101的字符数组，以包含100个字符和一个空字符  
    int i;  
      
    // 使用循环初始化字符串，填充前100个字符  
    for (i = 0; i < 100; i++) {  
        str[i] = 'a'; // 这里只是用字符'a'作为示例  
    }  
    str[100] = '\0'; // 添加结尾的空字符  
      
    // 输出字符串  
    printf("%s\n", str);  
      
    return 0;  
}
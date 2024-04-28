#include <stdio.h>  
#include <stdlib.h> 
#include<string.h> 
  
int main() {  
    char input[100]; // 假设小数不会超过99个字符  
    float number;  
  
    printf("请输入一个小数: ");  
    fgets(input, sizeof(input), stdin); // 从标准输入读取一行，存储在input中  
  
    // 移除可能的换行符  
    input[strcspn(input, "\n")] = 0;  
  
    // 将字符串转换为浮点数  
    number = atof(input);  
  
    printf("你输入的小数是: %.2f\n", number);  
  
    return 0;  
}
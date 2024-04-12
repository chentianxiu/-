#include <stdio.h>  
#include <string.h>  
#include <ctype.h>  
  
// 自定义函数，用于统计字符串中的单词个数  
int countWords(const char *str) {  
    int count = 0; // 单词计数器  
    int inWord = 0; // 当前是否处于单词内部的标志  
  
    // 遍历字符串中的每个字符  
    for (const char *p = str; *p != '\0'; p++) {  
        // 如果当前字符是空格且之前不在单词中，则忽略它  
        if (isspace(*p) && inWord) {  
            inWord = 0; // 结束当前单词  
        } else if (!isspace(*p)) {  
            if (!inWord) {  
                count++; // 开始一个新单词  
                inWord = 1;  
            }  
        }  
    }  
  
    return count;  
}  
  
int main() {  
    char str[1001]; // 假设字符串长度不会超过1000个字符  
  
    // 从用户处读取字符串  
    printf("请输入一个字符串（用空格分隔单词）：\n");  
    if (fgets(str, sizeof(str), stdin) != NULL) {  
        // 移除字符串末尾的换行符（如果有的话）  
        str[strcspn(str, "\n")] = 0;  
  
        // 调用自定义函数统计单词个数  
        int wordCount = countWords(str);  
  
        // 输出结果  
        printf("字符串中的单词个数为：%d\n", wordCount);  
    } else {  
        printf("读取字符串时出错。\n");  
    }  
  
    return 0;  
}
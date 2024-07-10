#include <stdio.h>
#include <conio.h>

int main() {
    char pwd[32];
    int i = 0;
    char ch;
    printf("请输入密码: ");

    while ((ch = getch()) != '\r') { // '\r' 是 Windows 上的回车键
        if (ch == '\b' && i > 0) {   // 处理退格键
            printf("\b \b");         // 光标回退，打印空格，再次回退光标
            i--;
        } else if (ch != '\b') {
            pwd[i++] = ch;
            printf("*");             // 为每个字符显示星号
        }
    }
    pwd[i] = '\0';                  // 字符串结尾加空字符

    printf("\n您输入的密码是: %s\n", pwd); // 出于演示目的显示密码
    return 0;
}

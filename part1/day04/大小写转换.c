//思路：字母的大小写ascii码的值相差为32，转换时ascii码的值加或者减32即可。不是大小写的字母的其他值
//ascii码值加一用作区分
#include <stdio.h>

int main()
{
    char ch;
    printf("请输入一个字符\n");
    scanf("%c",&ch);
    
    if(ch>='a'&&ch<='z'){
        ch=ch-32;
    }else if(ch>='A'&&ch<='Z'){
        ch=ch+32;
    }else{
        ch=ch+1;
    }
    printf("转化后的字符是%c\n",ch);

    return 0;
    
}
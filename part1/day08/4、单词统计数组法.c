#include <stdio.h>
#include <string.h>
//统计字符串中单词的个数
int countworld(const char* str){
//标记是否在单词中
    int count = 0;
    int inworld = 0;//用0表示在单词外，1表示在代词里面，每次遇到空格1就变成0，遇到非空格就变成1

//遍历字符串
    for(int i = 0;str[i]!='\0';i++){
        //如果遇到空格并且前一个字符不是空格，说明找到了一个单词
        if(str[i] == ' '&&inworld==1){
            count++;
            inworld = 0;//重置标记
        }else if(str[i]!=' '){
            inworld = 1;//标记在单词中
        }
    }
//如果字符串以单词结束，需要额外计数
    if(inworld){
        count++;
    }
    return count;
}

int main()
{
    //定义一个字符串数组
    char str[100] = "";
    //读取字符串，包括空格
    printf("请输入一行字符串:\n");
    fgets(str,sizeof(str),stdin);
    //移除可能的换行符
    str[strcspn(str, "\n")] = 0;//strcspn(str, "\n")计算字符串str中第一个\n字符的索引。str[strcspn(str, "\n")]访问该索引处的字符。= 0;将该字符替换为字符串结束符'\0'

    //声明调用函数
    int Cworld = countworld(str);
    printf("字符串中单词的数量是:%d\n",Cworld);

    return 0;
    
}
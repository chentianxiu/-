#include<stdio.h>
#include<unistd.h>

int main(){
    char str[128] = {0};
    printf("请输入:");

    /*输入-从终端读取*/
    fscanf(stdin,"%s",str);

    /*输出-打印到终端上*/
    fprintf(stdout,"%s\n",str);

    return 0;
}
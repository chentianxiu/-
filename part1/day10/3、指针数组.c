#include <stdio.h>

int main()
{
    //定义一个长度为6的数组
    int arr[6] = {10,20,30,40,50,60};
    //定义一个长度为3的指针数组，里面存放arr中1、2和最后一个数据
    int *parr[3]={&arr[0],&arr[1],&arr[5]};
    //通过指针数组访问数据及地址
    int length1 = sizeof(parr)/sizeof(parr[0]);
    for (int i = 0;i<length1;i++){
        //printf("数据%d,地址%p\n",*(parr+i),parr+i);
        printf("数据%d,地址%p\n",*parr[i],parr[i]);
    }

    return 0;
    
}
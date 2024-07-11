#include <stdio.h>
//定义遍历函数
void printArray(int *ptr,int length)
{
    for(int i = 0;i<length;++i){
        printf("%d\n",*(ptr+i));
    }
}

// 主函数
int main()
{
    int arr[]={10,20,30,40};
    int length = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,length);//引用函数


    return 0;
    
}
#include <stdio.h>

int main()
{
    int arr[5] = {10,20,30,40,50};
    //数组的长度
    int length = sizeof(arr)/sizeof(arr[0]);

    //定义一个指针数组
    int *ptrArr[4];
    //通过遍历进行复制
    for (int i = 0;i<length;i++)
    {
        ptrArr[i] = &arr[i];
    }

    //打印结果
    for (int i = 0;i<length ;i++)
    {
        printf("值:%d,地址:%p\n",*ptrArr[i],ptrArr[i]);
    }

    return 0;
    
}
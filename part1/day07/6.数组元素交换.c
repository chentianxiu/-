#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,5};
    int length=sizeof(arr)/sizeof(arr[0]);
    //定义一个变量i 表示左边索引
    //定义一个变量j 表示右边索引
    //遍历数组，进行交换，交换条件为 i<=j
    for (int i = 0,j=length-1; i <= j; i++,j--)
    {//替换
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    //遍历数组
    for (int i = 0; i < length; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    

    return 0;
    
}
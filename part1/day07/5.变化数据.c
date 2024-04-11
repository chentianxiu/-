#include <stdio.h>


//定义一个函数，将传递的数组扩大两倍
//数组声明方式：数组的大小必须在函数定义是指定，且不能省略
void updateArray1(int arr[],int length){
    for (int i = 0; i < length; i++)
    {
        arr[i]*=2;
    }
}
int main()
{
    int arr[]={1,2,3,4,5};
    int length=sizeof(arr)/sizeof(arr[0]);
    printf("变化之前的结果:\n");
    for(int i=0;i<length;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");

    //数组声明方式调用函数
    updateArray1(arr,length);

    printf("数组声明变化之后的结果\n");
    for(int i=0;i<length;i++){
        printf("%d\t",arr[i]);
    }

    return 0;
    
}
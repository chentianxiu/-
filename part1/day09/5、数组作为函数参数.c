//定义一个函数，将传递的数组元素扩大2倍

#include <stdio.h>

void updateArray2(int *ptr,int length){
    for(int i = 0;i<length;i++)
    {
        *(ptr+i)*=2;
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int length = sizeof(arr)/sizeof(arr[0]);
    printf("原来的数组是:\n");
    
    for(int i = 0;i<length;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");

    //指针方式调用函数
    updateArray2(arr,length);
    
    printf("变化后的数组是:\n");

    for(int i = 0;i<length;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");


    return 0;
    
}
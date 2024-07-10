#include <stdio.h>
//定义函数
int chengFA(int arr[],int length){
    int M = 1;
    for(int i = 0;i<length;i++){
        M *=arr[i];
    }
    return M;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};

    int length = sizeof(arr)/sizeof(arr[0]);
//函数声明调用
    int mul = chengFA(arr,length);

    printf("数组相乘的答案是：%d\n",mul);

    return 0;
    
}
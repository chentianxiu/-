#include <stdio.h>

int main()
{
    int arr1[5]={1,3,5,7,9};
    printf("%d\n",arr1[5]);
    for(int i=0;i<=4;i++){
        printf("%d\n",arr1[i]);
    }
    int size_arr=sizeof(arr1);//4个字节*5个数
    //printf("数组的长度是%d\n",length);
    int length = size_arr/sizeof(arr1[0]);//第一个元素的长度为4个字节
     printf("数组的长度是%d\n",length);

    return 0;
    
}
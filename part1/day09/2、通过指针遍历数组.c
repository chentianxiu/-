#include<stdio.h>
//通过指针遍历数组
int main() 
{

    int arr[]={10,20,30,40};

    int *ptr = arr;//*ptr 就是数组元素

    int length = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<length;++i){
        int temp = *(ptr+i);
        printf("%d\n",*(ptr+i));
    }


    return 0;
}
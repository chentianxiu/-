#include<stdio.h>
//通过指针遍历数组
int main() 
{

    int arr[]={10,20,30,40};

    int *ptr = arr;//*ptr 就是数组元素

    int length = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<length;++i){
        int temp = *(ptr+i);
        printf("%d\n",temp);
    }

    for(int i = 0;i<length;++i){
        int temp = *ptr++;
        printf("%d\n",temp);
    }
    printf("%d\n",*ptr);//ptr指针超过数组，成为野指针


    return 0;
}
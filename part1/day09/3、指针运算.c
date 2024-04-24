#include<stdio.h>

int main()
{
    int arr[]={10,20,30,40};
    int *ptr1 = &arr[0];
    int *ptr2 = &arr[2];

    int offset = ptr2 - ptr1;//两个指针相差的步数


    printf("%d\n",offset);

    printf("%d\n",(*ptr2 - *ptr1));//两个数组元素的差



    return 0 ;
}
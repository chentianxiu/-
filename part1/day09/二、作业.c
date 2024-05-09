#include <stdio.h>
//指针冒泡排序，就是数组排序换一种写法,arr[i]用指针代替掉

void Maopao(int *ptr,int length){
    int temp = 0;
    for(int i = 0;i<length-1;i++){
        for(int j=0;j<length-1-i;j++){
            if(*(ptr+j)>*(ptr+j+1)){
                temp = *(ptr+j+1);
                *(ptr+j+1) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
}

int main()
{
    int arr[] ={1,16,9,55,44,99};
    int *ptr = arr;
    int length = sizeof(arr)/sizeof(arr[0]);
    Maopao(arr,length);
    printf("数组排序完结果是：\n");
    for(int i = 0;i<length;i++){
        printf("%d ",*(ptr+i));
    }

    return 0;
    
}
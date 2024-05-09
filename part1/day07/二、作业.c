#include <stdio.h>

int main()
{
    int arr[10];
    int length = sizeof(arr)/sizeof(arr[0]);
    int he = 0;
    int he2 = 0;
    printf("请依次输入10个元素:\n");
    for(int i = 0;i<=length-1;i++){
        scanf("%d",&arr[i]);
        //偶数下标的和
        if(i%2==0){
            he +=arr[i];
        }//偶数元素的和
        if(arr[i]%2==0){
            he2 +=arr[i];
        }
    }
    printf("数组是：\n");
    for(int i =0;i<=length-1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("所有偶数下标的和是%d\n",he);
    printf("所有偶数元素的和是%d\n",he2);



    return 0;
    
}
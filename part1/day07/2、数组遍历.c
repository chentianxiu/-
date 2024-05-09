#include <stdio.h>

int main()
{
    int arr1[5]={1,2,3,4,5};
    int length=sizeof(arr1)/sizeof(arr1[0]);

    printf("[");
    for (int i = 0; i < length; i++)
    {
        if(i==length-1){
            printf("%d",arr1[i]);
        }else{
            printf("%d, ",arr1[i]);
        }
        //printf("%d, ",arr1[i]);
    }


    
    
    printf("]\n");//打印数组
    int add=0;
    for (int i = 0; i < length; i++)
    {
        add+=arr1[i];
    }
    printf("数组的和是%d\n",add);//求和

    return 0;
    
}
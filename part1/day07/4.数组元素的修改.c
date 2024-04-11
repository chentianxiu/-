#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int length=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<length;i++){
        if(arr[i]%2!=0){
            arr[i]*=2;
        }else{
            arr[i]/=2;
        }
    }
    printf("变化之后的结果是:\n");
    printf("[");
    for(int i=0;i<length;i++){
        if(i<length-1){
        printf("%d, ",arr[i]);
        }else{
            printf("%d",arr[i]);
        }
    }
    printf("]");

    return 0;
    
}
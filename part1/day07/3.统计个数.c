#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    //sizeof 获取数组长度
    int length = sizeof(arr)/sizeof(arr[0]);
    //定义一个变量用于计数
    int count = 0;
    printf("能被3整除的数是:");
    for(int i=0;i<length;i++){
        //，满足条件的计数
        if(arr[i]%3==0){
            count++;
            printf("%d\t",arr[i]);
        }
    }
    printf("\n");
    printf("1~10之间能被3整除的个数有:%d个\n",count);

    return 0;
    
}
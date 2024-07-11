#include <stdio.h>

//定义一个函数返回最大值和最小值
void ReturnDX(int *ptr,int length){
    int D=0;//给初始值为0
    int X = *(ptr+0);//最小值初始值给一个数组中的数，好比较
    for(int i = 0;i<length;i++){
        if(*(ptr+i)>D){
            D=*(ptr+i);
        }
        if(*(ptr+i)<X){
            X=*(ptr+i);
        }
    }
    printf("最大值是%d,最小值是%d\n",D,X);
    int arr1[2]={D,X};
    printf("%d %d",arr1[1],arr1[2]);
    return ;
}

int main()
{
    int arr[5];
    int *ptr = arr;
    for(int i = 0;i<5;i++){
        printf("请输入第%d个数:\n",i+1);
        scanf("%d",(ptr+i));//这里要输入地址，用ptr不用&；
    }

    ReturnDX(arr,5);
    return 0;
    
}
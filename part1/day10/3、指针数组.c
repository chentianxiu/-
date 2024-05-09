#include <stdio.h>

int main()
{
    //定义一个长度为6的数组

    int arr[6] = {10,20,30,40,50,60};

    //定义一个长度为3的指针数组，里面存放arr中1、2和最后一个数据

    int *parr[3]={&arr[0],&arr[1],&arr[5]};

    //定义长度为5的指针数组，里面都放arr的地址
    
    int *parr2[5]={arr,arr,arr,arr,arr};

    //获取第二个数组的所有数据

    //外层循环；指针数组循环

    int length2 = sizeof(parr2)/sizeof(parr[0]);

    //内层循环，遍历数组arr

    int length3 = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0;i<length2;i++){

        for(int j = 0;j<length3;j++){

            printf("%d ",*(parr2[i]+j));

        }

        printf("\n");
        
    }
    //通过指针数组访问数据及地址

    int length1 = sizeof(parr)/sizeof(parr[0]);

    for (int i = 0;i<length1;i++){

        //printf("数据%d,地址%p\n",*(parr+i),parr+i);

        printf("数据%d,地址%p\n",*parr[i],parr[i]);

    }

    return 0;
    
}
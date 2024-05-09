#include <stdio.h> 
  
void bubbleSort(int arr[], int length) {  
    int i, j, temp;  
    //i表示轮次，j表示数组中元素索引
    //1、使用嵌套循环，外层循环表示比较的轮次，内层循环表示每轮比较的次数；
    //2、外层循环：变量i表示循环的次数，i<=（n-1）;（n表示元素的个数）；
    //3、内层循环：变量j表示元素的索引,arr[j]需要与后面的（n-1）个元素进行比较，
    //由于每轮都能获取该轮的最大值，顾每次比较（n-1-i）次；

    for (i = 0; i < length-1; i++) {  
        for (j = 0; j < length-i-1; j++) {  
            if (arr[j] > arr[j+1]) {  //从小到大排序
                // 交换 arr[j] 和 arr[j+1]  
                temp = arr[j];  
                arr[j] = arr[j+1];  
                arr[j+1] = temp;  
            }  
        }  
    }  
}  
  
int main() {  
    int arr[] = {64, 34, 25, 12, 22, 11, 63};  
    int length = sizeof(arr)/sizeof(arr[0]);  
    int i;  
  
    printf("原始数组：\n");  
    for (i = 0; i < length; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
  
    bubbleSort(arr, length);  
  
    printf("排序后的数组：\n");  
    for (i = 0; i < length; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
  
    return 0;  
}
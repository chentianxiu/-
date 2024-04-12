#include <stdio.h> 
  
void bubbleSort(int arr[], int length) {  
    int i, j, temp;  
    for (i = 0; i < length-1; i++) {  
        for (j = 0; j < length-i-1; j++) {  
            if (arr[j] > arr[j+1]) {  
                // 交换 arr[j] 和 arr[j+1]  
                temp = arr[j];  
                arr[j] = arr[j+1];  
                arr[j+1] = temp;  
            }  
        }  
    }  
}  
  
int main() {  
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
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
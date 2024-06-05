#include <stdio.h>

//计算数组中唯一元素的个数
int removeDuplicates(int *nums, int numsSize)
{
    int pre = 0;
    int cur = 1;
    while(cur<numsSize)
    {
        if(nums[pre]==nums[cur]){
            cur++;
        }
        else{
            nums[pre+1]=nums[cur];
            pre++;
            cur++;
        }
    }
    return pre+1;
    
}

//出去数组中指定的值
int removeElement(int* nums, int numsSize, int val) {
     int left = 0;
    for (int right = 0; right < numsSize; right++){
        if (nums[right] != val){
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}

//返回第二个字符串在第一个字符串中的下标
int strStr(char* haystack, char* needle) {
    if (*needle == '\0') {
        return 0; // 空 needle 匹配任何字符串的开始
    }

    int a = 0;
    while (haystack[a] != '\0') {
        int b = 0;
        while (haystack[a + b] != '\0' && needle[b] != '\0' && haystack[a + b] == needle[b]) {
            b++;
        }
        if (needle[b] == '\0') {
            return a;
        }
        a++;
    }
    return -1;
}

int main()
{
    char st1[]="leetcode";
    char st2[]="leeto";
    int a = strStr(st1,st2);
    printf("%d\n",a);
    return 0;
}

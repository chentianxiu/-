#include<stdio.h>

int main()
{
    printf("please input:");
    freopen("dream.txt","w",stdout);

    char str[128] = {0};
    scanf("%s",str);
    printf("%s\n",str);
}
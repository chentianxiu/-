#include <stdio.h>
#include <stdlib.h>

int main()
{
int *num;
    
//使用malloc函数动态分配内存

num = (int*)malloc(sizeof(int));

if (num == NULL)
{
    printf("内存分配失败！\n");
    return 1;
}
    
*num = 666;

printf("分配的动态内存中的值为%d\n",*num);

//释放动态分配的内存

free(num);

num = NULL;//不在指向有效内存

printf("%p\n",num);//防止野指针


return 0;
    
}
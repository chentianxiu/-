#include <stdio.h>
#include <stdlib.h>

int main()
{
int *num;
int *arr=NULL;
    
//使用malloc函数动态分配内存

num = (int*)malloc(sizeof(int));

arr=(int*)malloc(10*sizeof(int));

if (num == NULL)
{
    printf("内存分配失败！\n");
    return 1;
}

if (arr == NULL)
{
    printf("内存分配失败！\n");
    return 2;
}
    
*num = 666;

printf("分配的动态内存中的值为%d\n",*num);


for (int i = 0; i < 10; i++)
{
    *(arr+i)=i+1;
}


//打印数组元素
printf("数组元素为:\n");
for (int i = 0; i < 10; i++)
{
    printf("%d ",*(arr+i));
}

printf("\n");



//释放动态分配的内存

free(num);

num = NULL;//不在指向有效内存


printf("%p\n",num);//防止野指针


int *newarr = NULL;
int newlength  = 13;

newarr = (int *)realloc(arr,newlength*sizeof(int));

if (newarr ==NULL)
{
    printf("内存分配失败！\n");
    return 3;
}

for (int  i = 0; i < newlength; i++)
{
    printf("%d %p\n",*(newarr+i),(newarr+i));
}

free(arr);
free(newarr);
arr = NULL;
newarr = NULL;

return 0;
    
}
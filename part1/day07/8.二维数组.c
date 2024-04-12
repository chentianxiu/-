#include <stdio.h>

int main()
{
    int arr[4][5]={{101,102,103,104,105},
    {201,202,203,204,205},
    {301,302,303,304,305},
    {401,102,403,404,405},};

    int hang = sizeof(arr)/sizeof(arr[0]);//获取行
    int lie = sizeof(arr[0])/sizeof(arr[0][0]);//获取列
    printf("行数%d\n",hang);
    printf("列数%d\n",lie);
    //遍历数组
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
        
    }
    


    return 0;
    
}
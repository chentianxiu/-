/*用*打印三角形，
      *
    *   *
  *   *   *
*   *    *   *
每个*之间距离相等*/
//假设每个✳之间的空格为一个，那我们定义一个变量space来代替空格
//比如有三行，那第一行第一个星星在第三个空格处
#include <stdio.h>

int main()
{
    int raw=0;
    int space=0;
    printf("请输入打印的行数:\n");
    scanf("%d",&raw);
    for(int i=1;i<=raw;i++){
        for(space=1;space<=raw-i;space++){
            printf(" ");    //每行左边空格是总行数-当前行数
        }
        for(int j=1;j<=i;j++){
            printf("* ");//*数是当前行数
        }
        printf("\n");
    }

    return 0;
    
}
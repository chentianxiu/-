#include <stdio.h>

int main()
{
    int chenji[6][5];
    int i,j;
    double sum = 0;
    double avg = 0;
    //一次输入每个的成绩
    for( i=0;i<6;i++){
        printf("请输入第%d个学生的成绩\n",i+1);
        for( j =0;j<5;j++){
            printf("请输入第%d门科成绩",j+1);
            scanf("%d",&chenji[i][j]);
        }
        printf("输入完了其中一个\n");
    }
    printf("五个人的成绩是：\n");

    for( i=0 ; i<=5 ; i++){
        sum = 0;
        avg = 0;
        for( j=0; j<=4 ; j++){
            //printf("%d ",chenji[i][j]);
            sum+=chenji[i][j];
        }
        avg= (double)sum/5.0;

        printf("第%d位学生的总分是%.2f,平均分是%.2f",i+1,sum,avg);
        printf("\n");
    }
    return 0;
    
}
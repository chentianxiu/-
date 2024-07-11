// 定义学员结构体包括：姓名，学号(int)，编写代码
// a) 创建3个学员数组并键盘录入学生姓名和学号；
// b) 学号重复，重新录入；
// c) 打印所有学员信息。

#include <stdio.h>

typedef struct student
{
    char name[20];
    int id;

}Student;

int main()
{
    Student stu[3];

    for(int i = 0;i<3;i++){

        printf("请输入第%d个学生的信息：\n",i+1);
        scanf("%s%d",stu[i].name,&stu[i].id);
    //列举
    // if (i==1&&stu[i].id==stu[i-1].id)
    // {
    //     printf("id重复,请重新输入第%d个学生的id\n",i+1);
    //     scanf("%d",&stu[i].id);
    // }
    // if (i==2&&(stu[i].id==stu[i-1].id||stu[i].id==stu[i-2].id))
    // {
    //     printf("id重复,请重新输入第%d个学生的id\n",i+1);
    //     scanf("%d",&stu[i].id);
    // }
    // printf("输入完毕\n");
    // }
    //for循环
        for(int j=0;j<i;j++){
            if(stu[i].id==stu[j].id){
                printf("id重复,请重新输入第%d个学生的id\n",i+1);
                scanf("%d",&stu[i].id);
                j--;
            }
        }
    }

    for(int i=0;i<3;i++){
        printf("第%d个学生学号是%d,姓名是%s\n",i+1,stu[i].id,stu[i].name);
    }

    return 0;
    
}
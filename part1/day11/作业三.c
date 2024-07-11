//定义三个学生结构体（姓名、身高、体重）数组，
//键盘录入学生信息，并输出身高最高的学生全部信息。
#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[20];
    float high;
    float weight;

}Student;


int main()
{

    Student stu[3];
    for (int i = 0; i < 3; i++)
    {
        printf("请输入第%d个学生的信息\n",i+1);
        scanf("%s%f%f",stu[i].name,&stu[i].high,&stu[i].weight);

    }

    int maxindex = 0;

    for (int i = 0; i < 0; i++)
    {
        if (stu[i].high>stu[maxindex].high)
        {
            maxindex = i;
        }
        
    }
    printf("第%d个学生最高，她的信息是：\n",maxindex+1);
    printf("第%d个学生的信息是%s  %.2f  %.2f",maxindex+1,stu[maxindex].name,stu[maxindex].high,stu[maxindex].weight);


    
    
    // Student stu1,stu2,stu3;
    // printf("请输入第一个学生的信息\n");
    // scanf("%s%f%f",stu1.name,&stu1.high,&stu1.weight);
    // //printf("第一个学生的信息是%s  %.2f  %.2f",stu1.name,stu1.high,stu1.weight);


    // printf("请输入第二个学生的信息\n");
    // scanf("%s%f%f",stu2.name,&stu2.high,&stu2.weight);

    // printf("请输入第三个学生的信息\n");
    // scanf("%s%f%f",stu3.name,&stu3.high,&stu3.weight);

    // float max1 = 0;
    // float max2 = 0;
    // max1 = stu1.high>stu2.high?stu1.high:stu2.high;
    // max2 = max1>stu3.high?max1:stu3.high;

    // if(max2 == stu1.high){
    //     printf("第一个学生最高，她的信息是：\n");
    //     printf("第一个学生的信息是%s  %.2f  %.2f",stu1.name,stu1.high,stu1.weight);
    // }
    // if (max2 == stu2.high)
    // {    
    //     printf("第二个学生最高，她的信息是：\n");
    //     printf("第二个学生的信息是%s  %.2f  %.2f",stu2.name,stu2.high,stu2.weight);
    // }    
    // if(max2 == stu3.high)
    // {
    //     printf("第三个学生最高，她的信息是：\n");
    //     printf("第三个学生的信息是%s  %.2f  %.2f",stu3.name,stu3.high,stu3.weight);
    // }
    
    

    return 0;
    
}
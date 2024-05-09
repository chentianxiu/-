#include <stdio.h>

//结构体声明
typedef struct student
{
    char name[20];
    int age;
    struct student * next;//和上面的的struct student 一致
    
}Student;


int main()
{
    //创建结构体
    Student stu5 = {"E",14,NULL};
    Student stu4 = {"D",15,NULL};
    Student stu3 = {"C",16,NULL};
    Student stu2 = {"B",17,NULL};
    Student stu1 = {"A",18,NULL};
    //将节点连接
    stu1.next = &stu2;
    stu2.next = &stu3;
    stu3.next = &stu4;
    stu4.next = &stu5;


    Student * crruentstudent = &stu1;
    //遍历结构体链表
    while (crruentstudent !=NULL)
    {
        printf("姓名是%s  年龄是%d\n",crruentstudent->name,crruentstudent->age);
        crruentstudent  = crruentstudent->next;
    }

    return 0;
    
}
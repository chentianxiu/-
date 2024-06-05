#include <stdio.h>
#include <string.h>

//声明一个结构体
typedef struct student
{
    char name[20];//%s
    int age;//%d
    char gender;//%c

}Student;


int main()
{
    Student stu;
    strcpy(stu.name,"张三");
    stu.age = 18;
    stu.gender = 'm';
    Student stu2 = {"李四",22,'w'};

    FILE*file =NULL;

    file = fopen("格式化.txt","a");
    if (file ==NULL)
    {
        printf("文件读取失败\n");
        return 1;
    }
    
    fprintf(file,"姓名：%s\n年龄:%d\n性别:%c\n",stu.name,stu.age,stu.gender);
    fprintf(file,"姓名：%s\n年龄:%d\n性别:%c\n",stu2.name,stu2.age,stu2.gender);


    return 0;
    
}
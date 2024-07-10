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
    

    FILE*file =NULL;

    file = fopen("格式化.txt","r");
    if (file ==NULL)
    {
        printf("文件读取失败\n");
        return 1;
    }
    //将文本的文档读取到系统中
    Student stus[20];
    int num = 0; 

    while (fscanf(file,"姓名：%s\n年龄:%d\n性别:%c\n",
    stus[num].name,&stus[num].age,&stus[num].gender)!=EOF)
    {
        num++;
    }


    for (int i = 0; i < num; i++)
    {
        printf("%s %d %c\n",stus[i].name,stus[i].age,stus[i].gender);
    }
    
    
    
    //fscanf(file,"姓名：%s\n年龄:%d\n性别:%c\n",stu.name,stu.age,stu.gender);
    fclose(file);

    return 0;
    
}
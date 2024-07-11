#include <stdio.h>
#include <string.h>
#include <conio.h>

//结构体声明
typedef struct student
{
    char stu_name[21];
    char stu_format[21];
    char stu_confirmformat[21];
    
}Student;

//全局变量:各个地方都可以调用
//定义最大学生数量

//const int studentNum = 20;

#define studentNum 20

Student students[studentNum];

int count = 0;

//函数声明
//1.功能一：用户名长度验证
int checkStuname(char * stu_name);

//2.密码格式验证
int checkStuFormat(char * stu_fomat);

//3.重复密码验证
int confirmFormat(char * stu_fomat,char *stu_confirmformat );

//4.学员注册

void stu_Register(Student students[], int length);

//5.学员登录

void stu_Login(Student students[], int length);//length只是保证传参正确

//6.查看
void stu_check(Student students[], int length);

//菜单
void Menu();



int main()
{
    int flag = 1;
    while(flag==1){
        //打印菜单
        Menu();
        char ch = getch();
        switch (ch)
        {
        case '1':
            stu_Login(students,count);
            break;
            
        case '2':
            stu_Register(students,count);
            break;
            
        case '3':
            stu_check(students,count);
            break;

        case '4':
            flag = 0;
            break;
        
        default:
            break;
        }
        
    }

    return 0;
    
}

void Menu(){
    printf("*************************************************\n");
    printf("*\t欢迎使用高校学生登录注册功能\t*\n");
    printf("*\t\t请选择功能\t\t\t*\n");
    printf("*\t\t1.学生登录\t\t\t*\n");
    printf("*\t\t2.学生注册\t\t\t*\n");
    printf("*\t\t3.学生信息打印\t\t\t*\n");
    printf("*\t\t4.退出\t\t\t*\n");

}

//1.功能一：用户名长度验证
int checkStuname(char * stu_name){
    int length = strlen(stu_name);

    printf("用户名长度是%d\n",length);

    //判断是否符合条件
    if(length>=4&&length<=20){
        return 1;
    }
    printf("长度过长\n");
    return 0;

}



//2.密码格式验证
int checkStuFormat(char * stu_fomat){

    //长度判断
    int length = strlen(stu_fomat);

    printf("密码长度是%d\n",length);

    //判断是否符合条件
    if(length<10||length>20){
        printf("密码长度不符合要求\n");
        return 0;
        //printf("密码长度不符合要求\n");
    }

    //合法性验证，不是数字和字母
    for (int i = 0; i < length; i++)
    {
        //定义一个变量，表示字符串中的每个字符
        char ch = stu_fomat[i];

        if(!((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))){
            printf("密码不是由数字或者字母组成\n");
            return 0;
        }
    }
    //符合要求
    return 1;
}

//3.重复密码验证
int confirmFormat(char * stu_fomat,char *stu_confirmformat ){
    if (strcmp(stu_fomat,stu_confirmformat)==0)
    {
        printf("确认密码成功\n");
        return 1;
    }else{
    printf("确认密码失败\n");
    return 0;
    }
}


//4.学院注册
void stu_Register(Student students[], int length){
    Student student;
    //1.用户名格式
    while (1)
    {
        printf("请输入用户名\n");
        scanf("%s",student.stu_name);
        int result = checkStuname(student.stu_name);
        if (result == 1)
        {
            break;
        }
        
    }

    //2.密码格式验证
     while (1)
    {
        printf("请输入密码\n");
        scanf("%s",student.stu_format);
        int result1 = checkStuFormat(student.stu_format);
        if (result1 == 1)
        {
            break;
        }
        
    }

    //3.重复输入密码确认
      while (1)
    {
        printf("请再次输入密码\n");
        scanf("%s",student.stu_confirmformat);
        int result2 = confirmFormat(student.stu_format,student.stu_confirmformat);
        if (result2 == 1)
        {
            break;
        }
        
    }


    //4.注册：数组添加元素
    students[count] = student;
    count++;
    printf("学员注册成功\n");

    return;
}


//登录
void stu_Login(Student students[], int length){

    if (count<=0)
    {
        printf("无用户注册，返回主页\n");
        return;
    }
    int choice = 3;
    char nowstuname[21];
    char nowstufomat[21];
    while (choice>0)
    {
        printf("您有%d次机会\n",choice);
        printf("请输入用户名\n");
        scanf("%s",nowstuname);
        for (int i = 0; i < count; i++)
        {
            if(strcmp(nowstuname,students[i].stu_name)==0){
                printf("请输入密码\n");
                scanf("%s",nowstufomat);
                if(strcmp(nowstufomat,students[i].stu_format)==0){
                    printf("登录成功\n");
                    choice = 0;
                    break;
                }
                else
                {
                    printf("密码错误\n");
                    
                    choice--;
                    //printf("你还有%d次机会\n",choice);
                }
                
            }else{
                printf("用户名输入错误\n");
                choice--;
                //printf("你还有%d次机会\n",choice);
            }
        }
        
    }
    
    return;
    
}


void stu_check(Student students[], int length){
    printf("用户名是\t\t密码是\t\t\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\t\t\t%s\n",students[i].stu_name,students[i].stu_format);
    }
    
    
}
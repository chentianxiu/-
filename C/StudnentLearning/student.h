#ifndef _STUDENT_H
#define _STUDENT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>

//存储管理员账号密码
typedef struct user{
    char username[50];
    char password[50];
    struct user *next;
}User,*UserLink;


//存储学生信息
typedef struct student
{
    char id[20];
    char name[50];
    char password[50];
    char clssName[50];
    int age;
    int grades[3];
    int totalScore;
    int rank;
    struct student *next;

}Student,*StuLinklist;

//创建学生链表
//Student *create_LinkedList();

//从文件中加载信息
void loadStudents(const char* filename,StuLinklist  stulist);
//将信息保存入链表之中
void saveStudnets(const char* filename, StuLinklist stulist);
//加密保存
void Encrypt(char * password);
//解密字符串
void Decrypt(char * password);
//生成id
void creatID(char * classname,StuLinklist stulist ,char * id);

//添加学生(链表操作)
int InputStudent(StuLinklist stulist,const char *id,const char *name,const char *password,char *className,int age,int grades[3]);
//单个添加学生（键盘录入操作）
void AddStudnet(StuLinklist stulist);

//学生总分排序
void calculateRanks(StuLinklist stulist);

//学生单科排序
void calculatebyalone(StuLinklist stulist,int num);

//学生姓名排序
void calculatebyname(StuLinklist stulist);

//查找学生是否存在
Student* findStudent(StuLinklist stulist, const char* id);

//打印学生信息
void PrintMassge(StuLinklist stulist);

//打印学生排名信息
void rankPrintMassge(StuLinklist stulist);

//加载管理员信息
void loadUser(const char* filename,UserLink userlist);
//保存管理员信息
void saveUser(const char* filename,UserLink userlist);
//添加管理员(链表操作)
void InputUser(UserLink userlist,const char *username,const char *password);




//学生查看自己的信息
void StuPrintMassge(StuLinklist stulist,char * id);
//学生修改密码
void ChangeStuPassWorld(StuLinklist stulist,char * id);

//隐藏密码
void get_password(char *password); 




//删除学生
void delete_studnet(StuLinklist stulist);

//查询学生
void Selectstudent(StuLinklist stulist);

//修改学生信息
void ChangStudentMssage(StuLinklist current,StuLinklist stulist);

//打印单个学生信息
void Printonestudent(StuLinklist current);

void menu1();
void menu2();
void menu3();



#endif
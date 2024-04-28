#include <stdio.h>  
#include <string.h>  
  
// 定义老师信息的结构体  
typedef struct Teacher {  
    char name[50];       // 姓名  
    int age;             // 年龄  
    char gender[10];     // 性别  
    char employeeID[20]; // 工号  
    char grade[10];      // 年级  
    char subject[50];    // 学科  
    char phoneNumber[20];// 手机号  
    char address[100];   // 家庭住址  
} Teacher;  
  
// 函数声明  
void printTeacherInfo(Teacher teacher);  
  
int main() {  
    // 创建一个老师对象  
    Teacher teacher1;  
  
    // 初始化老师信息  
    strcpy(teacher1.name, "张老师");  
    teacher1.age = 40;  
    strcpy(teacher1.gender, "男");  
    strcpy(teacher1.employeeID, "T001");  
    strcpy(teacher1.grade, "高一");  
    strcpy(teacher1.subject, "数学");  
    strcpy(teacher1.phoneNumber, "13800138000");  
    strcpy(teacher1.address, "北京市朝阳区某街道某号");  
  
    // 打印老师信息  
    printTeacherInfo(teacher1);  
  
    return 0;  
}  
  
// 定义函数，用于打印老师信息  
void printTeacherInfo(Teacher teacher) {  
    printf("姓名: %s\n", teacher.name);  
    printf("年龄: %d\n", teacher.age);  
    printf("性别: %s\n", teacher.gender);  
    printf("工号: %s\n", teacher.employeeID);  
    printf("年级: %s\n", teacher.grade);  
    printf("学科: %s\n", teacher.subject);  
    printf("手机号: %s\n", teacher.phoneNumber);  
    printf("家庭住址: %s\n", teacher.address);  
}
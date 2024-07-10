#include <stdio.h>  
  
// 定义一个结构体类型  
struct Student{  
    int id;  
    char name[50];  
    float score;  
};  
  
int main() {  
    // 创建一个结构体变量  
    struct Student student1 = {1, "张三", 90.5f};  
  
    // 定义一个指向结构体类型的指针  
    struct Student *pStudent;  
  
    // 将指针指向结构体变量  
    pStudent = &student1;  
  
    // 通过指针访问和修改结构体变量的成员  
    printf("ID: %d\n", pStudent->id);       // 使用 -> 运算符访问成员  
    printf("Name: %s\n", pStudent->name);  
    printf("Score: %.1f\n", pStudent->score);  
  
    // 修改结构体变量的成员  
    pStudent->score = 95.0f;  
  
    // 再次输出修改后的值  
    printf("Modified Score: %.1f\n", pStudent->score);  
  
    return 0;  
}
#include "date.h"

struct student
{
    int num;
    char name[20];
    Date date;
    float score[3];
};

typedef struct student Student;
//键盘录入
Date inputDateValue();
Student input();
//输出
void output(Student student);

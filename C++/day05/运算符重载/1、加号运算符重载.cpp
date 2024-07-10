#include <iostream>
using namespace std;

class Student{

public :
    //语文成绩
    int chinese_Score;
    //数学成绩
    int math_Socre;

    // //定义一个函数，讲两个对象相加
    // Student operator+(Student & s){
    //     //创建一个临时的学生
    //     Student temp;
    //     temp.chinese_Score = this->chinese_Score+s.chinese_Score;
    //     temp.math_Socre = this->math_Socre+s.math_Socre;

    //     return temp;

    // }

};

    //定义一个函数，讲两个对象相加
    Student operator+(Student & s1,Student & s2){
        //创建一个临时的学生
        Student temp;
        temp.chinese_Score = s1.chinese_Score+s2.chinese_Score;
        temp.math_Socre = s1.math_Socre+s2.math_Socre;

        return temp;
    }


int main(){
    Student xz1;
    xz1.chinese_Score = 40;
    xz1.math_Socre = 40;


    Student xz2;
    xz2.chinese_Score = 51;
    xz2.math_Socre = 50;

    Student xb;
    //学霸的成绩是两个学渣成绩之和
    xb = xz1+xz2;
    //xb = xz1.StudentAddStudent(xz2);

    cout<<"学霸语文成绩:"<<xb.chinese_Score<<endl;
    cout<<"学霸数学成绩:"<<xb.math_Socre<<endl;
    
    

}



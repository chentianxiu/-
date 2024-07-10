#include <iostream>
using namespace std;

class Student{

public:
    static int age;
    string name;//非静态的，后面加载

public :
    //静态函数中不能添加非静态的(静态的优先加载)
    static void study(){//静态函数,优先加载
        age = 18;
        cout<<age<<endl;
        //name = "张三";//name不是静态的，所以后面再加载，但是此时必须加载study函数，所以报错
        cout<<"好好学习"<<endl;
    }

private ://静态函数，依然有权限限制
    static void sleep(){//静态函数,优先加载
    
        cout<<"好好睡觉"<<endl;
    }


};
//1、类内声明，类外初始化
int Student::age = 18;

int main(){
    
    Student s1;
    //通过对象访问
    s1.study();
    Student s2;
    //通过对象访问
    s2.study();
    //通过类型进行访问
    Student::study();

    //访问睡觉
   // Student::sleep();
}



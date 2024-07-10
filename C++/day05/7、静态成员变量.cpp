#include <iostream>
using namespace std;


class Student{

public:
    static int age;
private:
    static string name;

};
//1、类内声明，类外初始化,必须初始化
int Student::age = 18;//相当于一个全局变量,共享空间
//脱离了对象的范畴，可以通过类来访问
//也存在权限的限制
static string name  = "张三";

int main(){

    //创建对象
    Student s1;

    //赋值
    s1.age = 18;
    cout<<"s1年龄："<<s1.age<<endl;
    //cout<<"s1年龄地址："<<&s1.age<<endl;


    Student s2;

    s2.age = 20;

    cout<<"s2年龄："<<s2.age<<endl;
    cout<<"s1年龄："<<s1.age<<endl;
    //可以直接通过类来访问age
    cout<<Student::age<<endl;
    //cout<<"s2年龄地址："<<&s2.age<<endl;

    //直接通过类名进行访问
    //cout<<"年龄："<<Student::age<<endl;
    //cout<<"年龄地址："<<&Student::age<<endl;

    //Student s3;
    // cout<<"姓名："<<s3.name<<endl;
    // cout<<"姓名："<<Student::name<<endl;



}



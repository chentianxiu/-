#include <iostream>
#include <fstream>//头文件
using namespace std;

//定义类
class Student{
public:
    string name;
    int age;

};


int main() {
    
    //数组
    const int numStudent= 3;
    Student students[numStudent];

    //遍历数组，进行赋值
    for(int i=0;i<numStudent;i++){
        cout<<"请输入第"<<i+1<<"个学生的姓名和年龄:"<<endl;
        //键盘录入
        cin >> students[i].name>>students[i].age;
    }

    //文件写入的功能
    //创建流对象
    ofstream ofs("student.txt",ios::out);

    //写入功能
    for(int i=0;i<numStudent;i++){
        ofs << students[i].name<<" "<<students[i].age<<endl;
    }

    ofs.close();

    cout<<"学生信息已经录入到文档中啦"<<endl;
    return 0;
}


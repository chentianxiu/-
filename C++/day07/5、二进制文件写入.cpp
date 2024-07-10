#include<iostream>
using namespace std;

//1、头文件
#include<fstream>
#include<string>

//定义一个类
class Person{
public:
    char name[20];//字符串也可以  string name；
    int age;
};

int main(){

    //2、创建流对象
    ofstream ofs("preson.txt",ios::binary|ios::out);

    //3、打开文件
   // ofs.open("preson.txt",ios::binary|ios::out);

    //4、写入操作

    Person p={"张三",18};

    ofs.write((const char *)&p,sizeof(Person));

    //5、关闭文件
    ofs.close();


    return 0;
}



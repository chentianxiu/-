#include<iostream>
using namespace std;

//1、头文件
#include<fstream>

int main(){

    //2、创建流对象：输出流
    ofstream ofs;

    //3、打开文件并判断
    ofs.open("test.txt",ios::app);

    //4、写入操作
    ofs<<"姓名：张三"<<endl;
    ofs<<"性别：男"<<endl;
    ofs<<"年龄：18"<<endl;

    //5、关闭文件
    ofs.close();

    return 0;
}


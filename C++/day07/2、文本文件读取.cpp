#include<iostream>
using namespace std;

//1、头文件
#include<fstream>

int main(){

    //2、创建流对象：输入流
    ifstream ifs;

    //3、打开文件并判断
    ifs.open("test.txt",ios::in);

    if (!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return 0;
    }
    

    string str;
    //4、读写操作
    while (ifs>>str)
    {
        cout<<str<<endl;
    }

       //4、读取操作
   //第一种读取：数组读取
//    char buf[1024] = {0};
//    while(ifs>>buf){
//     cout<<buf<<endl;
//    }

    //第二种读取：数组一行读取
    // char buf[1024] = {0};
    // while(ifs.getline(buf,sizeof(buf))){
    //     cout<<buf<<endl;
    // }

    // 第三种：读取到字符串中
    // string buf;
    // while(getline(ifs,buf)){
    //     cout<<buf<<endl;
    // }

    //第四种：字符读取
    //char ch;
    //while((ch = ifs.get())!=EOF ){//-1  end of file
    //    cout<<ch;
    //}
    //5、关闭文件
    ifs.close();

    return 0;
}


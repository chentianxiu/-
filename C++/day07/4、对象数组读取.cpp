#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//定义类
class Student {
public:
    string name;
    int age;
};

int main() {
    
    //读取文件，并添加到数组中
    //创建流对象
    ifstream ifs("student.txt",ios::in);
    //判断
    if(!ifs.is_open()){
        cout<<"文件打开失败"<<endl;
        return 0;
    }

     //定义数组
    Student stuArr[100];//目前暂时用数组，后期用list等容器
    int num = 0;//表示数组中真实存在的人，用于后面的遍历

    //读取功能
    //定义一个字符串
    string line;
    while(getline(ifs,line)){
        cout<<line<<endl;
        // line :张三 18
        //对这个字符串进行操作    前面是name属性   后面是age属性
        //在空格处切割姓名和年龄
        int pos =  line.find(" ");
        //姓名赋值        张三 18
        stuArr[num].name = line.substr(0,pos);//截取
        //年龄赋值
        stuArr[num].age = stoi(line.substr(pos+1));

        //人数更新
        num++;
    }

    //关闭文件
    ifs.close();

    //遍历数组
    for(int i=0;i<num;i++){
        cout<<"姓名："<<stuArr[i].name<<" 年龄:"<<stuArr[i].age<<endl;
    }

    return 0;
}
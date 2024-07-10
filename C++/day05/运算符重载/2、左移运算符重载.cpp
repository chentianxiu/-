#include <iostream>
using namespace std;

class Person{

friend ostream & operator<<(ostream & cout,Person & person);

private :
    string name;
    int age;
public:
    Person(string name,int age){
        this->name = name;
        this->age  = age;
    } 
    
};

//使用全局函数重载左移操作符
ostream & operator<<(ostream & cout,Person & person){
    //输出格式
    cout<<"姓名:"<<person.name<<"，年龄:"<<person.age;
    return cout;
}


int main(){

    //创建对象
    Person person("张三",18);
    cout<<person<<endl;
  
  return 0;

}



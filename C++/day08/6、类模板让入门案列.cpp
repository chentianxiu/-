#include<iostream>
#include<string>
using namespace std;

//类模版
template<class NameType,class AgeType>
class Person{
public:
    NameType mName;
    AgeType mage;

    //构造函数
    Person(NameType name,AgeType age){
        this->mName = name;
        this->mage = age;
    }
    void showPerson(){
        cout<<"姓名："<<this->mName<<",年龄："<<this->mage<<endl;
    }
};

void test01(){
    //创建对象
    Person<string,int> p("孙悟空",999);
    p.showPerson();
}


int main(){

    test01();
  
    
}




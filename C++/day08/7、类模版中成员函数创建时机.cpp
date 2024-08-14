#include<iostream>

using namespace std;

class Person1{
public:
    void showPreson1(){
        cout<<"Person1 show"<<endl;
    }
};

class Person2{
public:
    void showPreson2(){
        cout<<"Person2 show"<<endl;
    }
};

template<class T>
class MyClasss{
public:
    T obj;

    //调用类模版中的成员函数
    void fun1(){
        obj.showPerson1();
        obj.showPerson2();

    }
};

void test01(){

    MyClasss<Person2> p2;

    //p1.fun1();
    p2.fun1();


}


int main(){

  // test01();
   
}




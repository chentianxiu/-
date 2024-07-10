#include<iostream>
using namespace std;//命名空间，标准库

//定义父类
class Animal
{
public:
    //属性
    string name;
    int age;

    //行为
    void eat()
    {
        cout<<this->name<<"在吃饭"<<endl;
    }
    void sleep()
    {
        cout<<this->name<<"在睡觉"<<endl;
    }
};

//定义子类
//狗
class Dog:public Animal{
    //写自己特有的属性
public:
    string color;
    void lookhome()
    {
        cout<<this->name<<"在看家"<<endl;
    }
};

class Cat:public Animal{

public:
    string breed;

    void catchMouse()
    {
        cout<<this->name<<"在抓老鼠"<<endl;
    }
};

int main()
{
    //创建狗对象
    Dog dog;
    //赋值
    dog.name = "旺财";
    dog.age = 2;
    dog.color = "yellow";//子类特有
    //行为
    dog.eat();
    dog.sleep();
    dog.lookhome();//子类特有

    //创建猫对象
    Cat cat;
    cat.name = "tom";
    cat.age = 3;
    cat.breed = "蓝猫";

    cat.eat();
    cat.sleep();
    cat.catchMouse();//子类特有

    return 0;

}
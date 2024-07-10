#include<iostream>

using namespace std;

//定义父类
class Animal{

public:
    //动物在叫，说明一种本能，具体如何叫，好像没有规定
    //抽象的概念，virtual
    //虚函数,只规定这种行为，没有具体要求
    virtual void speak(){
        cout<<"动物在叫"<<endl;
    }

    //规定吃
    virtual void eat(){
        cout<<"动物在吃"<<endl;
    }
};
//子类
class Dog :public Animal{

public:
    //狗在叫，重写父类功能
    void speak(){
        cout<<"小狗在汪汪的叫"<<endl;
    }

    void eat(){
        cout<<"小狗在津津有味的啃骨头"<<endl;
    }
};

//子类
class Cat :public Animal{

public:
    //猫在叫
    void speak(){
        cout<<"小猫在喵喵的叫"<<endl;
    }

    void eat(){
        cout<<"小猫在津津有味的吃鱼"<<endl;
    }
};
//函数，定义叫的动作
void doSpeak(Animal & animal){
    animal.speak();
}

//函数，定义吃的动作
void doEat(Animal & animal){
    animal.eat();
}



int main(){

    Dog dog;
    //狗是不是也是动物
    doSpeak(dog);
    doEat(dog);

    Cat cat;
    doSpeak(cat);
    doEat(cat);
   
    return 0;
}
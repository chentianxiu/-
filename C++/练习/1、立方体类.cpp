/*
练习案例1：设计立方体类
设计立方体类(Cube)
求出立方体的面积和体积
分别用全局函数和成员函数判断两个立方体是否相等。
*/

#include<iostream>
using namespace std;//命名空间，标准库

class Cube{
    
friend bool isEqual2(Cube &c1,Cube &c2);

private:
    double side;
    
public:
    Cube(double side){
        this->side = side;
    }
    //计算面积
    double getSurfaceArea(){
        return 6*side*side;
    }

    //计算体积
    double getVolume(){
        return side*side*side;
    }
    
    //成员函数判断两个立方体是否相等
    bool isEqual(Cube & cube){
        return this->side==cube.side;
    }
};

//全局变量判断两个立方体是否相等
bool isEqual2(Cube &c1,Cube &c2)
{
    return c1.side==c2.side;
}


int main()
{
    Cube c1(4);
    Cube c2(5);

    cout<<c1.isEqual(c2)<<endl;
    cout<<isEqual2(c1,c2)<<endl;

    return 0;

}
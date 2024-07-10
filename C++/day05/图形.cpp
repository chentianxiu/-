#include<iostream>
using namespace std;//命名空间，标准库

class Shape
{
public:
    void draw(){
        cout<<"画一个图形"<<endl;
    }
    void area()
    {
        cout<<"面积是"<<endl;
    }
   
};

class Circle:public Shape{
    private:
        double r;
    public:
        Circle(double r){
            this->r = r;
        };
        //重写draw函数
        void draw(){
            cout<<"画一个圆"<<endl;
        }
        void area(){
            double area1 = 3.14*r*r;
            cout<<"面积是"<<area1<<endl;
        }
        ~Circle(){};
};

class Square : public Shape{
    private:
        double side;
    public:
        Square(double side){
            this->side = side;
        };
        //重写draw函数
        void draw(){
            cout<<"画一个正方形"<<endl;
        }
        void area(){
            double area2 = side*side;
            cout<<"面积是"<<area2<<endl;
        }
        ~Square(){};
};



int main()
{
    Circle c1(2);
    Square sq(5);

    c1.draw();
    c1.area();
    sq.draw();
    sq.area();

    return 0;

}
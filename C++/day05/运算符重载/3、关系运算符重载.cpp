#include <iostream>
using namespace std;

class Person{
    
    friend bool operator==(Person &p1,Person &p2);

public:
  string name;
  int age;

  Person(string name,int age){
    this->name = name;
    this->age = age;
  }

//   bool operator==(Person & p){
//     if(this->name==p.name  &&  this->age == p.age){
//       return true;
//     }else{
//       return false;
//     }
//   }
};

bool operator==(Person &p1,Person &p2)
{
    if (p1.name==p2.name&&p1.age==p2.age)
    {
        return true;
    }else
    {
        return false;
    }
}


int main(){

    Person p1("张三",18);
    Person p2("张三",19);
    
    // bool result = (p1==p2);
    // if(result){
    //   cout<<"两个相等"<<endl;
    // }else{
    //   cout<<"两个不想等"<<endl;
    // }
    if (p1==p2)
    {
        cout<<"两个相等"<<endl;
    }else{
        cout<<"两个不想等"<<endl;
    }
    
  
  return 0;

}



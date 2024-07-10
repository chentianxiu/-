#include <iostream>

using namespace std;

class Animal{
public:
    int m_Age;
};

class Sheep :public Animal{};

class Tuo :public Animal{};

class SheepTuo :public Sheep,public Tuo{};


int main(){

    //创建子类对象
    SheepTuo st;

    cout<<"坨:"<<sizeof(Tuo)<<endl;
 

    //赋值
   //st.m_Age = 18;//不明确，二义性

   st.Sheep::m_Age= 8;
   st.Tuo::m_Age= 28;

   cout<<"羊的年龄:"<<st.Sheep::m_Age<<endl;
   cout<<"驼的年龄:"<<st.Tuo::m_Age<<endl;

   
    return 0;
}



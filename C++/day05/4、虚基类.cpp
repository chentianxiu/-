#include <iostream>

using namespace std;


class Animal{
public :
    int m_Age;

};
//虚继承
class Sheep :virtual public Animal{};
//虚继承
class Tuo :virtual public Animal{};

class SheepTou : public Sheep,public Tuo{};




int main(){

    //创建子类对象
    SheepTou  st;

    st.m_Age = 18;//不会报错

    cout<<"羊驼的年龄:"<<st.m_Age<<endl;//18

    st.Sheep::m_Age= 8;

    st.Tuo::m_Age= 28;

    //最后一个m_Ages赋值的什么，那么这三个就是一样的为这个值

    cout<<"羊的年龄:"<<st.Sheep::m_Age<<endl;//28

    cout<<"驼的年龄:"<<st.Tuo::m_Age<<endl;//28

    cout<<"羊驼的年龄:"<<st.m_Age<<endl;//28

    return 0;
}




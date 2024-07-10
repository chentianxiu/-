#include <iostream>

using namespace std;

class Animal{
public:
    int m_Age;
};

class Sheep :virtual public Animal{};

class Tuo :virtual public Animal{};

class SheepTuo :public Sheep,public Tuo{};
//虚拟继承可以避免菱形继承的空间浪费


int main(){
    
    cout<<"Animal内存大小:"<<sizeof(Animal)<<endl;
    cout<<"羊内存大小:"<<sizeof(Sheep)<<endl;
    cout<<"坨内存大小:"<<sizeof(Tuo)<<endl;
    cout<<"羊驼内存大小:"<<sizeof(SheepTuo)<<endl;

    return 0;
}



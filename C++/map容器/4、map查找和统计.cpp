#include<iostream>
using namespace std;
#include <map>

void test01() {
	
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));

    //查找
    map<int,int>::iterator pos =  m.find(3);

    if(pos != m.end()){
        cout<<"key:"<<(*pos).first<<",value:"<<pos->second<<endl;
    }else{
        cout<<"没有找到"<<endl;
    }

    //计数
    int num = m.count(3);
    cout<<num<<endl;
	
}



int main(){

    test01();
    return 0;
}
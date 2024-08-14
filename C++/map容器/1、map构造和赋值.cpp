#include<iostream>
using namespace std;
#include <map>

void printMap(map<int,int> & m){
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key:"<<it->first<<",value:"<<it->second<<endl;
    }
    cout<<endl;
}

void test01() {

    map<int,int> m;

    // 1、自动排序     2、key不重复，value不管
    m.insert(pair<int,int>(1,10));// 1: key  10:value
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,300));
    m.insert(pair<int,int>(5,10));

    printMap(m);


    map<int,int> m2(m);
    printMap(m2);

    map<int,int> m3;
    m3 = m;
    printMap(m3);


	
}



int main(){

    test01();
    return 0;
}
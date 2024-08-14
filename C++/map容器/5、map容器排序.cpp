#include<iostream>
using namespace std;
#include <map>

class MyCompare{

public:
    bool operator()(const int v1,const  int v2){
        //从大到小
        return v1>v2;
    }

};

void test01() {
	
	//默认从小到大
    //利用仿函数，实现自定义规则
    map<int,int,MyCompare> m;

    m.insert(make_pair(1,10));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));
    m.insert(make_pair(2,20));

    //遍历
    for(map<int,int,MyCompare>::const_iterator it = m.begin();it!=m.end();it++){
        cout<<"key:"<<it->first<<",value:"<<it->second<<endl;
    }

}

int main(){

    test01();
    return 0;
}
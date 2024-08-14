#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void print01(int val){
    cout<<val+10<<" ";
}

class print02{
public :
    void operator()(int val){
         cout<<val+100<<" ";
    }
};


void test01() {

	vector<int> v;
    for(int i =0;i<10;i++){
        v.push_back(i);
    }
    
    //遍历，然后遍历时进行的操作
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    //仿函数
    for_each(v.begin(),v.end(),print02());
}



int main(){

    test01();
    return 0;
}
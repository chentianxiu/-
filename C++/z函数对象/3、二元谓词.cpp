#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class MyCompare{

public:
    bool operator()(int num1,int num2){
        return num1>num2;
    }
};

void test01() {

    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    v.push_back(60);

    sort(v.begin(),v.end());

    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //从大到小
    sort(v.begin(),v.end(),MyCompare());
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
	
}

int main(){

    test01();
    return 0;
}
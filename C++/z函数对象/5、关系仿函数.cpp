#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>



void test01() {

    vector<int> v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40); 

    sort(v.begin(),v.end(),greater<int>());

    for(vector<int>::iterator it = v.begin();it !=v.end();it++){
        cout<<*it<<" ";
    }
}



int main(){

    test01();
    return 0;
}
#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>



void test01() {

    vector<bool> v;

    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for(vector<bool>::iterator it = v.begin();it !=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //搬运  反转搬运
    vector<bool> v2;//空
    //确定v2的大小
    v2.resize(v.size());//提前开辟空间，才能搬运
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());

    for(vector<bool>::iterator it = v2.begin();it !=v2.end();it++){
        cout<<*it<<" ";
    }

	
}



int main(){

    test01();
    return 0;
}
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class TransForm{

public:
    int operator()(int num){
        return num+100;
    }
};

class print02{
public :
    void operator()(int val){
         cout<<val<<" ";
    }
};

void test01() {

	vector<int> v1;
    for(int i =0;i<10;i++){
        v1.push_back(i);
    }

    //搬运到另外一个容器中
    vector<int> v2;//空
    v2.resize(v1.size());

    transform(v1.begin(),v1.end(),v2.begin(),TransForm());

    for_each(v2.begin(),v2.end(),print02());

}



int main(){

    test01();
    return 0;
}
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class GreateFive{

public:
    bool operator()(int val){

        return val >5;
    }
};

void test01() {

    vector<int> v;
    for(int i =0;i<10;i++){
        v.push_back(i);
    }
    //查找有没有大于5的元素(find_if调用仿函数，find可以直接查找值)

    vector<int>::iterator it = find_if(v.begin(),v.end(),GreateFive());

    //vector<int>::iterator it = find(v.begin(),v.end(),5);


    if(it!= v.end()){
            cout<<*it<<endl;
    }else{
        cout<<"没有找到"<<endl;
    }
	
}



int main(){

    test01();
    return 0;
}
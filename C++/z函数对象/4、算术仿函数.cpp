#include<iostream>
#include<functional>
using namespace std;



void test01() {
   

    //取反
	negate<int> n;
    cout<<n(10)<<endl;

    //加法
    plus<int> p;
    cout<<p(10,20)<<endl;

}



int main(){

    test01();
    return 0;
}
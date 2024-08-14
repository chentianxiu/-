#include<iostream>
using namespace std;
#include<vector>


void test01()
{
	vector<int> v;

    //预留空间
    v.reserve(10000);

   //定义一个变量，表示扩展空间的次数
   int num = 0;
   //定义一个指针，
   int * p = NULL;

   for(int i=0;i<10001;i++){
        v.push_back(i);
        //扩展次数
        if( p !=&v[0]){//指针一直都是指向开头，一旦扩展，开头的地址就会变化，通过这个来判断是否扩展(扩展一次是默认的开辟的一次)
            p = &v[0];
            num++;
        }
   }

   cout<<"一共扩展的次数："<<num<<endl;


	
}



int main(){

    test01();
    return 0;
}
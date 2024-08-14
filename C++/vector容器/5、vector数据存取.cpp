#include<iostream>
using namespace std;
#include<vector>


void test01()
{

   vector<int> v1;
   for(int i=0;i<10;i++){
        v1.push_back(i);
   }

   //获取  at
   for(int i=0;i<v1.size();i++){
        cout<<v1.at(i)<<" ";
   }
    cout<<endl;
    //获取  []
   for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
   }
   cout<<endl;

   cout<<"容器第一个元素："<<v1.front()<<endl;//0
   cout<<"容器最后一个元素："<<v1.back()<<endl;//9
	
	
}



int main(){

    test01();
    return 0;
}
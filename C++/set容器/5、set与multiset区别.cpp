#include<iostream>
using namespace std;
#include <set>


void test01() {
	
    set<int> s;

   pair<set<int>::iterator,bool>  ret =  s.insert(10);
   if(ret.second){
        cout<<"第一次插入成功"<<endl;
   }else{
        cout<<"第一次插入失败"<<endl;
   }
     //成对出现的数据，利用对组可以返回两个数据
   pair<set<int>::iterator,bool>  ret2 =  s.insert(10);
   if(ret2.second){
        cout<<"第二次插入成功"<<endl;
   }else{
        cout<<"第二次插入失败"<<endl;
   }

    //multiset
    multiset<int> ms;

    ms.insert(10);
    ms.insert(10);

    for(multiset<int>::iterator it = ms.begin();it!=ms.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
	
}




int main(){

    test01();
    return 0;
}
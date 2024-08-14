#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void MyPrint(int val){
    cout<<val<<endl;
}


void test01(){

    //创建一个容器  vector
    vector<int> v;
    //添加值
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //输出
    //迭代器
    vector<int>::iterator pBegin = v.begin();//返回第一个指向迭代器的指针
    vector<int>::iterator pEnd   = v.end();//代表最后一个的下一个指针

    //第一种方式
    while(pBegin != pEnd){
        cout<<*pBegin<<endl;
        //指针移动
        pBegin++;
    }
    cout<<endl;

    //第二种方式
    for(vector<int>::iterator it = v.begin();it !=v.end();it++){
        cout<<*it<<endl;
    }

    cout<<endl;
    //第三种：算法
    for_each(v.begin(),v.end(),MyPrint);
}

int main(){

  test01();
    return 0;
}
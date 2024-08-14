#include<iostream>

using namespace std;
#include<vector>
#include<algorithm>

void test01(){

    //创建一个大容器
    vector<vector<int> > v;

    //创建小容器  4个
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    //小容器赋值
    for(int i=0;i<4;i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }//循环一遍给小容器的第一个赋值

    //大容器里面放小容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //输出  it：相当于指针
    for(vector<vector<int> >::iterator it = v.begin();it !=v.end();it++){
        //vit：相当于指针
        for(vector<int>::iterator vit = (*it).begin();vit!=(*it).end();vit++){
            cout<<*vit<<endl;
        }
        cout<<endl;

    }

}

int main(){

    test01();
    return 0;
}
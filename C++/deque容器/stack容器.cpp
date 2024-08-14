#include<iostream>
using namespace std;
#include<stack>



void test01() {

	stack<int> s1;

    //向栈顶添加元素   入栈
    s1.push(10);
    s1.push(20);
    s1.push(30);

    stack<int> s;
    s = s1;


    cout<<" 大小："<<s.size()<<endl;//3

    //遍历（删除遍历）
    while(!s.empty()){
        cout<<"栈顶元素："<<s.top()<<" ";
        //删除栈顶
        s.pop();
    }

    cout<<" 大小："<<s.size()<<endl;//0
	
}



int main(){

    test01();
    return 0;
}
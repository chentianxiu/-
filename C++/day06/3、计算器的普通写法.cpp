#include<iostream>

using namespace std;

//普通实现
class Calculator {
public:
	int m_Num1;
	int m_Num2;

public:
	//定义一个函数，实现各种操作的结果
	int getResult(string oper){
		if(oper == "+"){
			return m_Num1+m_Num2;
		}else if(oper == "-"){
			return m_Num1-m_Num2;
		}else if(oper == "*"){
			return m_Num1*m_Num2;
		}else{
			//暂时不写除的操作
			return 0;
		}
	}
};

//定义一个函数，实现两个数的操作
void test01(int num1,int num2){
	//创建一个计算器类
	Calculator c;

	//计算器的两个变量赋值
	c.m_Num1 = num1;
	c.m_Num2 = num2;

	cout<<c.m_Num1<<"+"<<c.m_Num2<<"="<<c.getResult("+")<<endl;
	cout<<c.m_Num1<<"-"<<c.m_Num2<<"="<<c.getResult("-")<<endl;
	cout<<c.m_Num1<<"*"<<c.m_Num2<<"="<<c.getResult("*")<<endl;

}



int main(){
    
	test01(10,5);
  
    
    return 0;
}


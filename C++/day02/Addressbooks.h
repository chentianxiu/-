#include<iostream>
using namespace std;
//结构体

struct person
{
    string m_Name;//姓名
    int m_Sex;//性别：1.男 2.女
    int m_Age;//年龄
    string m_phone;//电话
    string m_Addr;//住址
};

//声明通讯录结构体
#define MAX 1000    //最大人数

//通讯录结构体

struct Addressbooks
{
    struct person personArray[MAX];//通讯录中保存的联系人数组
    int m_size;//通讯录中的人员个数
};


//函数声明

//菜单
void showMenu();

//添加
void addperson(Addressbooks * adr);

//显示
void printaddbook(Addressbooks * adr);

//是否找到
int exitaddbook(Addressbooks * adr,string name);


//删除
void deleteaddbook(Addressbooks * adr);


//查找
void findaddbokk(Addressbooks * adr);

//修改
void modifyaddbook(Addressbooks * adr);


//清空
void cleanaddbook(Addressbooks * adr);


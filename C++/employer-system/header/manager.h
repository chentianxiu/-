#pragma once//避免重复加载
#include<iostream>
using namespace std;
#include<string>

#include"worker.h"

//经理类  继承worker类

class Manager :public Worker{

public :

    //构造函数
    Manager(int id,string name,int DeptId);

    //功能
    //显示信息
    virtual void showInfo();

    //获取部门名称
    virtual string getDeptName();

};
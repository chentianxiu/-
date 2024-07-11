#pragma once//避免重复加载
#include<iostream>
using namespace std;
#include<string>

#include"worker.h"

//总裁类  继承worker类

class Boss :public Worker{

public :

    //构造函数
    Boss(int id,string name,int did);

    //功能
    //显示信息
    virtual void showInfo();

    //获取部门名称
    virtual string getDeptName();

};
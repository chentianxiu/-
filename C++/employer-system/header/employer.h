#pragma once //避免重复定义

//类：函数
#include<iostream>
using namespace std;
#include<string>

#include"worker.h"

//普通员工类  继承worker类(son类)

class Employer : public Worker{

    public:

        //构造函数
        Employer(int id,string name,int DeptId);

        //功能
        //显示信息
        virtual void showInfo();

        //获取部门名称
        virtual string getDeptName();
};
#pragma once //避免重复定义

//类：函数
#include<iostream>
using namespace std;
#include<string>

//职工抽象类(father类)
class Worker
{
public:
    //属性
    int m_Id;//工号
    string m_Name;//姓名
    int m_DeptId;//部门编号

    //功能
    //显示信息
    virtual void showInfo() = 0;

    //获取部门名称
    virtual string getDeptName() = 0;

    //析构
    virtual ~Worker(){};
};


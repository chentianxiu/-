#pragma once //避免重复定义

//类：函数
#include<iostream>
using namespace std;
#include "header.h"
#include <fstream>
#define FILENAME "empFile.txt"

//定义管理类
class WorkerManager
{

public:

    //构造函数
    WorkerManager();
    //析构函数
    virtual ~WorkerManager();

    //显示菜单
    void Show_Menu();

    //退出系统
    void exitSystem();

    //记录文件中的人数个数
    int m_EmpNum;
    //员工数组指针
    Worker ** m_EmpArrary;

    //添加员工
    void Add_Emp();

    //保存文件
    void save();

    //标志文件是否为空
    bool m_FileIsEmpty;

    //统计文件中的人数
    int get_EmpNum();
    
    //初始化员工
    void init_Emp();

    //显示员工
    void Show_Emp();

    //删除员工
    void Del_Emp();

    //按照员工编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1；
    int IsExist(int id);

    //修改职工
    void Mod_Emp();

    //查找职工

    void Find_Emp();

    //排序职工

    void Sort_Emp();

    //清空文件
    void Clean_File();

};


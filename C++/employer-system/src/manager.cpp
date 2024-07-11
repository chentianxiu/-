#include "manager.h"

//构造函数
   Manager:: Manager(int id,string name,int did){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId =did;
   }

    //功能
    //显示信息
    void Manager:: showInfo(){
        cout<<"职工编号："<<this->m_Id
            <<"\t职工姓名："<<this->m_Name
            <<"\t岗位："<<this->getDeptName()
            <<"\t岗位职责:完成总裁交代的任务"<<endl;
    }

    //获取部门名称
    string Manager:: getDeptName(){
        return string("经理");
    }
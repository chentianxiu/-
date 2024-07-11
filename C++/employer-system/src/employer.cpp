//普通员工类  实现
#include "employer.h"

//构造函数
//构造函数
    Employer::Employer(int id,string name,int DeptId){
        this->m_Id = id;
        this->m_Name = name;
        this->m_DeptId =DeptId;
    }

    //显示信息
    void Employer::showInfo(){
        cout<<"职工编号："<<this->m_Id
            <<"\t职工姓名："<<this->m_Name
            <<"\t岗位："<<this->getDeptName()
            <<"\t岗位职责:完成经理安排的任务"<<endl;
    }

    //获取部门名称
    string Employer::getDeptName(){
         return string("员工");
    }
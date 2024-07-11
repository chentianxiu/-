
#include "boss.h"


//构造函数
   Boss:: Boss(int id,string name,int did){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId =did;
   }

    //功能
    //显示信息
    void Boss:: showInfo(){
        cout<<"职工编号："<<this->m_Id
            <<"\t职工姓名："<<this->m_Name
            <<"\t岗位："<<this->getDeptName()
            <<"\t岗位职责:负责全公司的运营"<<endl;
    }

    //获取部门名称
    string Boss:: getDeptName(){
        return string("总裁");
    }
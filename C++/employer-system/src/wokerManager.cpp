//具体功能的实现

#include "workerManager.h"

    //构造函数(初始化)
    WorkerManager:: WorkerManager(){
        //读取文件，加载员工

        //文件读取操作
        ifstream file(FILENAME,ios::in);

        //判断文件不存在
        if (!file.is_open())
        {
            cout<<"文件不存在"<<endl;
            //初始化员工为零
            this->m_EmpNum = 0;
            //初始化数组
            this->m_EmpArrary = nullptr;
            //标志文件是否为空
            this->m_FileIsEmpty = true;
            //关闭文件
            file.close();
            return;
        }
        //文件存在，但是里面没有内容
        char ch;
        file>>ch;
        if (file.eof())//end of file
        {
            cout<<"文件为空"<<endl;
            //初始化员工人数
            this->m_EmpNum = 0;
            //初始化数组
            this->m_EmpArrary = NULL;
            //标志文件是否为空
	        this->m_FileIsEmpty = true;
            //关闭文件
            file.close();
            return;
        }
        //文件存在，并且有内容
        int num = this->get_EmpNum();
        cout<<"职工人数为:"<<num<<endl;

        //人数更新
        this->m_EmpNum = num;

        //显示人员信息
        //根据获取的数量，创建数组空间
        this->m_EmpArrary = new Worker *[this->m_EmpNum];
        
        //调用初始化函数
        this->init_Emp();




    }

    //析构函数
    WorkerManager:: ~WorkerManager(){

    }

    //显示菜单
    void WorkerManager::Show_Menu(){

    cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
        
    }

    //退出系统
    void WorkerManager::exitSystem(){

        cout<<"欢迎您的再次使用"<<endl;

        //退出
        exit(0);
    }

    //添加员工
    void WorkerManager::Add_Emp()
    {
        cout<<"请输入添加员工个数:"<<endl;

        int addNum = 0;

        cin>>addNum;

        if (addNum>0)
        {
            //1、开辟空间，在原来的基础上开辟
            int newSize = this->m_EmpNum+addNum;//确定新空间大小

            //开辟新空间(堆内存中创建，不使用栈内存)
            Worker ** newSpace = new Worker*[newSize];

            //2、原来的人，拷贝到新的空间里面，还是原来的位置


            //3、新人添加
        }
        
    }
#include<header.h>



//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
    this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->initVector();

	//获取机房信息
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;//创建一个容器来存储机房信息
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为： " << vCom.size() << endl;

	ifs.close();
}

//选择菜单
void Manager::operMenu()
{
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}


//添加账号  
void Manager::addPerson()
{
    int id;//编号，学号，工号
    string name;
    string pwd;
    string fileName;

    int select = 0;

    cout<<"请输入添加账号的类型"<<endl;
    cout<<"1.添加学生"<<endl;
    cout<<"2.添加老师"<<endl;

    cin>>select;

    bool flag = false;//验证是否重复的标记

    if (select == 1)
    {
        fileName = STUDENT_FILE;
        cout<<"请输入学号： "<<endl;
		cin >> id;
		bool ret = this->checkRepeat(id, 1);
		if (ret) //没有重复
		{
			flag = true;//可以录入
		}else{
			cout <<  "学号重复,请重新添加" << endl;
			return ;//结束添加功能
		}
    }else
    {
        fileName = TEACHER_FILE;
		cout<<"请输入工号： "<<endl;
		cin >> id;
		bool ret = this->checkRepeat(id, 2);
		if (ret) //没有重复
		{
			flag = true;//可以录入	
		}else{
			cout <<  "工号重复,请重新添加" << endl;
			return ;//结束添加功能
		}
    }
    ofstream ofs;//输入流
	ofs.open(fileName, ios::out | ios::app);
	cout << "请输入姓名： " << endl;
	cin >> name;
	cout << "请输入密码： " << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	ofs.close();

	//初始化容器
	this->initVector();
}

//打印学生信息
void printStudent(Student & s)
{
    cout<<"学号："<<s.m_Id<<"\t姓名："<<s.m_Name<<"\t密码："<<s.m_Pwd<<endl;
}

//打印老师信息
void printTeacher(Teacher & t)
{
    cout<<"工号："<<t.m_EmpId<<"\t姓名"<<t.m_Name<<"\t密码："<<t.m_Pwd<<endl;
}

//查看账号
void Manager::showPerson()
{   
    cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;
    
	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

}


//查看机房信息
void Manager::showComputer()
{
    cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号： " << it->m_ComId << " 机房最大容量： " << it->m_MaxNum << endl;
	}
}

//清空预约记录
void Manager::cleanFile()
{
    ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
}

//初始化容器
void Manager::initVector()
{
    //初始化，两个容器先清空
	vStu.clear();
    vTea.clear();

	//读取学生文件中信息
	ifstream ifs;
	//打开学生文件
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
    
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name &&  ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	//关闭学生文件
	ifs.close(); 

	//读取老师文件信息
	//打开老师文件
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name &&  ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为： " << vTea.size() << endl;
	//关闭老师文件
	ifs.close();
}

//检测重复 参数:(传入id，传入类型) 返回值：(false 代表有重复，true代表没有重复)
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)//检查学生
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)//找到重复学号
			{
				return false;
			}
		}
	}
	else //检查老师
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)//找到重复工号
			{
				return false;
			}
		}
	}
	return true;//没有重复
}
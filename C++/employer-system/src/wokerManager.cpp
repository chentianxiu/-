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
        //释放
        if(this->m_EmpArrary != NULL){
            delete[] this->m_EmpArrary;
        }
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

            /*
            Worker **newSpace = new Worker*[newSize]; 这段代码在堆内存中创建了一个指向 Worker 指针的指针数组。
            具体来说，这个数组中的每个元素都是指向 Worker 或其派生类对象（如 Manager、Employer 和 Boss）的指针。
            这样可以方便地管理多个不同类型的 Worker 对象。
            */

            //2、原来的人，拷贝到新的空间里面，还是原来的位置
            if(this->m_EmpArrary !=NULL){
                    //原来的人，还是原来的位置，添加的新人，在后面
                    for(int i= 0;i<this->m_EmpNum;i++){
                        newSpace[i] = this->m_EmpArrary[i];
                    }
            }

            //3、新人添加
            //多少个新人信息
            for(int i = 0;i<addNum;i++){

                //键盘录入新人信息
                //定义新人的三个变量
                int id;
                string name;
                int dSelect;
                

                cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
                cin >> id;
                int index = this->IsExist(id);
                if (index!=-1)
                {
                    cout<<"这个编号已经存在"<<endl;
                    i--;
                    continue;
                }
                cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
                cin >> name;
                cout << "请选择该职工的岗位：" << endl;
                cout << "1、普通职工" << endl;
                cout << "2、经理" << endl;
                cout << "3、总裁" << endl;
                cin >> dSelect;

                //创建一个临时员工
                Worker * worker = NULL;

                //员工赋值:三种情况
                switch(dSelect){
                    case 1://普通职工
                        worker = new Employer(id,name,1);
                        break;
                    case 2://经理
                        worker = new Manager(id,name,2);
                        break;
                    case 3://总裁
                        worker = new Boss(id,name,3);
                        break;
                    default :
                        cout<<"添加失败"<<endl;
                        break;
                }

                //将新员工，添加到新数组中：哪个位置？
                newSpace[this->m_EmpNum+i] = worker;
                //delete worker;
        }

        //收尾
            //原来的空间，释放
            delete[] this->m_EmpArrary;

            //更新新的地址
            this->m_EmpArrary = newSpace;

            //更新人员数量
            this->m_EmpNum = newSize;


            //更新文件是否为空的标记
            this->m_FileIsEmpty = false;

            //友好提示
            cout<<"成功添加"<<addNum<<"名新员工"<<endl;

            //调用保存到文件的函数
            this->save();

        }else{
            cout<<"人数输入有误"<<endl;
        }

        
    }

    //保存文件
    void WorkerManager:: save(){

        //1、创建流对象
        ofstream file;

        //2、打开文件
        file.open(FILENAME,ios::out);

        //3、写入操作
        for(int i=0;i<this->m_EmpNum;i++){
            file<<this->m_EmpArrary[i]->m_Id<<" "
                <<this->m_EmpArrary[i]->m_Name<<" "
                <<this->m_EmpArrary[i]->m_DeptId<<endl;
        }

        //4、关闭
        file.close();

    }

    //统计文件中的人数
    int WorkerManager::get_EmpNum()
    {
        //文件读取
        ifstream file;
        file.open(FILENAME,ios::in);
        if(!file.is_open()){
            cout<<"文件没有打开"<<endl;
            return 0;
        }

        int id;
        string name;
        int dId;

        //定义一个变量，表示文件中的人数
        int num = 0;
        //读取
        while(file>>id && file>>name &&file >>dId){
            //记录人数
            num++;
        }

        file.close();
        return num;
    }

    //初始化员工
	void WorkerManager:: init_Emp(){

        //读取文件中的内容，并添加到数组中
        ifstream file;
        file.open(FILENAME,ios::in);

        int id;
        string name;
        int dId;

        //添加到数组中，位置
        int index = 0;

        //一边读取，一边添加
        while(file>>id && file>>name &&file >>dId){
            //去读的内容，赋值给 员工
            //创建一个临时员工
            Worker * worker = NULL;
            if(dId == 1){
                worker = new Employer(id,name,dId);
            }else if(dId == 2){
                worker = new Manager(id,name,dId);
            }else{
                 worker = new Boss(id,name,dId);
            }
            //员工再添加到数组中,位置？
            this->m_EmpArrary[index] = worker;

            index++;
            //delete worker;

        }

    }

    //显示职工
	void WorkerManager:: Show_Emp(){

        if(this->m_FileIsEmpty){
            cout<<"文件不存在或者为空"<<endl;
        }else{
            //for循环遍历数组
            for(int i= 0;i<m_EmpNum;i++){
                //调用展示的接口
                this->m_EmpArrary[i]->showInfo();
            }
        }
    }

    //删除职工
    void WorkerManager::Del_Emp(){
        
        //判断文件是否存在
        if (this->m_FileIsEmpty)
        {
            cout<<"文件为空"<<endl;
            return ;
        }
        //删除
        cout<<"请输入你要删除的员工编号:"<<endl;
        int id = 0;
        cin>>id;
        int index = this->IsExist(id);

        if (index==-1)
        {
            cout<<"查无此人"<<endl;
        }else{
            //index索引后面的内容往前移动一位
            for (int i = index; i < this->m_EmpNum-1; i++)
            {
                this->m_EmpArrary[i] = this->m_EmpArrary[i+1];
            }
            
            this->m_EmpNum--;
            this->save();
            cout<<"删除成功"<<endl;
        }
        
        
    }

    ////按照员工编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1；
    int WorkerManager::IsExist(int id){
        int index = -1;
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArrary[i]->m_Id==id)
            {
                index = i;
                return index;
            }
            
        }
        return index;
    }



    //修改职工
	void WorkerManager:: Mod_Emp(){

        //判断文件是否存在
        if (this->m_FileIsEmpty)
        {
             cout<<"文件不存在或者为空，不能修改"<<endl;
        }else
        {
            cout<<"请输入需要修改的员工编号："<<endl;
            int id;
            cin >> id;

            int index =  this->IsExist(id);

            if(index != -1){

                //删掉
                delete this->m_EmpArrary[index];

                //重新赋值
                int newId =0;
                string newName = "";
                int dSelect = 0;

                cout<<"查到："<<id<<"号员工，请输入新编号："<<endl;
                cin >> newId;

                cout<<"请输入新的姓名："<<endl;
                cin >> newName; 

                cout<<"请输入新岗位："<<endl;
                cout<<"1、普通员工"<<endl;
                cout<<"2、经理"<<endl;
                cout<<"3、总裁"<<endl;
                cin >> dSelect;

                //创建一个临时员工
                Worker * worker = NULL;

                //员工赋值:三种情况
                switch(dSelect){
                    case 1://普通职工
                        worker = new Employer(newId,newName,1);
                        break;
                    case 2://经理
                        worker = new Manager(newId,newName,2);
                        break;
                    case 3://总裁
                        worker = new Boss(newId,newName,3);
                        break;
                    default :
                        cout<<"添加失败"<<endl;
                        break;
                }
                //创建好一个新的元素
                //添加到数组中，还是原来的位置
                this->m_EmpArrary[index] = worker;

                cout<<"修改成功"<<endl;

                //保存到文件中
                this->save();

            }else
            {
                cout<<"查无此人，修改失败"<<endl;
            }
            
        }
        
        
    }

    //查找职工
    void WorkerManager::Find_Emp(){

        //判断文件是否存在
        if(this->m_FileIsEmpty){
            cout<<"文件不存在或者为空"<<endl;
        }else{
            cout<<"请输入查找方式："<<endl;
            cout<<"1、按照编号查找："<<endl;//编号唯一
            cout<<"2、按照姓名查找："<<endl;//姓名不唯一
            int select = 0;
            cin >> select;

            if(select==1){

                int id =0;
                cout<<"请输入员工编号:"<<endl;
                cin>>id;
                //判断是否存在
                int index =   this->IsExist(id);
                if(index !=-1){
                    cout<<"查到此人，员工信息如下："<<endl;
                    this->m_EmpArrary[index]->showInfo();
                }else{
                    cout<<"查无此人"<<endl;
                }

            }else if(select==2){//姓名查找，，重名

                string name = "";
                cout<<"请输入需要查找的人姓名:"<<endl;
                cin >> name;

                //循环遍历
                //定义一个变量，标记是否查到
                bool flag = false;
                for(int i=0;i<this->m_EmpNum;i++){
                    if(this->m_EmpArrary[i]->m_Name == name){
                        //展示信息
                        cout<<"查到此人，员工信息如下："<<endl;
                        this->m_EmpArrary[i]->showInfo();
                        flag = true;
                        //这里不能break和return，因为可能重名
                    }
                }
                if(flag == false){
                    cout<<"没有查到该姓名的员工"<<endl;
                }

            }else{
                cout<<"输入选项有误"<<endl;
            }
        }

    }

    //排序职工
    void WorkerManager ::  Sort_Emp()
    {
        if(this->m_FileIsEmpty){
             cout<<"文件不存在或者为空"<<endl;
        }else{
            //排序
            cout<<"请输入排序的方式："<<endl;
            cout<<"1、编号升序"<<endl;
            cout<<"2、编号降序"<<endl;
            int select = 0;
            cin >> select;

            //选择排序
            for(int i = 0;i<this->m_EmpNum;i++){
                //定义一个数的索引，为最大值或者最小值
                int minOrmax = i;
                for(int j= i+1;j<this->m_EmpNum;j++){

                    //比较
                    if(select == 1){//升序比较
                    //前面的数 大于 后面的数
                    if(this->m_EmpArrary[minOrmax]->m_Id>this->m_EmpArrary[j]->m_Id){
                        //索引重新赋值
                        minOrmax = j;
                    }

                    }else{//降序
                        //前面的数 小于 后面的数
                        if(this->m_EmpArrary[minOrmax]->m_Id < this->m_EmpArrary[j]->m_Id){
                            //索引重新赋值
                            minOrmax = j;
                        }
                    }
                } 

                //是否需要交换
                //如果先选中的索引，和经过一轮后的索引不一样，则进行交换
                if(i != minOrmax){
                    //交换
                    Worker * temp = this->m_EmpArrary[i];
                    this->m_EmpArrary[i] = this->m_EmpArrary[minOrmax];
                    this->m_EmpArrary[minOrmax] = temp;

                }
            }

            //冒泡排序
            // for (int i = 0; i < this->m_EmpNum; i++)
            // {
            //     for (int j = 0; i < this->m_EmpNum-i-1; i++)
            //     {
            //         if (this->m_EmpArrary[j]->m_Id>this->m_EmpArrary[j+1]->m_Id)
            //         {
            //             Worker * temp = this->m_EmpArrary[j];
            //             this->m_EmpArrary[j] = this->m_EmpArrary[j+1];
            //             this->m_EmpArrary[j+1] = temp;
            //         }
                    
            //     }
                
            // }
            

            cout<<"排序后的结果："<<endl;
            this->save();
            this->Show_Emp();

        }
    }

    //清空文件
    void WorkerManager:: Clean_File(){

    //再次确认是否清空
    cout<<"确定清空？"<<endl;
    cout<<"1、确定"<<endl;
    cout<<"2、取消"<<endl;
    int select = 0;
    cin >> select;


    if(select == 1){

        //1、清空文件
        ofstream ofs;
        ofs.open(FILENAME,ios::trunc);
        ofs.close();

        //2、删除数组
        if(this->m_EmpArrary !=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                //删除数组里面的元素（指针）
                delete this->m_EmpArrary[i];
            }
        }

        //数组数量置空
        this->m_EmpNum = 0;
        //删除数组
        delete[] this->m_EmpArrary;
        //手动置空
        this->m_EmpArrary = NULL;

        //文件是否为空的标记
        this->m_FileIsEmpty = true;
        cout<<"清空成功"<<endl;
    }
}
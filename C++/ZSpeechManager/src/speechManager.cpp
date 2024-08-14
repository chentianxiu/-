#include "speechManager.h"

//构造函数
SpeechManager::SpeechManager(/* args */)
{
	//初始化属性
	this->initSpeech();

    //创建选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();
}

//析构函数
SpeechManager::~SpeechManager()
{

}

void SpeechManager::show_Menu()
{

    cout << "********************************************" << endl;
    cout << "************* 欢迎参加演讲⽐赛 ************" << endl;
    cout << "************* 1.开始演讲⽐赛 *************" << endl;
    cout << "************* 2.查看往届记录 *************" << endl;
    cout << "************* 3.清空⽐赛记录 *************" << endl;
    cout << "************* 0.退出⽐赛程序 *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// 退出
void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

// 初始化属性
void SpeechManager::initSpeech()
{
	//容器保证为空
    this->m_Speaker.clear();
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	//初始化比赛轮数
	this->m_Index = 1;
	//初始化记录容器
	this->m_Record.clear();
}

// 初始化创建12名选⼿
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
    //12名选手赋值
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
        //创建临时演讲者
		Speaker sp;
        //姓名赋值
		sp.m_Name = name;
        //成绩赋值（两轮成绩，初始值为0）
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}

		//第一轮12名选手编号
		this->v1.push_back(i + 10001);

		//选手编号 以及对应的选手 存放到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
    
}

// 开始⽐赛
void SpeechManager::startSpeech()
{
    // 第⼀轮⽐赛
    // 1、抽签
    speechDraw();
    // 2、⽐赛
    speechContest();
    // 3、显示晋级结果
    showScore();
    // 第⼆轮⽐赛
	this->m_Index++;
    // 1、抽签
    speechDraw();

    // 2、⽐赛
    speechContest();

    // 3、显示最终结果
    showScore();
    // 4、保存分数
    saveRecord();

	//重置比赛
	//初始化属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//获取往届记录
	this->loadRecord();

	cout<<"本届比赛完成！"<<endl;
}

// 抽签
void SpeechManager::speechDraw()
{
    cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
    cout << "---------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;
    if (this->m_Index == 1) // 第一轮比赛抽签
    {

        // 洗牌(打乱)
        shuffle(v1.begin(), v1.end(), default_random_engine());

        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else // 第二轮比赛抽签
    {
        shuffle(v2.begin(), v2.end(), default_random_engine());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;

    cout << endl;
}

// ⽐赛
void SpeechManager::speechContest()
{
    cout<<"------------- 第"<<this->m_Index<<"轮正式比赛开始：------------- "<<endl;

    //临时容器，保存key分数 value选手编号
	multimap<double, int, greater<int> > groupScore;
    int num = 0; //记录人员数，6个为1组

	//比赛的人员容器
	vector <int> v_Src; 

	if (this->m_Index == 1)//第一轮
	{
		v_Src = v1;
	}
	else//第二轮
	{
		v_Src = v2;
	}

    //遍历所有参赛选手，对每名选手进行分数赋值
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;//人数+1

        //评委打分
		deque<double> d;
		//每个选手都有10个评委进行打分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			// 测试：所有人员成绩
			//cout << score << " ";
			d.push_back(score);
		}
        
        sort(d.begin(), d.end(), greater<double>());//从大到小排序

        d.pop_front();//去掉最高分
		d.pop_back();//去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);//获取总分
		double avg = sum /  (double)d.size();//获取平均分

		//cout<<endl;
		//每个人平均分
		//cout << "编号： " << *it  << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均分为： " << avg << endl;  //打印分数
		//编号和选手  容器中选手赋值
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;


        //用临时容器保存
		groupScore.insert(make_pair(avg, *it));//key是得分，value是选手的编号

        //每6人获取前三名
		if (num % 6 == 0)
		{

			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<int> >::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << " 姓名： " << this->m_Speaker[it->second].m_Name << " 成绩： " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			int count = 0;

			//取前三名，进入下一轮
			for (multimap<double, int, greater<int> >::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)//第一轮比赛
				{
					v2.push_back((*it).second);//第一轮晋级人员编号
				}
				else
				{
					vVictory.push_back((*it).second);//第二轮前三名，也就是总决赛前三名
				}
			}

			groupScore.clear();//临时小组清空

			cout << endl;

		}
	}
	cout << "------------- 第" << this->m_Index << "轮比赛完毕  ------------- " << endl;


}



// 显示⽐赛结果
void SpeechManager::showScore()
{
    cout << "---------第" << this->m_Index << "轮晋级选手信息如下：-----------" << endl;

	//将每轮晋级的选手编号，临时放入一个容器中
	vector<int>v;

	if (this->m_Index == 1)
	{
		v = v2;//第二轮的选手（编号）放入临时容器
	}
	else
	{
		v = vVictory;//将前三名的选手（编号）放入容器中
	}
	//遍历选手成绩
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << " 姓名： " << m_Speaker[*it].m_Name << " 得分： " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

}

// 保存记录
void SpeechManager::saveRecord()
{
	ofstream file;
	//csv格式文件，每个数据都是用逗号分隔
	file.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件  -- 写文件

	//将每个人数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		file << *it << ","
			<< m_Speaker[*it].m_Score[1] << ",";
	}
	//文件换行
	file << endl;
    
	//关闭文件
	file.close();
    
	cout << "记录已经保存" << endl;

	//有记录了，文件不为空
	this->fileIsEmpty = false;
}

//读取记录
void SpeechManager::loadRecord()
{
	ifstream file("speech.csv", ios::in); //输入流对象 读取文件

	if (!file.is_open())
	{
    //确定文件为空
		this->fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		file.close();
		return;
	}

	char ch;
	file >> ch;
	if (file.eof())
	{
		cout << "文件为空!" << endl;
    //确定文件为空
		this->fileIsEmpty = true;
		file.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	file.putback(ch); //将刚刚读取的单个字符放回去

	string data;
	int index = 0;//表示第几届
	while (file >> data)//一行一行读取到data中
	{
		//测试，加载成绩
		//cout << data << endl;

		//解析往届成绩：10005,83.6125,10007,82.7375,10008,80.725,


		//每一行存到一个容器里面，这个容器每一个位置存储一个以，分割的单词，然后将这个容器存到记录(map这个容器)中

		vector<string>v;//创建临时容器，存放截取的字符串

		int pos = -1;//查找 “,”的位置变量
		int start = 0;//起始位置

		while (true)
		{
			pos = data.find(",", start); //从0开始查找 ','
			if (pos == -1)
			{
				break; //找不到break返回
			}
			//找到了,进行分割 参数1 起始位置，参数2 截取长度
			string temp = data.substr(start, pos - start); 
			//cout<<temp<<" ";
			v.push_back(temp);
			start = pos + 1;//start重新开始，+1表示跳过“,”
		}
		// 添加到往届记录容器中
		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	file.close();

}


//显示往届得分
void SpeechManager::showRecord()
{
	if(this->fileIsEmpty){
		cout<<"文件不存在，或者记录为空"<<endl;
	}else{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
}


//清空记录
void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->initSpeech();

		//创建选手
		this->createSpeaker();

		//获取往届记录
		this->loadRecord();
		

		cout << "清空成功！" << endl;
	}
}

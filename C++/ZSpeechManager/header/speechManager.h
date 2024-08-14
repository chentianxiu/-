#pragma once

#include<iostream>
#include "speaker.h"
#include<vector>
#include<map>
#include<deque>
#include<numeric>
#include<fstream>
#include<algorithm>
#include <random>
#include<ctime>

using namespace std;

//演讲管理类
class SpeechManager
{

public:
    SpeechManager(/* args */);
    ~SpeechManager();

    //菜单
    void show_Menu();

    //退出
    void exitSystem();

    //存放编号 以及对应的 具体选⼿ 容器，可以通过编号，找到选⼿
    map<int, Speaker> m_Speaker; 

    //比赛选手 容器 12人
    vector<int> v1;

    //第⼀轮晋级容器 6⼈
    vector<int> v2;

    //胜利前三名容器 3⼈
    vector<int> vVictory;

    //记录⽐赛轮次
    int m_Index;


    //初始化属性
    void initSpeech();


    //初始化创建12名选⼿
    void createSpeaker();

     //开始⽐赛 - ⽐赛流程控制
    void startSpeech();


     //抽签
    void speechDraw();

    //⽐赛
    void speechContest();


    //显示⽐赛结果
    void showScore();

    //保存记录
    void saveRecord();

    //读取记录
	void loadRecord();

    //文件为空的标志
	bool fileIsEmpty;

    //往届记录：key：第几届比赛。 value：每届成绩汇总
	map<int, vector<string> > m_Record;

    //显示往届得分
	void showRecord();

    //清空记录
	void clearRecord();

};



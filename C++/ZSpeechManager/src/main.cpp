#include <iostream>
using namespace std;
#include "speechManager.h"

int main()
{

    SpeechManager sm;

    int choice = 0; // 用来储存用户选项

    while (true)
    {
        sm.show_Menu();
        cout << "请输⼊您的选择： " << endl;
        cin >> choice; // 接受⽤户的选项
        switch (choice)
        {
        case 1: // 开始⽐赛
            sm.startSpeech();
            break;
        case 2: // 查看记录
            sm.showRecord();
            break;
        case 3: // 清空记录
            sm.clearRecord();
            break;
        case 0: // 退出系统
            sm.exitSystem();
            break;
        default:
            cout << "您输⼊的命令有误,请重新输⼊:" << endl;
            break;
        }
    }

    return 0;
}
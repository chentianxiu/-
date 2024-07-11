#include<iostream>
using namespace std;

#include "header.h"

int main(){
    //创建管理类
    WorkerManager wm;

    int choice = 0;
    while (true)
    {
        //显示主菜单
        wm.Show_Menu();
        cout<<"请输入您的选择:"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 0://退出系统
            wm.exitSystem();
            break;
        
        default:
            cout<<"您输入的命令有误，请重新输入:"<<endl;
            break;
        }
    }
    return 0;
}
#include "Addressbooks.h"

int main()
{
    Addressbooks abs;//创建通讯录
    abs.m_size = 0;//初始化通讯录中的人数
    int select = 0;
    int flag = 1;
    while (flag)
    {
        showMenu();
        cout<<"请输入您的选择:"<<endl;
        cin>>select;

        switch (select)
        {
        case 1://添加联系人
            addperson(&abs);
            break;
        case 2://显示联系人
            printaddbook(&abs);
            break;
        case 3://删除联系人
            deleteaddbook(&abs);
            break;
        case 4://查找联系人
            findaddbokk(&abs);
            break;
        case 5://修改联系人
            modifyaddbook(&abs);
            break;
        case 6://清空联系人
            cleanaddbook(&abs);
            break;
        case 0://退出通讯录
            exit(0);
            break;
        default:
            cout<<"你输入的指令有误，请重新输入"<<endl;
            break;
        }
    }
    



    return 0;
}
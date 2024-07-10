#include "Addressbooks.h"

// 菜单
void showMenu()
{
    cout << "***********" << endl;
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出通讯录" << endl;
    cout << "***********" << endl;
}

// 添加
void addperson(Addressbooks *adr)
{
    person p;
    cout << "请输入姓名" << endl;
    cin >> p.m_Name;
    cout << "请输入性别(1.男/2.女)" << endl;
    cin >> p.m_Sex;
    cout << "请输入年龄" << endl;
    cin >> p.m_Age;
    cout << "请输入电话号码" << endl;
    cin >> p.m_phone;
    cout << "请输入地址" << endl;
    cin >> p.m_Addr;
    adr->personArray[adr->m_size] = p;
    adr->m_size++;
    cout << "添加成功" << endl;
}

// 显示
void printaddbook(Addressbooks *adr)
{
    if (adr->m_size == 0)
    {
        cout << "电话簿为空" << endl;
    }
    else
    {

        for (int i = 0; i < adr->m_size; i++)
        {
            cout << "姓名是:" << adr->personArray[i].m_Name << "\t";
            cout << "性别是:" << adr->personArray[i].m_Sex << "\t";
            cout << "年龄是:" << adr->personArray[i].m_Age << "\t";
            cout << "电话号码是:" << adr->personArray[i].m_phone << "\t";
            cout << "地址是:" << adr->personArray[i].m_Addr << endl;
        }
    }
}

// 是否找到
int exitaddbook(Addressbooks *adr, string name)
{
    for (int i = 0; i < adr->m_size; i++)
    {
        if (adr->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

// 删除
void deleteaddbook(Addressbooks *adr)
{
    string name;
    cout << "请输入你要删除的名字" << endl;
    cin >> name;
    int result = exitaddbook(adr, name);
    if (result != -1) // 找到之后将目标之后所有的往前移动一步
    {
        for (int i = result; i < adr->m_size; i++)
        {
            adr->personArray[i] = adr->personArray[i + 1];
        }
        adr->m_size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

// 查找
void findaddbokk(Addressbooks *adr)
{

}

// 修改
void modifyaddbook(Addressbooks *adr)
{

}

// 清空
void cleanaddbook(Addressbooks *adr)
{
    
}
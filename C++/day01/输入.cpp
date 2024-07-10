#include <iostream>
using namespace std; // 命名空间，标准库

int main()
{
    // // 整型输入
    // int a = 0;
    // cout << "请输入整型变量：" << endl;
    // cin >> a;
    // cout << a << endl;
    // // 浮点型输入
    // double d = 0;
    // cout << "请输入浮点型变量：" << endl;
    // cin >> d;
    // cout << d << endl;
    // // 字符型输入
    // char ch = 0;
    // cout << "请输入字符型变量：" << endl;
    // cin >> ch;
    // cout << ch << endl;
    // // 字符串型输入
    // string str;
    // cout << "请输入字符串型变量：" << endl;
    // cin >> str;
    // cout << str << endl;
    // 布尔类型输入
    bool flag = true;
    cout << "请输入布尔型变量：" << endl;//输入数是1，其他的是0
    cin >> flag;
    cout << flag << endl;

    /*
    输入 0 会将布尔变量设为 false，输出 0。
    输入非零整数会将布尔变量设为 true，输出 1。
    输入非数字字符会导致 cin 失败，布尔变量的值保持不变，可以通过检查 cin.fail() 来检测这种情况。
    但是有些编译器会将cin失败后将flag置为0;
    */

    return 0;
}
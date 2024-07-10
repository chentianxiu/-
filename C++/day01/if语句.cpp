#include <iostream>
using namespace std; // 命名空间，标准库

int main()
{
    int flag =1;
    while (flag)
    {
        int score = 0;
        cout << "请输入你的分数：(输入0退出)" << endl;

        cin >> score;

        cout << "score = " << score << endl;

        if (score >= 600)
        {

            if (score >= 700)
            {
                cout << "你考上了北大" << endl;
            }
            else if (score < 700 && score >= 650)
            {
                cout << "你考上了清华" << endl;
            }
            else
            {
                cout << "你考上了人大" << endl;
            }
        }
        else if (score < 600 && score >= 500)
        {
            cout << "你考上了二本" << endl;
        }
        else if (score < 500 && score >= 400)
        {
            cout << "你考上了本科" << endl;
        }else if(score == 0)
        {
            break;
        }
        else
        {
            cout << "你没考上本科" << endl;
        }
    }

    return 0;
}
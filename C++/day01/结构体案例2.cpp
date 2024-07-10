/*
设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果
*/

#include<iostream>
using namespace std;//命名空间，标准库

struct hero
{
    string name;
    int age;
    bool sex;
};

void bubble(hero * H)//冒泡排序
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5-i-1; j++)
        {
            if (H[j].age>H[j+1].age)
            {
                hero temp = H[j];
                H[j]=H[j+1];
                H[j+1] = temp;
            }
        }
    }
}


int main()
{
    hero H[5];
    H[0]={"盖伦",18,1};
    H[1]={"诺手",35,1};
    H[2]={"赵信",25,1};
    H[3]={"狐狸",18,0};
    H[4]={"暮光星灵",1800,0};

    bubble(H);

    for (int i = 0; i < 5; i++)
    {
        cout<<"{"<<H[i].name<<","<<H[i].age<<","<<H[i].sex<<"}"<<endl;
    }
    return 0;

}
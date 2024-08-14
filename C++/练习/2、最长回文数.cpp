/*
给你一个字符串 s，找到 s 中最长的 回文子串
*/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        string res = "";//存放结果
        string temp = "";//存放字串
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j<s.length(); j++)
            {
                temp = temp+s[j];
                string tem = temp;//创建一个临时变量来比较反转结果
                reverse(tem.begin(),tem.end());//反转
                if (tem==temp)
                {
                    res =res.length()>temp.length()?res:temp;
                }
                
            }
            temp = "";
        }
        return res;
    }
};

int main()
{
    string s = "cbbd";

    Solution ss;
    string s1 = ss.longestPalindrome(s);
    cout<<s1<<endl;
}
#include <iostream>
#include <string>

/*
给你一个字符串 s，找到 s 中最长的回文子串。

*/

using namespace std;

class Solution
{
    string longestPalindromeByPos(string s, int left, int right)
    {
        if(left < 0 || right >= s.length())
        {
            return "";
        }

        if(s[left] != s[right])
        {
            return 
            s.substr(left, 1);
        }

        string tempStr1;
        while(true)
        {
            if (left < 0 || right >= s.length())
            {// 走到了边界需要进行回退
                tempStr1 = s.substr(left+1, right-1-(left+1)+1);
                break;
            }

            if(s[left] == s[right])
            {
                --left;
                ++ right;
            }
            else
            {//不相等需要进行回退
                tempStr1 = s.substr(left+1, right-1-(left+1)+1);
                break;
            }
        }

        return tempStr1;
    }

    string longestPalindromeByPos(string s, int pos)
    {
        // 1 先算是偶数的
        int left = pos;
        int right = pos + 1;

        string tempStr1 = longestPalindromeByPos(s, left, right);

        left = pos - 1;
        right = pos + 1;
        string tempStr2 = longestPalindromeByPos(s, left, right);

        if (tempStr2.length() > tempStr1.length())
        {
            return tempStr2;
        }
        else
        {
            return tempStr1;
        }
    }

public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }
        
        string lastStr;
        for (int i = 0; i < s.length(); ++i)
        {
            string result = longestPalindromeByPos(s, i);

            if(result.length() > lastStr.length())
            {
                lastStr = result;
            }
        }

        return lastStr;
    }
};

int main()
{
    Solution solution;

    std::string sourceStr = "babad";

    std::cout <<
    solution.longestPalindrome(sourceStr) << std::endl;

    return 0;
}
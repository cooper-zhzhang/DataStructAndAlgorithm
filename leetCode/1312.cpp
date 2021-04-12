#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minInsertions(string s) 
    {
        if(s.size() <= 1)
        {
            return 0;
        }

        vector<vector<int> > dp(s.size(), vector<int>(s.size(), INT_MAX));
        return minInsertions(s, 0, s.size()-1, dp);
    }


    private:
    int minInsertions(string &s, int lIndex, int rIndex, vector<vector<int> > &dp)
    {
        if (lIndex >= rIndex)
        {
            return 0;
        }

        if (dp[lIndex][rIndex] != INT_MAX)
            return dp[lIndex][rIndex];

        
        if (s[lIndex] == s[rIndex])
            dp[lIndex][rIndex] = std::min(dp[lIndex][rIndex], minInsertions(s, lIndex + 1, rIndex - 1, dp));

        // 右边插入
        dp[lIndex][rIndex] = std::min(dp[lIndex][rIndex], 1+minInsertions(s, lIndex + 1, rIndex, dp));

        // 左边插入
        dp[lIndex][rIndex] = std::min(dp[lIndex][rIndex], 1+minInsertions(s, lIndex, rIndex - 1, dp));

        return dp[lIndex][rIndex];
    }

};

int main(int argc, char** argv)
{
    vector<string> ve;

    ve.push_back("zzazz");
    ve.push_back("mbadm");
    ve.push_back("leetcode");
    ve.push_back("g");
    ve.push_back("no");
    ve.push_back("zjveiiwvc");//5

    Solution Solution;

    for (auto it : ve)
    {
        int result =Solution.minInsertions(it);

        std::cout << result << std::endl;
    }
    
    return 0;
}
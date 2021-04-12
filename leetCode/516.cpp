#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), INT_MIN));

        return longestPalindromeSubseq(s, 0, s.size()-1, dp);
    }

    private:
    int longestPalindromeSubseq(string &s, int lIndex, int rIndex, vector<vector<int> > &dp)
    {
        if (lIndex == rIndex)
        {
            return 1;
        }
        
        if (lIndex >= rIndex)
        {// TOOD: 这里是否需要进行返回1
            return 0;
        }
        
        if(dp[lIndex][rIndex] != INT_MIN)
            return dp[lIndex][rIndex];


        if (s[lIndex] == s[rIndex])
        {
            dp[lIndex][rIndex] = std::max(dp[lIndex][rIndex], 2+longestPalindromeSubseq(s, lIndex+1, rIndex-1, dp));
        }

        dp[lIndex][rIndex] = std::max(dp[lIndex][rIndex], longestPalindromeSubseq(s, lIndex+1, rIndex, dp));

        dp[lIndex][rIndex] = std::max(dp[lIndex][rIndex], longestPalindromeSubseq(s, lIndex, rIndex-1, dp));

        return dp[lIndex][rIndex];
    }
};

int main(int argc, char **argv) 
{
    vector<string> ve;

    ve.push_back("bbbab");//4
    ve.push_back("cbbd");//2

    Solution Solution;

    for (auto it : ve)
    {
        int result =Solution.longestPalindromeSubseq(it);

        std::cout << result << std::endl;
    }
    

    return 0;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        if (text1.size() <= 0 || text2.size() <= 0)
        {
            return 0;
        }
        
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), INT_MIN));

        return longestCommonSubsequence(text1, text2, 0, 0, dp);
    }

private:
    int longestCommonSubsequence(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= word1.size() || j >= word2.size())
            return 0;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        if (word1[i] == word2[j])
            dp[i][j] = std::max(dp[i][j], 1+longestCommonSubsequence(word1, word2, i + 1, j + 1, dp));

        dp[i][j] = std::max(dp[i][j], longestCommonSubsequence(word1, word2, i + 1, j, dp));
        dp[i][j] = std::max(dp[i][j], longestCommonSubsequence(word1, word2, i, j + 1, dp));
        
        return dp[i][j];
    }
};

int main(int argc, char **argv)
{

    vector<string> ve1;
    ve1.push_back("abcde");
    ve1.push_back("abc");
    ve1.push_back("abc");

    vector<string> ve2;
    ve2.push_back("ace");//3
    ve2.push_back("abc");//3
    ve2.push_back("def");//0


    Solution Solution;

    for (size_t i = 0; i < ve2.size(); i++)
    {
        int result =Solution.longestCommonSubsequence(ve1[i], ve2[i]);

        std::cout << result << std::endl;
    }

    return 0;
}


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
        vector<int> sum(s.size(), -1);

        return numDecodings(s, sum, 0);

        return 0;
    }


    int numDecodings(string &s, vector<int> &sum, int index)
    {
        if (index >= s.size())
        {// 走到最后了是一个可行的路径
            return 1;
        }

        if (sum[index] >= 0)
        {
            return sum[index];
        }

        sum[index] = 0;

        
        // 取一个
        char ch = s[index];

        if (ch == '0')
        {
            return sum[index];
        }

        // 取一个
        sum[index] += numDecodings(s, sum, index+1);
        
        // 取两个
        if (index+1 >= s.size())
        {//到了尾部
            return sum[index];
        }

        int number = ch - '0';
        number = number * 10 + s[index+1] - '0';
        if (number <= 26 && number >= 1)
        {
            sum[index] += numDecodings(s, sum, index+2);
        }
        

        return sum[index];
    }
};

int main(int argc, char **argv)
{
    Solution solution;

    vector<string> ve{"12", "226", "0", "06", "10011", "100"};
    //2 3 0 0 0 0

    for (size_t i = 0; i < ve.size(); i++)
    {
        std::cout << solution.numDecodings(ve[i]) << std::endl;
    }

    return 0;
}
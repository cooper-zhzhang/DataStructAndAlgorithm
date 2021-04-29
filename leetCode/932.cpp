#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int N) 
    {

        vector<int> sourceVec(N, 0);
        for (size_t i = 0; i < sourceVec.size(); i++)
        {
            sourceVec[i] = i+1;
        }

        beautifulArray(sourceVec, 0, N-1);

        return sourceVec;
    }

    void beautifulArray(vector<int> &sourceVec, int start, int end)
    {
        if(end - start + 1 <= 2)
        {// 数组中只有两个数字就不用排了
            return ;
        }
        
        std::vector<int> leftVec;
        std::vector<int> rightVec;

        for (int i = start; i <= end; i++)
        {
            if((i-start)%2==0)
            leftVec.push_back(sourceVec[i]);
            else
            rightVec.push_back(sourceVec[i]);
        }

        std::copy(leftVec.begin(), leftVec.end(), &(sourceVec[start]));
        std::copy(rightVec.begin(), rightVec.end(), &(sourceVec[start+leftVec.size()]));

        beautifulArray(sourceVec, start, leftVec.size()+start-1);
        beautifulArray(sourceVec, leftVec.size()+start, end);
    }
};

int main(int argc, char** argv)
{
    Solution solution;

    auto vec =
    solution.beautifulArray(9);
    for ( auto it : vec)
    {
        std::cout << it << " ";
    }
    
    return 0;
}
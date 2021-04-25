#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int> resultIndex(nums.size(), -1);
        stack<int> temStack;

        int i = -1;
        while(i <= int(nums.size()*2))
        {
            ++i;
            int curIndex = i % nums.size();
            int curValue = nums[curIndex];
            while(!temStack.empty())
            {// 依次进行一个比较
                int index = temStack.top();
                if (nums[index] < nums[curIndex])
                {
                    if(resultIndex[index] == -1)
                        resultIndex[index] = curIndex;
                    temStack.pop();
                }
                else
                {
                    break;
                }
            }
            temStack.push(curIndex);
        }

        for (i = 0; i < resultIndex.size(); ++i)
        {
            if (resultIndex[i] >= 0)
            {
                resultIndex[i]= nums[resultIndex[i]];
            }
        }
        
        return resultIndex;
    }
};

int main(int argc, char* argv[]) 
{
    Solution solution;
    std::vector<int> nums{1, 2, 1};
    //std::vector<int> nums{2, 3, 1, 4, 1};
    auto result = solution.nextGreaterElements(nums);
    for(auto value : result)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
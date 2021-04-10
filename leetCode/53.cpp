/*给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxValue = 0;
        if (nums.size() > 0)
        {
            maxValue = nums[0];
        }
        else
        {
            return 0;
        }

        int curValue = maxValue;
        for (size_t i = 1; i < nums.size(); i++)
        {
            curValue = max(curValue + nums[i], nums[i]);
            maxValue = max(maxValue, curValue);

            // curValue += nums[i];
            // if(curValue > maxValue)
            // {
            //     maxValue = curValue;
            // }

            // if (nums[i] > maxValue)
            // {
            //     curValue = maxValue = nums[i];
            // }

            // if (curValue < 0)
            // {
            //     curValue = 0;
            // }
        }

        return maxValue;
    }
};

int main(int argc, char **argv)
{
    Solution solution;

    //std::vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //std::vector<int> vec{-1, 2, 3};
    std::vector<int> vec{3, -1, 3};

    std::cout << solution.maxSubArray(vec) << std::endl;
    return 0;
}
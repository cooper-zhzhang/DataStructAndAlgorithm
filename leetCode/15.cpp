/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

算法思想上可以 就是实现细节需要优化

*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:


vector<vector<int>> threeSumtttt(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }


    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<int> uniqueSet;
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());//o(n*logn)

        for (int i = 0; 0 < nums.size(); )//O(n)
        {
            int value = nums[0];
            nums.erase(nums.begin());

            if(uniqueSet.find(value) != uniqueSet.end())
            {// 只需要保存上次的数就行了 TODO
                continue;
            }

            uniqueSet.insert(value);
            vector<vector<int>> ve = twoSum(nums, 0-value);// O(n)

            if (!ve.empty())
            {
                for (size_t j = 0; j <ve.size(); j++)
                {
                    ve[j].insert(ve[j].begin(), value);
                    result.push_back(ve[j]);
                }
            }
        }

        return result;
    }

    vector<vector<int>> twoSum(vector<int> &nums, int value)
    {
        int i = 0;
        int j = nums.size() - 1;

        vector<vector<int>> ve;

        while(i < j)
        {
            if(nums[i] + nums[j] < value)
            {
                ++i;
            }
            else if(nums[i] + nums[j] > value)
            {
                --j;
            }
            else
            {
                int value1 = nums[i];
                int value2 = nums[j];

                ve.push_back(vector<int>{nums[i], nums[j]});
                ++i;
                --j;

                while(i < j)
                {
                    if (value1 == nums[i] || value2 == nums[j])
                    {
                        if (value1 == nums[i])
                        {
                            ++i;
                        }

                        if (value2 == nums[j])
                        {
                            --j;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        return ve;
    }

};

int main()
{
    Solution solution;

    vector<int> nums = {-1,0,1,2,2,-1,-4,-2,-3,3,0,4};
    //vector<int> nums = {0, 0, 0, 0};
    

    vector<vector<int>> result =
    solution.threeSumtttt(nums);

    for(auto &itVe : result)
    {
        for(auto it : itVe)
        {
            std::cout << it << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
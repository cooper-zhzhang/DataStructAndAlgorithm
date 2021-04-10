/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

 

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int insertIndex = 0;
        int deleteIndex = 0;

        int count = nums.size();
        for (int deleteIndex = 0; deleteIndex < count; deleteIndex++)
        {
            if(nums[deleteIndex] != val)
            {
                nums[insertIndex++] = nums[deleteIndex];
            }
        }

        return insertIndex;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int result =
    solution.removeElement(nums, val);

    for (int i = 0; i < result; i++)
    {
        std::cout << nums[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}